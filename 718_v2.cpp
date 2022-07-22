#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;


/*
*这题依旧是两种做法。含前导0和不含前导0的。这题含前导0简单一些因为不需要手动初始化第一个。这里是不含前导0 nums.size()
dp[i][j]的意思是以下标i为结尾的nums1，和以下标j为结尾的nums2，最长重复子数组长度为dp[i][j]。

?如何初始化？这里初始化和做法1不一样。做法1我们知道第0个数是没有意义的。但是这里我们第一个数有意义，所以需要手动初始化

我们需要将所有在nums1数组里等于nums2[0]的数字的对应位置标记为1。
        for(int i = 0; i <nums1.size(); i++){
            if(nums1[i] == nums2[0]){
                dp[i][0] = 1;
            }
            res = max(res, dp[i][0]); 
            !这里记得取max。因为res可能会更新。
        }
然后需要在nums2数组里等于nums1[0]的数字的对应位置标记为1
        for(int i = 0; i <nums2.size(); i++){
            if(nums1[0] == nums2[i]){
                dp[0][i] = 1;
            }
            res = max(res, dp[0][i]);
            !这里记得取max。因为res可能会更新。
        }


举例子  nums1 = [1,2,3,2,1]
        nums2 = [3,2,1,4,7]        

dp[i][j]    [1  2   3   2   1]
            0   1   2   3   4
    [3  0   0   0   1   0   0
    2   1   0       *
    1   2   1*
    4   3   0
    7]  4   0   

*标注星号的位置是更新了的值。说白了就是找到数字相等的位置标记成1


?递推公式呢？
我们知道如果第一个数组和第二个数组的第i位相同，就证明这个共同的数组长度加了1
所以我们有dp[i][j] = dp[i-1][j-1]+1 意思就是说我们在到i-1为止和j-1为止的最长字数粗的值基础上+1。
然后每一轮记录最大值就可以
!注意这里数组没有错位，所以不需要-1
*/


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(),0));
        int res = 0;
        for(int i = 0; i <nums1.size(); i++){
            if(nums1[i] == nums2[0]){
                dp[i][0] = 1;
            }
            res = max(res, dp[i][0]);
        }
        for(int i = 0; i <nums2.size(); i++){
            if(nums1[0] == nums2[i]){
                dp[0][i] = 1;
            }
            res = max(res, dp[0][i]);
        }
        for(int i = 1; i < nums1.size(); i++){
            for(int j = 1; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){ //!注意这里数组没有错位，所以不需要-1
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{   //二维数组加不加都可以。一维数组必须加。因为要覆盖值
                    dp[i][j] = 0;
                }
                if(dp[i][j] > res){
                res = dp[i][j];
                }
            }
        }
        return res;

    }
};