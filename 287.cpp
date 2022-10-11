#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
text 寻找重复的数。这道题二分的原则是抽屉原则。也就是10个苹果放入9个抽屉，那么必然有一个抽屉有两个苹果。
放到这道题就是，如果mid的左侧 比mid小或等于mid的数字比mid大，就说明这个多余的数字在左边。
&理论上，这个数组应该是从1到n。也就是小于等于5的数一定只有5个。12345这五个。如果发现有六个了，那就说明这个多余的数字一定在5左侧。
&例子就是 1 2 2 3 4 5 6 7 8。然后我们要遍历整个数组！因为我们不知道重复的数字会重复了几次。所以必须从头到尾遍历。这时候我们发现小于等于4的数字有5个。
所以这个重复的数字一定在4左边。因为如果在4右侧的话，4应该在他应该呆的位置，也就是小于等于4的数字只能有四个。


*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ret = 0;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid){
                    count++;
                }
            }
            if(count > mid){
                right = mid-1;
            }
            else{
                left = mid +1;
            }
        }
        return left;
    }
};

int main(){
    cout << 9/2 << endl;
}
