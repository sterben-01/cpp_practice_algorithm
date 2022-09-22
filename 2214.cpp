#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

/*
护盾只能扣一次，所以找最大的扣。
然后如果最大值-护盾变成负数了就换成0
然后数组accumulate取和即可。
*/

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        auto iter = max_element(damage.begin(), damage.end());
        *iter = *iter - armor >= 0 ? *iter-armor : 0;
        return accumulate(damage.begin(), damage.end(), 0LL)+1;
    }
};