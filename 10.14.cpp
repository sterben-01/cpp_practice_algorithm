#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <sstream>
using namespace std;

class myobj{
    public:
        //myobj(){};
        myobj(int x, int y){
            inner_vec.resize(x, y);
        }
        myobj(initializer_list<int>my_list){
            for(auto& j:my_list){
                inner_vec.emplace_back(j);
            }
        }
        int val1;
        int val2;
        vector<int> inner_vec;
};



int main(){
    myobj ob1(2,3);
    for(auto& i:ob1.inner_vec){
        cout <<i << endl;
    }
    cout <<"----------" << endl;
    myobj ob2{1,2,3,4,5,6,7};
    for(auto& i:ob2.inner_vec){
        cout <<i << endl;
    }
    return 0;
}