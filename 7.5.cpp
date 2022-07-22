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
#include <stdarg.h>
using namespace std;

class singleten{
    public:
        static singleten& get_singleten(){
            static singleten instance;
            return instance;
        }
        static singleten& get_singleten(int a){
            static singleten instance(a);
            return instance;
        }
        void getval(){
            cout << val << endl;
        }


    private:
        singleten(){}
        singleten(int x):val(x){}
        singleten(const singleten&) = delete;
        singleten& operator=(const singleten&) = delete;
        ~singleten(){
            cout <<"destroyed" << endl;
        }

    public:


    private:
        int val;

};

int main(){
    singleten& inst = singleten::get_singleten(6);
    inst.getval();

    return 0;
}