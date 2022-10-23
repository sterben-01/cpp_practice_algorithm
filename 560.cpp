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
text 前缀和类的。
如果想知道`nums[i] ~ nums[j] `的和，我们只需要计算`presum[j+1] - presum[i] `即可

比如
nums = 	   [1,2,3,4, 5, 6, 7]
presum = [0,1,3,6,10,15,21,28]

假如我们想知道`nums[2] ~ nums[5]`的和，也就是`3+4+5+6 = 19`
我们可以通过计算`presum[5+1] - presum[2] = 21 - 3 = 19`
加1是因为前缀和比原数组在开头多一个0。

那么我们这个题如果用暴力做的话就是两个for循环。然后一个一个试。但是就算用了前缀和也显然不够快。
&因为我们不需要知道具体的结果范围，只需要知道有几个就可以所以我们用哈希表。这里非常像两数之和
&前缀和的核心理解是累加。所以如果我们知道了当前的前缀和，如果我们的map里出现过 [当前前缀和-k]的过去的前缀和，就证明有连续的一段满足要求。
%我们map存的每一个key都是一段儿数组的前缀和。比如0~1,0~2, 0~3 ,... 0~nums.size()。如果0~6的前缀和减掉0~4的前缀和刚好为k，证明5~6是一个相加为k的子数组。
&换句话说就是如果0~6的前缀和减掉k是0~4的前缀和，那么证明5-6是我们需要的。所以我们只需要每次取哈希表找一下[0~6的前缀和-k]这个数值到底在不在，也就是当前presum-k到底在不在，如果在就累计次数。
用我们上面的例子说明。0~6的前缀和是presum[7]-presum[0] = 28
0~4的前缀和是presum[5] - presum[0] = 15
那么5~6的和就是28-15 = 13 = 6 + 7

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> my_map;
        my_map[0]++; //必须预存0
        int count = 0;
        int presum = 0;
        for(int i = 0; i < nums.size(); i++){
            presum = presum +  nums[i];
            if(my_map.find(presum - k) != my_map.end()){ //presum - （presum-k） == k 这个就是为啥要找presum-k
                count = count + my_map[presum-k];
            }
            my_map[presum]++;
        }
        return count;
    }
};