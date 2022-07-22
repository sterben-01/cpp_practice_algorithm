#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <cstring>
using namespace std;
// 变量名其实有问题。nextcover的意思是看这个位置的数是几，意思是看之后最大能走几步。curcover其实是当前位置的意思。
class Solution {
public:
    int jump(vector<int>& nums) {
        int nextcover = 0;
        int curcover = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            nextcover = max(nums[i]+i, nextcover); // 这里要取max因为如果是5,1,1 这样你不取max的话无意义了。注意这是有+i的 要记住这玩意相当于累加！！！
            if(i == curcover){ // 这里指的是如果你走到了当前这一步能覆盖的范围的最大值的时候。比如[5,1,1,1,1,3,4]这的意思是index为0的时候你走了5步。也就是当前index值能覆盖的最大范围。
            /*
            [5,1,1,1,1,3),4,1,1,1,1,1]
                       ↑ 第一步能跳到这 是5

            */
                if(curcover!=nums.size()-1){ //没到终点
                    res = res+1;
                    if(nextcover >= nums.size() - 1){ //发现下一步已经能cover终点了，就找到了。可以返回
                        break;
                    }
                    curcover = nextcover; // 重新开始计算走几步。
                    /*
                        [5,1,1,1,1,(3,4,1,1,1,1,1]
                                    ↑ 第二步从这开始跳 重新开始算走几步 比如下一个coverage能到8（5+3） 所以从这走到第八位。
                    */
                }
            }

        }
        return res;
    }
};