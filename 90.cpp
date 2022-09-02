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
本题用了used数组
update 针对组合，没有重复元素，不可取重复的用startindex。 有重复元素且不可取重复的用startindex+used
和78没啥区别。多了个used数组。
*/

class Solution {
public:
    vector<vector<int>>ret;
    vector<int>vec;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        ret.push_back(vector<int>());
        backtracking(nums, 0, used);
        return ret;
    }
    void backtracking(vector<int>& nums, int startindex, vector<int>& used){
        if(vec.size() >= nums.size()){
            return;
        }
        for(int i = startindex; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == 0){
                continue;
            }
            used[i] = 1;
            vec.push_back(nums[i]);
            ret.push_back(vec);
            backtracking(nums, i+1, used);
            vec.pop_back();
            used[i] = 0;
        }
    }
};