#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <memory>
#include <functional>
#include <atomic>
#include <assert.h>
#include <type_traits> 
#include <thread>
using namespace std;

template<typename... Types>
struct my_tuple{}; //主模板。和typelist一样。


template<typename First, typename... Others>
struct my_tuple<First, Others...>{
    First first; //头元素
    my_tuple<Others...> others; //其他的元素组成的my_tuple

    my_tuple(){
        cout <<"const" << endl; //默认构造
    };
    my_tuple(const First& head, const my_tuple<Others...>& tail):first(head), others(tail){
        cout <<"tuple const called" << endl;
        //这个构造的意义是使用一个元素和另一个tuple进行构造。
    };  

    my_tuple(const First& head, const Others&... tail):first(head), others(tail...){
        cout << first << endl;
        cout << "size of rest elements: "<< sizeof...(tail) << endl;
        std::puts(__PRETTY_FUNCTION__);
        cout <<"element const called" << endl;
        //这个构造才是我们直观的，使用一堆独立的元素构造
    };


    First& getHead(){
        cout <<"getHead called" << endl;
        return first;
    }

    const First& getHead() const{
        cout <<"getHead called" << endl;
        return first;
    }

    my_tuple<Others...>& getTail(){
        cout <<"getTail called" << endl;
        return others;
    }

    const my_tuple<Others...>& getTail() const{
        cout <<"getTail called" << endl;
        return others;
    }
    ~my_tuple(){
        cout <<"dest" << endl;
    }
};


template<> //这个特化是针对空参数。也就是最后剩余参数为0的情况
struct my_tuple<>{

};



template <unsigned int m_index>
struct find_element{
    template<typename First, typename... Others>
    static auto m_get(const my_tuple<First, Others...>& t){
        cout <<"current index: " << m_index << endl;
        return find_element<m_index-1>::m_get(t.getTail());
        //这里的类模板是get<N>的N我们要显式指定
        //这里的函数模板是通过my_tuple进行推导。可变参数被拆分了。
        //随后递归调用，m_index每次-1然后调用getTail，也就是去掉每一次的头部。
    }
};

template<> //find_element的特化。也就是此时index减到为0了。我们找到了想找的元素
struct find_element<0>{
    //下面是两个版本而已。
    template<typename First, typename... Others>
    static const First& m_get(const my_tuple<First, Others...>& t){
        cout <<"m_get called" << endl;
        return t.getHead();
        //由于此时头部元素就是我们想要找的，所以直接调用getHead
    }
    template<typename First, typename... Others>
    static First& m_get(my_tuple<First, Others...>& t){
        cout <<"m_get called" << endl;
        return t.getHead();
    }
};

//----------const和非const的get。注意get不是成员函数。标准库也是这样设计的。
template<unsigned int m_index, typename... Types>
auto get(const my_tuple<Types...>& t ){
    return find_element<m_index>::m_get(t);
}
template<unsigned int m_index, typename... Types>
auto get(my_tuple<Types...>& t ){
    return find_element<m_index>::m_get(t);
}
int main(){
    my_tuple<int, char, double, float> testtuple(10, 'a', 2.3, 3.4);
    cout<<"--------------------------------------" << endl;
    cout << get<2>(testtuple) << endl;
}
/*
我们发现，构造过程中和CRTP一样，是递归调用。
我们通过函数签名发现，每次在构造函数中初始化本类的others的时候，都会进入下一层的递归。
所以在最后一层Others参数包为空的时候，first就是tuple的最后一个元素。
所以第一个打印出来的是3.4 最后一个元素。参数包size为0。
然后逐层弹出。

所以我们发现，一共有四个my_tuple对象被构造了。因为我们的others成员变量本身就是一个my_tuple对象。
所以 10, 'a', 2.3, 3.4 相当于
my_tuple(10, mytuple('a', mytuple(2.3, mytuple(3.4, 空))))



然后看一下get。
这个get和typelist的get如出一辙。都是通过index逐次-1然后去掉头部元素（这里是通过gettail保留尾部）实现的
我们从打印中能看出来。index每次减掉1，然后getTail被调用。
当index为0的时候匹配至特化，这时候调用getHead。

*/