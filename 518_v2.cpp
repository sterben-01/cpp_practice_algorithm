#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
这道题有V1和V2两种二维数组解法。这里是V2。
首先，DP使用二维数组的时候一般会有两种初始化想法。第一种是数组size+1。另一种是数组size。
数组size的时候 dp[i][j]里面 i的意思是从数组下标第0到第i个取。所以不存在取空的情况 
这里就很复杂，不仅要看第一列的初始化情况，而且需要对第一个数进行判断也就是第一行。
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0));
        if(coins[0] <= amount){ //如果第一个数可以放进背包
            /*
            根据本题的意思。这里需要说明。假如硬币数组是[2,5,10]。amount是10。
            我们数组第一个数是2
            这里数组应该是这样
            0   1   2   3   4   5   6   7   8   9   10

coins[0]2   1   0   1   0   1   0   1   0   1   0   1

coins[1]5   1    ...

coins[2]10  1    ...
            为什么是这样呢数组dp[i][j]的意思是 从第下标为0-i个数字任取任意个能组合成值恰好为j的组合种类数。
            这里是组合种类数。
            当物品只有2的时候   能组合成和为0有一种。就是不取。也就是0x2
                                能组合成和为1有零种。
                                能组合成和为2有一种。1x2
                                能组合成和为3有零种。
                                能组合成和为4有一种。2x2
                                ...
            我们发现。从大小为自己本身的时候，自己本身可以刚好放进容量为自己本身的背包。
            同时因为可以重复取，我们大于自己本身的时候都应该考虑初始值。
            但是注意，这道题是 恰好 和为amount的时候。注意是恰好。如果是小于或者大于这种非恰好题目，后面的就需要另一种考虑方式了
            但是这道题是恰好。所以只有容量是自己或者自己的倍数的时候，才能有方法让和恰好为amount
            这里注意是组合数量。和为10的时候数组不是5.因为硬币只有两元的，我想要凑够10元只有拿5个两元硬币的这一种方法。所以这里是1


            */
            for(int i = coins[0]; i < amount+1; i++){ //从最大容量为第一个数开始

                if(i % coins[0] == 0){ //如果可以被自己整除

                    dp[0][i] = 1; //有一种方法
                }
                else{
                    dp[0][i] = 0;
                }

            }
        }
        for(int i = 0; i < coins.size(); i++){ //第一列统一有一种方法
            dp[i][0] = 1;
        }  
        for(int i = 1; i < coins.size(); i++){
            for(int j = 0; j < amount+1; j++){
                if(coins[i] > j){ //如果放不下
                    dp[i][j] = dp[i-1][j]; //上一个值拿来用

                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]; //老样子 注意这里是i不是i-1 V1已经说过了这里不赘述了
                }
            }
        }
        for(int a = 0; a < coins.size(); a++){ //打印
            for(int b = 0; b < amount+1; b++){
                cout << dp[a][b];
            }
            cout << endl;
        }
        return dp[coins.size()-1][amount];

    }
};