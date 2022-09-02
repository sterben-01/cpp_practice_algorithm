#include <iostream>
#include <vector>
using namespace std;
/*
这是第二种写法
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
            for(int k = 0; k < K; k++){//总之，我们今日如果买入了，一定要和昨天的k差1.所以k从1~k变成0~k-1
                dp[i][0][k+1] = max(dp[i-1][0][k+1], dp[i-1][1][k+1] + prices[i]);
                dp[i][1][k+1] = max(dp[i-1][1][k+1], dp[i-1][0][k] - prices[i]);
            }
        }
        return dp[prices.size()-1][0][K];
    }
};