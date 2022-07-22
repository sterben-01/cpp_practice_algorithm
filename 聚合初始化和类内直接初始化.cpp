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
using namespace std;


class test{
    int test_val1;
    int test_val2;
    public:
    test(int x, int y):test_val1(x), test_val2(y){};
    struct obj{
        int _objval;
        int _faf;
        obj(){}
        obj(int x): _objval(x){}
    };
    obj inclass_obj1; //obj对象使用无参构造函数
    obj inclass_obj2(); //这是返回obj类型的函数
    obj inclass_obj3(5); //这里表面是使用了obj的有参构造，但是不允许这种行为。因为有二义性。编译器认为这是个返回obj类型的形参为5的函数。但是形参为5是啥玩意？所以一个类内不允许使用圆括号初始化另一个类。
    //也就是不允许使用直接初始化
    //举个例子：
    int a = 5; //拷贝初始化 OK
    int b(5); //直接初始化。ERROR。
    //替代方案：
    obj inclass_obj4 = {test_val1}; // 列表初始化 OK //* 注意这里使用了类的有参构造函数。没有使用拷贝构造  //!注意这不是聚合初始化。聚合初始化不能有用户定义的构造函数
    obj inclass_obj5{test_val2}; //列表初始化 OK //* 注意这里使用了类的有参构造函数。没有使用拷贝构造 //!注意这不是聚合初始化。聚合初始化不能有用户定义的构造函数
    obj inclass_obj6 = 5; //该处的初始化方式是隐式调用obj(int)构造函数生成一个临时的匿名对象，再调用拷贝构造函数完成初始化。
    obj inclass_obj7 = obj(5); //显式调用有参构造函数生成一个临时的匿名对象，再调用拷贝构造函数完成初始化 OK

};


class test1{
    public:
    struct obj{
        int _objval;
    };
    int _val;
    obj inclass_obj;
    test1(int x, int y): _val(x), inclass_obj._objval(y){} // 错误。这是构造函数初始化列表。用来初始化的。这里的inclass_obj._objval(y)是赋值操作。不允许。
    test1(int x, int y): _val(x), inclass_obj(y){} // 错误 obj类没有有参构造函数。
    test1(int x, int y): _val(x), inclass_obj(){} // 可以 obj类有默认无参构造函数。
    test1(int x, int y): _val(x), inclass_obj{y}{} // 可以 这里的inclass_obj{y}叫做聚合初始化(aggregate initialization)。没有构造函数也可以初始化其中的参数。但是有如下限制
    /*
    1.  数组类型
    2.  满足下列条件的类类型（通常是结构体（struct）或者联合体（union））：
        没有私有或保护的非静态数据成员
        没有用户提供的构造函数
        没有基类
        没有虚函数
    */
};







// template<typename T>
// void func(){
//     test t(5,8);
//     typename T::obj* ptr = &t.s;
//     cout << ptr->_sb << endl;
// } 

int main(){
    //A a;
    //cout << a.b->_bval << endl;
    test t(5,10);
    cout << t.inclass_obj6._objval << endl;
    //func<test>();
    //cout << t.inclassobj._objval << endl;
    return 0;

}