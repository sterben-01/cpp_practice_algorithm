#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;
// class mycompare{
// public:
//     bool operator()(const pair<int,int>& a , const pair<int,int>& b) const{
//         if(a.first<b.first){
//             return false;
//         }
//         if(a.second == b.second){
//             if(a.first < b.first){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class mycompare{
public:
    bool operator()(const pair<int,int>& a , const pair<int,int>& b) const{
        if(a.first < b.first == true){
            return false;
        }
        return true;

    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i :arr){
            map[i]+=1;
        }
        for(auto iter = map.begin(); iter != map.end(); iter++){
            cout << iter->first<<"," << iter->second << endl;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycompare> que;
        for(auto iter = map.begin(); iter != map.end(); iter++){
            que.push(*iter);
        }
        for(int i = 0; i<k && res.size()<k ;i++){
            int count = que.top().second;
            for(int j = 0; j < count&& res.size() < k; j++){
                res.push_back(que.top().first);
            }
            que.pop();

        }
        for(int i = 0; i < res.size(); i++){
            cout <<res[i] << endl;
        }
        return res;

    }
};
int main(){
    vector<int> test = {0,0,1,2,4,2,2,3,1,4};
    int ss = 8;
    Solution* obj = new Solution;
    obj->getLeastNumbers(test,ss);

}