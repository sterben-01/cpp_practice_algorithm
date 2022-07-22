#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
void printvector01(int a){ //这里函数对象对应的函数的形参应该是迭代器指向的容器对象的对应类型。比如vector<int>的话这里就要int, vector<pair<int,int>>的话就要pair<int, int>
    cout << a << endl;
}

void printvector02(pair<int, int> a){ //注意这里pair<int a, int b>是错的！！！ pair<>括号里头的是数据类型，外面的才是名字！你不能vector<int a>吧
    cout<<a.first << " , " << a.second << endl;
}

int main(){
    vector<int> test = {1,2,3,4,5};
    for_each(test.begin(), test.end(), printvector01); //注意这里传递的是函数对象，不是函数。printvector()加了括号的叫调用！！
    vector<pair<int,int>> test2 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    for_each(test2.begin(),test2.end(), printvector02);
}
/*
template <class _InIt, class _Fn>
_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
    _Adl_verify_range(_First, _Last);
    auto _UFirst      = _Get_unwrapped(_First);
    const auto _ULast = _Get_unwrapped(_Last);
    for (; _UFirst != _ULast; ++_UFirst) {
        _Func(*_UFirst); //这里已经对迭代器对象解引用了，所以直接传入的是迭代器对应的值。
        // 注意这里调用函数的方式是直接把参数塞进去。所以传递函数对象就行 不用() 加了括号叫调用
    }

    return _Func;
}
*/