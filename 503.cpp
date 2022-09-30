#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <stack>

/*
text 下一个更大的元素。
&stk储存的是下标。因为方便查找。
&stk是单调递减的。我们每次判断当前数字是否比栈顶的要大。如果比栈顶的大，那就证明这个数字是栈顶的下一个更大的元素。使用while循环直到当前数字比栈顶小，然后入栈
%由于是循环数组，所以采用i%size的方式来得到正确下标。又因为最多遍历两次，所以for循环是size*2

*/

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        stack<int> stk;
        vector<int> ret(size, -1);
        for(int i = 0; i < size*2; i++){
            while(!stk.empty() && nums[i%size] > nums[stk.top()]){ //如果当前数字比栈顶的数字大。注意栈储存的是下标。所以栈顶数字是nums[stk.top]

                ret[stk.top()] = nums[i%size]; //那么这个数字是当前栈顶数字的下一个更大的元素。栈顶储存的是下标，我们要把结果放入新数组。所以是ret[stk.top()]
                stk.pop();
            }
            stk.push(i%size); //入栈
        }
        return ret;
    }
};