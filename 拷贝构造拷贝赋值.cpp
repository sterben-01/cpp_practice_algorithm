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

class A {
    public:
        A(){}
        A(int a) :m_a(a) {}
        virtual~A(){}
        A& operator=(const A& rhs) {
            m_a = rhs.m_a;
            return *this;
        }
	int m_a;
};

class B : public A{
    public:
        B(){}
        B(int x):m_b(x){}
        B(int no, int x):A(no),m_b(x){} //这里用到了子类调用父类构造
        ~B(){}
        
        B& operator=(const B& rhs) {
            A::operator=(rhs); //这里是函数调用。
            /*
            我们函数调用可以不接受返回值。operator=的返回值的目的是返回一个自己用来进行下一步操作。是为了满足链式调用。当然也可以啥也不返回。
            &所以隔壁的拷贝构造就没返回值。
            但是我们子类调用父类的拷贝赋值仅仅是把子类的父类部分调用父类的拷贝赋值来进行一个赋值。
            这里的例子就是子类的父类部分m_a使用父类的拷贝赋值给copy一遍。
            然后我们直接调用完了父类的拷贝赋值后，再自己赋值子类部分。
            text 时刻谨记 b1 = b2 就是b1.operator=(b2);
            */
            m_b = rhs.m_b;
            return *this;

        }
        int m_b;
};

int main(){
    B b(5,8);
    cout << b.m_a << endl;
    
    return 0;
}