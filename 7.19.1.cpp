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

vector<int> a;
void test(const int& obj){
    a.push_back(obj);

}

class myclass{
    public:
        int val;
        vector<myclass> myvec;
        myclass(){};
        myclass(int a):val(a){myvec.reserve(10);}
        void addval(myclass obj){
            myvec.push_back(obj);
        }
        myclass(const myclass& obj){
            cout << "copy const" << endl;
        }
        // myclass(const myclass&& obj) noexcept{
        //     cout << "move const" << endl;
        // }

};



int main()
{
    myclass a(3);
    myclass b(8);
    a.addval(b);
    cout << "-----" << endl;
    a.addval(myclass(5));
//     cout << a.myvec.size() << endl;
//     cout << a.myvec.capacity() << endl;
//     a.addval(myclass(6));
//     cout << a.myvec.size() << endl;
//     cout << a.myvec.capacity() << endl;
}
/*
实例化函数模板时, 模板实参必须是已知的, 但不必显式指定. 
编译器会从函数模板的实参中推导缺失的模板实参. 另外模板参数推导也可以在 auto 说明符的上下文中从初始化器推导变量的类型.
*/