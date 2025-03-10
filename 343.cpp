
#include <vector>
using namespace std;
/*
这个比较有感觉。
dp[i]就是i拆分后的最大乘积。
注意拆出来的需要是正整数，所以不能有0
那么我们初始化就好理解了。0自然是0，1也是0，2只能拆成1+1，所以是1
然后我们从3开始，对于每一个i，我们都要遍历一遍，看看拆成几个数的乘积最大
j就是我们拆出来的数字。从1开始拆。所以对于拆出来的数字我们有俩可能：
第一种可能是拆出来的直接乘。也就是最多拆成俩数字。就是(i-j)*j
另一种可能就是拆出来的数字还能继续拆。dp[i-j]已经是拆分拆出来的数字的最大乘积了，所以这里就是dp[i-j]*j
所以就取max就好了。
为啥还要取第二次max，因为我们dp[i]在每一轮j的时候都会被覆盖。我们要取历史最大值
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){ // 这里是i-1的原因是不能有0。比如i是10, 那么j最大是9，不然就是0了，0不是正整数
                dp[i] = max(dp[i], max(dp[i-j] * j, (i-j) * j));
            }
        }

        return dp[n];
    }
};