#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class test1{
    public:
    int _val;
    int _sb;
    test1(int val):_val(val){};
    

    test1 addnum(int x){ //链式调用不返回引用的话只有第一个能作用到身上，剩下的是创建了临时对象不会作用到自己身上。
        this->_val = this->_val + x;
        this->_sb = 5;
        return *this;
    }
    test1& addnum2(int x){ //链式调用必须返回对象的引用。不然链式调用的时候除了第一个以外剩下的都是返回临时对象，无法作用到本身。
        this->_val = this->_val + x;
        this->_sb = 5;
        return *this;
    }

    void addnum3(int x){ //无返回值的函数无法进行链式调用。
        this->_val = this->_val + x;
        this->_sb = 5;
    }

};
int main(){
    test1 a(5);
    test1 b(5);
    test1 c(5);
    test1 d(5);
    a.addnum2(3).addnum2(7).addnum2(9); //正确链式调用
    cout << a._val << endl;

    b.addnum(3).addnum(7).addnum(9); //链式调用但是后两个结果无法作用到自己身上
    //第一个b.addnum(3)返回的是我的b的副本。是一个临时对象。我把这个临时对象再.addnum(7)是加到了临时对象身上。所以我打印b的话就不会改因为我后面的改动是针对临时对象的
    cout << b._val << endl;

    c.addnum(3); //想不返回引用而且正确使用的话就要分开调用。
    c.addnum(7);
    c.addnum(9);
    cout << c._val << endl;

    d.addnum3(3);  //无返回值的函数无法进行链式调用。因为你调用之后再.addnum3(7)这个前面没东西。是void.
    d.addnum3(7);
    d.addnum3(7);
    cout << d._val <<endl;
}