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
used[i-1] = ture 判断树枝的重复元素是因为还在当前树枝，也就是当前遍历的是i-1为根的这个树枝。
used[i-1] = false 判断树层的重复元素是因为已经遍历到可以i为根的树枝，因为是顺序遍历，那么i之前的used[i-1]肯定回溯为false了。
&几个要点。
%1. 记得排序，因为用了used数组和sum + candidates[i] <= target的剪枝优化
%2. 记得backtracking参数是i+1
%3. 记得判断used数组的时候，是判断used[i-1]==0 和 candidates[i] == candidates[i-1]。不是判断used[i] == used[i-1]
*/

class Solution {
public:
    vector<int>vec;
    vector<vector<int>>ret;
    int sum = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> used(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return ret;
    }
    void backtracking(vector<int>& candidates, int target, int startindex, vector<int>& used){

        if(sum == target){
            ret.push_back(vec);
            return;
        }
        
        for(int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == 0 ){
                continue;
            }
            used[i] = 1;
            sum = sum + candidates[i];
            vec.push_back(candidates[i]);
            backtracking(candidates, target, i+1,used);
            vec.pop_back();
            sum = sum - candidates[i];
            used[i] = 0;

        }
    }
};