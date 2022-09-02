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
&几个要点：1. 树层去重用used数组记得排序。2. 树层去重used数组看的是used[i-1] == false. 3. 树枝去重used数组看的是used[i] == true.具体原理稍微想想就知道了，不解释。
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