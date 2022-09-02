#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

void normal_func(){
    cout << "func" <<endl;
}

void call_back_test(int& a, int& b){
    cout << a + b << endl;
}


class test{
    public:
        int val = 5;
        void class_nonstatic_func(){
            cout << "class_nonstatic_func" <<endl;
        }
        static void class_static_func(){
            cout << "class_static_func" <<endl;
        }
        void callback(void(*ptr)(int&, int&), int& a, int& b){
            ptr(a, b);
            void(*normal_funcptr)() = &normal_func; //类内获取全局函数指针。注意全局函数必须写在这一行的前面。
            normal_funcptr(); //调用 语法糖
            (*normal_funcptr)(); //调用


            void(test::*class_nonstatic_func_ptr)() = &test::class_nonstatic_func; //类内获取类非静态成员函数指针
            (this->*class_nonstatic_func_ptr)(); //调用。调用类成员函数指针必须加*解引用。而且需要绑定对象。类内就是用this。

            void(*class_static_func_ptr)() = &test::class_static_func; //类内获取类非静态成员函数指针
            class_static_func_ptr();    //调用 语法糖
            (*class_static_func_ptr)(); //调用


        }
};


int main(){
    void (*normal_funcptr)() = &normal_func;          //普通函数指针
    void (*normal_funcptr1)() = normal_func;          //也可以不取地址。语法糖。

    normal_funcptr(); //调用方式，不解引用也可以，语法糖
    normal_funcptr1();

    (*normal_funcptr)();    //解引用，正确方式。应该这么写，更加清晰。
    (*normal_funcptr1)();

    test classobj;
    test* classobj_ptr = new test();
    void (test::*class_nonstatic_func_ptr)() = &test::class_nonstatic_func; //获取类非静态成员函数指针，必须取地址
    //获取类获取类非静态成员函数指针 必须在指针名字前面加类作用域，用来辨别。
    (classobj.*class_nonstatic_func_ptr)(); //对象调用。调用类成员函数指针必须加*解引用。而且需要绑定对象。
    (classobj_ptr->*class_nonstatic_func_ptr)(); //指针调用。调用类成员函数指针必须加*解引用。



    void(*class_static_func_ptr)() = &test::class_static_func; //获取类静态成员函数指针 ，必须取地址
    //获取类获取类静态成员函数指针 不需要指针名字前面加类作用域。因为静态成员函数可以理解为在类作用域内的全局函数。
    //所以取地址还要加作用域，函数名字不需要。
    class_static_func_ptr(); //直接调用。语法糖
    (*class_static_func_ptr)(); //直接调用。解引用

    //!(classobj.*class_static_func_ptr)();     //对象调用错误
    //!(classobj_ptr->*class_static_func_ptr)();//指针调用错误


    return 0;
}

// void callback(int(*ptr)(int, int), int a, int b){ //回调函数 如果需要返回值就return
//     ptr(a, b);
// }


// class test{
//     public:
//         static int add(int a, int b){ //需要被执行的函数。注意要static。要么就全局。
//             cout << a+b << endl;
//             return (a+b);
//         }
//         void registure(){ //注册函数
//             callback(add, 3, 5);
//         }
        
// };

// int main(){
//     test Test;
//     Test.registure();
//     return 0;
// }