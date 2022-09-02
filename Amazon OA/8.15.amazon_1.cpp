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

using namespace std;

class mycomp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second < b.second) {
            return true;
        }
        return false;
    }
};

class myadd {
public:
    int operator()(int val, const pair<int, int>& rhs) {
        return val + rhs.first;
    }
};

void solution(vector<int>& nums, int k) {
    unordered_map<int, int> my_map;
    int max_val = -1;
    int val = 0;
    int index = 0;
    for (; index < k - 1; index++) {
        my_map[nums[index]]++;
    }

    for (; index < nums.size(); index++) {

        my_map[nums[index]]++;
        auto T = max_element(my_map.begin(), my_map.end(), mycomp());
        if (T->second == 1) {
            if (my_map.size() == k) {
                val = accumulate(my_map.begin(), my_map.end(), 0, myadd());
                max_val = max(max_val, val);
            }

        }
        if (my_map[nums[index - k + 1]] > 1) {
            my_map[nums[index - k + 1]]--;
        }
        else if (my_map[nums[index-k+1]] == 1) {
            my_map.erase(nums[index - k + 1]);
        }
    }
    cout << max_val << endl;

}



int main() {
    vector<int> test{1,1,1,1,2,2,2,2};
    solution(test, 1);
    return 0;
}