#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
struct myobj{
    myobj(int x):val(x){}
    int val;
};


int main(){
    // shared_ptr<myobj> shared = make_shared<myobj>(5);
    // auto lambda = [=](int b){
    //     cout << shared->val + b << endl;
    //     cout <<"in lambda:" <<shared.use_count() << endl;
    // };
    // cout <<"out lambda:" <<shared.use_count() << endl;
    // shared.reset();
    // cout <<"out lambda:" <<shared.use_count() << endl;
    // lambda(10);
    myobj* obj = new myobj(5);
    shared_ptr<myobj> shared = make_shared<myobj>(obj);
    return 0;
}