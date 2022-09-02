#include <iostream>
#include <vector>
using namespace std;

/*

本题套用了模板。也就是最多可以完成k笔交易
!注意此处大小是size，没有前导0
数组dp[i][j][k] 的含义是 到第i天为止，持股状态为j，交易了k次的时候的利润
所以我们有i的大小是size。
j的大小是2
k的大小是k+1 要+1的原因是0-k一共是k+1个数


我们可以缩减空间。也就是k的大小要么是k本身，要么是size/2 因为每次买卖都是需要两天。说白了就是交易次数如果比你的数组一半还要大，那么多出来的交易次数是用不到的。所以可以去掉

我们可以发现第0天的时候，交易利润和几轮无关。我们持股状态是0也就是不持股的时候就是0 持股状态是1也就是买入的时候就是-price[0]。


*/




class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int size = prices.size();
        int K = min(k, size/2);
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(K+1,0)));

        for(int i = 0; i < K+1; i++){
            dp[0][0][i] = 0;
            dp[0][1][i] = -prices[0];
        }
        for(int i = 1; i < prices.size(); i++){
            for(int k = 1; k < K+1; k++){//我们一定要记住。买入的时候k会+1.也就是如果今天买入了，那么我今天的k和昨天的k一定要差1.我们这里用的是今天是k昨天是k-1的写法
                dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k] + prices[i]);  //今日不持股 昨日不持股和昨天持股也就是今天卖出取最大值
                dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k-1] - prices[i]);//今日持股。昨日持股和昨日不持股也就是今日买入取最大值
                //注意这里是k-1 为什么要-1 因为我们今日交易次数是k 所以昨天就要-1
            }
        }
        return dp[prices.size()-1][0][K];
    }
};