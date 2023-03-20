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

        myobj(const myobj& obj){ //拷贝构造
            cout <<"copy const" << endl;
            val = new int(*obj.val);
        }
        myobj& operator=(const myobj & rhs){ //拷贝赋值
            cout <<"copy= const" << endl;
            if(this == &rhs){
                return *this;
            }
            delete this->val;
            val = new int(*rhs.val);
            return *this;
        }

        myobj(myobj&& obj){ //移动构造
            cout <<"mv" << endl;
            val = obj.val;
            obj.val = new int(3939);
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


class testobj{
    public:
    myobj inner;
    testobj(myobj&& obj):inner(forward<myobj>(obj)){}
};

class Person{
    public:
    int id;
    int day;
    Person(int x, int y): id(x),day(y){}
};

int main(){
    int x = 100;
    auto cmp = [](const Person& a, const Person& b) -> bool {return (a.id < b.id);
    };
    set<Person, decltype(cmp)> my_set(cmp); //set的自定义比较。
    my_set.emplace(3,1);
    my_set.emplace(1,2);
    my_set.emplace(2,2);
    for(auto& i:my_set){
        cout << i.id << " " << i.day << endl;
    }



    vector<Person> my_vec;
    my_vec.emplace_back(3,1);
    my_vec.emplace_back(1,2);
    my_vec.emplace_back(2,2);
    sort(my_vec.begin(), my_vec.end(), [](const Person& a, const Person& b){return a.id < b.id;}); //sort的自定义排序
    for(auto& i:my_vec){
        cout << i.id << " " << i.day << endl;
    }
    return 0;

}