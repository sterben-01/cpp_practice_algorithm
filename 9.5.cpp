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
#include <stack>
#include <set>

using namespace std;

class my_class{
    public:
    int val;
    my_class(int x):val(x){}

    void getval(){
        cout << val << endl;
    }
    void add(int another){
        val = val + another;
        cout << val << endl;
    }
    static void staticfunc(int val){
        cout << "static" << val << endl;
    }
};


int myfunc(int a){
    cout << a << endl;
    return a;
}

int myfunc1(const int& a){
    cout << a << endl;
    return a;
}

int myfunc2(int&& a){
    cout << a << endl;
    return a;
}


int main(){
    my_class obj1(10);

    // auto task1 = mem_fn(&my_class::getval);
    // task1(&obj1);

    // auto task2 = mem_fn(&my_class::add);
    // task2(&obj1, 5);

    // //auto task3 = mem_fn(&my_class::staticfunc);


    function<void(void)> task1_2 = bind(&my_class::getval, &obj1);
    task1_2();

    function<void(int)> task2 = bind(&my_class::add, &obj1, placeholders::_1);
    task2(5);

    return 0;
}

