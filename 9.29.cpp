#include <iostream>
#include <string>
#include<memory>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

/*
text 我们的目的是传入一个数字X，让容器内的数字依据和X的差值进行排序。
*/
class mycomp{ //&priority_queue 的比较器
    public:
        bool operator()(int a, int b, int x){
            if(abs(a-x) >= abs(b-x)){
                return false;
            }
            return true;
        }
};
class mycomp1{ //&vector 的比较器。注意和优先队列是相反的。
    public:
        bool operator()(int a, int b, int x){
            if(abs(a-x) <= abs(b-x)){
                return false;
            }
            return true;
        }
};
void func(vector<int>& vec, int x){

    sort(vec.begin(), vec.end(), bind(mycomp1(), placeholders::_1, placeholders::_2, x)); //&使用bind对sort所需的自定义比较器参数进行绑定。

    auto cmp = [=](int a, int b) { return abs(a-x)< abs(b-x); };//&使用lambda做为自定义比较器
    priority_queue<int, vector<int>, decltype(cmp)> my_que{cmp}; //%注意，类型使用decltype自动推导，并且需要在优先队列构造函数内传入该比较器对象。
    //* 可以换成花括号。尤其是当要传入一个匿名对象的时候，防止语义问题。

    auto cmp1 = bind(mycomp(), placeholders::_1, placeholders::_2, x); //&使用bind生成的可调用对象做为自定义比较器
    priority_queue<int, vector<int>, decltype(cmp1)> my_que1(cmp1);//%注意，类型使用decltype自动推导，并且需要在优先队列构造函数内传入该比较器对象。

    priority_queue<int, vector<int>, decltype(bind(mycomp(), placeholders::_1, placeholders::_2, x))> my_que2(bind(mycomp(), placeholders::_1, placeholders::_2, x)); //直接写入。会非常长。


    //------测试部分---------
    for(int i = 0; i < vec.size(); i++){
        my_que1.push(vec[i]);
        my_que.push(vec[i]);
        my_que2.push(vec[i]);
    }

    cout <<"myque" << endl;
    while(!my_que.empty()){
        cout << my_que.top() << endl;
        my_que.pop();
    }

    cout << "myque1" << endl;
    while(!my_que1.empty()){
        cout << my_que1.top() << endl;
        my_que1.pop();
    }

    cout << "myque2" << endl;
    while(!my_que2.empty()){
        cout << my_que2.top() << endl;
        my_que2.pop();
    }
}



int main(){
    vector<int>a {1,2,3,9,100,7,5};
    func(a, 2);
    cout <<"vec" << endl;
    for(auto& i:a){
        cout <<i << endl;
    }
    return 0;
}