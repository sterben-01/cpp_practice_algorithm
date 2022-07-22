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
*这道题也有V1 V2两版本。区别在于数组初始化。这里是V1 数组初始化为nums.size()+1
这道题和之前的唯一区别在于有两种情况，一种是不偷第一个房子偷剩下的，另一种是偷第一个房子不偷最后一个。
所以我们分开写，将DP抽离出来。相当于计算出两种结果然后取最大值
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
        int res1 = rob_process(nums, 0, nums.size()-1); //我们这里初始化成了nums.size()+1 所以-1是倒数第二个房子。这里是偷第一个不偷最后一个
        int res2 = rob_process(nums, 1, nums.size()); //nums.size()是最后一个房子，这里是从第二个开始偷，也就是不偷第一个偷最后一个
        return max(res1, res2); //两种取最大值

    }
    int rob_process(vector<int>& nums, int start, int end){ //!注意这里end指的是最后一个数的下标。这里永远是能取到end的
        vector<int>dp(nums.size()+1,0);

        dp[start] = 0; //包含前导0的数组。第0个房子没意义，所以第0个是0 我们这里使用start代替0.
        dp[start+1] = nums[start]; //和上一题一样。带前导0的dp数组和nums有串位。所以第一个房子(start+1)是nums(start)
        for(int i = start + 2; i < end+1; i++){//!注意这里end指的是最后一个数的下标。这里永远是能取到end的 所以要么是<=end 要么是<end+1
            dp[i] = max(dp[i-2] + nums[i-1] , dp[i-1]); //和上一题一样
        }
        return dp[end]; //返回数组最后一个数 注意这里end是最后一个数。
        //! V2这里也不是end-1 因为end是最后一个数。
    }
};