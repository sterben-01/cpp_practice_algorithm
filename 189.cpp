#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    void printout(vector<int>& nums){
        for (int i = 0; i < nums.size(); i++){
            cout << nums[i] << endl;
        }
        cout << "-------" << endl;
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.begin()+k);
        printout(nums);
        reverse(nums.begin()+k,nums.end());
        printout(nums);
        reverse(nums.begin(), nums.end());
        printout(nums);
    }
};
int main(){

}