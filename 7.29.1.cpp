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

class myobj{
    public:
        myobj(int x):vala(x), valb(5){ cout <<"fuckconstructor" << endl;}
        
        myobj(int x, int y):vala(x), valb(y){ cout <<"constructor" << endl;}

        //myobj(initializer_list<int> lst): vala(*lst.begin()), valb(*lst.begin()+1){}

        myobj(const myobj& obj){
            this->vala = obj.vala;
            this->valb = obj.valb;
            cout <<"copy constructor" << endl;
        }

        myobj(myobj&& obj){
            this->vala = obj.vala;
            this->valb = obj.valb;
            cout <<"mv constructor" << endl;
        }

        int vala;
        int valb;
};





int main(){
    vector<myobj> vec;
    vec.reserve(10);
    //vec.push_back(myobj(1,2));      //先调用默认构造，然后因为是临时对象触发移动构造
    //vec.push_back({1,2});
    // cout << "---" << endl;
    // vec.push_back(1);  
    // vec.push_back({1,2});             //不可以
    // cout << "---" << endl;
    // vec.emplace_back(myobj (1,2));   //显式使用构造函数，所以先调用默认构造然后因为是临时对象触发移动构造
    // cout << "---" << endl;
    // vec.emplace_back(myobj{3,3}); 
    // cout << "---" << endl;
    myobj mm(1,2);
    //vec.push_back(mm);           //左值对象的形式传入时，不论是否有移动构造函数，因为对象已经存在，所以只调用一次拷贝构造。
    // cout << "---" << endl;
    //vec.emplace_back(3,3);          //参数列表的形式传入时，不论是否有移动构造函数，都是原地构造，只会调用一次构造函数
    //vec.emplace_back(myobj{3,3});  
    // cout << "---" << endl;
    vec.push_back(move(mm));
    // vector<int> resv;
    // resv.reserve(10);
    // resv[5] = 5;
    //vec.push_back(myobj(1,2));  
    // cout << resv[6] << endl;

}