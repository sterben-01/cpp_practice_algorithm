#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){

    //1. 创建共享内存
    int shmid = shmget(100, 4096, IPC_CREAT | 0664); //这里第一个参数是一个key，也就是这块共享内存的名字。进程间使用共享内存就靠这个名字建立联系。

    //2. 和当前进程进行关联。我们无法直接操作共享内存，必须将shmget函数返回的值输入至shmat函数后得到对应共享内存的首地址指针。

    void* ptr = shmat(shmid, NULL, 0);

    //3. 写入数据

    char *  str = "hello, world";

    memcpy(ptr, str, strlen(str) + 1); //不要忘了+1把字符串终止符拷贝进来。strlen计算的是有效长度所以不包括\0

    printf("按任意键继续");
    getchar(); //这样做目的是让程序在这里暂停，这样可以看见这个程序的效果。不然直接就结束了。

    //4. 解除关联
    shmdt(ptr);

    // 5.删除共享内存
    shmctl(shmid, IPC_RMID, NULL);





    return 0;
}