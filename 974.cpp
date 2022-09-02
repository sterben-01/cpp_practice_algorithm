#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;




/*
text 这道题核心是同余定理。也就是 (a-b)%k = 0  相当于  a%k = b % k
而且题目问的是有几个数组，首先它连续，其次不用输出具体数组，只要计数就可以。
这题的做法是哈希表储存presummodK 和 前缀和
前缀和数组我们已经熟悉了。所以我们想求数组区间i-j的和，仅需在前缀和数组中计算presum[j] - presum[i-1]
&所以原来的题目要求转化为公式就是 (presum[j] - presum[i-1]) % k
&通过同余定理可以换成 找到 presum[j] % k = presum[i-1] % k 也就是找到同样的presum的数量。
&几个小细节。第一点就是，先count++再给次数++。因为是假如我们有两个presummodk一样了，有一种组合，也就是这两个一样数字之间的部分可以满足条件。乳沟有三个一样，那就是1+2 = 3种。所以这里是排列组合的形式。
&第二个是负数要处理下。
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        my_map[0] = 1;
        int presumModK = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            presumModK = (presumModK + nums[i]) % k;
            if(presumModK < 0){
                presumModK = presumModK + k;
            }
            if(my_map.find(presumModK) != my_map.end()){
                count = count + my_map[presumModK];
                my_map[presumModK]++;
            }
            else{
                my_map[presumModK]++;
            }
        }
        return count;
    }
};