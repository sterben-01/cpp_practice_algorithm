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
text 和487基本一模一样。滑动窗口。就把0的计数换成k即可。
给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
这句话可以翻译成：允许存在k个0的最大区间。也就是给定一个区间，该区间中最多只能包含k个0，求出该区间的最大长度。
维护一个区间，这个区间中最多只包含k个0。当区间中包含两个0的时候，直接移动左边界l直到区间只包含k个0即可。这个过程中去更新最大区间长度，最后就能得到答案。

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxret = 0;
        int zero_count = 0;
        for(; right < nums.size(); right++){
            if(nums[right] == 0){
                zero_count++;
                while(zero_count > k){ //和487唯一区别
                    if(nums[left] == 0){
                        zero_count--;
                    }
                    left++;
                }
            }
            maxret = max(maxret, right - left+1);
        }
        return maxret;
    }
};