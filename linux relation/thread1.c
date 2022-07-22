/*
    一般情况下,main函数所在的线程我们称之为主线程（main线程），其余创建的线程
    称之为子线程。
    程序中默认只有一个进程，fork()函数调用，2进行
    程序中默认只有一个线程，pthread_create()函数调用，2个线程。

    #include <pthread.h>
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
    void *(*start_routine) (void *), void *arg);

        - 功能：创建一个子线程
        - 参数：
            - thread：传出参数，线程创建成功后，子线程的线程ID被写到该变量中。
            - attr : 设置线程的属性，一般使用默认值，NULL
            - start_routine : 函数指针，这个函数是子线程需要处理的逻辑代码
            - arg : 给第三个参数使用，传参
        - 返回值：
            成功：0
            失败：返回错误号。这个错误号和之前errno不太一样。
            获取错误号的信息：  char * strerror(int errnum);

*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>



int* createsomeshit(int* a){ //c无引用，唯指针尔。所以传入为指针
    *a = *a + 5; //解引用相加
    return a; //传出还是指针
}








void * callback(void * arg) {
    printf("child thread...\n");
    printf("arg value: %d\n", *(int *)arg);//传参需要从void*强转到对应类型
    createsomeshit((int*) arg);//传参需要从void*强转到对应类型
    printf("arg value: %d\n", *(int *)arg); //传参需要从void*强转到对应类型
    return (void*)arg;
    //return NULL; 这句话等于pthread_exit(NULL);
}

int main() {

    pthread_t thread1;

    void* result_ptr;

    int num = 10;

    // 创建一个子线程
    int ret = pthread_create(&thread1, NULL, callback, (void *)&num); //这里传参需要从对应类型强转到void*类型

    if(ret != 0) {
        char * errstr = strerror(ret);
        printf("error : %s\n", errstr);
    } 

    for(int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }

    pthread_join(thread1, (void**)&result_ptr); //使用pthread_join回收子线程资源，并且获取子线程的返回值。
    //!该函数是阻塞的。
    //!函数的第二个形参是二级指针，所以传入一个一级指针然后取地址即可。或者加一个(void**)强转一下。

    printf("%d\n", *(int*)result_ptr); //先把指针转换成int*。然后再次解引用。


    pthread_exit(NULL); //主 **线程** 退出不会影响正常运行的其他线程。下面的代码不会执行。比如return0。所以**进程**不会退出！
    

    return 0;   // exit(0);
}