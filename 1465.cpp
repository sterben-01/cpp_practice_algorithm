#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

/*
text 单纯贪心。
理解题意就好办。把边界加进去之后找到所有切割范围的最大值然后相乘即可。
&记得排序，因为顺序随机。
*/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long maxhor = horizontalCuts[0]-0;
        long long maxver = verticalCuts[0]-0;
        

        for(int i = 1; i < horizontalCuts.size(); i++){
            maxhor = max(maxhor, (long long)horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i = 1; i < verticalCuts.size(); i++){
            maxver = max(maxver, (long long)verticalCuts[i] - verticalCuts[i-1]);
        }

        if(horizontalCuts.back() < h){
            maxhor = max(maxhor, h - (long long)horizontalCuts.back());
        }
        if(verticalCuts.back() < w){
            maxver = max(maxver, w - (long long)verticalCuts.back());
        }
        long long mods = 1e9+7;
        return maxhor * maxver % mods;
    }
};