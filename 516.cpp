#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题注意初始化的两种情况。也是有两种初始化。含前导0和不含前导0.情况和647差不多懒得写了。这里就是不含前导0。
!回文子串是要连续的，回文子序列可不是连续的。这是回文子序列。不需要连续。
dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。

当字符相同的时候也就是s[i] = s[j] 的时候，我们有两种情况
第一种情况是如果i和j相等了，我们这时候直接让他为1.对应情况就是单个字符。如 a 一个字符。
第二种情况是其他情况。这样的话我们就把前面的范围+1后面的范围-1也就是i+1 j-1 看看里面的这个子字符串是否是回文：
图解：
        a   b   c   b   a
        ↑               ↑
        i               j
        这时候s[i] = s[j]我们将i后移j前移判断子字符串区间是否是回文
        a   b   c   b   a
            ↑       ↑
            i       j
所以我们有dp[i][j] = dp[i+1][j-1] + 2;
?为什么要+2？因为我们dp数组储存的是回文序列长度。我们判断s[i] = s[j]了相当于长度加2了。

当s[i] != s[j]的时候，我们就老样子。先把i往里面缩一位看看不含当前i的回文长度。再把j往里面缩一位看不含当前j的回文长度
所以我们有dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
!注意这道题的return。我们是看整个字符串最大的回文长度。所以起始位置是0 终止位置是s.size()-1

*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // for(int i = 0; i < s.size(); i ++){ //!注意这里 因为我们把i=j的情况放入了递推公式的判断所以不需要初始化。
                                                //!如果我们要放在外面初始化的话，我们下面的j就要是 j=i+1 不能让j和i再相等了。不然会越界。
        //     dp[i][i] = 1;
        // }

        for(int i = s.size()-1; i >=0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[i] == s[j]){
                    if(i == j){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];

    }
};