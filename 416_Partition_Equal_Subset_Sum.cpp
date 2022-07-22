#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*

[1,5,11,5]

背包重量(和)j→      0   1   2   3   4   ... 11
数组编号    i↓  0   F   T   F   F   F       F

                1   F   ...

                2   F   ...
                
                3   F   ...

                4   F   ...
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }
        if(sum %2 != 0){
            return false;
        }
        int bagweight = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(bagweight+1,false));
        if(nums[0] <= bagweight){ //如果第一个数背包放得下
            dp[0][nums[0]] = true; //从前1个数任取0-1个数，和为背包容积，那么只有背包容积为他自己的背包符合条件。
        }
        for(int i = 0; i < nums.size(); i++){ //可以不写。第一列都是false 因为背包容积为0
            dp[i][0] = false;
        }
        // for(int i = 0; i < nums.size(); i++){ 打印
        //    for(int j = 0; j < bagweight+1; j++){
        //        cout << dp[i][j];
        //    }
        //    cout <<endl;
        // }
        //注意ij 不要写反。外层是物品，内层是容量。意思是对编号为i的物品遍历0-j的容量。所以是先遍历容量。（和写法相反因为是内层先执行完毕）
        for(int i = 1; i < nums.size(); i++){ //i j不要写反。遍历物品
            for(int j = 1; j < bagweight+1; j++){ //遍历容量
                if(nums[i] > j){ //如果放不下
                    dp[i][j] = dp[i-1][j]; //直接拷贝
                }
                else{ //如果放得下
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]; //不加nums[i] 因为我们这儿是true false 不用统计具体是几。 这俩有一个是true就行。
                }
            }
        }
        return dp[nums.size()-1][bagweight]; //return最右下角的就可以。原理是如果我已经能从数组中找到几个数的和为整个数组和的一半了，那么数组剩下的数也一定等于数组和的一半。
    }
};