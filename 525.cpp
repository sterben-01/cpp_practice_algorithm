#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
text 前缀和 参考523。
这道题最难以理解的地方还是，哈希表内为什么还是 key是前缀和，value是index？
&我们通过题意可以让当前num的数是0的时候-1， 是1的时候+1。这样当0和1出现次数相同的时候前缀和刚好为0。
如果我们能在哈希表中找到当前的 accumu 值, 则取出对应的 pos, 在看当前的 index - pos 是否比 maxret 大, 取其中的最优解。
&为什么我们要去哈希表中找当前的前缀和呢？我们应该这样理解。
假设我们在第i位。如果当前前缀和为10，那么假设哈希表中出现过前缀和为10的部分。我们是不是可以减掉那一部分来得到一个前缀和为0的子数组呢？
nums    = 0   1   1   0   1   1   1   0   0   1   1   0   1   0   0   1
presum  = -1  0   1   0   1   2   3   2   1   2   3   2   3   2   1   2

map:
0 -1
-1 0
1 2
2 5
3 6

假设现在在倒数第二位。我们现在前缀和是1。那么我们查表。我们发现从第0位到第2位的子数组前缀和为1。
那么从第0位到第14位的子数组 - 从第0位到第2位的子数组 的前缀和 就相当于
1 - 1 = 0。
因为从第0位到第14位的子数组前缀和是1。那么我们查表找到另一个前缀和为1的子数组，二者相减则数组前缀和为0.这时候计算其长度即可。
所以此时长度是14 - 2 = 12。也就是从第3位到第14位为止，数组前缀和为0。
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>presum; //key是前缀和，value是下标。
        presum[0] = -1; //老规矩添加前导0
        int maxret = 0; //保存结果
        int accumu = 0; //前缀和。
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0){ //如果是0就-1
                accumu -= 1;
            }
            else{
                accumu += 1; //如果是1就+1
            }
            if(presum.find(accumu) != presum.end()){ //查表看这个前缀和是否出现过。
                maxret = max(i-presum[accumu], maxret); //出现过就计算区间长度取最大值。
            }
            else{
                presum[accumu] = i; //没有出现过就插入
            }
        }
        return maxret;
    }
};