#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        这道题是查找次数不是值。注意这点。
        通过观察可以得出可以将数组的数字分为两部分。第一部分相加全都做为加法部分，第二部分相加全都做为减法部分
        1 1 1 1 1
        + + + - -
        所以假设第一部分是前三个一。和为3。 第二部分为后两个1，和为2。注意这里的和是不带加减号的。所以后两个的和不是-2而是2。
        我们让相加的部分和是pos，相减的部分和为neg
        我们发现pos+neg = total 这里就是3+2=5
        pos - neg = target 这里就是 3-2=1;
        所以我们有
        pos + neg = total
        pos - neg = target
        可以有
        pos+neg+pos-neg = total + target
        2pos = total+target
        pos = (total+target)/2
        ----------
        pos + neg - pos + neg = total - target
        2neg = total - target
        neg = (total-target)/2
        */
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total = total + nums[i];
        }
        if(abs(total) < abs(target)){ //如果和都小于target那肯定不行。
            return 0;
        }
        if((total+target)%2 != 0){ //5个1肯定凑不出来6。也就是总和 和 target奇偶性不一致的话也不行。
            return 0;
        }

        int pos = (total+target)/2;
        int neg = (total-target)/2;
        int bagweight = min(pos,neg); // 二者取最小。不写也可以主要是节省空间
        vector<vector<int>> dp(nums.size(), vector<int>(bagweight+1, 0));
        //dp[i][j]意义。从下标为0-i的数中间任取，相加或相减满足和为j有几种方法。
        //相加就相当于放入加法部分，相减就相当于放入减法部分。
        /*
        这里2者取最小的原因是，如果我放入加法堆里，那么加法堆的和最大为3，如果我放入减法堆，减法堆的和最大为2。所以我们只需要取一个最小的就能知道另一个是多少了。
        */

        //!下面这个条件也就是能放得进去。因为bagweight说白了就是我们需要的和为几。假设bagweight为2，如果第一个数就是3了那已经太大了。就已经不能满足条件了就不行了。
        if(nums[0] <= bagweight){ //如果能放的进去。
            dp[0][nums[0]] = 1; //下标为0的数如果能放得下，那么满足的只能是他自己。比如第一个数是5那么只有和为5能满足有一种方法
        }

        for(int i = 0; i < nums.size();i++){ //这里是看和为0的情况。任取任何数和为0的时候都有至少一种情况，也就是不拿这个数字。
            dp[i][0] = dp[i][0] + 1;
            //这里的意思是
            //这里不可以写成dp[i][0] = dp[1]
            //这里是特殊情况。当第一位不是0的时候 比如[1,0,0,0]可以正常运行因为没有重复初始化。
            //当第一位是0的时候比如[0,0,0,1].这里我上面第一行初始化的时候dp[0][0] = 1;然后又在这块第一列初始化的时候dp[0][0] = 1; 
            //这样的话这里其实本来应该是2。但是重复初始化变成了1.所以我们这里采用累加的方式防止重复初始化。
            //!意思就是。当我从下标为0到0数中任取让和为0的时候，如果我的下标为0也就是数组中的第一个数等于0的时候。我有要么是取要么是不取两种方法。所以第一个数为0的时候dp[0][0]应该为2。
        }
        /*
        if(nums[0] == 0){
            dp[0][0] = 2;       这么写是一样的。将第一位数是不是0单独判断。
        }
        else{
            dp[0][0] = 1;
        }
        */
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j <= bagweight; j++){
                if(nums[i] > j){ //放不下，那就只能不拿。也就是保持之前的种类数量。
                    dp[i][j] = dp[i-1][j];
                    
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]; //递推公式 这里不加nums[i] 是因为我们统计的是方法不是具体数值。这里j-nums[i]一定不能换成i-1或者i+1
                }
            }
        }
        // 打印
        // for(int i = 0; i < nums.size(); i++){ 
        //     for(int j = 0; j <= bagweight; j++){
        //         cout << dp[i][j];
        //     }
        //     cout << endl;
        // }
        return dp[nums.size()-1][bagweight];



    }
};