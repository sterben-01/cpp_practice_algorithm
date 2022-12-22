#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <sstream>
using namespace std;


/*
text 和打家劫舍非常像。我们先看传统办法。
&传统办法：
1. 对原数组排序。这样可以模仿打家劫舍。
2. 使用哈希表统计这个数字出现了几次。
3. 统计后使用unique去重。遍历范围是2~unique返回的迭代器。
dp[i]的意思是到下标为i的的数字的时候累计最大值。具体初始化思路和dp思路和打家劫舍一样。
再次重申一次。dp不要向后思考，要向前思考。要从已知（前）推未知（后）。
比如我当前是i，不能连着拿就是要么 不拿当前的，所以就是当前的和上一个的一样 dp[i] = dp[i-1], 要么就是拿当前的，就是dp[i] = dp[i-1] + nums[i];
4. 初始化。因为不一定是连续的数字，可能会有 1 3 5，所以因为3比1大了2，可以同时拿3和1。所以需要if判断一下是否这个数字只比上一个大了1，如果只大1就是老规矩，如果大了更多就可以都拿
5. 循环。一样不赘述。

*/


class Solutionold {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(), nums.end()); //排序
        vector<int>dp(nums.size());
        unordered_map<int,int> my_map; //哈希
        for(int i = 0; i < nums.size(); i++){
            my_map[nums[i]]++;
        }
        if(nums.size() == 1){
            return my_map[nums[0]] * nums[0];
        }
        int endpos = unique(nums.begin(), nums.end()) - nums.begin(); //去重
        dp[0] = my_map[nums[0]] * nums[0]; //初始化
        if(nums[1] == nums[0]+1){
            dp[1] = max(my_map[nums[0]] * nums[0], my_map[nums[1]] * nums[1]);
        }
        else{
            dp[1] = my_map[nums[0]] * nums[0] + my_map[nums[1]] * nums[1];
        }

        for(int i = 2; i < endpos; i++){
            if(nums[i] == nums[i-1]+1){
                dp[i] = max(dp[i-1], (dp[i-2] + my_map[nums[i]] * nums[i]));
            }
            else{
                dp[i] = dp[i-1] + my_map[nums[i]] * nums[i];
            }
        }
        for(auto j:dp){
            cout << j << endl;
        }
        return dp[endpos-1];
    }
};

/*
&更好的办法
&优化空间在于哈希表和if判断。
我们真的需要那么大的map做哈希表吗？其实不一定。我们可以用哈希数组
加入nums是 2,2,3,3,3,4,5
那么哈希数组就是 0,0,2,3,1,1
下标是数字，下标所在的元素值是出现的次数
比如i = 3，num[3] = 3 代表的是3这个数字在原数组出现了3次。
这样我们省去了一次排序，一次去重和一次unique。相当大的节省！！
更关键的是我们省去了if判断。因为使用哈希数组后，就变得和打家劫舍一模一样了。
!因为一定是连着的0 1 2 3 4。所以偷1一定不能偷0和2，无论0和2是否在原数组出现过。
不需要判断当前数字是什么了。因为如果这个数字没有出现过的话他的元素值为0。那么下标*值就还是0，不会造成影响。因为我们取max。

比如哈希后的数组就是0,0,2,3,1,1。完全变成了打家劫舍的，不能偷相邻的房子。价值就是当前下标*下标元素的值。
dp[i]的意思一样。是到下标为i的的数字的时候累计最大值。具体初始化思路和dp思路和打家劫舍一样。
因为不能偷连着的房子。所以
dp[0] = num[0] * 0 就是偷下标0的房子的价值（为0）
dp[1] = num[1] * 1 就是偷下标1的房子的价值（为1） 

剩下的就是从2开始，偷到maxnum。maxnum就是原数组出现过的最大值。最大是100的话第101位就不可能有用。
具体递推和打家劫舍一样。
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxnum = *max_element(nums.begin(), nums.end());
        vector<int> num(maxnum+1);
        vector<int> dp(maxnum+1);
        for(int i = 0; i < nums.size(); i++){ //哈希数组
            num[nums[i]]++;
        }

        dp[0] = num[0] * 0; 
        dp[1] = num[1] * 1;
        for(int i = 2; i <= maxnum; i++){
            dp[i] = max(dp[i-1], (dp[i-2] + num[i] * i));
        }
        return dp[maxnum];
    }
};