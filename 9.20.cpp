#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class mycomp{   
    public:
    bool operator()(const pair<int,int>&a, const pair<int, int>& b) const{
        double numa = double(a.first)/double(a.second);
        double numb = double(b.first)/double(b.second);
        if(numa < numb){
            return true;
        }
        return false;

    }
};
class mycomp1{   
    public:
    bool operator()( pair<int,int>&a,  pair<int, int>& b) {
        if(a.first < b.first){
            return true;
        }
        return false;

    }
};

void func(vector<int>& vec, int num){
    priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp> my_queue;
    for(int i = 0; i < vec.size(); i++){
        my_queue.push({vec[i],1});
    }
    for(int i = 0; i < num; i++){
        auto t = my_queue.top();
        my_queue.pop();
        t.second++;
        my_queue.push(t);

    }
    vector<int> ret;
    priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp1> my_queue1;
    while(!my_queue.empty()){

        my_queue1.push(my_queue.top());
        my_queue.pop();
    }
    for(int i = 0 ;i < vec.size(); i++){
        ret.push_back(my_queue1.top().second-1);
        my_queue1.pop();
    }
    for(auto i : ret){
        cout << i << endl;
    }

}
int main(){
    vector<int>a {10,6,4,3,2};
    cout <<"!" << endl;
    func(a,4);
    return 0;
}