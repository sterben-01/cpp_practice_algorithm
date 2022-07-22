#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
这题比300简单直观很多。因为要求连续。
dp[i]的含义是到nums[i]为止连续递增的子序列的长度


?初始化怎么办？
以下标i为结尾的数组的连续递增的子序列长度最少也应该是1，即就是nums[i]这一个元素。
所以dp[i]应该初始1;

?递推公式？
这个简单。只要nums[i] > nums[i-1] 也就是这个数比前一个数大。就在前一个数的dp位置+1
即dp[i] = dp[i-1] + 1；
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 2){
            return 1;
        }
        int res = 0;
        vector<int> dp (nums.size(),1);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){ //注意这里是nums[i]和nums[i-1]比较不是dp[i]和dp[i-1]
                dp[i] = dp[i-1] + 1; //递推

            }
            if(dp[i] > res){ //保存最大值
                res = dp[i];
            }
        }
        return res;
    }
};