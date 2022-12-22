#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <unordered_map>
using namespace std;


class myobj{
    public:
        int val;
        string str;
        unique_ptr<int>u_ptr;

        myobj(int x, const string& rhsstr, int* num = nullptr): val(x), str(rhsstr), u_ptr(num){}

};

class father{
    public:
        int val = 10;
        virtual void func(){
            cout <<"f "<< endl;
        }
};

class child: public father{
    public:
        int val = 20;
        virtual void func(){
            cout <<"c" << endl;
        }
};

void setsss(father* ptr){
    ptr->func();
}

class fuck{
    public:
    fuck(){
        setall();
    }
    void setall(){
        a = 10;
        b = 20;
    }
    int a;
    int b;
    
};

int main(){ 
    fuck obj;
    cout << obj.a << endl;
    return 0;
}