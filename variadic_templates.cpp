#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
 
template<typename T0>
void print(T0 value)  //必须有一个单参数的函数重载。因为递归到最后一层的时候函数包里面只有一个参数，这个参数被当做第一个参数，而函数包就空了。就少了一个参数
                        //所以必须有一个单参数的函数重载。
{
    cout << value << endl;
}

template<typename T, typename... Ts>
void print(T value, Ts... args) 
{
    cout << value << endl;
    print(args...);
}
 
int main() 
{
    print(1, 1000, "123", 1.123, "HahaahaH");

}
