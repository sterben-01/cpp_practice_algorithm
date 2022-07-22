#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题依旧是两种做法。含前导0和不含前导0的。这题含前导0简单一些因为不需要手动初始化第一个。这里是含前导0 nums.size()+1
dp[i][j]的意思是以下标i - 1为结尾的nums1，和以下标j - 1为结尾的nums2，最长重复子数组长度为dp[i][j]。
!第i个数字的下标是i-1;所以这句话可以翻译成dp[i][j]的意思是到第i个数为止的nums1，和到第j个数为止的nums2，最长重复子数组长度为dp[i][j]。

?如何初始化？都初始化为0即可。

我们循环i和j要从1开始。因为第0个是没有意义的

?递推公式呢？
我们知道如果第一个数组和第二个数组的第i-1位相同，就证明这个共同的数组长度加了1
!为什么是i-1？因为我们dp数组含有前导0 所以错位了一位。所以需要减掉1。和小偷系列是一样的
所以我们有dp[i][j] = dp[i-1][j-1]+1 意思就是说我们在到i-1为止和j-1为止的最长字数粗的值基础上+1。
然后每一轮记录最大值就可以


*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));
        int res = 0;
        for(int i = 1; i < nums1.size()+1; i++){
            for(int j = 1; j < nums2.size()+1; j++){
                if(nums1[i-1] == nums2[j-1]){ //数组错位。-1
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{ //二维数组加不加都可以。一维数组必须加。因为要覆盖值
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

