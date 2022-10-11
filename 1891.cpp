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
text 二分法。我一直不太会。
个人理解就是暴力，但是速度更快。
&首先我们划分查找范围。我们要满足分出来k段绳子的长度相同。那么我们就是每一个长度去尝试。使用二分法速度更快而已。
&那么自然而然左边界是1，没有0长度的绳子。
&注意！！绳子可以整条扔掉。也就是右侧边界并不是最短的绳子的长度。比如10000 10000 10000 10000 1。我们可以把长度为1的绳子扔掉。
%所以右边界是什么呢？右侧边界是所有绳子长度的和除以需要分割的数量。因为假设我们有5 7 9三条，分割出3段。那么我们右侧边界应该是7。
为什么是7？
%注意，我们这里的右侧边界是保证不会出错的情况。虽然说确实5 7 9取3,最长只能是5。但是如果是10000 10000 10000 1 取3的话，确实可以取3个10000。这里就不可以以最小长度为基准了。
% 什么是保证不会出错？我们假设5 7 9是一条绳子。长度是5+7+9=21。从这一条绳子取3段每段最多是7。你不可能取8因为不够长。所以这个右侧边界就是所有绳子长度的和除以需要分割的数量。
&我们有一个检查函数。我们检查每条绳子按照这个长度分割可以最多分几条。然后把总条数和需要的条数比较，如果小于了就说明这个长度有点长了。那么就要缩短长度。就是right = mid - 1
&如果数量满足要求，我们还需要让长度尽可能长。所以left = mid+1。因为可能这一次就又分不出来了，所以我们需要记录上一次的长度，所以就是ret = mid。


*/


class Solution {
public:
    bool can_devide(vector<int>& ribbons, long long length, long long nums){
        long long sum = 0;
        for(int i = 0; i < ribbons.size(); i++){
            sum = sum + (ribbons[i]/length);
        }
        if(sum >= nums){
            return true;
        }
        return false;

    }
    int maxLength(vector<int>& ribbons, int k) {
        long long left = 1;
        long long right = accumulate(ribbons.begin(), ribbons.end(), 0LL)/k;
        long long ret = 0;
        while(left <= right){
            long long mid = (left+right)/2;
            if(can_devide(ribbons, mid, k) == true){
                ret = mid;
                left = mid+1;
                
            }
            else{
                right = mid-1;
            }
        }
        return ret;
    }
};