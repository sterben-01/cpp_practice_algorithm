#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
using namespace std;

/*
text 非常像前缀乘法
原数组：       [1       2       3       4]
左部分的乘积：   1       1      1*2    1*2*3
右部分的乘积： 2*3*4    3*4      4      1
结果：        1*2*3*4  1*3*4   1*2*4  1*2*3*1
从上面的图可以看出，当前位置的结果就是它左部分的乘积再乘以它右部分的乘积。
因此需要进行两次遍历，第一次遍历用于求左部分的乘积，第二次遍历在求右部分的乘积的同时，再将最后的计算结果一起求出来。
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(),0);
        int left_mult = 1;
        int right_mult = 1;
        
        for(int i = 0; i < nums.size(); i++){
            ret[i] = left_mult; //注意先放入再乘。
            left_mult = left_mult * nums[i];
        }
        for(int j = nums.size()-1; j > 0; j--){
            right_mult = right_mult * nums[j]; //注意先乘再放入
            ret[j-1] = ret[j-1] * right_mult;//减掉1的原因是我们从后往前算。比如我们现在是4的位置。我们要算3。
            //3的右侧是一个4。所以我们要在3的已经算完左侧部分的基础上把4乘上去。3当前的算好的部分就是ret[j-1]。
        }
        return ret;
    }
};