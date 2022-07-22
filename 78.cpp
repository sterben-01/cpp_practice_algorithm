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
求子集唯一的区别就是之前求组合的时候是满足某一个条件再push。比如和为n，或者是k个数
子集是所有的可能。也就是之前只收集到根节点，这次我们也要收集叶子结点。
所以我们在回溯前面就存放一次结果。因为每一个for循环都是一个节点。
*/

class Solution {
public:
    vector<int>vec;
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.push_back(vector<int>());
        backtracking(nums, 0);
        return ret;
    }
    void backtracking(vector<int>& nums, int startindex){
        if(startindex >= nums.size()){
            return;
        }
        for(int i = startindex; i < nums.size(); i++){
            vec.push_back(nums[i]);
            ret.push_back(vec);
            backtracking(nums, i+1);
            vec.pop_back();
        }
    }
};