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
&注意为什么这里也需要startindex？我们说过，只要是从单个集合中求组合就需要startindex
不要被这道题的无限重复选取迷惑了。（回溯可以看成二叉树）我们无限重复选取意思是比如2367这条路径下的每一层都可以从2367选。
但是下一条路径367的2不可以选了。因为如果你没有startindex又从2开始选了的话，你上一条路径选的23和这条路径选的32会重复
因为这是组合。组合的话23和32是一个。排列的23和32才不同。
所以无限重复取的核心在递归的时候startindex这次不+1了。这样每次都可以从当前的startindex取
比如2367 因为startindex不+1 下一层还可以2367取。
下一条路径的367同理。
&注意我们使用了优化的方式判断和是否已经大于要求了。即在for循环里判断而不是在终止递归条件里判断。
%我们的判断方式是如果当前这个数加上累计和已经大于目标和了，即可停止循环直接返回。
!基于这个判断方式，我们的数组必须先排序！！如果不排序我们当前这个数字加上累计和大于目标和不能保证下一个加上之后也大于目标和
*/

class Solution {
public:
    
    vector<int>vec;
    vector<vector<int>>res;
    int countsum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //必须排序
        backtracking(candidates, target, 0);
        return res;
    }
    void backtracking(vector<int>&candidates,int target, int startindex){
        if(countsum == target){
            res.push_back(vec);
            return;
        }
        for(int i = startindex; i < candidates.size() && countsum + candidates[i] <= target; i++){ //优化判断和在这里
            countsum = countsum + candidates[i];
            vec.push_back(candidates[i]);
            backtracking(candidates, target, i); //注意这里操作的是i不是startindex。而且不加1
            vec.pop_back();
            countsum = countsum - candidates[i];
        }
    }
};