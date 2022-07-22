#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

template<typename T1, typename T2>
class test{
public:
    T1 _a;
    T2 _b;

    test(T1 a, T2 b) : _a(a), _b(b) {}

    void showitem(){
        cout << this->_a << "," << this->_b << endl;
    }


};

template<typename T1, typename T2, typename T3, typename T4>
class test1 : public test<T1, T2>{ //!继承模板父类，子类父类都要是模板类。而且要显式指定父类模板类型。
public:
    // T1 _a;   //!如果子类也有自己的_a 和_b变量的话 那就不能调用父类构造函数赋值。
                //!想一下，子类自己的东西怎么可能让父类构造函数赋值？
                //@所以调用父类构造函数赋值其实相当于给子类的父类成分赋值。
    // T2 _b;
    T3 _c;
    T4 _d;
    //test1(T3 a, T4 b) : _a(a), _b(b) {}
    test1(T1 a, T2 b, T3 c, T4 d) : test<T1, T2>(a,b),_c(c),_d(d) //调用父类构造函数赋值 //!记得调用模板类父类构造函数的时候要显式指定数据类型
    {
        //!可以用构造列表也可以普通构造函数
        // _c = c; 
        // _d = d;
    }
    void showitem(){
        cout << this->_a << "," << this->_b << "," << this->_c << "," << this->_d<< endl;
    }

};



int main(){
    test<int,int>* b = new test<int, int>(5,5);
    b->showitem();
    test1<int, int, char, char>* c = new test1<int, int, char, char>(1,2,'a','b');
    c->showitem();
    
    //指针和对象都可以
    test<int,int> bb(5,5);
    bb.showitem();
    test1<int, int, char, char> cc (1,2,'a','b');
    cc.showitem();
}