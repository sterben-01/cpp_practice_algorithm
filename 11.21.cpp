#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;

template <typename T>
void test(T a, T b){
    cout << "模板函数" << endl;
}

template <typename T, typename T2>
void test(T a, T2 b){
    cout << "重载的模板函数" << endl;
}

class obj{
    public:
        int val1;

    void func() const {
    }

};


int main(){
    test<int>(1,2);
    return 0;
}