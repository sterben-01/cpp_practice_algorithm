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
#include <algorithm>
#include<functional>
#include <type_traits>
using namespace std;


template<int stat>
typename enable_if<stat == 1, bool>::type checkstate(){
    cout <<"type is bool" << endl;
    return true;
}
template<int stat>
typename enable_if<stat == 0, int>::type checkstate(){
    cout <<"type is int" << endl;
    return 5;
}

template<bool stat>
typename enable_if<stat == true, int>::type checkstate1(){
    cout <<"type is int" << endl;
    return 5;
}


template<typename T>
void func(T obj){
    cout << obj << endl;
}


template<typename T, int MAXSIZE>
void func1(T obj){
    vector<T>a;
    a.reserve(MAXSIZE);
    cout << a.capacity() << endl;
    a.push_back(obj);
    cout << a[0] << endl;
    const bool sdsdd = true;
    checkstate1<sdsdd>();
}





int main() {
    const int myobj = 1;
    checkstate<myobj>();
    checkstate<0>();
    // func<int> (4);
    // const int s = 4;
    // func1<int, s>(5);
}