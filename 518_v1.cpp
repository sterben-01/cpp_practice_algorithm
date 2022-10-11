#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
这道题有V1和V2两种二维数组解法。这里是V1。
首先，DP使用二维数组的时候一般会有两种初始化想法。第一种是数组size+1。另一种是数组size。
数组size+1的时候 dp[i][j]里面 i的意思是从第0个到第i个。所以会有第0个的情况，也就是空的情况
所以这时候初始化非常简单。第一行全是0仅仅需要考虑第一列的特殊情况。
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, 0)); //dp[i][j]的意思是从第0-i个数字任取任意个能组合成值恰好为j的组合种类数。
        for(int i = 0; i < coins.size()+1; i++){ //第一列特殊情况。就是从第0-i个任取，组成和为0的情况都是1。因为可以不取。（取空=第0个）
            dp[i][0] = 1;
        }
        for(int i = 1; i < coins.size()+1; i++){
            for(int j = 1; j < amount+1; j++){
                if(coins[i-1] > j){ //如果放不下 注意这里是i-1 因为i是从1开始不是从0开始不然会越界。但是硬币要从第一个开始也就是index=0开始 所以要i-1
                //如果不好理解的话可以看下面的
                    dp[i][j] = dp[i-1][j]; //不取的话就是上一个值直接拉过来。

                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]; //可以看下面那块的注释
                    //这道题是完全背包，可以重复取值。01背包是i-1因为物品i取完了不能再取所以要看i-1。但是这里i还可以再取所以就从i自己开始。
                    //因为是求组合数。看dp_note.cpp文件的注释。
                    //dp[i-1][j]是不拿。也就是看从之前的硬币中想凑齐值为j的组合有多少种。
                    //然后因为我们想拿这个硬币。那么假如和为10，当前硬币为5.因为我们无论如何都想拿，那么我们就要看剩下的硬币中凑齐10-5 = 5的时候有多少种
                    //注意，这里因为每一种硬币无限多。所以我们是可以拿了当前硬币后再拿当前硬币的。所以就是从0~i中看而不是i-1。
                }
            }
        }
/* 不好理解看这里
        for(int i = 1; i < coins.size()+1; i++){
            int coin = coins[i-1]; //要从硬币数组的第1个开始 也就是index0
            for(int j = 1; j < amount+1; j++){
                if(coin > j){  //如果放不下
                    dp[i][j] = dp[i-1][j];

                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coin]; //这里就好理解了。是背包总容积j减去当前物品（硬币）的重量也就是coin 所以是j-coin
                    但是注意。这道题是完全背包，可以重复取值。01背包是i-1因为物品i取完了不能再取所以要看i-1。但是这里i还可以再取所以就从i自己开始。
                }
            }
        }
*/
        for(int a = 0; a < coins.size()+1; a++){ //打印
            for(int b = 0; b < amount+1; b++){
                cout << dp[a][b];
            }
            cout << endl;
        }
        return dp[coins.size()][amount];

    }
};