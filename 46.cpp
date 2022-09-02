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
针对组合问题，没有重复元素，不可取重复的用startindex。 有重复元素且不可取重复的用startindex+used
针对排列问题，比如全排列。12和21是两种排列。所以不需要startindex。used数组是用来标记同一树枝用过的数字的。
举例：123这个排列，先取了2，因为没有startindex，所以我们还是从1开始取。但是2已经被拿走了，所以2跳过。从1和3选。所以排列问题的used数组去重是判断是否为true。
&几个要点。1.不用排序。2.不需要看nums[i] == nums[i-1]所以没有i>0这个判断。
update 注意和47 全排列II的区别
*/

class Solution {
public:
    vector<int>vec;
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        backtracking(nums, used);
        return ret;
    }
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(vec.size() == nums.size()){
            ret.push_back(vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true){
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