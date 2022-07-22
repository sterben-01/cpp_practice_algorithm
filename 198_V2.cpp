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
* 初始化dp数组大小为nums.size()+1的情况下，dp[j]的含义是从第0个房子开始到j为止的最大金额
我们通过题目可以知道，我们不能连着偷房子
所以当我们想要偷第i个房子的时候，我们要考虑要么是不偷这个，偷前一个的时候最大；要么是偷这个和前两个的时候最大

     nums[1  2   3   4   3]
          0   1   2   3   4

    dp[0                 ]
       0   1   2   3   4
           ↑   ↑   ↑ 
           i-2 i-1 i

我们第j个, 所以j=0时候是没有意义的。所以dp[0] = 0
所以我们dp[1]的金额就是nums数组的第一个也就是dp[1] = nums[0]。
这里我们不用继续推dp[2]了
!注意这里是nums[i] 不是dp[i] 因为nums数组储存的是金额也就是value。所以如果是从第0个开始的话，nums数组的下标和dp是差一位的因为dp数组长了一位。
这里面 我们要么是偷dp[i-1]的房子，要么是dp[i-2]的房子 + nums[i-1]
为什么这里是nums[i-1] 因为我们dp数组是从0开始的。没有前0个房子。所以我们看到了dp[0] = 0; dp[1] = nums[0] dp[1]的时候才等于nums[0]

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
        vector<int>dp (nums.size()+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < nums.size()+1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]); //注意这里的差别！
        }

        return dp[nums.size()];

    }
};
