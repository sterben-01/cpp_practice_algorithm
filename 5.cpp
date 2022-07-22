#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
#include <memory>
using namespace std;

/*
text 每日思考：总有比自己牛逼的人，时刻保持谦逊，时刻学习。
这题和647挺像的。
一个道理 我们假设是abcdbdc
dp[i][j]的意思是从下标为i开始到j结束的子字符串是否是回文。
首先对角线，也就是单个字符串 也就是1开始1结束 2开始2结束的这种单个字符都是回文 初始化为true
&我们要从后往前遍历，注意我们的遍历顺序是
cc
dd,dc
bb,bd,bdc
dd,db,dbd,dbdc
cc,cd,cdb,cdbd,cdbdc
bb,bc,bcd,bcdb,bcdbd,bcdbdc
也就是
66
55 56
44 45 46
33 34 35 36
22 23 24 25 26
11 12 13 14 15 16
&因为我们是判断i和j相等不相等。如果i和j字符一样，就看里面那一段，也即是i+1,j-1这一段是不是回文。
&所以我们从后往前遍历。这样可以保证我们i+1 j-1是遍历过的。因为我们i从大到小遍历的。
!注意我们不断往左移动的是i，j仅仅是作为遍历，从i开始往右侧移动。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        string result;
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));
        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true; //对角线初始化为true。因为单个字符
        }
        int maxLen = 0;
        int beginIndex = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    if(j-i <= 2){ //字符相等的时候，如果下标差小于等于2 则直接true 比如 bb（下标差1） bab(下标差2)
                        dp[i][j] = true;
                    }
                    else if(dp[i+1][j-1] == true) { //如果下标差大于2，看里面那段也就是i+1 j-1是不是回文
                        dp[i][j] = true;
                    }
                    if(dp[i][j] && j - i + 1 > maxLen) { //记录最大值
                        maxLen = j - i + 1;
                        beginIndex = i;
                    }
                }
                //初始化数组的时候已经默认false了。不等的时候直接略过
            }
        }
        result = s.substr(beginIndex,maxLen); //截取
        return result;
    }
};
