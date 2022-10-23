#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
text 这题和1991一样。前缀和基础应用。
例子                2   3   -1  8   4
前缀和数组：    0   2   5   4   12  16
我们可以看到，如果我们要知道nums[0] ~ nums[i]的和，只需要查看prefix[i+1]即可。
比如查看nums[0]~nums[2]的和 = 2 + 3 - 1 = 4
只需要查看prefix[3]即可。也就是4。因为有前导0
所以我们只需要查看 总和 - 左侧的和 = 右侧的和 是否成立即可。
右侧的和是accumu - prefix[i+1], 左侧的和便是prefix[i]，
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> prefix(nums.size()+1,0);
        int accumu = 0;
        for(int i = 1; i <= nums.size();i++){
            accumu += nums[i-1];
            prefix[i] = accumu;
        }

        for(int i = 0; i < nums.size(); i++){
            if(accumu - prefix[i+1] == prefix[i]){
                return i;
            }
        }
        return -1;
    }
};