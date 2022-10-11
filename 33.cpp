#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

/*
text 这道题的核心是二分法的时候判断中间的mid数具体是在整个数组的左边还是右边。比如4567 8 0123。mid比left大，所以mid在左侧。
text所以如果这时候目标比left大比mid小，比如5，这时候应该把mid向左侧移动。如果这时候目标值比mid大或者是比left还小，证明要到右侧去找。就是left = mid+1
反之亦然。
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                if(target <= nums[right] && target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};