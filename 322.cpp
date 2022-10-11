#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);//dp[j]含义是凑足金额为j的时候所需的最少硬币数量
        //因为求最小值，所以我们要初始化成一个无法达到的最大值 amount+1即可
        dp[0] = 0; //凑足金额为0的时候不需要硬币所以是0个
        //一位数组初始化我们不需要再看第一行。仅仅需要第一个。二维数组的第一列就是一位数组的第一个
        for(int i = 0; i < coins.size(); i++){
            for(int j = 1; j < amount+1; j++){
                if(coins[i] <= j){//如果放得下
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);//dp[j-nums[i]]+value[i]这个value 如果是求值那就是这个东西的价值。如果是求个数 那就是+1 
                }
            }
        }
        if(dp[amount] > amount){ //如果还是初始化的值，那就说明凑不了 返回-1
            return -1;
        }
        return dp[amount];
    }
};