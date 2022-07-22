#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
class mycomp{
public:
    int m_val;
    mycomp(int passval): m_val(passval){}; //构造函数 一定要有类构造函数这样你谓词函数初始化的时候可以把值传进来
    bool operator()(int val) const{
        if(val < m_val){
            cout << "true: " << val<< endl;
            return true;
        }
        cout << "false: " << val<< endl;
        return false;
    }
    static void print(const int& printval){ //必须静态 静态没有this指针
        cout << printval << endl;
    }

};
class fuck{
public:
    int val;
    fuck():val(0){}
    fuck(int x):val(x){} //所以类要有对应的构造函数
    void print2(){
        cout << this->val << endl;
    }
    static void print3(fuck x){
        cout << x.val << endl;
    }
    static void print4(fuck* x){
        cout << x->val << endl;
    }

};

int main(){
    vector<int> test = {1,2,3,4,5,6,7};
    for_each(test.begin(), test.end(), mycomp(3));//又叫谓词函数。第一步先用括号内的参数对类进行声明一个类的匿名对象。然后会被for_each调用操作符重载部分
    mycomp(3)(5); //显示看一看到底怎么用的。第一个括号声明了类的匿名对象，然后调用操作符重载。一开始肯定要先用构造函数声明啊不然你怎么用。对吧
    mycomp a(3); //上面一行的分步骤实施。首先使用构造函数和其参数声明具名对象
    a(10);//这里用的是操作符重载
    for_each(test.begin(), test.end(), &mycomp::print); //取成员函数的地址然后成员函数必须为静态。

    /*下面这块比较复杂*/

    vector<fuck*> pointvec;//这里必须是类类型的 
    pointvec.push_back(new fuck(1)); //所以类要有对应的构造函数
    pointvec.push_back(new fuck(2));
    pointvec.push_back(new fuck(3));
    for_each(pointvec.begin(), pointvec.end(),mem_fun(&fuck::print2));//这块你用了类成员转换函数，那你对应的东西存的类型也要是类类型。东西必须是对象指针 c++17已弃用
    for_each(pointvec.begin(), pointvec.end(),&fuck::print4); //你for_each取出来的是个加了*的。就是你存的东西的类型。你存的是指针所以你print4函数传入也得是指针是fuck*
    for_each(pointvec.begin(), pointvec.end(),mem_fn(&fuck::print2));
    vector<fuck> fuckvec;
    fuckvec.push_back(fuck(3));
    fuckvec.push_back(fuck(4));
    fuckvec.push_back(fuck(5));
    for_each(fuckvec.begin(), fuckvec.end(),&fuck::print3); //static 这个地方for_each取出来的是fuck本身 所以print3形参是fuck
    for_each(fuckvec.begin(), fuckvec.end(),mem_fun_ref(&fuck::print2)); //存的是实体可以用mem_fun_ref c++17已弃用
    for_each(fuckvec.begin(), fuckvec.end(),mem_fn(&fuck::print2)); //static 这个地方for_each取出来的是fuck本身 所以print3形参是fuck




}
