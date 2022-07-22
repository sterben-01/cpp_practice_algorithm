#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

void switchcase(int a){
    switch(a){
        case (1):{ //case不可以放表达式。
            cout << "1" << endl; // 不加break的话会执行从当前case开始直到结尾的全部代码。他也就是输入1会执行123 输入2会执行23
        }
        case(2):{
            cout << "2" << endl;
        }
        case(3):{
            cout << "3" << endl;
        }
    }
}


int main(){
    int a = 1;
    switchcase(a);
}



