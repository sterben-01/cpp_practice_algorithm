#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

/*
text 锐评：三数之和等于0。经典题。第一次做还是在软工课上。当时想了一节课。
&排序+三指针。一看这个题就知道肯定得排序。直接sort就完事了
&先判断sort之后第一个数是不是大于0。大于0就直接return
%我们要找三数之和等于0。你sort完了之后第一个数就大于0了你啥玩意能相加为0？
*现在是第一次去重。如果我们发现i不是第一位然后发现nums[i] = nums[i-1]也就是第一个数相同了，直接跳过。不然会取重复三元组。
&然后我们明确一下。left指针指向i+1; right指针指向size-1也就是最后一位。假如三个数相加，大于0了，right左移。如果小于0了left右移。
%记住要判断left < right
&现在进入第二三次去重。每次指针移动 left右移或者right左移的时候，需要判断现在这个指向的数是不是和移动之前指向的那个数一样。如果一样了就等于做了重复工作，就一直移动到不重复为止
&第四次去重是在取了三元组之后。取了三元组之后左右指针同时移动，当我们发现移动后的指针还是指向刚才已经满足条件的数的时候，也要跳过。不然也会重复。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums[0] > 0){
            return res;
        }
        for(int i = 0; i < nums.size() - 1; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right] + 1){
                        right--;
                    }
                }
            }
        }
        return res;
    }
};