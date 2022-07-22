#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/epoll.h>
#define MAX_EPOLL_FD_SIZE 1024
int main(){

    //1. 创建socket -- 用于监听的套接字。

    int listen_FD = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_FD == -1){
        perror("listen FD create error");
        exit(-1);
    }

    //@1.1 绑定前使用setsockopt来设置端口复用。第四个参数是void*所以需要传地址。
    
    int optval = 1;
    setsockopt(listen_FD, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

    //2. bind 将监听的文件描述符和一个ip地址、端口进行绑定
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET; //设置协议族

    //inet_pton(AF_INET, "127.0.0.1", server_address.sin_addr.s_addr); //点分十进制转换为网络字节序的ip整数
    //上面这一行是之前地址转换函数的融合。第二个位置可以用char[] 也可以直接写一个字符串。第三个可以写一个unsigned char去接也可以直接赋值给sock_address的ip
    server_address.sin_addr.s_addr = INADDR_ANY; //指定ip地址 0.0.0.0 指的是任意地址。仅服务端可以这样使用。
    server_address.sin_port = htons(9999); //指定服务器端口并转换为网络字节序 

    int ret = bind(listen_FD,(struct sockaddr *)&server_address, sizeof(server_address)); //第二个参数是sockaddr类型的指针。直接取地址之后强转即可。
    if(ret == -1){
        perror("bind error");
        exit(-1);
    }

    //3. 监听
    ret = listen(listen_FD, 128);
    if(ret == -1){
        perror("listen error");
        exit(-1);
    }

    //4. 调用epoll_create 创建EPOLL实例
    int epoll_fd = epoll_create(39);
    
    //@4.1 创建epoll_event 结构来封装信息后告知具体要监听文件的哪个操作
    struct epoll_event epoll_Event;
    epoll_Event.events = EPOLLIN; //监听是否可读
    epoll_Event.data.fd = listen_FD; //监听 监听文件描述符

    //5. 将监听文件描述符添加至epoll监听的监听文件队列
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_FD, &epoll_Event);

    //5.1 建立 储存epoll_wait检测到的 修改过的 文件描述符的 数组
    struct epoll_event epoll_fds[MAX_EPOLL_FD_SIZE];

    while(1){
        //6. 调用epoll_wait 检测哪些文件描述符被修改了, 储存到epoll_fds数组
        int ret = epoll_wait(epoll_fd, epoll_fds, MAX_EPOLL_FD_SIZE, -1); //第四个参数设置为-1代表阻塞至至少有一个文件描述符被修改。
        if(ret == -1){
            perror("epoll detection error");
            exit(-1);
        }

        printf("epoll_wait return value = %d\n", ret); //返回值储存了修改了的文件描述符的数量。通过这个值可以决定我们需要遍历到数组的哪个下标

        /*
        因为epoll_wait每次会把所有检测到改动的文件描述符复制到epoll_fds数组。他会从0开始覆盖。假如第一次是 1 3 5被修改，数组就是1 3 5。第二次是 3 8被修改 则数组就是 3 8。
        TODO: 具体是3 8 还是 3 8 5 还真不清楚
        */
        // for(int i = 0; i < 10; i++){
        //     printf("fds in event = %d\n",epoll_fds[i].data.fd);

        // }


        //7. 遍历储存了被修改的文件描述符的数组。这里我们仍旧需要将监听文件描述符和读写文件描述符分开判断
        for(int i = 0; i < ret; i++){
            int current_fd = epoll_fds[i].data.fd; //当前文件描述符

            //8. 如果是监听文件描述符对应的缓冲区被修改, 接收客户端链接
            if(current_fd == listen_FD){
                struct sockaddr_in client_INFO;
                int client_INFO_size = sizeof(client_INFO);
                int accept_FD = accept(listen_FD, (struct sockaddr *)&client_INFO, &client_INFO_size); 

                if(accept_FD == -1){
                    perror("accept connection error");
                    exit(-1);
                }
                //8.1 将接收到的客户端信息转换为主机字节序

                char client_ip[16];
                inet_ntop(AF_INET, &client_INFO.sin_addr.s_addr, client_ip, sizeof(client_ip)); //客户端ip端口储存在名为client_INFO的结构体里面 客户ip转换为主机字节序
                unsigned short client_port = ntohs(client_INFO.sin_port); // 客户端口转换为主机字节序
                printf("clientIP:%s, clientPort: %d\n", client_ip, client_port);

                //9. 把新建立的读写文件描述符放入epoll监听的监听文件文件描述符队列
                //@复用epoll_event 结构来封装信息后告知具体要监听文件的哪个操作
                epoll_Event.events = EPOLLIN; //监听是否可读
                epoll_Event.data.fd = accept_FD; //监听 新接受的读写文件描述符
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, accept_FD, &epoll_Event);
            }
            //10. 如果是读写文件描述符对应的缓冲区被修改, 接收客户端数据
            else{ 
                if(epoll_fds[i].events & EPOLLOUT){
                    //!这里是如果你有监听多种事件的话，比如这里如果监听写的话 操作写在这。为什么要用&上一个IO_POLL写过了。
                    continue;
                }
                if(epoll_fds[i].events & EPOLLIN){
                    //!这里仅针对读
                    char recv_buf[1024] = {0}; //设立数据缓冲区
                    int len = read(current_fd, recv_buf, sizeof(recv_buf)); //读取客户端发送的数据
                    if(len == -1){ //如果读取错误
                        perror("read error");
                        exit(-1);
                    }
                    else if(len == 0){//!这里千万不要忘！等于0就是客户端断开了连接
                        printf("client disconnected...\n");
                        epoll_ctl(epoll_fd, EPOLL_CTL_DEL, current_fd, NULL); //客户端断开连接了就不需要继续让epoll监听了。可以删掉了
                        close(current_fd); //关闭读写文件描述符 //!别关错了
                    }
                    else if(len > 0){
                        printf("receive message from client: %s\n", recv_buf); //打印读取到的数据
                        //9. 数据写回客户端
                        write(current_fd, recv_buf, strlen(recv_buf) + 1);
                        bzero(recv_buf, 1024);
                    }
                }
                //TODO 如果其他情况可以写在这。
                

            }



            

        }




    }

    //10. 关闭文件描述符
    close(listen_FD); //关闭监听文件描述符
    close(epoll_fd); //关闭epoll文件描述符

    return 0;
}