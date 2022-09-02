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
#include <set>

using namespace std;

/*
text 差分数组
什么是差分数组？就是和前缀和反过来的。对于数组 [1,2,2,4]，其差分数组为 [1,1,0,2]
也就是说我们对差分数组求前缀和即可得到原数组。
所以针对这道题，我们的思路是，我们只需要看后一个比前一个多了多少就可以。因为我们是要求每个航班预定的总座位数。
我们传入的数组第0位是起始航班号，第1位是终点航班号，第2位是预定了多少座位。也就是在这一个航班号区间内，每一个航班都预定了对应的座位。
也就是说，我们可以发现，每一个航班的座位总数是累加的。
&一个小要点：差分数组，假如我们第二位是10，意味着从第二位开始到最后这个区间内，累计值被增加了10。因为我们是累加
举个例子
假如差分数组是 10 0 10 10 20 -20
那么我们能求得原数组是 10 10 20 30 50 30
假如我们想让第二位是0的话，我们的差分数组必须在第二位-10，也就是把前面加过的加掉。因为差分数组的核心是累加。
&所以我们要在我们不需要增加这个值的区间的起点把增加的值减掉。

我们结合题目看，输入的是[[1,2,10],[2,3,20],[2,5,25]]
翻译过来就是区间[1,2] 每一个航班号+10个座位数。以此类推
&我们可能难以理解。为啥可以用差分数组。明明航班1和航班2没啥联系。我个人的理解是因为我们每一个航班号应用了叠加，而不是说航班1和航班2有联系才用的差分数组

*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n,0);
        for(auto& items : bookings){
            ret[items[0] - 1] = ret[items[0] - 1] + items[2]; //这里下标-1是因为航班1要放在下标0的位置。我们把这个位置的值加上这次的座位数量

            if(items[1] < n){
                ret[items[1]] = ret[items[1]] - items[2]; //然后在区间终点把加上去的减掉，避免影响其他区间。这里不-1是因为截止到2号航班就是3号航班开始减掉。3号航班的下标刚好是2
            } 
        }
        for(int i = 1; i < n; i++){
            ret[i] = ret[i-1] + ret[i]; //之后累加求得结果
        }
        return ret;
    }
};