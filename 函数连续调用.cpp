#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <stdarg.h>
#include <future>
#include <thread>
#include <numeric>
using namespace std;

//& 注意连续调用需要让函数返回对象的引用。所以return的是*this

class test{
    public:
    int val;
    test(){};
    test(int x):val(x){};

    test& add(int x){
        this->val = this->val + x;
        return *this;
    }
    test& minus(int x){
        this->val = this->val - x;
        return *this;
    }
    test& mult(int x){
        this->val = this->val * x;
        return *this;
    }
    void getval(){
        cout << this->val << endl;
    }
};
int main(){
    test tt(5);
    tt.add(4).minus(4).mult(5).add(6);
    tt.getval();
    //输出为31. (5+4-4) * 5 + 6 = 31
}