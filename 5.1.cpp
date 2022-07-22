#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
class A{
    public:
    void test1(){
        cout <<"Atest1" << endl;
    }
    virtual void test2(){
        cout <<"Atest2" << endl;
    }
};

class B : public A{
    public:
    void test1(){
        cout <<"Btest1" << endl;
    }
    virtual void test2(){
        cout <<"Btest2" << endl;
    }
};
int main(){
    A* a = new A(); //父类指针调用父类函数
    a->test1();//子类虚函数
    a->test2();//父类虚函数
    B* b = new B(); //子类指针调用子类函数
    b->test1(); //子类普通函数
    b->test2(); //子类虚函数
    A* ab = new B(); //父类指针指向子类 
    ab->test1(); //父类的普通函数
    ab->test2(); //子类的虚函数
    B objb;
    A* aptr = &objb;
    aptr->test1();
    aptr->test2();
    vector<int> ff = {1,2,3,43,54};
    cout << 4%1;
}