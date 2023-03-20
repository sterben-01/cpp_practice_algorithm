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
#include <type_traits>
#include <memory>
using namespace std;

//*构造过程的各种测试。


class myobj{
    public:
        myobj(int x):val(new int(x)){ //构造
            cout <<"const" << endl;
        }
        // int& getval(){
        //     return *val;
        // }

        // myobj(const myobj& obj){ //拷贝构造
        //     cout <<"copy const" << endl;
        //     val = new int(*obj.val);
        // }
        // myobj& operator=(const myobj & rhs){ //拷贝赋值
        //     cout <<"copy= const" << endl;
        //     if(this == &rhs){
        //         return *this;
        //     }
        //     delete this->val;
        //     val = new int(*rhs.val);
        //     return *this;
        // }

        myobj(myobj&& obj){ //移动构造
            cout <<"mv" << endl;
            val = obj.val;
            obj.val = nullptr;
        }
        myobj& operator=(myobj&& rhs){ //移动赋值
            cout <<"mv=" << endl;
            if(this == &rhs){
                return *this;
            }
            if(this->val != nullptr){
                delete val;
            }
            val = rhs.val;
            rhs.val = nullptr; 
            return *this;

        }
        ~myobj(){
            cout <<"dest" << endl;
            delete val;
            val = nullptr;
        }


        int* val;
        
};


class myclass{
    public:
        int a;
        int b;
        myclass(int l, int r):a(l),b(r){};
};



int main(){
    myclass obj{2,3};
    auto t = {1,2,3,4};
    return 0;
}