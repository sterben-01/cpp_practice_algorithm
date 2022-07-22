#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*这题也是两种方法。含有前导0和不含前导0。这里是不前导0的解法。
!回文子串是要连续的，回文子序列可不是连续的。
这里是回文子串，需要连续。
这里的dp数组是bool类型的
dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
所以我们有如下情况
当s[i] != s[j] 的时候，那就是false
如果相等有四种情况：
TODO:a (j-i = 0) 或者 aa(j-i = 1) 或者 aba(j-i = 2) 这时候就是true
TODO: cabac 这时候cc相等就前面往后挪一位后面往前挪一位看是不是回文 即 aba是不是。

?如何初始化？
全部是false。当然我们也可以手动初始化一遍。但是我们是从后往前遍历的。所以也不用特殊操作
!注意遍历顺序是从后往前。因为我们需要用dp[i+1][j-1]这个状态来判断dp[i][j]是不是回文。所以是先有了i+1才有i。
!注意循环次序。外侧的i是起始位置。从尾向头。内部的j是终止位置，从i到尾。
*/
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        
        for(int i = s.size() - 1; i >=0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{ //s[i] == s[j]
                    if(j - i <= 2){ 
                        dp[i][j] = true;
                        res++;
                    }
                    else if(dp[i+1][j-1] == true){
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;

    }
};