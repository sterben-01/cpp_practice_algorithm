#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <stack>
using namespace std;
/*
双指针。一个头一个尾。每轮更新最大值（区间*最短的板子的高度）。
移动的时候，每次把短的板子往里移动即可。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while(left <= right){
            int temp = (right - left) * min(height[left], height[right]);
            res = res < temp ? temp : res;
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};