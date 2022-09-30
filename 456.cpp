#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;



/*
text 456 单调栈。不好想
核心就是我们知道132。我们要从后往前找，看当前这个数字和栈顶比大小。如果当前数字比栈顶要大，那么当前的数字可能是我们要找的3。
&为什么？因为我们让这个栈是单调递减的。也就是只有当前的数字比栈顶的小，才能入栈。
假如我们有42513
3入栈，然后看1， 1比栈顶3小，那么入栈，栈是13
然后有5。5比栈顶的大，那么这个有可能是我们想要的。我们就把所有比当前5小的数字拿出来，然后记录拿出来的数字的最大值。
%当然了，如果是425138的话，那么栈里还是有8的。因为我们让栈是单调递减的。
我们记录拿出来的数字的最大值之后，开启下一轮，如果这时候依旧当前数字还是比栈顶要大，那就继续和k比较寻找所有拿出来过的数字的最大值。
%目的就是找到比当前数字小的数字里面的最大值。
然后继续遍历，如果当前数字比k小，那么就满足条件。
&因为我们假设当前的数字是中间的最大的数字，我们每次比较，k都是比当前数字小的数字里面最大的值。然后我们一旦找到了一个数字比k小，那就说明找到了。因为k一定小于i，然后当前数字还比上一轮的i小，那么就找到了。因为当前数字小于上一轮的数字（模拟最大值）也小于k

*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> my_stk;
        int k = INT32_MIN;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < k){
                return true;
            }
            while(!my_stk.empty() && nums[i] > my_stk.top()){
                k = max(k, my_stk.top());
                my_stk.pop();
            }
            my_stk.push(nums[i]);
        }
        return false;
    }
};