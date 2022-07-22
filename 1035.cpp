#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题和1143一模一样。
不相交的线也就是判断两个数组保持相对顺序的部分有多少。也就是所谓的最长公共子序列


*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for(int i = 1; i < nums1.size()+1; i++){
            for(int j = 1; j < nums2.size()+1 ;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j]  = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }

        }
        return dp[nums1.size()][nums2.size()];

    }
};