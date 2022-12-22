#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
using namespace std;

template<typename T, typename... Args>
vector<T> func(const Args&... args){
    return {args...};
}

class A{
    public:
    static void callback(A *pThis); //静态函数
    void b(){ //非静态函数
        cout <<"b" << endl;
        cout << val << endl;
    }       
    void in_class(){
        callback(this);
    } 
    int val = 10;
}; 
 
void A::callback(A *pThis)
{
    pThis->b(); //静态函数中调用非静态函数
}
int main(){
    A* aptr = new A();
    aptr->in_class();
    delete aptr;
    return 0;
}