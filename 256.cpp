#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
using namespace std;



/*
text 不难理解的dp。个人认为这种dp比较像股票。也就是一个维度是时间，另一个维度是条件。这道题里面的时间就是房子的下标。条件就是刷成什么颜色。
&所以dp[i][j]的含义是粉刷下标i个房子使用下标j个颜色的时候，粉刷从下标0~下标i的房子的最低开销。
dp[0][0]就是给下标 0 个房子刷红色时，粉刷从下标 0 到下标 0 个房子的最低开销是多少？
dp[0][1]就是给下标 0 个房子刷蓝色时，粉刷从下标 0 到下标 0 个房子的最低开销是多少？
dp[0][2]就是给下标 0 个房子刷绿色时，粉刷从下标 0 到下标 0 个房子的最低开销是多少？
dp[1][0]就是给下标 1 个房子刷红色时，粉刷从下标 0 到下标 1 个房子的最低开销是多少？
dp[1][1]就是给下标 1 个房子刷蓝色时，粉刷从下标 0 到下标 1 个房子的最低开销是多少？
dp[1][2]就是给下标 1 个房子刷绿色时，粉刷从下标 0 到下标 1 个房子的最低开销是多少？


&非常自然地，数组不需要前导0。初始化就非常简单。刷第一间房子(下标0)的时候三个颜色的最小开销就是那三个数。
&递推公式也非常直观。三种颜色分开判断，因为颜色不能挨着，所以如果当前刷蓝色，就看上一间房子刷红色和刷绿色哪个便宜然后加上当前房子刷蓝色的花费。最后返回也是三个数字取最小值。
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(3,0));
        for(int i = 0; i < 3; i++){
            dp[0][i] = costs[0][i];
        }
        //0是红，1是绿，2是蓝
        for(int i = 1; i < costs.size(); i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2])+costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2])+costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1])+costs[i][2];
        }
        return min(dp[costs.size()-1][0],min(dp[costs.size()-1][1],dp[costs.size()-1][2]));
    }
};