#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <array>
#include <future>
#include <math.h>
#include <time.h>
#include <bitset>
#include <stack>
using namespace std;




template<typename T, typename... Args> //变长参数模板
std::unique_ptr<T> my_make_unique(Args&&... args){ //函数会返回unique_ptr
    return std::unique_ptr<T> (new T(std::forward<Args>(args)...)); //使用完美转发至对象的构造函数。构造智能指针。，
}




class obj{
    public:
        obj(){};
        obj(int a):val1(a){};
        explicit obj(int a, int b):val1(a), val2(b){};
    int val1;
    int val2;
};

int main(){
    obj t1; //可以，有默认构造函数
    obj t2(10,20); //可以，explicit只能限制拷贝初始化。这里是直接初始化。
    //obj t3 = (10,20);//不可以，禁止隐式类型转换。
    obj t4 = obj(10,20);//可以，显式类型转换。
    obj t5 = (20); //可以。因为这个构造函数没有被explicit修饰

    vector<obj> myvec{obj(10,20), (20)}; //可以这样搭配使用。

    return 0;
}