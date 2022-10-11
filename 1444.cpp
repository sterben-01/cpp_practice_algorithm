#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <bitset>
#include <stack>
using namespace std;


/*
text 字节跳动北美题。3维dp+逆向的前缀和（从右下角到左上角）
动态规划

&定义
    %dp[i][j][k] 表示以i，j为左上角，m-1,n-1为右下角（固定），切k刀的方案数。那么对于K的份数，就是切K-1刀

&初始化
    %dp[i][j][0]=1 即不切任何一刀为1，但是前提是需要里面以i,j为左上角的范围内至少有一个苹果
    *意思就是最下角的那个地方，一开始如果没有苹果，那就没法切，方案结果就是0。如果有苹果，那就只有一种切法就是切0刀。方案就是1

&计算
    %辅助 cnt[i][j] 表示以i，j为左上角的苹果的数量
        *我们需要快速知道范围内苹果的数量，所以使用一个二维前缀和和记录范围内苹果的数量
        *这个数量也会帮助我们计算这个范围内是否可以切一刀（至少有一个苹果就可以）。计算就是从右下角开始计算即可，二维前缀和
    %d[i][j][k] 计算
        *初始值，即d[i][j][0]=1 (cnt[i][j] > 0)
        *考虑两种切法，横向和纵向，只要之间有差值就可以切
            @x轴：sum_over_x(d[x][j][k-1])，需要满足 cnt[i][j]-cnt[x][j] > 0 即至少有苹果
            @y轴：sum_over_y(d[i][y][k-1])，需要满足 cnt[i][j]-cnt[i][y] > 0 即至少有苹果
        *把各种切的情况累加在一起
&结果
    %d[0][0][K-1]


todo 计算前缀和注意事项

.   .   .

.   A   A

.   A   A
假设上面为初始数组。我们计算前缀和 则
*为未计算部分。
第一次：
*   *   *

*   *   *

*   *   1

------------------
第二次，向左计算
*   *   *

*   *   *

*   2   1

-----------------
第三次，向左计算
*   *   *

*   *   *

2   2   1
------------------
第四次 向上计算
*   *   *

*   *   2

2   2   1
&------------------
&第五次，向左计算
*   *   *

*   4   2

2   2   1


&这里就是关键点。这里我们当前4位置的前缀和应该是右侧+下侧-右下角。不然的话会变成2+2+自己当前的1 = 5。所以我们应该是2+2+1-1 = 4。


*/


class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>> apple_sum(pizza.size(), vector<int>(pizza[0].size(), 0));
        for(int i = pizza.size()-1; i >= 0; i--){
            for(int j = pizza[0].size()-1; j>=0; j--){

                if(pizza[i][j] == 'A'){
                    apple_sum[i][j] = 1;
                }
                if(i == pizza.size()-1 && j == pizza[0].size()-1){
                    continue; //最右下角已经初始化。
                }
                else if(i == pizza.size()-1){
                    apple_sum[i][j]+= apple_sum[i][j+1]; //在最下面一行
                }
                else if(j == pizza[0].size()-1){
                    apple_sum[i][j]+= apple_sum[i+1][j]; //在最右面一行
                }
                else{
                    apple_sum[i][j]+= apple_sum[i][j+1] + apple_sum[i+1][j] - apple_sum[i+1][j+1]; //需要减掉右下角重复计算的部分。一会会有说明。
                }
            }
        }

        int base = 1000000007;
        vector<vector<vector<int>>> dp(pizza.size(),(vector<vector<int>>(pizza[0].size(), vector<int>(k,0))));
        for(int i = pizza.size()-1; i >= 0; i--){
            for(int j = pizza[0].size()-1; j>=0; j--){
                if(apple_sum[i][j] > 0){ //初始化。看右下角有没有苹果，没有就是0，有就是1
                    dp[i][j][0] = 1;
                }
                for(int cut = 1; cut < k; cut++){
                    for(int x = i+1; x <= pizza.size()-1; x++){ //按照x轴切
                        if(apple_sum[i][j] - apple_sum[x][j] > 0){
                            dp[i][j][cut] = (dp[i][j][cut] + dp[x][j][cut-1]) % base;
                        }
                    }
                    for(int y = j+1; y <= pizza[0].size()-1; y++){ //按照y轴切
                        if(apple_sum[i][j] - apple_sum[i][y] > 0){
                            dp[i][j][cut] = (dp[i][j][cut] + dp[i][y][cut-1]) % base;

                        }
                    }
                }
            }
        }
        return dp[0][0][k-1] % base;
    }
};