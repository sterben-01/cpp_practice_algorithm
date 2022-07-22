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
using namespace std;


class test{
    public:
    test(){}
    typedef int inputtype;
};


template<typename T>
class test1{
    public:
    test1(){};
    typedef typename T::inputtype inputtype;
};



// template<typename T>
// class pclass{
// public:
//     typedef T valuetype;
// };

// template<typename T>
// class pclass<T*>{
// public:
//     typedef T valuetype;
// };


int main(){
    test::inputtype x; //这句话等于告诉你 test类下面的inputtype这个东西是int 

    // pclass<int>::valuetype x;
    // pclass<int*>::valuetype x;

}