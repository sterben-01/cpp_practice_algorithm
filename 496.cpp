#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>

using namespace std;


/*
text 单调栈 下一个更大的元素
&要点1：找到某一个元素下一个更大的元素，我们的vector存的是结果，stack是单调栈，map的作用是找到nums1里面的元素对应的下一个最大的元素
&1.1 如何理解单调栈，举例就是说看身高，比我们矮的都不看，都拿出去就完了。有点像滑动窗口区间单调栈的那个意思。
&1.2 我们是把nums2也就是所有元素的下一个更大的元素都找到。然后我们要倒序入栈。倒序的目的是正序拿出。
逆序遍历，如果当前元素nums[i]大于栈中元素，那么对于其前面的元素来说，肯定nums[i]更可能是其下一个更大元素。
&1.3 map的目的是，因为我们找到了所有的元素对应的下一个更大的元素，所以我们最后需要从map里面挑出来nums1里面让我们找的元素。
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> my_map;
        stack<int> my_stk;
        vector<int> res;
        for(int i = nums2.size()-1; i >= 0; i--){ //倒序入栈
            while(!my_stk.empty() && my_stk.top() <= nums2[i]){ //如果栈顶的元素比当前小，就拿走。因为那个肯定不是比当前大的元素。
                my_stk.pop();
            }
            int num = my_stk.empty() ? -1 : my_stk.top();   //如果拿完了空了，证明自己的右侧没有比自己大的了，就返回-1。如果不空，那么栈顶元素就是比自己大的下一个元素
            my_map.insert(make_pair(nums2[i], num));
            my_stk.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            res.push_back(my_map[nums1[i]]); //最后从map选出自己想要的就可以了
        }
        return res;
    }
};