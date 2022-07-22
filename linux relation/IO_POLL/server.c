#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <poll.h>
#define MAX_POLL_FD_SIZE 1024
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

    //4. 初始化poll检测的文件描述符数组
    struct pollfd poll_fd_set[MAX_POLL_FD_SIZE];
    //todo：对数组进行初始化操作
    memset(&poll_fd_set, 0, sizeof(poll_fd_set)); //数组初始化为0
    for(int i = 0; i < MAX_POLL_FD_SIZE; i++){
        //bzero(&clients[i], sizeof(clients[i]));
        poll_fd_set[i].fd = -1; //对文件描述符置-1
        poll_fd_set[i].events = POLLIN; //表示要全部都检测读的事件
    }
    //4.1 将监听的文件描述符加入poll数组。原理和select一样。
    poll_fd_set[0].fd = listen_FD;
    int max_valid_fd = 0; //我们需要一个需要poll监听文件描述符数组中的最后一个有效元素的下标 + 1。一开始我们只给了下标为0的赋值为listenfd 所以我们这里直接给0即可。下面再+1

    while(1){


        //5. 使用poll来让内核帮助检测哪些文件描述符被修改了。
        int ret = poll(poll_fd_set, max_valid_fd + 1, -1); 
        /*
            第二个参数是第一个参数数组中//!最后一个有效元素的下标 + 1。
            *注意是下标，不是文件描述符本身。
            TODO 第三个参数设置为-1就是永久阻塞，直到有至少一个文件描述符对应的缓冲区被更改。设置为0是不阻塞、
        */
        

        if(ret == -1){
            perror("POLL IO reuse ERROR");
            exit(-1);
        }
        else if(ret == 0){
            //Poll返回值代表着有几个文件描述符对应的缓冲区被更改。如果是0代表没有文件描述符对应的缓冲区被更改。但是我们这里设置的是永久阻塞所以这里不可能为0。此处仅作为模板和示例。
            continue;
        }
        else if (ret > 0){
            //说明有ret个文件描述符对应的缓冲区被更改。
            //TODO: 我们需要判断两种。第一种是监听的文件描述符对应的缓冲区是否被更改。第二种是读写文件描述符。
            //!这里最好不要直接 用 == 来判断，因为假如我们同时监听POLLIN和POLLOUT，poll会返回如 POLLIN | POLLOUT 这样的值。这个是不等于POLLIN的。所以我们用&来判断。非0为真0为假
            if(poll_fd_set[0].revents & POLLIN == POLLIN){ 
                //6.如果监听文件描述符对应的缓冲区被修改, 接收客户端链接
                struct sockaddr_in client_INFO;
                int client_INFO_size = sizeof(client_INFO);
                int accept_FD = accept(listen_FD, (struct sockaddr *)&client_INFO, &client_INFO_size); 

                if(accept_FD == -1){
                    perror("accept connection error");
                    exit(-1);
                }
                //6.1 将接收到的客户端信息转换为主机字节序

                char client_ip[16];
                inet_ntop(AF_INET, &client_INFO.sin_addr.s_addr, client_ip, sizeof(client_ip)); //客户端ip端口储存在名为client_INFO的结构体里面 客户ip转换为主机字节序
                unsigned short client_port = ntohs(client_INFO.sin_port); // 客户端口转换为主机字节序
                printf("clientIP:%s, clientPort: %d\n", client_ip, client_port);

                //6.2 把新建立的读写文件描述符放入poll监听的文件描述符数组 并 更新最大的文件描述符值。
                for(int i = 1; i < MAX_POLL_FD_SIZE; i++){ //注意从1开始遍历是否有文件描述符为-1的元素（也就是可用的元素）。从1开始遍历是因为0是我们的监听文件描述符
                    if(poll_fd_set[i].fd == -1){
                        poll_fd_set[i].fd = accept_FD; //@新增了需要让poll监听的文件描述符 至 poll监听的文件描述符数组。
                        poll_fd_set[i].events = POLLIN; //@设置为监听是否可读。
                        max_valid_fd = max_valid_fd > i ? max_valid_fd : i; //判断一开始的描述符大还是新建立的读写描述符大, 设置最大的有效的描述符索引
                        /*
                        这玩意好像后来就没用了。假如你一开始顺序链接，干到了1020.然后你突然10~1020全断开了。这时候第一个可用的是10。i = 10。
                        但是max这玩意降不下来啊。。。。这时候比较一下max还是1020.这玩意只升不降。所以这个应该是个峰值。假如最高链接到了1023那就一直是1023了。。很痛苦
                        */
                       printf("current FD = :%d\n", i);
                        break; //找到了就退出
                    }
                }
                

            }
            //7. 遍历poll监听的文件描述符数组。因为文件描述符是增长的。我们的监听文件描述符一定是最先的。剩下新建的都在后面。而且这个位置是索引。所以我们从1开始，不用再看listen_fd了因为上一部分看了。
            //一直看到当前最大的描述符(包含)为止 后期max_valid_fd这个玩意就一直是1024了
            for(int current_fd = 1; current_fd <= max_valid_fd; current_fd++){ 
                if(poll_fd_set[current_fd].revents & POLLIN == POLLIN){ 
                    //8. 如果对应的文件描述符对应的缓冲区被修改 也就是客户端发来了数据。接受客户端发送的数据。
                    char recv_buf[1024] = {0}; //设立数据缓冲区
                    int len = read(poll_fd_set[current_fd].fd, recv_buf, sizeof(recv_buf)); //读取客户端发送的数据
                    if(len == -1){ //如果读取错误
                        perror("read error");
                        exit(-1);
                    }
                    else if(len == 0){//!这里千万不要忘！等于0就是客户端断开了连接
                        printf("client disconnected...\n");
                        poll_fd_set[current_fd].fd = -1; //客户端断开连接了就不需要继续让poll监听了。可以描述符设为-1了
                        poll_fd_set[current_fd].events = -1; // 事件设为-1
                        poll_fd_set[current_fd].revents = -1; // 事件设为-1
                        close(poll_fd_set[current_fd].fd); //关闭读写文件描述符 //!别关错了
                    }
                    else if(len > 0){
                        printf("receive message from client: %s\n", recv_buf); //打印读取到的数据
                        //9. 数据写回客户端
                        write(poll_fd_set[current_fd].fd, recv_buf, strlen(recv_buf) + 1);
                        bzero(recv_buf, 1024);
                    }
                }

            }

        }


    }
    //10. 关闭文件描述符
    close(listen_FD); //关闭监听文件描述符



    return 0;
}