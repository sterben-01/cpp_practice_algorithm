#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
本题和上一题等和子集思路基本一致。难点在于发现这题可以用01背包做。
核心算法是平分石头的总重量，然后让两堆石头的重量尽可能小
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i = 0; i < stones.size(); i++){
            sum = sum + stones[i];
        }
        int rawsum = sum;
        sum = sum/2; 
        vector<vector<int>> dp(stones.size(), vector<int>(sum+1,0)); //dp[i][j]含义:从下标为0~i的范围内任取石头满足重量为j
        if(stones[0] <= sum){
            for(int i = stones[0]; i <= sum; i++){
                dp[0][i] = stones[0]; //这里需要注意。上一道题等和子集是“恰好相等” 所以上一道题只能初始化恰好相等的
                //这道题是传统的01背包。所以是只要能放的进去我就放进去。所以这里第1行就是只要物品重量小于限制（可以放进背包），我就让重量等于那个数。
            }
        }
        for(int i = 1; i < stones.size(); i++){
            for (int j = 1; j < sum+1; j++){
                if(stones[i] <= j){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]]+stones[i]); //递推公式。这里和传统01背包一样。加了石头重量。理论在01背包基本思想里说过了不赘述了。
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout <<dp[stones.size()-1][sum] <<endl;
        return rawsum - dp[stones.size()-1][sum] - dp[stones.size()-1][sum];  //这里是这样。总重量减掉这一堆的重量，剩下的再和另外一堆的重量相减。差就是结果。
    }
};