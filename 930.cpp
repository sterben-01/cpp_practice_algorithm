#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
text 前缀和 和560差不多
&给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
这里不要被子数组迷惑了。
首先哈希表的key是前缀和，value是出现的次数。所以key会是0~1, 0~2 ,... ,0~n的前缀和。
比较好理解的地方是如果需要找和为goal的区间，我们只需要找到presum[j+1] - presum[i] = goal的区间有几个即可。
也就是如果想知道`nums[i] ~ nums[j] `的和，我们只需要计算`presum[j+1] - presum[i] `即可
公式变形一下就是presum[j+1] - goal = presum[i]
&但是问题来了。如何求子数组的数量？这句话的意思其实就是问你有多少个区间满足presum[j+1] - goal = presum[i]
所以你只需要查表。在哈希表中查有多少个presum[j+1]-goal然后累加就行了。
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> presum;
        presum[0]++;
        int count = 0;
        int accumu = 0;
        for(int i = 0; i < nums.size(); i++){
            
            accumu += nums[i];
            if(presum.find(accumu - goal) != presum.end()){ //核心 哈希表中查有多少个presum[j+1]-goal然后累加就行了。
                count += presum[accumu - goal];
            }
            presum[accumu]++;
        }
        return count;
    }
};