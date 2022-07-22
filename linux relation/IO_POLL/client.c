#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //1. 创建套接字

    int client_FD = socket(AF_INET, SOCK_STREAM, 0);
    if(client_FD == -1){
        perror("client FD create error");
        exit(-1);
    }

    //2. 连接服务器
    struct sockaddr_in server_INFO;
    server_INFO.sin_family = AF_INET; //设置协议族
    inet_pton(AF_INET, "10.0.2.15", &server_INFO.sin_addr.s_addr); //指定客户端连接的服务端ip地址，并将点分十进制转换为网络字节序的ip整数

    server_INFO.sin_port = htons(9999); //指定客户端连接的服务端端口。并转换为网络字节序

    int ret = connect(client_FD,(struct sockaddr *) &server_INFO, sizeof(server_INFO)); //第二个参数是sockaddr类型的指针。直接取地址之后强转即可。

    if(ret == -1){
        perror("connect error");
        exit(-1);
    }


     char recv_buf[1024] = {0}; //设立数据缓冲区

    //4. 读取数据
    while(1){
        //3. 发送数据（通信）
        char senddata[1024];
        printf("请输入发送数据：\n");
        fgets(senddata, 1024, stdin);

        write(client_FD, senddata, strlen(senddata) + 1); //写入要长度+1把\0放进去 因为strlen不包括\0。
        int len = read(client_FD, recv_buf, sizeof(recv_buf)); //读取服务端发送的数据。注意这里文件描述符是接收客户端的时候建立的文件描述符，而不是监听的文件描述符
        //!这里注意不可以用strlen(recv_buf)。因为我们不知道服务器返回的是多长。所以我们一次读完一整个缓冲区。而且他读到\0就停了。
        if(len == -1){ //如果读取错误
            perror("read error");
            exit(-1);
        }
        else if(len > 0){
            printf("receive message from server: %s\n", recv_buf); //打印读取到的数据
        }
        else if(len == 0){//!这里千万不要忘！等于0就是服务端断开了连接
            printf("server disconnected...\n");
            break;
        }
        bzero(recv_buf, 1024);
        bzero(senddata, 1024);
        sleep(2);

    }
   


    //8. 关闭文件描述符
    close(client_FD); //先关闭读写文件描述符




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
    TODO：读的时候要把大小设置为一整个缓冲区的大小。因为我们不知道服务器发回来的是多大。
*/