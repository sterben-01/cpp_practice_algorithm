#include <iostream>
#include <vector>
using namespace std;

/*
*还是两种方法。带前导0和不带前导0.这里是带前导0的解法。
不过多赘述了。和121都一样。惟一的区别是可以买卖多次。可以买卖多次意味着我们可能会有之前卖出的利润。意味着身上会有多的钱。
之前只能买买一次的时候，买股票一定是-prices[i-1]。因为不可能有之前利润。
现在可以买卖多次了，买股票应该是当前手里的金额—prices[i-1]。
所以惟一的区别就是今天持股昨天不持股的时候，dp[i-1][0] - prices[i-1]需要用当前剩下的钱减掉股票的钱。

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,0));

        dp[0][0] = 0;
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[1][1] = -prices[0];

        for(int i = 2; i < prices.size()+1; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]); //唯一区别
        }
        return dp[prices.size()][0];
    }
};