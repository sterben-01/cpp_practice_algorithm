#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题依旧是两种做法。含前导0和不含前导0的。这题含前导0简单一些因为不需要手动初始化第一个。第二种懒得写了。
dp[i][j]的意思是以下标i - 1为结尾的text1，和以下标j - 1为结尾的text2，最长公共子序列长度为dp[i][j]。
!第i个数字的下标是i-1;所以这句话可以翻译成dp[i][j]的意思是到第i个数为止的text1，和到第j个数为止的text2，最长公共子序列长度为dp[i][j]。

?如何初始化？都初始化为0即可。

我们循环i和j要从1开始。因为第0个是没有意义的

?递推公式呢？
我们知道如果第一个数组和第二个数组的第i-1位相同，就证明这个最长公共子序列长度加了1
举个例子：
对于 ab 和 bc而言。他们的最长公共子序列是a和b的最长公共子序列长度(0)+1 = 1
!为什么是i-1？因为我们dp数组含有前导0 所以错位了一位。所以需要减掉1。和小偷系列是一样的
所以我们有dp[i][j] = dp[i-1][j-1]+1 意思就是说我们在到i-1为止和j-1为止的最长公共子序列长度的值基础上+1。

!如果不等于呢？
不等于的时候就是判断[第一个字符串去掉当前这位和第二个字符串包含当前这位]，和[第一个字符串包含当前这位和第二个字符串去掉当前这位]比哪个大
举个例子：
对于ace和acf而言。这时候最后一位不相等。所以他们的公共子序列长度是ace和ac的最长子序列长度2 和ac acf的最长子序列长度2 取最大值即2

也可以长度不等，因为我们是逐个比较 两层for循环

举个例子：
对于ace和bc而言，他们的最长公共弄个子序列长度是ace和b的最长公共子序列长度0 和ce be的最长公共子序列长度1 取最大值 即 1

所以我们有dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for(int i = 1; i < text1.size()+1; i++){
            for(int j = 1; j <text2.size()+1; j++){
                if(text1[i-1] == text2[j-1]){ //注意数组错位需要-1。
                    dp[i][j] = dp[i-1][j-1] + 1; //相等直接+1
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]); //不等就两个字符串分别去掉这位，取最大值。
                }
            }
        }
        return dp[text1.size()][text2.size()];


    }
};