#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
 
class X
{
    public:
        void do_lengthy_work(){
            std::cout <<"1:1" << std::endl;
        }
};

/*
当使用类的非静态成员函数来做为thread的启动函数的时候，注意语法。而且，第二个参数必须为类的对象/引用或指针。
下面三个都可以，具体要按照情况分析。比如当禁用了X类的拷贝构造的时候，第三种按值传递就不可以。因为是拷贝。
*/

int main(){
    X my_x;
    std::thread t(&X::do_lengthy_work, std::ref(my_x)); // 引用
    std::thread t(&X::do_lengthy_work, &my_x);          // 指针
    std::thread t(&X::do_lengthy_work, my_x);           // 值
    t.join();
    return 0;
}