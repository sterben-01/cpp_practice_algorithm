#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题和1143相似度很高。含前导0和不含前导0的。这题含前导0简单一些因为不需要手动初始化第一个。第二种懒得写了。注意含有前导0会数组错位记得-1
1143最长子序列我们是双相判断，既要判断字符串1是不是2的子序列，也要看2是不是1的子序列
!dp[i][j]表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
这样才有了当这一位不相等的时候，dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 这样的取最大值。
!这道题是判断子序列。我们仅仅是判断字符串1(s)是不是字符串2(t)的子序列。我们不需要反过来看
所以在当前这位不相等的时候，我们仅仅需要dp[i][j] = dp[i][j-1]即可
为什么是i 和j-1呢？1143的笔记写过了。我们可以理解为删除掉t的这位然后看s和t剩下的部分的最大子串是几
举个例子：
ace和acf相比，这时候最后一位不相等。所以去掉f。ace和ac的最大子串是ac是2。

!等到最后了我们就看最后一位也就是s比到t最后的时候长度是不是等于s的长度。
怎么理解呢？就是我们s是abc t是ahfbdhc。我们一轮一轮比，当前位不等的时候我们就看去掉这位的公共子串长度(理解为删掉t不等于的部分)
最后比完了，如果t包含s，那么长度一定是等于s的。因为不等的都删没了。
所以有
if(dp[s.size()][t.size()] == s.size())
{
    return true;
}

*/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp (s.size()+1, vector<int>(t.size()+1,0)); //含有前导0

        for(int i = 1; i < s.size() + 1; i++){
            for(int j = 1; j < t.size() + 1; j++){
                if(s[i-1] == t[j-1]){ //注意数组错位
                    dp[i][j] = dp[i-1][j-1] + 1; 
                }
                else{
                    dp[i][j] = dp[i][j-1]; //只需要单向判断是否含有子串，
                }
            }

        }
        if(dp[s.size()][t.size()] == s.size()){
                return true;
        }
        return false;

    }
};