#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class A{
    public:
    A(){}
    virtual void p(){
        cout <<"A" << endl;
    }

};

class B: public A{
    public:
    B(){}
    int bval = 3;
    // void p(){
    //     cout <<"b" << endl;
    // }
};

class C :public B{
    public:
    C(){}
    int cval = 4;
    // void p(){
    //     cout << "c" << endl;
    // }
};

int main(){
    A* a = new C;
    C* c = new C;
    C* s = static_cast<C*>(new A);

    C* ss = (C*)new A;
    // a->p();
    // vector<int> test = {1,2,3,4,5,6,7,8,9,10};
    // cout << sizeof(test) << endl;
    // vector<int> test1(test.size());
    // memcpy(&test1[0], &test[0], sizeof(int) * test.size());
    // for (auto t : test1) {
    //     cout << t << endl;
    // }
    // cout << test.size() << endl;
    a->p();
    cout << typeid(*a).name() << endl;
    cout << typeid(*s).name() << endl;
}