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
text 最小差值平方和
&这道题的核心是一个数组。这个数组储存了每一个差出现的次数。数组的下标代表了差为几，下标对应的值代表了出现的次数
%因为给的数组最小值是1，最大值是1e5。所以我们的数组大小要是1e5+1
举例子：nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
差数组：0,0,0,1,3
这个3代表了差为3的地方出现了1次，差为4的地方出现了3次。
&我们知道一共可以调整k1+k2次。然后是+1或-1。自然我们想要让差缩小，所以要用减法。
&所以如果此时把差为4的数字对的其中一位加1，那么差为4的地方会变成差为3，那么差数组就会变成0,0,0,2,2。
所以只需要从大到小来看，把差不为0的地方减掉直到次数用尽即可。每次差为i的地方少一个，那么差为i-1的地方会多一个。

&最后变成0,0,0,3,1.计算方法就就是3x3x3 + 4x4x1 = 43
因为叫差值平方和。差值的平方是3x3，出现了三次就是3x3x3.
*/



class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(1e5+1, 0);
        for(int i = 0; i < nums1.size(); i++){
            diff[abs(nums1[i]-nums2[i])]++; //细节，记得取绝对值，因为不一定谁大谁小，
        }
        int total_k = k1 + k2;
        for(int i = diff.size()-1; total_k>0 && i > 0; i--){ //i可以到1就停止，因为差为0的部分无意义。
            int change = min(total_k, diff[i]); //这部分是因为数组很多地方是0.这样就不能减掉。
            total_k-=change; //k减少次数
            diff[i-1]+=change; //差-1的地方加次数
            diff[i]-=change; //差的地方减次数 
        }
        long long ret = 0;
        for(long long i = 0; i < diff.size(); i++){
            if(diff[i] != 0){
                ret = ret + i*i*diff[i]; //计算平方和。
            }
            
        }
        return ret;
    }
};