#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

struct client_param{
    int fd; //通信文件描述符，也就是accept_FD
    struct sockaddr_in client_INFO; // 客户端信息 如端口 地址
    pthread_t tid; //线程号

};

/*
我们现在没有线程池。所以需要限制最大链接数量。可以使用一个结构体数组来储存所有的客户端信息。然后传入子线程执行参数。如果达到了上线就无法放入元素就阻止链接
*/

struct client_param clients[128]; // 限制传入子线程执行参数的客户端数组元素数量最大为128


void* working(void* arg){
    //子线程和客户端通信
    //TODO: 需要 通信文件描述符，也就是accept_FD， 客户端信息，线程号
    char client_ip[16];
    //inet_ntop(AF_INET, &(((struct client_param*)arg)->client_INFO.sin_addr.s_addr), client_ip, sizeof(client_ip)); //客户端ip端口储存在名为client_INFO的结构体里面 客户ip转换为主机字节序
    /*
    我们需要传递进来的所有信息都在void*类型的arg里面
    所以我们需要先提取arg里面的client_INFO
    *上面那一行太抽象了。我们在外面进行转型。
    */
    struct client_param* input_client_INFO = (struct client_param*)arg;
    inet_ntop(AF_INET, &input_client_INFO->client_INFO.sin_addr.s_addr, client_ip, sizeof(client_ip)); //客户端ip端口储存在名为client_INFO的结构体里面 客户ip转换为主机字节序
    unsigned short client_port = ntohs(input_client_INFO->client_INFO.sin_port); // 客户端口转换为主机字节序
    
    printf("clientIP:%s, clientPort: %d\n", client_ip, client_port);


    //7.接受客户端发送的数据。
    char recv_buf[1024] = {0}; //设立数据缓冲区
    while(1){
        int len = read(input_client_INFO->fd, &recv_buf, sizeof(recv_buf)); //读取客户端发送的数据。注意这里文件描述符是接收客户端的时候建立的文件描述符，而不是监听的文件描述符
        //!这里注意不可以用strlen(recv_buf)。因为我们不知道客户输入的是多长。所以我们一次读完一整个缓冲区。而且他读到\0就停了。
        if(len == -1){ //如果读取错误
            perror("read error");
            exit(-1);
        }
        else if(len > 0){
            printf("receive message from client: %s\n", recv_buf); //打印读取到的数据
        }
        else if(len == 0){//!这里千万不要忘！等于0就是客户端断开了连接
            printf("client disconnected...\n");
            break;
        }
        //8. 给客户端发送数据
        write(input_client_INFO->fd, recv_buf, strlen(recv_buf) + 1); //写入要长度+1把\0放进去 因为strlen不包括\0。
        bzero(recv_buf, 1024);
    }
    //9. 关闭读写文件描述符并退出子线程
    //!因为主进程一直在监听。所以这里不关闭监听文件描述符
    close(input_client_INFO->fd); //关闭读写文件描述符
    return NULL;

}



int main(){


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
    
    //todo：对数组进行初始化操作
    memset(&clients, 0, sizeof(clients)); //数组初始化为0
    int nums_in_array = sizeof(clients) / sizeof(clients[0]); //获取数组元素数量。其实就是128。
    for(int i = 0; i < nums_in_array; i++){
        //bzero(&clients[i], sizeof(clients[i]));
        clients[i].fd = -1; //对文件描述符置-1
        clients[i].tid = -1; //对子线程线程号置-1
    }


    //4. 不断循环等待客户端连接
    while(1){
        struct sockaddr_in client_INFO;
        int client_INFO_size = sizeof(client_INFO);

        //5.接收客户端链接
        int accept_FD = accept(listen_FD, (struct sockaddr *)&client_INFO, &client_INFO_size); 

        if(accept_FD == -1){
            perror("accept connection error");
            exit(-1);
        }



        //todo: 创建含有信息的参数用来传入子线程执行函数
        struct client_param * thread_needed_info; //创建指针
        //@ struct client_param  thread_needed_info; //创建实例
        for(int i = 0; i < nums_in_array; i++){
            //从数组中找到一个空的(当前不含有信息的）客户端信息的元素，然后赋值
            if(clients[i].fd == -1){
                //表明元素可用。
                thread_needed_info = &clients[i]; //如果创建的是指针，则直接把地址赋值过去。不存在拷贝。指针指过去
                //@memcpy(&thread_needed_info, &clients[i], sizeof(clients[i])); //使用memcpy进行深拷贝。注意因为参数是指针所以要传地址。
                break;
            }
            if(i == nums_in_array - 1){
                sleep(1);
                i = -1; //到127都没找到，那就把i置为-1。为什么是-1？因为过了这一行i会自增，这样会自增到i = 0
                //如果这里是i = 0, 那么client[0]这个元素只可以使用一次

            }
        }
        //todo 如果用的是指针，给找到的数组中的空元素进行赋值。
        //thread_needed_info->fd = accept_FD; //上下两种都行
        (*thread_needed_info).fd = accept_FD;
        //memcpy(&(*thread_needed_info).client_INFO, &client_INFO, client_INFO_size); //注意因为参数是指针所以要传地址。
        //*上面写的太脑残了。正常一点
        memcpy(&thread_needed_info->client_INFO, &client_INFO, client_INFO_size); //注意因为参数是指针所以要传地址。
        

        //6.创建子线程。每建立一个新连接，创建一个子进程和客户端通信。并且让子线程执行working函数 也就是和客户端通信
        int ret = pthread_create(&thread_needed_info->tid, NULL, working, (void*)thread_needed_info); //这里传参需要从对应类型强转到void*类型 //!好像转不转都行
        //@这里我们直接用create函数给传参结构体内的线程号字段赋值。因为我们只有创建线程的时候才有线程号。所以我们直接赋值。

        //7.子线程结束后释放资源
        //pthread_join会阻塞。所以不可以使用。应该使用detach
        pthread_detach(thread_needed_info->tid); //让子线程结束后自动回收资源，不需要父线程等待阻塞回收

        

    }
    //8. 关闭监听文件描述符
    close(listen_FD);

    return 0;
}