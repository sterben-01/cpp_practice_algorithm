#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1,0))); //这里加一是为了避免当字符串只有一位的时候要分类讨论。
        //dp的意义是从第0-i个字符串中任选使其中0的数目不超过j，1的数目不超过k
        //这里不用初始化的原因是默认都是0.
        for(int i = 1; i <= strs.size(); i++){
            int countone = findone(strs[i-1]);
            int countzero = findzero(strs[i-1]);
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if( countzero <= j && countone <= k){ //如果放得下
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-countzero][k-countone] + 1); //加1是因为要么加要么不加这个字符。加了就是加1
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k]; //放不下就复制
                    }

                }
            }
        }
        return dp[strs.size()][m][n];
    }


    int findzero(string str){ //查找字符串有几个0
        int count = 0;
        for(char a: str){
            if(a == '0'){
                count++;
            }
        }
        return count;
    }
    int findone(string str){  //查找字符串有几个1
        int count = 0;
        for(char a : str){
            if(a == '1'){
                count++;
            }
        }
        return count;
    }
};