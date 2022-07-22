#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
/*
此题基本逻辑和62题一样。但是有很多注意的地方。
第一点是数会非常大，所以要用long long
第二点是关于障碍。我们不能像上一题一样将最下面一行和最后面一列都设置为1，假设有一个是障碍物，那么它的上面就应该全是0.过不去了
                     m-1 m→
    ————————————————————
    |   |   |   |   | 0 |
    ————————————————————
    |   |   |   |   | x |
    ————————————————————
    |   |   |   |   | 1 |
    ————————————————————
n-1 | 0 | 0 | x | 1 | 1 |  x位置是障碍物。我们可以知道，最右一列里所有障碍物上方的都是0.因为只能向下或者向右走。有障碍物就没法越过去，所以一定是0
n↓  ————————————————————    最下一行同理。只能向下和向右，所以最下一行障碍物左侧的都是0
*/
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n)); //数据很大，设置为longlong
        if(obstacleGrid[m-1][n-1] == 1){ //如果右下角是障碍，直接返回0
            return 0;
        }
        for(int i = m-1; i >=0; i--){ //因为是从终点开始算，遇到障碍物的时候障碍物的上方都是0，所以要从尾部开始（m-1)而不是从头部开始（0）
            if(obstacleGrid[i][n-1] == 0 ){//如果不是障碍物，就是1
                dp[i][n-1] = 1;
            }
            else{
                break;//是障碍物了直接break，因为vetor默认初始化全部元素都是0.从下往上遇到障碍物了直接停止赋值，剩下的都是0
            }
        }
        for(int i = n-1; i >=0; i--){ //因为是从终点开始算，遇到障碍物的时候障碍物的左方都是0，所以要从尾部开始（n-1)而不是从头部开始（0）
            if(obstacleGrid[m-1][i] == 0){
                dp[m-1][i] = 1;
            }
            else{
                break;//是障碍物了直接break，因为vetor默认初始化全部元素都是0.从右往左遇到障碍物了直接停止赋值，剩下的都是0
            }
        }
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                if(obstacleGrid[i][j] == 0){ //这里也要判断是不是障碍。如果当前不是障碍物就是1
                    dp[i][j] = dp[i][j+1] + dp[i+1][j]; //和62一样的递推公式
                }
                else{
                    dp[i][j] = 0;   //这里也要判断是不是障碍，如果当前是障碍物那就是0
                }
            }
        }
        for(int x = 0; x < dp.size(); x++){
            for(int y = 0; y < dp[0].size(); y++){
                cout << dp[x][y];
            }
            cout << endl;
        }
        return dp[0][0];


    }
};