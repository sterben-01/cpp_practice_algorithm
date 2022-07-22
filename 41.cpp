#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
text 这题有点傻逼。我不知道怎么形容。核心思想就是把数字1放到下标0的位置，数字2放到下标1的位置。因为我们找的是第一个缺少的正数
&换句话说，理想状态下，数组应该是 1 2 3 4 也就是nums[0] = 1, nums[1] = 2;
我们用while循环去找。找这个nums[i]是否等于i+1
首先如果当前数nums[i]比0小，或者比数组容量还大，或者是这个数和上一次换的数是一样的的情况下就终止循环。因为我们上一次已经把一个数放到了正确的位置了
然后我们记录下这个数应该放置的位置。比如3应该放到下标2的位置。我们就把下标2的数和这个3换了。也就是nums[nums[i]-1] 和 nums[i]换

都换完了之后我们遍历，找到第一个不符合nums[i] = i + 1的数。那么这个i+1就是结果。
假如现在数组是3 4 5 6。那么i=0，nums[0] = 1， 3!=1 所以缺少的就是1。


纯数学题

*/

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {

            while (nums[i] != i + 1) {
                
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                int idx = nums[i] - 1;
                swap(nums[idx], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
};

