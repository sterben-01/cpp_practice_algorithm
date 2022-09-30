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

&切记不可以这样判断大小：
if(i > 0 && nums[i] < nums[i-1]){
    continue;
}
&因为子序列不一定连续。所以说不能单纯看原数组两个数之间的关系。应该看这个要加进来的数字和当前数组最末尾的值的关系。



%而且限制条件
if(temp.size() >= 2){
  ret.push_back(temp);
}
if(startindex > nums.size()){
  return;
}
%下面的那个可以不加，如果加必须放在pushback后面，因为我们是进入到下一层后判断数组大小后放入结果集合的。


&还有关于为什么我们set在for外面。我们set的去重作用是比如4777.我们针对第一个7，可以有47 477 4777。也就是在取了4的时候，我们第二位取了第一个7，第三位取了第二个7 第四位取了第三个7.....

&但是在回退的时候，我们不能让第二位取第二个7。也就是在同一个节点中不能有两条路径从一个值开始。我们知道for循环内是递归调用。也就是控制树枝。for循环外是每一个节点。也就是一个树层。所以自然这个set要放在for循环外面，因为控制的是当前节点。

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