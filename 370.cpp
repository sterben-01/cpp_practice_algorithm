#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

/*
text 差分数组
& 这里差分数组数组+1的原因是为了每次在区间的末尾后面那一位把更改过的值改回来以免对其他值造成影响。
差分数组算出区间中总计要变化的数值后再进行累加即可。
输入: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
输出: [-2,0,3,5,3]
这里差分数组数组就变成了
-2  2   3   2   -2  -3
最后一个-3没什么用

0   0   0   0   0
    2   2   2   
        3   3   3
-2  -2  -2

总和就变成了 -2 0 3 5 3
然后就可以算出来差分数组就是
-2 +2 3 2 -2

详细长得就是下面这样
0   0   0   0   0
    2           -2
        3           -3
-2          2

所以加上了前导0，就是
-2  2   3   2   -2  -3

& 注意累加的返回值数组有一个前导0。这样方便计算。
&也可以换成注释的方法，单独拿一个数字出来计算累加量。
*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length+1,0);
        
        for(int i = 0; i < updates.size(); i++){
            diff[updates[i][0]] += updates[i][2];
            diff[updates[i][1]+1] -= updates[i][2];
        }

        vector<int>ret;
        ret.push_back(0);
        for(int i = 1; i < diff.size(); i++){
            ret.push_back(ret[i-1] + diff[i-1]);
        }
        ret.erase(ret.begin());
        return ret;

        // int accumu = 0;
        // for(int i = 0; i < length; i++){
        //     accumu += diff[i];
        //     ret.push_back(accumu);
        // }
        // return ret;
    }
};