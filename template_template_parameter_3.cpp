#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

template<typename T>
class thing{
    public:
        T _val;
        thing(int x):_val(x){};
        //thing<T>; //thing也得是个模板类
};


template<template<typename> class thing, typename T1, typename T2> // 最基本的举例
class test{
    public:
        thing<T1> a1;
        thing<T2> a2;
};

//                                       ↓contain类的默认方法的类型。因为没用到可以忽略  ↓ container类的默认方法。可以不写
//template <typename T, template <typename U, typename Alloc = allocator<U>> class Container = deque>  这样做会让stack模板强制要求容器模板支持第二个参数
//         ↑这个T意思是储存T类型数据                    ↑contain类的默认方法的类型的分配器。因为没用到可以忽略     
//template <typename T, template <typename ...> class Container>   //使用可变参数模板简化后的方式
//template <typename T, template <typename, typename> class Container> //不能这么写，下面container<T>会少一个参数，但是你上面必须写俩必须写分配.



// template <typename T>
// using vec = vector<T,allocator<T>>; //要不然用别名模板也算是显式指定容器元素类型和分配器。
// template <typename T, template <typename> class Container>

template <typename T, template <typename U, typename Alloc = allocator<U>> class Container = deque>  //这样做会让stack模板强制要求容器模板支持第二个参数
class Stack {
    public:
        Container<T> elems; // container<T>会默认调用对应的容器的默认分配器
};
int main(){
    
    Stack<int,vector> sss; //一个stack，实现基于vector类，储存int类型数据

}
//这东西的目的是指定储存容器类型的时候不指定元素类型
