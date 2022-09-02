#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main(){
    vector<int> nums;
    while(true){
        int s;
        cin >> s;
        nums.push_back(s);
        if(getchar() == '\n'){
            break;
        }
    }
    int startindex = -1;
    int endindex = -1;
    int target;
    cin >> target;
    // for(auto i:nums){
    //     cout << i << endl;
    // }
    unordered_map<int, long long> my_map;
    vector<vector<int>> all_res;
    for(long long i = 0; i < nums.size(); i++){
        if(my_map.find(target - nums[i])!=my_map.end()){
            startindex = i;
            endindex = my_map[target-nums[i]];
            all_res.push_back({endindex, startindex});
        }
        my_map[nums[i]] = i;
        
    }
    if(startindex == -1 || endindex == -1){
        cout << "-1";
    }
    else{
        sort(all_res.begin(), all_res.end());
        cout << all_res[0][0] << " " << all_res[0][1];
    }


    return 0;
}
