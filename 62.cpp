#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m)); // 二维数组是vector的嵌套容器，而不是vector<int,int>。没有vector<int,int>这种东西，vector是塞单个元素的。
        //所以你可以vector<pair<int,int>>。 但是这样的话列数就固定为2了。所以你只能vector<vector<int>>进行嵌套初始化
        // 这里初始化的意思是把dp这个嵌套vector 用n个vector<int>(m)初始化。vector<int>(m)是初始化一个vector size为m。
        //换句话说，就是n个size为m的vector [[size m],[size m],[size m],...]
        //                              ↑ 一共n个
        /*             m→
            [   [size m] 
                [size m]    n↓
                [size m]    
                [size m]  
                [size m] 
            ]
        */



        for(int i = 0;i<n; i++){ //分开写for 初始化-列
            dp[i][m-1] = 1;
        }
        for(int i = 0; i < m; i++){//分开写for 初始化/列
            dp[n-1][i] = 1;
        }
        for(int i = n-2;i>=0;i--){
            for(int j = m-2; j>=0; j--){
                dp[i][j] = dp[i][j+1] + dp[i+1][j]; //递推公式。从尾部开始走的都用+号 因为尾部是已知.
            }
        }
        return dp[0][0];
    }
};


/*
这道题首先注意限制。只能往下或者往右走，不能往上往左或者斜着走。
所以我们能得到这样一张图
                     m-1 m→
    ————————————————————
    |   |   |   |   | - |
    ————————————————————
    |   |   |   |   | - |
    ————————————————————
    |   |   |   | * | - |
    ————————————————————
n-1 | / | / | / | / | + |  +号位置是m,n 但注意一下，数组的最后一个是index-1 所以题目里m其实是m-1 n是n-1 要对应-1
n↓  ————————————————————
    所有/号标记的位置都是固定的，因为他们都只有一种走法。就是向右走。所以dp[0~m-1][n-1] 都是1
    所有-号标记的位置都是固定的，因为他们都只有一种走法。就是向下走。所以dp[0~n-1][m-1] 都是1
    数组长度是m 但是下标最后是m-1
    数组长度是n 但是下标最后是n-1
    我们由此可得，*的位置是由他右面的-和他下面的/的位置倒推出来的。所以公式是
    dp[m-2][n-2] = + dp[m-2][n-1](/位置) + dp[m-1][n-2](-位置)
    但是我们的递推公式需要dp[i][j]的（dp[m][n])
    所以所有位置同时+2，可得
    dp[m][n] = dp[m][n+1] + dp[m+1][n]，但是不能这么用。
    也就是
    dp[i][j] = dp[i][j+1] + dp[i+1][j];

*/