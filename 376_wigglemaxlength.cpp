#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size(); // 只有一个就返回1
        }
        int curslope = 0;
        int preslope = 0;
        int res = 1; // 默认数组里有一个峰值
        for(int i = 0; i < nums.size() - 1; i++){ // 也可以从1开始到size
            curslope = nums[i+1] - nums[i]; // 那么这儿就要变成i-[i-1]
            if((curslope > 0 && preslope <= 0) || (curslope<0 && preslope>=0)){ //不能反着写！不能写curslope <= 0 && preslope>0. 因为cur是先动的，pre有可能等于0！比如33325.
                res = res + 1;
                preslope = curslope;
            }
            //preslope = curslope; // 不能放在这。反例 1 17 5 10 13 15 15 15 17 16 18 8
                                //                ↓+1                       ↑ 如果每次都更新的话在连续递增之后的弯折会把这里算上
                                /*                18
                 17                         17    / \
                |↑+1|                      /↑+1\  /   \
                 |  |                     /    16     \8
                 |  |          15---15---15    ↑+1
                 /  \         /           ↑ 如果放在if外面，这时候curslope>0 preslope = 0 会算上。但是这地方是单调递增，不应该算上。所以错了
                /    \      13
               /      \     /
              /        \   10
             /          \ /
            /            5
  --------- 1           ↑+1
            ↑+1

                                */
        }
        return res;
    }
    
};