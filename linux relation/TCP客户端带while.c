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
        char* data = "hello, I'm client";
        write(client_FD, data, strlen(data));
        int len = read(client_FD, recv_buf, sizeof(recv_buf)); //读取客户端发送的数据。注意这里文件描述符是接收客户端的时候建立的文件描述符，而不是监听的文件描述符
        if(len == -1){ //如果读取错误
            perror("read error");
            exit(-1);
        }
        else if(len > 0){
            printf("receive message from server: %s\n", recv_buf); //打印读取到的数据
        }
        else if(len == 0){//!这里千万不要忘！等于0就是服务端断开了连接
            printf("server disconnected...");
            break;
        }
        bzero(recv_buf, 1024);
        sleep(2);

    }
   


    //8. 关闭文件描述符
    close(client_FD); //先关闭读写文件描述符




    return 0;
}