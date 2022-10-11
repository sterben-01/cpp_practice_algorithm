
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;


/*
text 哈希表。先把两个数组的所有和 和出现的次数放到map里。然后第二次两层forloop把剩下两个数加起来，然后去map看有没有等于这个数的负数的。如果有就加次数。
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum;
        int ret = 0;
        for(int i = 0; i < nums1.size();i++){
            for(int j = 0; j < nums2.size(); j++){
                sum[nums1[i] + nums2[j]]++;
            }
        }
        for(int k = 0; k < nums3.size(); k++){
            for(int l = 0; l < nums4.size(); l++){
                int pivot = 0-(nums3[k] + nums4[l]);
                if(sum.find(pivot) != sum.end()){
                    ret = ret + sum[pivot];
                }
            }
        }
        return ret;

    }
};