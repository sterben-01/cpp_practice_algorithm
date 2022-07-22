#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/select.h>

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

    //4. 创建fd_set的集合存放文件需要检测的描述符
    fd_set select_fd_set, select_fd_set_KERN;
    /*
    @这里文件描述符数组有要点:
    我们内核select函数会直接修改这个需要检测的文件的数组。但是假如我们有4个客户端 100 101 102 103需要检测。
    所以100-103的位置都是1。
    我们如果此时只有100 和 101 被修改了，那么这个数组里面将只有100 和 101是1。 102和103将会被置为0，不会被继续监听。
    所以我们有两个数组。一个是原始的只可以被set和clr进行手动设置和归零的。
    另一个是给内核的，内核可以修改的。
    所以我们select的时候给内核可修改版本。set和clr还是修改原始版本。然后在每一次的while循环一开始，更新内核版本为原来的需要监听的那几个。
    */
    FD_ZERO(&select_fd_set); //文件描述符集合初始化为0
    FD_SET(listen_FD, &select_fd_set); //!我们这个程序依旧是单线程/单进程。accept函数是会被阻塞的。为了让accept部分也做到非阻塞我们必须要也监听listen_fd这个文件。
    //因为如果有客户端连进来了，listen_fd监听描述符的缓冲区也会被修改。这样也可以提示客户端有数据进来了，我们可以建立链接。
    int max_fd = listen_FD; //我们需要一个需要select监听的最大的文件描述符。第一次创建的时候仅监听listen_FD 所以我们一开始设置listen_FD为最大的文件描述符

    while(1){
        select_fd_set_KERN = select_fd_set; //重新给内核可修改的数组赋值

        //5. 使用select来让内核帮助检测哪些文件描述符被修改了。
        int ret = select(max_fd + 1, &select_fd_set_KERN, NULL, NULL, NULL); //最后一个参数设置超时时间。//@这里用的是内核可修改版。
        //TODO:设置为NULL就是永久阻塞，直到有至少一个文件描述符对应的缓冲区被更改。设置为0是不阻塞、
        if(ret == -1){
            perror("select IO reuse ERROR");
            exit(-1);
        }
        else if(ret == 0){
            //select返回值代表着有几个文件描述符对应的缓冲区被更改。如果是0代表没有文件描述符对应的缓冲区被更改。但是我们这里设置的是永久阻塞所以这里不可能为0。此处仅作为模板和示例。
            continue;
        }
        else if (ret > 0){
            //说明有ret个文件描述符对应的缓冲区被更改。
            //TODO: 我们需要判断两种。第一种是监听的文件描述符对应的缓冲区是否被更改。第二种是读写文件描述符。
            if(FD_ISSET(listen_FD, &select_fd_set_KERN)){ //@这里用的是内核可修改版。
                //6.如果监听的文件描述符对应的缓冲区被修改, 接收客户端链接
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

                //6.2 把新建立的读写文件描述符放入select监听的文件描述符数组 并 更新最大的文件描述符值。
                FD_SET(accept_FD, &select_fd_set); //@这里用的是原始版。因为新增了需要监听的文件描述符。
                max_fd = max_fd > accept_FD ? max_fd : accept_FD; //判断一开始的描述符大还是新建立的读写描述符大

            }
            //7. 遍历select监听的文件描述符数组。因为文件描述符是增长的。我们的监听文件描述符一定是最先的。剩下新建的都在后面。所以我们从listen_fd + 1 开始，不用再看listen_fd了因为上一部分看了。
            //一直看到当前最大的描述符(包含)为止
            for(int current_fd = listen_FD + 1; current_fd <= max_fd; current_fd++){ 
                if(FD_ISSET(current_fd, &select_fd_set_KERN)){ //@这里用的是内核可修改版。
                    //8. 如果对应的文件描述符对应的缓冲区被修改 也就是客户端发来了数据。接受客户端发送的数据。
                    char recv_buf[1024] = {0}; //设立数据缓冲区
                    int len = read(current_fd, recv_buf, sizeof(recv_buf)); //读取客户端发送的数据
                    if(len == -1){ //如果读取错误
                        perror("read error");
                        exit(-1);
                    }
                    else if(len == 0){//!这里千万不要忘！等于0就是客户端断开了连接
                        printf("client disconnected...\n");
                        FD_CLR(current_fd, &select_fd_set); //客户端断开连接了就不需要继续让select监听了。可以设为0了。 //@这里用的是原始版。因为减少了需要监听的文件描述符。
                        close(current_fd); //关闭读写文件描述符 
                    }
                    else if(len > 0){
                        printf("receive message from client: %s\n", recv_buf); //打印读取到的数据
                        //9. 数据写回客户端
                        write(current_fd, recv_buf, strlen(recv_buf) + 1);
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