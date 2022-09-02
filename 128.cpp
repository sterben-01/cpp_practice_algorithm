#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_set>

using namespace std;
/*
text 最长连续序列
这题贼有意思。先把例子放上来
nums = [100,4,200,1,3,2]
&第一步用set去重，其实干不干都行。明确一点，连续序列不包括重复数字。其实题里面压根儿没提。
&第二步有有意思了。我们已经把数字放到set里面了，有序无序无所谓，我们要干啥呢？我们要找当前这个数字的前一个数字在不在set里头
%为啥要找前一个数字？因为如果前一个数字在里面，证明当前数字不是这个序列的起始数字。跳过就行。如果不在，那就说明这个数字是这个序列的起始数字。
todo 注意这里指的是当前数字的前一个数字，而不是前一个元素。意思是 假设当前数字是100，我们要看99在不在set里面。如果当前数字是4 我们就看3在不在。
&如果当前数字的前一个数字不在set里面，开始表演了！为了连续，我们已知比这个数字小的不在set里面，那我们就找大的。假设从100开始找，我们查一下101在不在，不在就停。
&这样我们就保证了一个数字的序列长度是1
todo 这里有点要点，注意那个tempitem。这里tempitem是会++的，所以不要用原来的数字。需要一个临时变量。
&假设现在到4了我们4-1=3，看3在不在，3在就跳过4，然后下一位1， 1不在了，从1开始找。2在，++，3在++，4在++，5不在
所以最长区间就是1 2 3 4。
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> my_set;
        for(int i = 0; i < nums.size(); i++){
            my_set.insert(nums[i]);
        }
        int ret = 0;
        for(auto item : my_set){
            if(my_set.count(item-1) == 0){
                int temp_item = item;
                while(my_set.count(temp_item+1) == 1){
                    temp_item++;
                }
                ret = max(ret, (temp_item - item + 1));
            }
        }
        return ret;
    }
};