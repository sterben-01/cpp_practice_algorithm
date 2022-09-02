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

class myfunc{
    public:
    bool operator()(const int&a, const int& b) const{
        return a<=b;
    }
};

class A{
    public:
    int val = 0;
    A(){}
    A(int x):val(x){}
    A(A&& rhs){
        this->val = rhs.val;
        cout <<"move" << endl;
        rhs.val = 0;
    }
    A& operator=(A&& rhs){
        if(this != &rhs){
            this->val = rhs.val;
            cout <<"move equal" << endl;
            rhs.val = 0; 
        }
    }
};


// template<typename T>
// int add(const T&& x, const T&& y){
//     return x + y;
// }

// int main(){  
//     A* a = new A(5);
//     A* b = new A(0);
//     *b = move(*a);
//     //A* b = new A(move(*a));
//     cout << &*a << endl;
//     cout << &*b <<endl;
//     cout << a->val << endl;
//     cout << b->val << endl;


template<typename T>
void func(T& param) {
    cout << "传入的是左值" << endl;
}
template<typename T>
void func(T&& param) {
    cout << "传入的是右值" << endl;
}
// template<typename T>
// void warp(T&& param) {
//     func(param);
// }
template<typename T>
void warp(T&& param) {
    func(std::forward<T>(param));
}
int main() {
    int num = 2019;
    //warp(num);
    warp<int>(2019);
    return 0;
}