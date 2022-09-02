#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

struct myobj{
    myobj(int x):val(x){}
    int val;
};

void deleter(myobj* ptr){
    cout <<"deleter called" << endl;
    delete ptr;        //需要在这里删掉new出来的内容 如果不写的话会内存泄漏。因为智能指针不再执行自己的释放资源的函数。改为执行这个函数。但是这个函数里面如果没有释放资源就会内存泄漏。
    ptr = nullptr;
}

template<typename T>
class mydeleter{
    public:
        void operator()(T* ptr) const{
            cout <<"deleter called" << endl;
            delete ptr;        //需要在这里删掉new出来的内容 如果不写的话会内存泄漏。因为智能指针不再执行自己的释放资源的函数。改为执行这个函数。但是这个函数里面如果没有释放资源就会内存泄漏。
            ptr = nullptr;
        }


};


int main(){
    // unique_ptr<myobj> ptr1;                                         //空指针
    // //unique_ptr<myobj> ptr2 = new myobj(5);                        //错误。智能指针构造函数是explicit的。禁止隐式转换，所以不允许拷贝初始化。但是可以用直接初始化
    // unique_ptr<myobj> ptr3(new myobj(5));                           //ok
    // unique_ptr<myobj, void(*)(myobj*)> ptr4(new myobj(5), deleter); //自定义删除器。注意需要在自定义删除器内部进行资源释放，因为使用自定义删除器后，智能指针不会接管释放资源

    // unique_ptr<myobj, mydeleter<myobj>> ptr4_1(new myobj(5));       //自定义删除器。注意需要在自定义删除器内部进行资源释放，因为使用自定义删除器后，智能指针不会接管释放资源
    // //所以写自定义删除器的意义是如果你想在某一个资源的析构函数或者是释放资源的同时执行其他动作，就需要写这个。因为，资源的释放阶段是全部交给智能指针接管的。
    // //unique_ptr<myobj> ptr5 = make_unique<myobj>(new myobj(5));    //错误使用make方法。make_unique是把传入参数完美转发至对象构造函数。只需要传递参数即可，无需再次new。
    // unique_ptr<myobj> ptr5 = make_unique<myobj>(5);                 //使用make方法。make方法无法使用自定义删除器和大括号初始化（列表初始化）
    // //unique_ptr<myobj> ptr5(ptr3);                                   //禁止拷贝。因为只能有一个unique_ptr指向一个资源。所有权语义。
    // cout << sizeof(ptr4_1) << endl;
    // cout << ptr5.get()->val << endl;
    shared_ptr<myobj> ptr1(new myobj(5));       //创建共享指针     
    shared_ptr<myobj> ppp(make_shared<myobj>(5));
    // shared_ptr<myobj> ptr2(ptr1);               //通过共享指针直接初始化共享指针。两个指针指向同一个数据，所以不新建控制块。引用计数+1
    // shared_ptr<myobj> ptr3 = ptr1;              //可以通过赋值方法拷贝初始化共享指针。两个指针指向同一个数据，所以不新建控制块。引用计数+1
    // cout << ptr1.use_count() << endl;           //使用use_count查看引用计数。输出3
    // cout << ptr2.use_count() << endl;           //输出3
    // cout << ptr3.use_count() << endl;           //输出3



    // shared_ptr<myobj> ptr4 = make_shared<myobj>(5);     //使用make方法创建
    // ptr4 = ptr3;                                        //拷贝赋值。此时ptr4的控制块引用计数为0。因为被3覆盖了。所以ptr4指向的原始资源析构。ptr4此时和ptr3指向同一资源
    // cout << ptr4.use_count()<<endl;                     //共享控制块，此时为4。

    // //shared_ptr<myobj> ptr5 = new myobj(4);            //不可以。禁止隐式转换。智能指针构造函数是explicit的
    // shared_ptr<myobj> ptr6(new myobj(4), deleter);      //自定义删除器。无需指定类型名。
    // weak_ptr<myobj> weak(ptr4);
    // cout << weak.use_count() << endl;
    shared_ptr<myobj> ptr2(ptr1);   
    weak_ptr<myobj> ptr3(ptr1);                 //可以 直接初始化
    cout << ptr2.use_count() << endl;
    cout << ptr3.use_count() << endl;

}       