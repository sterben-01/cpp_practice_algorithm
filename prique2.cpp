#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

class mycompare{
public:
    bool operator()(const pair<string,int>& str, const pair<string,int>& num){
        if(str.second == num.second){
            return (str.first < num.first);
        }
        else{
            return (str.second > num.second);
        }
        
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(int i = 0; i < words.size(); i++){
            map[words[i]] = map[words[i]] + 1;
        }
        for (unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++) {
            cout << "-----new----" << endl;
            cout<< (*it).first  << ":" << (*it).second<< endl;
        }
        priority_queue<pair<string,int>, vector<pair<string, int>>, mycompare> que;
        unordered_map<string,int>::iterator iter;
        for(iter = map.begin(); iter != map.end();iter++){
            que.push(*iter);
            if(que.size() > k){
                que.pop();
            }
        }
    vector<string> res(k);
    for(int i = k-1; i >=0; i--){
        res[i] = que.top().first;
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