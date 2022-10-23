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
text 最大连续1的个数。这个题最简单的方式是记录上一个0出现的地方。
如果当前位置是1，则计算当前位置减掉上一个0出现的位置的差。这个区间就是连续1的区间。
如果当前位置是0，则更新0出现的位置。
&细节。上一个0出现的位置一开始应该设置为-1，但是不影响结果。i为0的时候，0-(-1) = 刚好为1。依次类推。

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zero_pos = -1;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zero_pos = i;
            }
            else{
                ret = max(ret, i-zero_pos);
            }
        }
        return ret;
    }
};