#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
这题首先注意一点。递增子序列。每一层用的数字不能重复。比如46777。我们可以467 但是只有一个。后面的第二个7和第三个7不能用，因为强调不能有重复的子序列。
所以我们用set去重。也就是判断这一层这个数字用过了没。
&切记不可以用used数组。因为用used数组需要排序。这道题不能排序！

*/

class Solution {
public:
    vector<int> vec;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
    void backtracking(vector<int>&nums, int startindex){
        if(vec.size() >1){
            res.push_back(vec);
        }
        unordered_set<int>uset;
        for(int i = startindex; i < nums.size(); i++){
            if((!vec.empty() && nums[i] < vec.back()) || uset.find(nums[i]) != uset.end()){ //判断，前面的是判断现在这个数是不是比vec里面最后一个数小。如果小就不是递增。第二个判断是看set里面有没有过这个数，也就是这一层用过没
                continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了。不需要清空。每一个树枝会自动清空。
            vec.push_back(nums[i]);
            backtracking(nums, i + 1);
            vec.pop_back();

        }

    }
};