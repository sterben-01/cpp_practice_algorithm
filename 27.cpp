#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <bitset>
#include <stack>
using namespace std;
/*
text 快慢指针 
&梳理一下快慢指针。这道题是去除特定的数字。
&不要被误解了。这里的fast和slow起始必须都是0！
假如我们有0 1 2 3 4 5 6 7 8 我们要去掉7
&正因为一开始快慢都是0，所以0不是目标数，所以0和0换，然后1和1换，2和2换 3和3换。以此类推
%直到遇到了7 7，也就是快慢都是7，那么到了目标数，快前进，变成了slow=7，fast= 8; 此时再覆盖slow的值。就变成了0 1 2 3 4 5 6 8.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};