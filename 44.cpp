#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
/*
这题核心在于思考三种递推
首先我们需要前导零，因为空串的问题。我们把空串当做字符串的第一个字符是空字符即可。所以字符串的第i个字符下标为i-1
&dp[i][j]意义：从第1个字符到第i个字符的匹配字符串（带*的）和从第1个字符到第j个字符的目标字符串是否可以匹配
&初始化：dp[0][0]为1 因为空串可以匹配
&递推：
& 1: 假如当前字符串p是*，则后面所有的字符都可以被匹配。所以说就是整个 [i][j~end]都是T （往右侧推）
%这里注意一件事。a和a*是可以匹配的。也就是说为什么我们这里可以往下推一格。因为这时候是a匹配a*。*可以匹配空串。所以a可以和a*匹配。所以为T。
todo 所以代码层面的话, 要么是第三个for循环的k从j-1开始推 dp[i][k] = 1;，要么是第三个for循环的k从j开始推，然后单独加一行dp[i][j-1]=1。
        S   j→    
        N   a   b   c   b   e   b
P   N   T   
i↓  a       T
    *       T   T   T   T   T   T
    b
    ?
    b
& 遇到问号，问号只可以匹配一个，相当于遇到啥都是匹配，所以只能往右下角推。也就是如果[i-1][j-1] = 1 并且如果字符是？，则都推一格。
& 单纯的相等，就也是右下角推。




*/

class Solution {
public:
    bool isMatch(string s, string p) {
        s = s + 'a'; //免去匹配空串单独判断
        p = p + 'a';
        vector<vector<int>>dp(p.size() + 1, vector<int>(s.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < p.size() + 1; i++) {
            for (int j = 1; j < s.size() + 1; j++) {

                if (p[i - 1] == '*' && dp[i - 1][j - 1] == 1) { //注意有前导0所以当前的字符串下标要-1 因为有错位。
                    for (int k = j - 1; k < s.size() + 1; k++) { //从j-1开始推，解释过了
                        dp[i][k] = 1;

                    }
                    //dp[i][j-1]=1; 如果从j开始推就要加这个
                }
                else if (p[i - 1] == '?' || s[j - 1] == p[i - 1]) { //如果有字符是问号，或者是字符相等，就往右下角推。也就是之前是啥现在就是啥
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};