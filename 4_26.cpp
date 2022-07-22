#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class CTest 
{ 
public: 
    int m;
    //explicit CTest(int x = 0):m(x){}; //构造函数 加了explicit
    CTest(int x = 0):m(x){}; //构造函数
    operator int(){ //类型转换省得重载<<了。
        return m;
    }
    void set(CTest test){
        m = test;
        cout << test << endl;
    }
    CTest get(){
        cout << this->m;
        return m; //不能隐式转换 不加explicit的用这一套
        //return (CTest)m; //显式转换 加了explicit的用这一套
    }
};

int main(){
    CTest test;
    test.set(25);//error 不能隐式转换 不加explicit的用这一套
    int c = test.get();
    //test.set((CTest)(20)); //ok 显式转换 加了explicit的用这一套
    //int d = test.get();

}