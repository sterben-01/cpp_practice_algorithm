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
        myobj(int x):val(new int(x)){}
        int& getval(){
            return *val;
        }

        myobj(const myobj& obj){
            val = new int(*obj.val);
        }
        myobj& operator=(const myobj & rhs){
            if(this == &rhs){
                return *this;
            }
            delete this->val;
            val = new int(*rhs.val);
            return *this;
        }

        myobj(myobj&& obj){
            cout <<"mv" << endl;
            val = obj.val;
            obj.val = nullptr;
        }
        myobj& operator=(myobj&& rhs){
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

        // myobj& operator=(const myobj&& rhs){

        // }


        ~myobj(){
            delete val;
            val = nullptr;
        }


        int* val;
        
};

int main(){
    myobj a(5);
    myobj b(10);
    cout << a.getval() << endl;
    myobj c(a);
    cout << c.getval() << endl;
    myobj d = c;
    cout << d.getval() << endl;
    d = b;
    cout << d.getval() << endl;

    myobj e = move(a);
    cout << e.getval() << endl;

    d = move(b);
    cout << d.getval() << endl;
    return 0;
}