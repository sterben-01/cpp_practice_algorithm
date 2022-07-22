#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
typedef void (*func)(void); //注意这可以用typedef。
class A{
public:
    int val;
    virtual void test1(){
        cout <<"virtual A test1" << endl;
    }
    virtual void test2(){
        cout <<"virtual A test2" << endl;
    }

};
class B : public A{
public:
    virtual void test1(){
        cout << "virtual B test1" << endl;
    }
};
int main(){
    A a;
    a.val = 10;
    //void* a_ptr = &a;
    long long* a_ptr = (long long*)&a;  
     /*
     a_ptr本身是对象的地址。
    首先，void*类指针不能解引用，因为他没有类型。不知道给你多少空间内的数据
    带有虚函数的对象的头部刚好是虚函数表的位置。所以我们可以直接获取对象的地址，这个地址就是虚函数表的位置。
    意思就是这个地址存的是虚函数表的位置
    &a 获取对象a的地址
    因为指针是8位, 我要把指针装进去就要开一块8大小的空间 我们这用了longlong。
    只有指针存地址才是有意义的，所以我们用一个能存8位的指针。也就是longlong*
    注意。指针类型必须和数据类型严格匹配.指针的类型决定了指针向前或者向后走一步有多大距离。int*只能指int。
    在这里.
    所以我们要进行类型转换。
    变量的地址类型就是指针类型。变量的地址就是指针类型的数据。所以int a的数据类型是int。&a的数据类型是int*
    (long long*)把&a转换成long long指针的type
    long long* a_ptr 这个指针类型是longlong。
    */
    //这里vscode必须用longlong，double不行。8位就行。看编译器的
    func a_ptr_ptr = (func)* (long long*)(*a_ptr);
    void(*another_a_ptr_ptr)(void) = (void(*)(void))*(long long*)(*a_ptr);//花活
    //void (*func)(void) = (func)* (long long*)(*a_ptr); 这里函数指针的类型不是func, 而是(void(*)(void))
    /*
    声明一个类型为func的变量叫a_ptr_ptr
    (*)a_ptr 将a_ptr（指向虚函数表的指针）取地址得到虚函数表。
    转换为longlong*类型
    然后再解引用 func后面的那个*。目的是从虚函数表得到虚函数。
    然后为了能够调用转换成func类型。
    */
    a_ptr_ptr(); //调用这个虚函数
    another_a_ptr_ptr();
    cout  << *((int*)a_ptr + 2)  << endl; 
    /*
        这里首先内部的（int*)a_ptr的目的是把a_ptr转换成正确大小。因为我们要获取val。val变量是个int所以是4字节。
        然后我们要注意，指针+1，走的步长是对应数据类型的大小。int是4字节，所以int*+1是往前走4。
        longlong是8字节，所以longlong*+1 就是往前走8
        对象地址的前8位是一个函数指针，然后从8位开始+4就能获取到val的地址。所以可以int*+2也可以longlong*+1。注意 longlong*+1会多抓4字节
        int*有地址0-4范围内的数据，int*+1有4-8范围内的数据，int*+2有8-12范围内的数据。
        指针指向地址是数据开头的位置。指针类型是为了告诉指针你到底要取从那个地址开始，多少范围内的数据。如果没有类型，自然不知道多少范围所以无法解引用。
        所以int* a 指向地址0。int告诉指针你可以抓4字节的。所以你解引用的时候*a会抓取0-4的数据。
    */
    cout  << *((long long*)a_ptr + 1)  << endl; 

    int temp[] = {1,2,3,4,5};
    cout << temp[1] << endl;
    auto ss = (long long*)a_ptr[0]; //这里是a_ptr对象地址的头8位。存的就是虚表地址。内存其实可以当做数组来看，这也就是为啥能+1
    cout << ss << endl;
    auto sss = (long long*)ss[0]; //也可以写成(long long*)*ss 这里是虚函数表的头部也就是第一个虚函数的地址。
    cout << sss << endl; 
    long long ssss = (long long)sss; //转换函数地址格式 longlong长度
    ((void(*)(void))ssss)(); //无类型函数指针进行函数调用
}