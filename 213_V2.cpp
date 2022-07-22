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
*这道题也有V1 V2两版本。区别在于数组初始化。这里是V2 数组初始化为nums.size()
这道题和之前的唯一区别在于有两种情况，一种是不偷第一个房子偷剩下的，另一种是偷第一个房子不偷最后一个。
所以我们分开写，将DP抽离出来。相当于计算出两种结果然后取最大值
*/
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
*这道题也有V1 V2两版本。区别在于数组初始化。这里是V2 数组初始化为nums.size()
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
        int res1 = rob_process(nums, 0, nums.size()-2); //我们这里初始化成了nums.size()所以-2是倒数第二个房子。这里是偷第一个不偷最后一个
        int res2 = rob_process(nums, 1, nums.size()-1); //nums.size()-1是最后一个房子，这里是从第二个开始偷，也就是不偷第一个偷最后一个
        return max(res1, res2);

    }
    int rob_process(vector<int>& nums, int start, int end){ //!注意这里end指的是最后一个数的下标。这里永远是能取到end的
        vector<int>dp(nums.size(),0);
        if(end == start){ //!这里就要考虑特殊情况了。有前导零的数组的时候也就是nums.size()+1的时候前后是不会贴上的。 
        //!比如[1,1]会变成[0,1,1]。但是没有前导0的时候[1,1] 前后会贴上。所以当起始坐标和终点坐标是一样的的时候就直接返回数就可以。
            return nums[start];
        }
        dp[start] = nums[start]; //下标start是有意义的。所以是第一个房子价值
        dp[start+1] = max(nums[start], nums[start+1]); //第一个和第二个房子价值取最大
        for(int i = start + 2; i < end+1; i++){
            dp[i] = max(dp[i-2] + nums[i] , dp[i-1]); //上一题一样
        }
        return dp[end]; //返回数组最后一个数 注意这里end是最后一个数。
    }
};