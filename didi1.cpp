#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

struct A{
    int x;
    A(int v = 10):x(v){};
    void p(){
        cout <<"called" << endl;
    }
    void f(){
        cout << x << endl;
    }
};

int main(){
    A* ps = nullptr;
    ps->p();
    return 0;
}