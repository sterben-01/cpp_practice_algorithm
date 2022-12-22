#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
#include <atomic>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int total_xor = 0;
        for(int i = 0; i < nums.size(); i++){
            total_xor ^= nums[i]; //把数组的数字全部取异或。这样最后的结果就是两个不同的数字的异或值。下一步要把他们分开。
        }
        //两个相同的数字异或后会为0。我们下一步需要区分出这两个数字。
        //区分的办法是首先找到这个异或值total_xor的哪一位不为0.不为0意味着两个原来的数字的这一位不相同。如果有多位不为0，任选一位即可。
        //然后用这个异或值去和数组里的数字每一个都异或一次。但是异或过程需要注意，假如我们选择的是第k位不同，那么我们整个数组里面第k位为0和第k位为1的数字要分别异或。然后放入两个数组。
        //因为所有第k位为0的数字刚好会有一个是单独的，第k位为1的数字也刚好会有一个是单独的。这样两个slot最后剩下的数字就是目标数字
        int pos = 0; //第k位
        while(((total_xor >> pos) & 1) == 0){
            //找到异或值的第几位为1。具体做法就是往右侧推。如果最右侧这位和1做与运算为0，证明最右侧这位不是1，就继续往右侧推。
            pos++;
        }

        int res[2]{};
        for(int i = 0; i < nums.size(); i++){
            if(((nums[i] >> pos) & 1) == 0){ //如果第pos位为0
                res[0] ^= nums[i]; //分别异或
            }
            else{ //如果第pos位为1
                res[1] ^= nums[i]; //分别异或
            }
        }
        
        return {res[0], res[1]};

    }

};