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

template<typename T>            // (1) - 主模板
string getTypeName(T){
    return "unknown";
}

template<typename T>            // (2) - 重载自 (1) 的主模板。 针对指针类型的模板重载
string getTypeName(T*){
    return "pointer";
}

//template<>                      // (3) - (2) 的显式全特化。针对int指针类型的显式全特化
string getTypeName(int*){
    return "int pointer";
}

// getTypeName2

template<typename T>            // (4) - 主模板
string getTypeName2(T){
    return "unknown";
}

//template<>                      // (5) - (4) 的显式全特化。 针对int指针类型的显式全特化
string getTypeName2(int*){
    return "int pointer";
}
template<typename T>            // (6) - 重载自 (4) 的主模板。 针对指针类型的模板重载
string getTypeName2(T*){
    return "pointer";
}


template<typename T>            // (7) - 主模板
string getTypeName3(T){
    return "unknown";
}

template<>                      // (8) - (7) 的显式全特化。 针对int指针类型的显式全特化
string getTypeName3(int*){
    return "int pointer";
}
template<typename T>            // (8) - 重载自 (7) 的主模板。 针对指针类型的模板重载
string getTypeName3(T*){
    return "pointer";
}
template<>                      // (10) - (9) 的显式全特化。 针对int指针类型的显式全特化
string getTypeName3(int*){
    return "another int pointer";
}

template <typename T>
void func(T a){ //主模板
    cout <<"main" << endl;
}
template <typename T>
void func(T* a){ //重载模板
    cout << "overload" << endl;
}


template<typename T>
class myobj{
    public:
        static const int val = 1000;
};

int out_val = myobj<int>::val;



template <typename T>
int out_val_T = myobj<T>::val;


int out_val1 = out_val_T<int>;

int main(){
    cout << out_val << endl;
    cout << out_val1 << endl;
    return 0;
}