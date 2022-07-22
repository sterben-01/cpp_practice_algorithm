#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

//!函数指针 回调函数1
typedef int(*ptr)(int, int); //typedef 定义别名
ptr instance = add; //方法一 函数外直接生成示例并赋值。注意这里typedef之后直接把函数赋值过去即可。
ptr test1;
test1 = add; //这里是错的。函数体外只能进行全局函数和变量的声明，而无法执行语句或调用函数。

int add(int a, int b){ //不需要传入函数指针了。
    cout << a+b << endl;
    return (a+b);
}

int main(){
    ptr test; //方法二 函数内进行分离声明
    test = add;
    test(5,8);
}


//!------------------------------------
//!函数指针 回调函数2

int add(int a, int b){ 
    cout << a+b << endl;
    return (a+b);
}

void callback(int(*ptr)(int,int), int a, int b){ //设立callback函数。传入函数指针和参数。
  //注意这里如果需要有值传出就要设置为返回int
    ptr(a, b);
}

int main(){
    callback(add, 5, 8);
}


//!------------------------------------
//!函数指针 回调函数3  c++风格

void callback(int(*ptr)(int, int), int a, int b){ //回调函数 如果需要返回值就return
    ptr(a, b);
}


class test{
    public:
        static int add(int a, int b){ //需要被执行的函数。注意要static。要么就全局。
            cout << a+b << endl;
            return (a+b);
        }
        void registure(){ //注册函数
            callback(add, 3, 5);
        }
        
};

int main(){
    test Test;
    Test.registure();
    return 0;
}

//!------------------------------------
//!函数指针 回调函数4 c++多态

class basecase{
    public:
        virtual void testmsg() = 0;
        virtual ~basecase(){}; //虽然这里没什么卵用但是还是要记得虚析构，不然无法执行子类析构
};

class case1 : public basecase{ //继承
    public:
        void testmsg() override{
            cout << "Case1 coutmsg" << endl;
        }
};

class case2 : public basecase{ //继承
    public:
        void testmsg() override{
            cout << "Case2 coutmsg" << endl;
        }
};

int main(){
    basecase* test1 = new case1();
    basecase* test2 = new case2();
    test1->testmsg();
    test2->testmsg();
    delete test1; //养成良好习惯
    delete test2;
    return 0;
}

