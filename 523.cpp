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
text 这道题核心是 当两个不同位置的前缀和对 k 的余数相同时就相当于找到了一个和是 k的倍数的连续子数组。974和这个的框架几乎一样。还有525

这题的做法是哈希表储存presummodK 和 前缀和
步骤；
1. 创建一个哈希表，key来储存当前前缀和的余数，value则储存对应的index
2. 如果哈希表中存在其对应的余数，取出其pos，看当前的下标 index 到 pos的距离是否大于等于2. 如果是则返回true。不是我们则继续遍历。不要更新哈希表中的下标！(贪心的思维)
3. 如果不存在则将当前余数与其对应的下标储存在哈希表中。
&核心：当两个不同位置的前缀和对 k 的余数相同时，我们看这两个位置的下标是否距离大于等于2. 如果满足以上条件，我们即找到了一个和是 k 的倍数 的 连续子数组。
& 为什么找到了相同的余数就相当于找到了一个和是 k 的倍数 的 连续子数组？
假设我们有数组 a    b   c   d   e   f   
假设abc和abcdef的和 余k都是rem 则有
a+b+c       = x*k + rem
a+b+c+d+e+f = y*k + rem
所以
sum(abcdef) - sum(abc)  = (y*k + rem) - (x*k + rem)
              sum(def)  = y*k + rem - x*k - rem
                        = y*k - x*k
                        = (y-x)*k
                        所以我们找到了一个和是 k 的倍数[(y-x)*k必然是k的倍数]的连续数组(def)
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix; //注意key是前缀和的余数。value是下标
        prefix[0] = -1; //前缀和数组一定带0。但是这个0在数组内实际不存在，所以下标安排为-1
        int presumModK = 0; //前缀和对k的余数
        for(int i = 0; i < nums.size(); i++){
            presumModK += nums[i]; //计算前缀和
            presumModK = presumModK % k; //&计算前缀和对k的余数。注意这个数字不清零。因为map的key就是它
            //presumModK = (presumModK + nums[i]) % k; 可以合并写起来。
            if(prefix.find(presumModK) != prefix.end()){ //如果找到了，也就是如果当两个不同位置的前缀和对 k 的余数相同时
                if(i - prefix[presumModK] >= 2){ //必须距离大于2
                    return true;
                }
                //!注意，如果距离不大于2不作任何动作，下标不更新。因为有贪心思想。
            }
            else{
                prefix[presumModK] = i; //如果没找到，就把这个前缀和对k的余数和它出现的位置储存起来。
            }
        }
        return false;
    }
};