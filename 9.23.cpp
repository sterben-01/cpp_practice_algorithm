#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

class A
{
public:
    A(int i):a(i){} 		//单参构造函数
    A operator+(const A& rhs){
        A temp(this->a + rhs.a);
        return temp;
    }
    int a;
};


int main(){
    A a(5);
    a+5+10;
    cout << a.a << endl;
    return 0;
}