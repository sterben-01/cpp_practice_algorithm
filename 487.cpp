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
text 485的升级版。滑动窗口。
给定一个二进制数组 nums ，如果最多可以翻转一个 0 ，则返回数组中连续 1 的最大个数。
这句话可以翻译成：允许存在一个0的最大区间。也就是给定一个区间，该区间中最多只能包含1个0，求出该区间的最大长度。
维护一个区间，这个区间中最多只包含一个0。当区间中包含两个0的时候，直接移动左边界l直到区间只包含一个0即可。这个过程中去更新最大区间长度，最后就能得到答案。

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxret = 0;
        int zero_count = 0;

        for(; right < nums.size(); right++){
            if(nums[right] == 0){ //如果是0
                zero_count++; //增加0的计数。
                while(zero_count > 1){ //如果区间内0的数量超过1则开始收缩窗口
                    if(nums[left] == 0){  //如果收缩的时候发现当前是0，则更新0的计数
                        zero_count--;
                    }
                    left++; //收缩
                }
            }
            maxret = max(maxret, right - left+1); //记得更新窗口最大值。+1是因为2~4一共是3个数
        }
        return maxret;
    }
};