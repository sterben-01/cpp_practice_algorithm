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
using namespace std;

class test{
    public:
        void add(const int& x){
            this->a = x;
        }
        int a;
        int b;
};

int main(){
    test T;
    T.add(4);
    cout << T.a << endl;
}
//%