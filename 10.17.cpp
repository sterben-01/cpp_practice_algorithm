#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;

// bool is_odd(int s){
//     if(s % 2 == 0){
//         return true;
//     }
//     return false;
// }


void process(vector<int>& nums, vector<vector<int>>& updates){
    map<vector<int>,int> my_map;
    for(int i = 0; i < updates.size(); i++){
        my_map[updates[i]]++;
        if(my_map[updates[i]] > 2){
            my_map[updates[i]] = my_map[updates[i]]%2;
        }
    }
    for(auto t = my_map.begin(); t != my_map.end(); t++){
        if(t->second > 0){
            auto update = t->first;
            for(int j = update[0]-1; j < update[1]-1; j++){
                nums[j] = -nums[j];
            }
        }
    }
}




int main(){
    vector<int> nums{3,1,3,0,7};
    vector<vector<int>> processvec{{1,4}, {3,5}, {1,4},{3,5}, {2,3}};
    process(nums, processvec);
    for(auto j:nums){
        cout << j << endl;
    }
    return 0;
}