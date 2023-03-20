#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
#include <list>
#include <atomic>
using namespace std;

// template<typename T1, typename T2>
// class MyClass {
//     public:
//     //主模板
//     MyClass(T1 a, T2 b):val1(a), val2(b){
//         cout <<"diff type" << endl;
//     }
//     T1 val1;
//     T2 val2;
// };

// template<typename T>
// class MyClass<T,T> {
//     public:
//     MyClass(T a, T b):val1(a), val2(b){
//         cout << "same type" << endl;
//     }
//     T val1;
//     T val2;
// };
// template<typename T1, typename... TN>
// constexpr bool isSameType (T1&, TN&...)
// {
//     return (std::is_same<T1,TN>::value && ...); // since C++17
// }






// template<typename T> //要有单参打印的重载。不然会无限调用。
// void print(T t){
//     cout << t << endl;
// }


// template<typename... Args>
// void print(Args... args){
//     (print(args), ...); //这里外部一定要加括号。注意语法。这里的,是逗号运算符。
// }


// // template<typename... T>
// // void printDoubled (T const&... args)
// // {
// //     print((args + 1)...); //要么这么写。多加个括号。
// // }  

// template<typename Container, typename Index>
// void getItem(Container& container, Index idx){
//     cout << container[idx] << endl;
// }
// template<int... Idx, typename Container>
// void getMultipleItem(Container& container){
//     print(container[Idx]...);
// }


// template<typename ...Ts>
// struct S;

// template<typename T, typename... Ts>
// struct S<T, Ts...> final{
//     void func(){
//         cout << "1" << endl;
//     }
// };

// template<typename... Ts>
// struct S<int, Ts...> final{
//     void func(){
//         cout << "2" << endl;
//     }
// };

// template<template<typename...> typename T, typename... Ts>
// struct S<T<Ts...>> final{
//     void func(){
//         cout << "3" << endl;
//     }
// };

template<typename T, int N, int M>
bool func (T(&a)[N], T(&b)[M]){
    cout << N << endl;
    cout << M << endl;
    for (int i = 0; i<N && i<M; ++i){
        if (a[i]<b[i]){
            return true; 
        }
        if (b[i]<a[i]){
            return false;
        }
    }
    return N < M;
}

class getInt{
    public:
        float val;
        getInt(float a): val(a){};

        template<typename T = int>
        T get() const{
            return val;
        }
};

template<>
inline string getInt::get<string>() const{
    return to_string(val);
}

template<typename T>
T f(T a, T b = 42)
{   
    cout <<"general" << endl;
    cout << b << endl;
    return b;
}
template<>
double f(double a, double b)
{
    cout <<"special" << endl;
    cout << b << endl;
    return b;
}


void test(int a, int b){
    cout << "普通函数" << endl;
}

template <typename T>
void test(T a, T b){
    cout << "模板函数" << endl;
}

template <typename T>
void test(T a, T b, T c){
    cout << "重载的模板函数" << endl;
}
template<>
void test<int>(int a, int b, int c){
//void test(int a, int b, int c){ //可以去掉 <int>
    cout <<"全特化" << endl;
}
// int main(){
//     test(1,2); //输出普通函数
//     test<>(1,2); //使用空模板参数列表 输出模板函数
//     test(1.1,2.2,3.3); //输出重载的模板函数
//     test(1,2,3); //输出全特化
//     test<int>(1,2,3); //输出全特化
//     return 0;
    
// }
int main(){
    //printDoubled(1, 2.3); //输出 2 4.6
    // vector<string> my_vec{"abc", "def", "ghi", "123", "456"};
    // getMultipleItem<1,2,3,4>(my_vec);
    // int x[] = {1,2,3};
    // int y[] = {1,2,3,4,5,6,7};
    // func(x,y);
    // func("abc", "abcde");

    // getInt myobj(12.345);
    // auto t = myobj.get();
    // cout << t << endl;
    // auto t1 = myobj.get<string>();
    // cout << t1 << endl;
    f(4);
    f(4.444);
    // test(1,2); //输出普通函数
    // test<>(1,2); //使用空模板参数列表 输出模板函数
    // test(1,2,3); //输出重载的模板函数
    // test(1.1,2.2,3.3); //输出全特化

    return 0;
    
}