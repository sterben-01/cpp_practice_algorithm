#include <iostream>
#include <string>
#include<memory>
#include <queue>
#include <functional>
using namespace std;


class mycomp{ //&priority_queue 的比较器
    public:
        bool operator()(int a, int b){
            if(abs(a-5) >= abs(b-5)){
                return false;
            }
            return true;
        }
};

int main(){
    priority_queue<int,vector<int>, mycomp>my_que{mycomp()}; //传入匿名对象使用花括号。
    my_que.push(10);


    return 0;
}