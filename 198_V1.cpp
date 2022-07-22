#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
/*
此题有两种解法。区别在于初始化数组的情况
* 初始化dp数组大小为nums.size()的情况下，dp[j]的含义是从第一个房子开始偷到下标为j的房子为止的最大金额
我们通过题目可以知道，我们不能连着偷房子
所以当我们想要偷第i个房子的时候，我们要考虑要么是不偷这个，偷前一个的时候最大；要么是偷这个和前两个的时候最大

    nums[1  2   3   4   3]
    dp  [                ]
            ↑   ↑   ↑ 
            i-2 i-1 i

我们是下标为j 所以j=0时候是有意义的 就是nums[0]的金额。所以dp[0] = nums[0]
所以我们dp[1]的金额就是看第一个房子最值钱还是第二个金额最值钱 dp[1] = max(nums[0], nums[1])
也就是要么是dp[i-1] 要么是dp[i-2] + nums[i]
!注意这里是nums[i] 不是dp[i] 因为nums数组储存的是金额也就是value。这里和V2不同。这里数组没有错位长度一样所以index不用-1

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int>dp (nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[nums.size()-1];

    }
};