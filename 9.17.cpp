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
#include <future>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;


class base{
    public:
    void func1(){
        cout << "base1" << endl;
    }
    virtual void func2(){
        cout << "base2" << endl;
    }
};

class derive:public base{
    public:
    void func1(){
        cout << "derived1" << endl;
    }
    void func2(){
        cout << "derived2" << endl;
    }
};

void func(base& b){
    b.func1();
    b.func2();
}

int main(){
    int a[] = { 1,2,3,4,5,6 };
    cout << a[1] << endl;
    cout << *(a+1) << endl;
    cout << 1[a] << endl;
    cout << (1)[a] << endl;
    return 0;
}