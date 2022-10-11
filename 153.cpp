#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <queue>
using namespace std;

/*
text 和 33 81 属于同一类型。
456780123，中间值8比右值大，证明最小的数字在右边。
&注意的是这题left不能等于right，不然会一直死循环。如果非要left = right，那么第一个if要加等于，并且返回right
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;                /* 左闭右闭区间，如果用右开区间则不方便判断右值 */ 
        while (left < right) {                      /* 循环不变式，如果left == right，则循环结束 */
            int mid = left + (right - left) / 2;    /* 地板除，mid更靠近left */
            if (nums[mid] > nums[right]) {          /* 中值 > 右值，最小值在右半边，收缩左边界 */ 
                left = mid + 1;                     /* 因为中值 > 右值，中值肯定不是最小值，左边界可以跨过mid */ 
            } else if (nums[mid] < nums[right]) {   /* 明确中值 < 右值，最小值在左半边，收缩右边界 */ 
                right = mid;                        /* 因为中值 < 右值，中值也可能是最小值，右边界只能取到mid处 */ 
            }
        }
        return nums[left];    /* 循环结束，left == right，最小值输出nums[left]或nums[right]均可 */     
    }
};
