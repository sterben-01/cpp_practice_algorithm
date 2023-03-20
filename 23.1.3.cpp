#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
#include <list>
#include <atomic>
using namespace std;


template <typename T>
void f(T param) {
    std::puts(__PRETTY_FUNCTION__);
}
// template<typename T, typename = enable_if_t<!is_const<T>::value>>
// void func (T& arg) { 
//     cout << "called" << endl;
//}

void changeval(int& a){
    a = 20000;
}

template <typename T>
void func(T a){
    std::puts(__PRETTY_FUNCTION__);
    changeval(a);
}

template <typename T>
void another_func(T a){
    std::puts(__PRETTY_FUNCTION__);
}


// template <typename T>
// void func2(T&& a){
//     cout <<"R ref" << endl;
// }

void this_func(){
    cout <<"called" << endl;
}

int main() {
    int a = 1;
    // func(a);
    // cout << a << endl;
    func(ref(a));
    // cout << a << endl;
    // auto func_ptr = this_func;
    // auto ref3 = ref(func_ptr);
    // ref3();
    //another_func(ref(a));
}
