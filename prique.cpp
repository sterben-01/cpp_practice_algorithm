#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;
class mycomparison {
public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
};

class Solution {
public:
    // 小顶堆
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = map[nums[i]] + 1;
        }
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            cout << "-----new----" << endl;
            cout<< (*it).first  << ":" << (*it).second<< endl;
        }
        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            cout<<it->first<<endl;
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

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
    vector<int> test = {1,1,2,1,2,2,3,3,3,4,4,4,4,4,4,1};
    vector<int> res;
    res = (obj->topKFrequent(test,3));
    for(int s = 0; s < res.size();s++){
        cout << res[s] << endl;
    }
    // int b = 5;
    // int* a;
    // a = &b;
    // top = &(top->topval(stock[st]));
}