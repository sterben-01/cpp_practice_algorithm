#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class A{
    public:
    A(){
        cout <<"a" << endl;
    }
    ~A(){
        cout <<"~A" << endl;
    }
};





int main(){
    A* arr = new A();
    int& s = 0;
    return 0;
}