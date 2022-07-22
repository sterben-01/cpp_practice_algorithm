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


//基本类

class FLOATtype{
public:
    float _val;
    FLOATtype(){}
    FLOATtype(float x):_val(x){};
    float retval (float& num){
        cout << _val*num << endl;
        return _val*num;
    }
    //我们假设FLOATtype没有自己的获取输入输出类型的部分
};

class INTtype{
public:
    int _val;
    INTtype(){}
    INTtype(int x):_val(x){};
    int retval (int& num){
        cout << _val*num << endl;
        return _val*num;
    }
    //我们假设INTtype没有自己的获取输入输出类型的部分
};


class fucktype{
public:
    int _val;
    fucktype(){}
    fucktype(int x):_val(x){};
    int retval (int& num){
        cout << _val*num << endl;
        return _val*num;
    }
    typedef fucktype rettype; //我们假设fucktype有自己的获取输入输出类型的部分。所以我们加了typedef。
    typedef int inputtype;
};




//萃取 模板特化
/*
这里的例子看起来非常脱裤子放屁。但是对于迭代器萃取来讲完全不是。
我们知道迭代器是泛化的指针，也就是说指针是退化的迭代器。
我们知道迭代器是一个class 所以他们有能力定义自己的associate type。
举个例子。我们知道迭代器类里面有自己的value_type。所以我们可以直接问 list<int>::iterator你的valuetype是什么，像这样 list<int>::iterator::value_type。它会回答你它是int。
但是如果我们给算法传入的不是迭代器，而是一个指针怎么办？指针不是类，指针不是结构体，指针无法给自己弄一堆typedef。怎么办
这就是萃取的意义。我们可以间接问。就是放入萃取机。
*/
template <typename T>
class testTraits{ //默认版本。直接问对应类的输入输出类型。如果有的话
    public:
        typedef typename T::rettype rettype; //注意这里一定要加typename告诉编译器 T::rettype是一个类型。
        typedef typename T::inputtype inputtype; //注意这里一定要加typename告诉编译器 T::rettype是一个类型。告诉编译器T类下的inputtype代表的不是变量，代表的是类型。
};

template<> //模板全特化。我们假设知道inttype不是类，不能放typename 就好比指针。所以我们在这里给他包一层，显式告知对应的输入输出类型是什么。让有人问的时候转到这里告诉他对应类型
class testTraits<INTtype>{
    public:
        typedef int rettype;
        typedef int inputtype;
};

template<>
class testTraits<FLOATtype>{ //和上面一样。
    public:
        typedef float rettype;
        typedef float inputtype;
};

//使用

/*
在这个例子里面。我们对照着迭代器萃取器的例子做一个总结。
假如我们有几个类是有inputtype的。到时候直接问那个类就可以。但是如果是一个普通变量或者指针，没有inputtype的怎么办？
就好比我们的fucktype。我们在fucktype类里面有自己的typedef。所以可以直接问。
但是INTtype和FLOATtype没有，不能直接问。我们就通过模板特化来加一个中间层。所以萃取其实就是中间层。
*/

template<typename T>
class test{
    public:
    //注意这里testTraits<T>::rettype是做为函数的返回类型。所以必须要加typename。不然编译器会认为rettype是一个在testTraits里的成员变量。但是因为是把testTraits类里的rettype成员变量对应的typedef的东西当做类型来看待。所以需要加typename
    typename testTraits<T>::rettype retvall(T& obj, typename testTraits<T>::inputtype input){
        return obj.retval(input);
    }
};

int main(){
    INTtype intnum(5);
    int INTarg = 5;
    test<INTtype> test1;
    test1.retvall(intnum, INTarg);

    FLOATtype floatnum(5.5f);
    float FLOATarg = 8.8f;
    test<FLOATtype> test2;
    test2.retvall(floatnum, FLOATarg);

    fucktype fucknum(10);
    int fuckarg = 5;
    test<fucktype> test3;
    test3.retvall(fucknum, fuckarg);
}
