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
update 注意和46 全排列的区别
如果排列问题有重复元素，那就是used数组既要判断false也要判断true。也就是树枝和树层都要去重。
&几个要点：1. 树层去重用used数组记得排序。2. 树层去重used数组看的是nums[i] == nums[i-1] && used[i-1] == false. 3. 树枝去重used数组看的是used[i] == true.具体原理稍微想想就知道了，不解释。
&树枝去重看used[i] = true 的原因是，我们没有startindex。所以每次都是从开头开始。如果没有树枝去重的话， 112这个组合的第一个1每次都会被选出来。就会出现111这种问题。
&所以使用了used[i]可以在一定程度上替代startindex。但是我们不用startindex的原因是，我们从2开始可以选回之前的这个1。因为我们used树枝的限制仅限于单个for循环也就是单个路径。不限制整个路径。
&used树层去重是限制的起始点的值重复。used树枝去重限制的是路径上的选择重复。
*/

class Solution {
public:
    vector<int> vec;
    vector<vector<int>> ret;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        sort(nums.begin(), nums.end()); //!记得排序
        backtracking(nums, used);
        return ret;
    }
    void backtracking(vector<int>&nums, vector<bool>&used){
        if(vec.size() == nums.size()){
            ret.push_back(vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){ //记得树层是i-1
                continue;
            }
            if(used[i] == true){ //树枝是i。
                continue;
            }
            used[i] = true;
            vec.push_back(nums[i]);
            backtracking(nums, used);
            vec.pop_back();
            used[i] = false;
        }
    }
};