#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int pipefd[2]; // 创建管道数组
    int ret = pipe(pipefd); //创建管道

    if(ret == -1){ //如果管道创建失败
        perror("pipe error");
        exit(0);
    }

       //必须要在fork之前创建管道。因为fork才能将文件描述符复制给子进程，这样才可以通信
    pid_t pid = fork(); //创建子进程

    char buf[1024] = {0}; //! 缓冲区不能写在这。写在这的话进程共用一个而且不清除的话第二轮父进程读的时候因为里面有数据所以不会被阻塞

    if(pid > 0){ //fork返回的pid是子进程id。也就是在父进程中，这个数字一定是大于0的
        //父进程
        //char buf[1024] = {0};
        //从管道的读取端读取
        while(1){

            //父进程循环读取数据。不用sleep因为默认是阻塞
            int len = read(pipefd[0], buf, sizeof(buf)); //! read函数默认是阻塞的。如果子进程没有写入到管道的话，父进程会一直等待子进程把数据写入管道。
            printf("father receive :%d , pid: %d, father pid: %d\n", len, pid, getpid());
            //printf(buf); 不要这样写。要按照下面去写。不要直接读变量，要按照字符串读写
            printf("%s\n", buf);
            bzero(buf, 1024); //如果缓冲区写在外面就必须要清零缓冲区

            //写入
            //!注意这里父进程和子进程读写顺序要相反。不然会一起读或者一起写。

            char* msg = "hello world i'm father";
            len = write(pipefd[1], msg, strlen(msg));
            printf("father send :%d , pid: %d\n", len, getpid());
            sleep(1);//sleep不然太快了
            bzero(buf, 1024); //如果缓冲区写在外面就必须要清零缓冲区

        }
    }
    else if(pid == 0){ //如果pid是0，代表现在切换进了子进程。
        //子进程
        //管道写入端写入
        //子进程循环写入
        //char buf[1024] = {0};
        while(1){
            //写入
            char* msg = "hello world i'm child";
            int len = write(pipefd[1], msg, strlen(msg));
            printf("child send :%d , pid: %d\n", len, getpid());
            sleep(1);//sleep不然太快了
            bzero(buf, 1024); //如果缓冲区写在外面就必须要清零缓冲区
            //读取
            len = read(pipefd[0], buf, sizeof(buf)); //! read函数默认是阻塞的。如果子进程没有写入到管道的话，父进程会一直等待子进程把数据写入管道。
            printf("child receive :%d , pid: %d, child pid: %d\n", len, pid, getpid());
            //printf(buf); 不要这样写。要按照下面去写。不要直接读变量，要按照字符串读写
            printf("%s\n", buf);
            bzero(buf, 1024); //如果缓冲区写在外面就必须要清零缓冲区
        }
    }

    return 0;
}