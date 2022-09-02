#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

/*
text 下一个排列。直接看题解
&第一步，从后往前 找到第一个升序的组合。比如1 2 3 8 5 7 6 4 。从后往前一个升序的组合是5 7。
%这里对应着的就是如果i = n, j = n-1, 那么就是找到nums[j] < nums[i]为止
&第二步，从后往前找到第一个比升序组合的第一个数要大的数字。这里是6。然后下标记作k
&第三部，把升序组合的第一个数和比升序组合的第一个数要大的数字互换。这里就是nums[j] 和 nums[k]换。也就是5和6换
&第四部，把升序组合的第二个数后面的数字重新按照升序排列。这里就是nums[i]后面的按照升序排列

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n <= 0){
            return;
        }
        int i = n;
        int j = n - 1;
        int k = n;

        while(j >= 0 && nums[j] >= nums[i]){
            j--;
            i--;
        }
        if(j >= 0){
            while(nums[j] >= nums[k]){
                k--;
            }
            swap(nums[j], nums[k]);

        }
        reverse(nums.begin() + i, nums.end());

    }
};