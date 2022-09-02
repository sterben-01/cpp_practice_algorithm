#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
#include <mutex>
using namespace std;


/*
&这题的dp数组定义应该是 从0,0开始到i+1,j+1为止，（我们以i+1,j+1这个点为要求的正方形右下角的点），在这个矩形区域内，在以i+1,j+1为右下角的端点所能构成的正方形中，最大的正方形的边长。
%这个定义有两个注意事项。第一是必须以i+1,j+1为右下角端点。而且是这个区域的最大值，不是全局最大值
& 老规矩，+1是加了前导0，不用处理边界。

输入数组：
0 0 0 0 0 0
0 1 0 1 0 0
0 1 0 1 1 1
0 1 1 1 1 1
0 1 0 0 1 0

dp数组：
0 0 0 0 0 0 
0 1 0 1 0 0 
0 1 0 1 1 1 
0 1 1 1 2 2 
0 1 0 0 1 0 

todo 我们要知道，这里每一位是以这一位为右下角的点的区域内的以右下角为点的正方形的最大边长。不是全局最大值
反例在这呢：

输入数组：
0 0 0 0 0 0
0 1 0 1 0 0
0 1 1 1 1 1
0 1 1 1 1 1
0 1 1 1 1 0

dp数组：
0 0 0 0 0 0 
0 1 0 1 0 0 
0 1 1 1 1 1 
0 1 2 2 2 2 
0 1 2 3 3 0 
todo 这个例子很明显了吧，不是全局的最大值。

&第二个注意的点，我们只有当前字符为1的时候才判断。因为是0的话判断没有意义。
&第三个是递推公式 为什么是dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
前提条件是当前字符是1。我们还以这个点为右下角的端点。也就是这个正方形多大就看他的上面，左边和左上角这三个值，找到最小值之后+1也就是加上自己这个就行。
为什么要最小值？因为如果有一个地方是0那么这正方形就断了。肯定要找最小值。
!动态规划不要上来就考虑比如：怎么确保是正方形，怎么记录之类的。动态规划是分解子问题。为什么叫递推？对吧。我们只需要思考基本的就行。管他当前区域内是不是正方形。我们只关心当前点的上边，左边和左上角是什么就行。


*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int maxres = 0;
        for(int i = 1; i < matrix.size() + 1; i++){
            for(int j = 1; j < matrix[0].size()+1; j++){
                if(matrix[i-1][j-1] == '1'){//有错位所以-1

                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1; //左上角，左侧和上侧的最小值+1
                    maxres = max(maxres, dp[i][j]); //记录全局最大值
                }
            }
        }
        for(auto i:dp){
            for(auto j:i){
                cout << j << " ";
            }
            cout << endl;
        }
        return maxres * maxres;

    }
};