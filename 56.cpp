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
text 合并区间 细节很多
首先我们让整个数组有序。使用了自带的排序。他会排序成这样
[[1,2],[1,3],[1,4],[2,3],[2,8],[10,20]]
&规律是，每一个子数组的最后一位如果比下一个子数组的第一位要大或者相等（没有gap），那么就是可以合并
1,2 1,3. 因为2比1大，所以当前子数组的后一位可以cover下一个数组的前面。也就是没有gap。所以可以变成1,3

然后2,8 和 10,20。 8和10中间有gap所以不能合并。

&注意细节。


*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());   //先排序
        vector<vector<int>> ret;
        for(int i = 0; i < intervals.size();){ //!注意没有第三个条件
            int cur = intervals[i][1]; //记录一下当前子数组的最后一位
            int j = i + 1; //然后开始看下一个数组
            while(j < intervals.size() && intervals[j][0] <= cur){ //使用while循环。一直找到下一个子数组的第一位要比当前子数组的最后一位要大的时候
                cur = cur > intervals[j][1] ? cur : intervals[j][1]; //如果小就合并。首先更新一下子数组的第二位。也就是合并了一个区间后，这个区间的最后一位
                j++; //&注意这个j++不要写到上面。因为我们上面用j了。小心越界！
            }
            ret.push_back({intervals[i][0], cur}); //我们发现不满足条件了，也就是 2,8 10,20这种情况了。我们就把2和8放进去。这里的细节是用i而不是0

            i = j; //!注意我们上面的for循环没有第三个条件，我们不用每次遍历，我们应该是选择不满足条件的地方（无法合并的地方）再更新位置开始遍历
        }
        return ret;

    }
};