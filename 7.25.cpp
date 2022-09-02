#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;


template<typename T>
class test{
    public:
        T val;
        vector<T> vec;
        void push(const T& item){
            vec.push_back(item);
        }
        void getval(){
            for(auto i:vec){
                cout << i.val << endl;
            }
        }
        void inser(const T& item, const int& pos){
            vec.insert(vec.begin() + pos, item);
        }
        T& ret(){
            return vec[3];
        }
};


int main(){
    // test<int> S;
    // int p = 5;
    // S.push(p);
    // cout << S.ret()<<endl;
    // S.push(8888);
    // cout << S.ret()<<endl;
    // S.push(100);
    // S.push(300);
    // S.push(50);
    // cout << S.ret()<<endl;
    // S.inser(5, 2);
    // cout << S.ret()<<endl;
    vector<int> a;
    a.reserve(20);
    for(int i = 0 ;i < 10; i++){
        a.push_back(i);
    }
    auto it = a.end();
    cout << *(it-1) << endl;
    a.insert(a.begin() + 3, 3333);
    for(auto i:a){
        cout <<i << endl;
    }
    cout << *(it-1) << endl;
}