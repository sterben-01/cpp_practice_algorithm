#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <errno.h>
void recycleChild(int arg){
    while(1){ 
        /*
        这里需要用while循环的原因是如果有一个子进程触发了信号然后回收，如果这时候信号还是未决状态，这时候又有其他子进程触发了信号，则其他信号会被丢弃。
        因为信号会被丢弃，所以处理信号的函数也就是这个函数仅会被执行一次。会导致有子进程无法被回收。
        !调用一次waitpid或wait仅能回收一个子进程 所以仅执行一次的话会导致有子进程无法被回收。
        加上while的话就会回收所有在while运行期间内结束的子进程。
        */
        int ret = waitpid(-1, NULL, WNOHANG); //回收所有子进程 设置为非阻塞

        if(ret == -1){
            //所有子进程都回收完毕
            break;
        }
        else if(ret == 0){
            //仍有子进程存活
            break;
        }
        else if(ret > 0){
            //子进程被回收
            printf("子进程%d 被回收了\n", ret);
        }

    }
}
/*
事实上，waitpid与SIGCHLD信号的关联并不大。
waitpid的函数构造是，回收第一个僵尸子进程。
而加上while之后就能够回收所有在while运行期间内结束的子进程。与SIGCHLD关系不大。
其实加上信号也仅仅是为了在没有子进程退出的时候不操心waitpid。或者是，更优雅一点。
*/
int main(){


    //TODO: 注册信号捕捉
    struct sigaction act;
    act.sa_flags = 0; //也可以设置为SA_RESTART
    sigemptyset(&act.sa_mask);
    act.sa_handler = recycleChild;

    sigaction(SIGCHLD, &act, NULL);



    //1. 创建socket -- 用于监听的套接字。

    int listen_FD = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_FD == -1){
        perror("listen FD create error");
        exit(-1);
    }


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

    //4. 不断循环等待客户端连接
    while(1){
        struct sockaddr_in client_INFO;
        int client_INFO_size = sizeof(client_INFO);

        //5.接收客户端链接
        int accept_FD = accept(listen_FD, (struct sockaddr *)&client_INFO, &client_INFO_size); 

        if(accept_FD == -1){
            if(errno == EINTR){
                continue;
            }
            perror("accept connection error");
            exit(-1);
        }



        /*
        int accept_FD = accept(listen_FD, (struct sockaddr *)&client_INFO, &client_INFO_size); 
        if(accept_FD == -1){
            perror("accept connection error");
            exit(-1);
        }
        我们目前这里有问题的原因是，当子进程退出之后，会触发信号，然后会产生软中断来进行回调函数的使用来回收子进程资源。
        但是accept是一直在这里阻塞的。如果阻塞的时候也就是建立有效连接之前被中断了，则会返回一个EINTR错误。
        所以目前来说，一个客户端退出了，直接这样用的话，服务端发现一个客户端断开连接，那么一个子进程将会停止。然后触发信号，触发软中断，使用回调函数回收子进程资源。
        回来的时候accept函数被中断了返回一个EINTR错误，直接执行了accept_FD == -1这一段，然后父进程会exit(-1)退出。

        *所以我们要让accept被打断后回来的时候判断一下，如果error number是EINTR的话，继续监听。也就是continue这个while监听循环

        */



        //6.创建子进程。每建立一个新连接，创建一个子进程和客户端通信。

        pid_t pid = fork();


        /*
        fork之后，子进程拥有和父进程一样的东西。因为是复制的。然后父子进程都从fork下面的第一条代码来执行。如何确保父进程只进行监听而子进程只进行数据传输呢？
        我们仅需要将pid = 0的时候也就是子进程执行的代码放进if里来执行数据传输即可。父进程执行fork后会有两次fork的返回值。一次是父进程，一次是子进程。父进程拿到的是子进程的pid，子进程拿到的是0.
        */

        if(pid == 0){
            //子进程
            
            char client_ip[16];
            inet_ntop(AF_INET, &client_INFO.sin_addr.s_addr, client_ip, sizeof(client_ip)); //客户端ip端口储存在名为client_INFO的结构体里面 客户ip转换为主机字节序

            unsigned short client_port = ntohs(client_INFO.sin_port); // 客户端口转换为主机字节序
            
            printf("clientIP:%s, clientPort: %d\n", client_ip, client_port);


            //7.接受客户端发送的数据。
            char recv_buf[1024] = {0}; //设立数据缓冲区
            while(1){
                int len = read(accept_FD, recv_buf, sizeof(recv_buf)); //读取客户端发送的数据。注意这里文件描述符是接收客户端的时候建立的文件描述符，而不是监听的文件描述符
                //!这里注意不可以用strlen(recv_buf)。因为我们不知道客户输入的是多长。所以我们一次读完一整个缓冲区。而且他读到\0就停了。
                if(len == -1){ //如果读取错误
                    perror("read error");
                    exit(-1);
                }
                else if(len > 0){
                    printf("receive message from client: %s\n", recv_buf); //打印读取到的数据
                }
                else if(len == 0){//!这里千万不要忘！等于0就是客户端断开了连接
                    printf("client disconnected...");
                    break;
                }
                //8. 给客户端发送数据
                write(accept_FD, recv_buf, strlen(recv_buf) + 1); //写入要长度+1把\0放进去 因为strlen不包括\0。
                bzero(recv_buf, 1024);
            }

            //9. 关闭读写文件描述符并退出子线程
            //!因为主进程一直在监听。所以这里不关闭监听文件描述符
            close(accept_FD); //关闭读写文件描述符
            exit(0);
        }




    }

    //10. 关闭监听文件描述符并退出子线程
    close(listen_FD);
    return 0;
}

/*
!要点
    *1.fgets会在输入流末尾自动加上’\0’
    *2.sizeof整个缓冲区的结果是缓冲区大小
        char test[1024]
        sizeof(test) 是1024
    *3.strlen不包含结尾的\0大小
        char test = "ABC"
        strlen(test) = 3
    *4.fgets会吸收换行符
        char test[1024]
        fgets(test, 1024, stdin);
        假如用户输入了ABC然后按回车
        strlen(test) = 4
    TODO：所以我们分析一下过程。客户端首先用fgets读取用户输入。假如输入ABC然后按回车。fget可以吸收换行符并且自动添加\0, 而strlen不计入\0，所以strlen拿到的是4。
    TODO: 我们避免出现读取到垃圾的情况，写入的时候需要把获取到的strlen + 1这样它可以把fget自动加的\0也放进去。这样就不会出现问题了
    TODO：读的时候要把大小设置为一整个缓冲区的大小。因为我们不知道客户端发回来的是多大。而且读是能读到\0的
*/