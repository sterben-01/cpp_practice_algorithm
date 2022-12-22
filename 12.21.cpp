#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
#include <list>
#include <atomic>
using namespace std;
struct Base {
    // no virtual here
    virtual ~Base()
    {
        printf("~Base\n");
    }
};

struct Derived : Base {
    ~Derived()
    {
    	printf("~Derived\n");
    }
};


int main(){
    // std::shared_ptr<Base> sp(new Derived()); //输出 ~Base 和 ~Derived
    // std::shared_ptr<Base> sp2 = make_shared<Derived>();
    // Base* ptr = new Derived; //只输出~Base
    // delete ptr;
    map<int,int> maps{{1,2},{2,3},{3,4},{4,5}};
    cout << maps.begin() + 2 << endl;
    return 0;
}