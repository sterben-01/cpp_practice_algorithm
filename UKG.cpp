#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<int>res;
    int LCM(vector<int>& nums, int length){
        int calclcm = -1;
        int max = INT32_MIN;
        for(int i = 0; i < length-1; i++){
            int residule = INT32_MAX;
            int firstnum = nums[i];
            int secondnum = nums[i+1];
            if(firstnum > secondnum){
                swap(firstnum, secondnum);
            }  
            while(residule!=0){
                residule = firstnum % secondnum;
                firstnum = secondnum;
                secondnum = residule;
            }
            calclcm = nums[i] * nums[i+1] / firstnum;
            res.push_back(calclcm);
        }
        for(int i = 0; i < res.size(); i++){
            if(res[i] > max){
                max = res[i];
            }
        }
        print(res);
        cout<<"---"<<endl;
        cout << max << endl;
        return max;
    }
    void print(vector<int> & nums){
        for(int i=0;i<nums.size();i++){
            cout << nums[i] << endl;
        }
    }

};
int main(){
    vector<int> test = {7,3,2,9,12};
    Solution* obj = new Solution();
    obj->LCM(test,5);
    cout<<"newnewnew" << endl;
    obj->print(obj->res);

}