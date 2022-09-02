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



int main(){
    int size;
    cin >> size;
    vector<long long> nums;
    vector<long long> nums1;
    vector<long long> nums2;
    for(int i = 0; i < size; i++){
        long long temp;
        cin >> temp;
        nums.push_back(temp);
    }
    long long count = 0;
    for(int i = 0; i < size; i+=2){
        nums1.push_back(nums[i]);
    }
    for(int i = 1; i < size; i+=2){
        nums2.push_back(nums[i]);
    }

    long long max1 = *max_element(nums1.begin(), nums1.end());
    long long max2 = *max_element(nums2.begin(), nums2.end());
    if(max1 == max2){
        long long accumu1 = accumulate(nums1.begin(), nums1.end(), 0);
        long long accumu2 = accumulate(nums2.begin(), nums2.end(), 0);
        long long total1 = nums1.size() * max1;
        long long total2 = nums2.size() * max2;
        if((total1 - accumu1)> (total2 - accumu2)){
            max2 = max2 + 1;
        }
        else{
            max1 = max1 + 1;
        }
    }
    for(int i = 0; i < nums1.size(); i++){
        count = count + (max1 - nums1[i]);
    }
    for(int i = 0; i < nums2.size(); i++){
        count = count + (max2 - nums2[i]);
    } 
    cout << count << endl;
    return 0;
}
