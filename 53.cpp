#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题也可以用贪心做。也是两个版本。含前导0和不含前导0.这里是含有前导0
dp[i]含义：包括第i个数之前的最大连续子序列和为dp[i]。
?递推公式？
两个选择，加上这个数或者是从头计算
dp[i-1]+nums[i-1]好理解，因为有数组错位所以不能nums[i]。
两个选择，加上这个数或者是从头计算。这里的意思是前一个数加上这个数。
!为什么要重新从头计算？因为子数组必须连续！如果断了就要从当前重新开始
!为什么要记录最大值？因为整体我们得到的结果不是一定递增的。就是有可能中间有一段产生了最大值，后面没有最大值。举个例子：
[0,0,5,5,-10,0]
这时候dp[nums.size()]出来的会是0。 因为前面有个-10隔着。所以从头到最后一位为止的子序列最大值是0+0+5+5-10+0 = 0.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        dp[0] = 0; //第0个数没意义。赋值0
        dp[1] = nums[0]; //dp[1]赋值nums[0]。因为基础的子数组和就是自己本身
        int res = dp[1]; //!这里不要赋值为0。一定要是dp[1]因为一开始的结果就是第一个数本身。
        for(int i = 1; i < nums.size()+1; i++){
            dp[i] = max(nums[i-1], dp[i-1] + nums[i-1]); //dp[i-1]+nums[i-1]好理解，因为有数组错位所以不能nums[i]。这里的意思是
            if(dp[i] > res){ //记录最大值。
                res = dp[i];
            }
        }
        return res;
    }
};