#include <iostream>
#include <vector>
using namespace std;

/*
*还是两种方法。带前导0和不带前导0.这里是带前导0的解法。
股票系列的关键在于明白dp数组的含义。
我们这里dp[i][j]的含义是 到第i的那一天为止,持股状态为j的时候我们持有的最大现金数。
!注意这里我们初始化数组是size+1不是size。所以是第i天。
j有两种状态。一种是当天不持股。j=0
一种是当天持股 j=1
因为我们只能买一次，所以我们假定我们的最大现金就是刚好够我们买某一天的股票的金额。
所以买完了，当天的金额就是负的当天股票金额也就是-price[i-1] 注意带前导零数组会窜位。所以需要prices[i-1]

dp[0][0] = 0 第0天不持股无意义
dp[0][1] = 0 第0天持股无意义
dp[1][1] = 0 第一天持股
dp[1][1] = -prices[0] 第一天持股因为购买了股票所以现金数是负的。所以是负的股票价值. 注意带前导零数组会窜位。所以需要prices[i-1]

*之后有两种情况。分别是今天持股和今天不持股
今天持股，前一天持股，不变。dp[i][1] = dp[i-1][1]
今天持股，前一天不持股，意思就是买入股票。现金等于股票金额相反数。所以dp[i][1] = -price[i-1] 注意带前导零数组会窜位。所以需要prices[i-1]
取max 所以有dp[i][1] = max(dp[i-1][1], -price[i-1])

今天不持股，前一天不持股。不变。dp[i][0] = dp[i-1][0]
今天不持股，前一天持股，意思就是卖掉了所以要加上今日股票价格。所以dp[i][0] = dp[i-1][1]+price[i-1]
                                                          ↑今天        ↑前一天

取max 所以有dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i-1])                                                       

*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <2){
            return 0;
        }

        vector<vector<int>> dp (prices.size()+1, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = -prices[0];

        for(int i = 2; i < prices.size()+1; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(-prices[i-1], dp[i-1][1]);
        }
        return dp[prices.size()][0];
    }
};