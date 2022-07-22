#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){

    //1. 创建socket -- 用于监听的套接字。

    int listen_FD = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_FD == -1){
        perror("listen FD create error");
        exit(-1);
    }

    //2. bind 将监听的文件描述符和一个ip地址、端口进行绑定
    struct sockaddr_in sock_address;
    sock_address.sin_family = AF_INET; //设置协议族

    //inet_pton(AF_INET, "127.0.0.1", sock_address.sin_addr.s_addr); //点分十进制转换为网络字节序的ip整数
    //上面这一行是之前地址转换函数的融合。第二个位置可以用char[] 也可以直接写一个字符串。第三个可以写一个unsigned char去接也可以直接赋值给sock_address的ip
    sock_address.sin_addr.s_addr = INADDR_ANY; //指定ip地址 0.0.0.0 指的是任意地址。仅服务端可以这样使用。
    sock_address.sin_port = htons(9999); //指定服务器端口并转换为网络字节序 

    int ret = bind(listen_FD,(struct sockaddr *)&sock_address, sizeof(sock_address)); //第二个参数是sockaddr类型的指针。直接取地址之后强转即可。

    if(ret == -1){
        perror("bind error");
        exit(-1);
    }


    //3. 监听
    ret = listen(listen_FD, 8);
    if(ret == -1){
        perror("listen error");
        exit(-1);
    }


    //4. 接收客户端链接
    struct sockaddr_in client_INFO;
    int client_INFO_size = sizeof(client_INFO);
    int accept_FD = accept(listen_FD, (struct sockaddr *)&client_INFO, &client_INFO_size);

    if(accept_FD == -1){
        perror("accept connection error");
        exit(-1);
    }
    //5. 将接收到的客户端信息转换为主机字节序

    char client_ip[16];
    inet_ntop(AF_INET, &client_INFO.sin_addr.s_addr, client_ip, sizeof(client_ip)); //客户端ip端口储存在名为client_INFO的结构体里面 客户ip转换为主机字节序

    unsigned short client_port = ntohs(client_INFO.sin_port); // 客户端口转换为主机字节序
    
    printf("clientIP:%s, clientPort: %d\n", client_ip, client_port);

    //6.接受客户端发送的数据。
    char recv_buf[1024] = {0}; //设立数据缓冲区
    int len = read(accept_FD, recv_buf, sizeof(recv_buf)); //读取客户端发送的数据。注意这里文件描述符是接收客户端的时候建立的文件描述符，而不是监听的文件描述符
    if(len == -1){ //如果读取错误
        perror("read error");
        exit(-1);
    }
    else if(len > 0){
        printf("receive message from client: %s\n", recv_buf); //打印读取到的数据
    }
    else if(len == 0){//!这里千万不要忘！等于0就是客户端断开了连接
        printf("client disconnected...");
    }

    //7. 给客户端发送数据
    char * data = "hello, i'm server";
    write(accept_FD,data, strlen(data));

    //8. 关闭文件描述符
    close(accept_FD); //先关闭读写文件描述符
    close(listen_FD); //再关闭监听文件描述符


    return 0;
}