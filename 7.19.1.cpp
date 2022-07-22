#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
#include <memory>
using namespace std;




int main()
{
    vector<int>t1 = {1,2,2,3,4,5};
    t1.erase(t1.begin() + 1);
    //remove(t1.begin(), t1.end(), 2);
    cout << t1.size() <<endl;
    cout << t1.capacity() << endl;
    t1 = vector<int>(t1);
    vector<int>(t1).swap(t1);
    cout << t1.size() <<endl;
    cout << t1.capacity() << endl;  
}
/*
实例化函数模板时, 模板实参必须是已知的, 但不必显式指定. 
编译器会从函数模板的实参中推导缺失的模板实参. 另外模板参数推导也可以在 auto 说明符的上下文中从初始化器推导变量的类型.
*/