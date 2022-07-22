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
#include <stdarg.h>
#include <future>
#include <thread>
#include <numeric>
using namespace std;


template<typename Arg1, typename Arg2, typename result>
struct b_func{
    typedef Arg1 first_type;
    typedef Arg2 second_type;
    typedef result result_type;
};

template<typename T>
struct lesss:public b_func<T,T,bool>{
    bool operator()(const T&x, const T& y){
        return x < y;
    }

};


int main(){

    int a = 6;
    int b = 7;
    bool res = lesss<int>()(a, b);
    cout << res << endl;
    return 0;
}