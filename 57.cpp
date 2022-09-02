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
text 这题和56合并区间 很像，但是有一个约束条件导致我们可以优化很多。
题目说了，是无重叠且按照起始端点排序的。所以我们理解为把每一个数字拿出来的话是单调递增的。
intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
所以我们可以这样
&第一步，找到这个新的区间应该插入在哪。我们的具体方法是一直找，直到插入区间的第一位比原来区间的后一位要小为止。
比如这里我们发现4比5小。所以index = 1就停了，意思是3,5可以和4,8合并了。
&第二步。一直合并，直到插入区间的最后位比原来区间的第一位小
合并的方法就是新区间的起点和当前老区间的起点取最小值，终点取最大值。
%注意我们这里是直接修改插入区间。因为这里还没有被放入结果数组。
比如3,5 4,8 合并为3,8
3,8和8,10 合并为 3,10
直到我们发现 10比12小。停止。
&第三步，把合并完的插入区间放入结果数组
&第四步，把剩下的放进结果数组。


*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int index = 0;
        while(index < intervals.size() && newInterval[0] > intervals[index][1]){
            ret.push_back(intervals[index]);
            index++;
        }
        while(index < intervals.size() && newInterval[1] >= intervals[index][0]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        ret.push_back(newInterval);
        while(index < intervals.size()){
            ret.push_back(intervals[index]);
            index++;
        }
        return ret;
    }
};