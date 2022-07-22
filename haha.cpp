#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
class A{
public:
    int val;
    virtual void test1(){
        cout <<"virtual A test1" << endl;
    }
    virtual void test2(){
        cout <<"virtual A test2" << endl;
    }

};
class B : public A{
public:
    virtual void test1(){
        cout << "virtual B test1" << endl;
    }
};
int main(){
    A a;
    long long* a_ptr = (long long*)&a;  
    auto ss = ((long long*)(long long*)&a)[0];
    auto sss = ((long long*)((long long*)(long long*)&a)[0])[0];
    long long ssss = (long long)((long long*)((long long*)(long long*)&a)[0])[0];
    ((void(*)(void))(long long)((long long*)((long long*)(long long*)&a)[0])[0])();
}