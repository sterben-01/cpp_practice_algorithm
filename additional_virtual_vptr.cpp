/*
通过内存，把虚函数拿出来看看
*/

#include <iostream>

using namespace std;
typedef void(*Fun)(void);

class Foo {
public:
    virtual void show() { cout << "hello world" << endl; }
    // virtual int add(int a, int b) { cout << a + b << endl; } 
    int x;
};  

void test() {
    Foo foo;
    foo.x = 10;
    void* p = &foo; // 指针和取地址可以说是进入内存世界的大门
    int* p = (int*)&foo;
    // 可以把虚函数表看成一个存放虚函数的数组，所以我们可以像数组一样把里面的虚函数拿出来用

    

    cout << "Foo::x = " << *((int*)p + 2)  << endl;  //这个是p是void*的情况  
    // cout << *(p + 2) << endl;  这个是p作为int* 被初始化的情况 
}


int main() {
    printf("sizeof(void*)%d, sizeof(double*)%d\n", sizeof(void*), sizeof(double*));
    test();
}