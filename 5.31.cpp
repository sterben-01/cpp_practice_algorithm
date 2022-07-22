#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

class test{
    public:
    int _a;
    int _b;
    test(int a, int b): _a(a), _b(b) {};
    /*
    这里如果没有写无参构造，编译器不会生成一个默认无参构造。因为有构造了。
    */
    test() = default; //使用默认生成的构造函数
    static void* operator new(size_t size) = default;
};




int main(){
    test a;

}