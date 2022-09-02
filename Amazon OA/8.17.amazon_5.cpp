
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
//text amazom medium 
//& Decreasing ratings
int accumu(int s) {
    int sum = 0;
    for (int i = 1; i <= s; i++) {
        sum = sum + i;

    }
    return sum;
}
void solution(vector<int>& nums) {

    int count = 0;
    int slow = 0;
    int fast = 1;
    while (fast < nums.size()) {

        if (nums[slow] <= nums[fast]) {
            count = count + accumu(fast - slow-1);

            slow = fast;
        }
        fast++;
    }
    count = count + accumu(fast - slow - 1);
    cout << count << endl;
}



int main() {
    vector<int>s{5,4,3,2,1};
    solution(s);
    return 0;
}