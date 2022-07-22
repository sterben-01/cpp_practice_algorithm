#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>> que;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x+y*y;
            pair<int,vector<int>> p(distance,points[i]);
            que.push(p);
            if(que.size()>k){
                que.pop();
            }
        }
        vector<vector<int>> res(k);
        for(int i = 0; i < k; i++){
            res[i] = que.top().second;
            que.pop();
        }
        return res;
    }
};
int main(){
    // Solution * obj = new Solution();
    // string a = "hello world";
    // string b = obj->reverseWords(a);
    // int a = 5;
    // int* t = new int;
    // t = &a;
    // cout << *t << endl;
    Solution* obj = new Solution;
    vector<string> test = {"i","love","leetcode","i","love","coding"};
    vector<string> res;
    res = (obj->topKFrequent(test,2));
    for(int s = 0; s < res.size();s++){
        cout << res[s] << endl;
    }
    
}