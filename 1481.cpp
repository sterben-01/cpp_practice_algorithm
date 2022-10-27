#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

/*
text 哈希表+优先队列。
题目：给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，请找出移除后数组中不同整数的最少数目。
说白了就是尽可能先把出现次数少的东西拿走。
&当我们发现处理对象的时候需要按照某种顺序的时候，就可以考虑使用优先队列了。
先用map统计每个元素出现次数，然后使用优先队列按照出现次数从少到多的顺序拿走即可。
&优先队列的细节。优先队列不可以修改值。但是我们如何处理拿走的数量呢？
k是固定的，我们每次拿走的时候，如果队头元素出现次数小于等于k次，证明可以一次性把元素取走。也就是pop掉。
如果发现队头元素出现次数大于k次了，证明这个元素拿不走了
todo 但是我们求的是剩下多少种，而不是剩下多少个。所以说只要这个元素不能被完全拿走，无论它剩几个和我们都无关。所以这时候直接break掉。
@当然这道题也可以替换为排序。把map里的元素拿出来到一个容器中排序也可以 。
*/
class mycomp{
    public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
            if(a.second > b.second){
                return true;
            }
            return false;
        }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>my_map;
        for(int i = 0; i < arr.size(); i++){
            my_map[arr[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp> my_que(my_map.begin(), my_map.end()); //!可以直接使用迭代器区间赋值。

        while( k > 0 && !my_que.empty()){
            auto top_item = my_que.top();
            if(top_item.second <= k){
                k = k - top_item.second;
                my_que.pop();
            }
            else{
                break;
            }
        }
        return my_que.size();

    }
};