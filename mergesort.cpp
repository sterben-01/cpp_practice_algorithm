
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
归并排序
先局部有序后整体有序。
简单理解就是有一个临时数组，然后左右哪个小放进去那个。然后额外的两遍遍历是怕左边或者右边先结束。
循环完毕后再复制会原数组。
[4,3,1,7,8,9,2,11,5,6]
step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
step=4: (1->2->3->4->7->8->9->11)->5->6
step=8: (1->2->3->4->5->6->7->8->9->11)
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums;
        }
        vector<int>temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size()-1);
        return nums;

    }
    void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end){
        if(start >= end){
            return; 
        }
        mergeSort(nums, temp, start, (start+end)/2);
        mergeSort(nums, temp, (start+end)/2+1, end);
        merge(nums, temp, start, end);
    }

    void merge(vector<int>& nums, vector<int>& temp, int start, int end){
        int left = start;
        int mid = (start+end)/2;
        int right = mid + 1;

        int tempIndex = left;

        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp[tempIndex] = nums[left];
                left++;
            }
            else{
                temp[tempIndex] = nums[right];
                right++;
            }

            tempIndex++;
        }

        while(left <= mid){
            temp[tempIndex] = nums[left];
            left++;
            tempIndex++;
        }
        
        while(right <= end){
            temp[tempIndex] = nums[right];
            right++;
            tempIndex++;
        }
        for(int i = start; i < end + 1; i++){
            nums[i] = temp[i];
        }
    }
};