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
为什么使用 while ？ 因为交换后，原本 i 位置的 nums[i] 已经交换到了别的地方，
        交换后到这里的新值不一定是适合这个位置的，因此需要重新进行判断交换
        如果使用 if，那么进行一次交换后，i 就会 +1 进入下一个循环，那么交换过来的新值就没有去找到它该有的位置
         比如 nums = [3, 4, -1, 1] 当 3 进行交换后， nums 变成 [-1，4，3，1]，
         此时 i == 0，由于当前num[0]是-1所以跳出判断。然后来到i == 2
         发现4应该在下标3的位置，于是和1换变成了 -1 1 3 4。但是注意，此时1不在正确位置上。如果使用 if ，那么会进入下一个循环， 这个 1 就没有进行处理
        所以使用while发现1不在正确位置上，应该在下标0，所以交换变成1 -1 3 4。
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

