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

template<int stat> //这里是非模板类型参数。上面提到了。注意一下
typename enable_if<stat == 1, bool>::type checkstate(){
    cout <<"type is bool" << endl;
    return true;
}
template<int stat>
typename enable_if<stat == 0, int>::type checkstate(){
    cout <<"type is int" << endl;
    return 5;
}

template<bool stat>			//bool也可以。隐式转换为整型了，但是必须要常量。
typename enable_if<stat == true, int>::type checkstate1(){
    cout <<"type is int" << endl;
    return 5;
}

template <int stat>
using test = enable_if_t<stat == 1, bool>;

// template <typename T, typename = enable_if_t< T == 1>>
// void anotherCheck(){
//     cout <<"type is bool" << endl;
//     return true;
// }
template<typename T, typename = std::enable_if<(sizeof(T) > 4)>>
T foo(T a) {
    cout << ">4" << endl;
    return a;
}
// template<typename T, typename = std::enable_if<(sizeof(T) <= 4)>>
// T foo(T a) {
//     cout << "<=4" << endl;
//     return a;
// }
// template<typename T, typename = std::enable_if_t<T == 2> >
//     void anotherone() {
// }
template <typename T, int T1,  enable_if_t<(T1 > 4)>* whatever = nullptr>
T functions(T a){
    cout << a << endl;
    cout <<" > 4" << endl;
    return a;
}
template <typename T, int T1,  enable_if_t<(T1 <= 4)>* whatever = nullptr>
T functions(T a){
    cout << a << endl;
    cout <<" <= 4" << endl;
    return a;
}
// template <typename T1,  typename enable_if<(sizeof(T1) <= 4)>::type* whatever = nullptr>
// T1 functions(T1 a){
//     cout << a << endl;
//     cout <<" > 4" << endl;
//     return a;
// }
// template <typename T1, enable_if_t<(sizeof(T1) > 4)>* whatever = nullptr>
// T1 functions(T1 a){
//     cout << a << endl;
//     cout <<" <=4" << endl;
//     return a;
// }
// template <typename T1, enable_if_t<(sizeof(T1) <= 4)>* whatever = nullptr>
// T1 functions(T1 a){
//     cout << a << endl;
//     cout <<" <=4" << endl;
//     return a;
// }
template <int value, typename = enable_if_t<value == 2>>
void myfunc(){
    cout <<"2" << endl;
}


int main(){
    // const int myobj = 1; 	//必须是const
    // checkstate<myobj>();	//输出"type is bool" 
    // checkstate<0>();		//输出"type is int" 
    //anotherCheck<1>();
    //anotherCheck<0>();
    //foo<5>();
    //foo<double>(20.123);
    //myfunc<3>();
    functions<double, 8>(10.123);
    functions<string, 2>("12345");
    return 0;
}