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
    vector<int>scores{2,4,10,230,2440,344445,24800000};
    vector<int>nums{0,1,2,3,4,5,6,7,8};
    unordered_map<int,int>my_map;
    vector<int> win_num;
    for(int i = 0; i < nums.size(); i++){
        int diff = scores.size() - nums[i];
        if(my_map.find(diff) != my_map.end()){
            win_num.push_back(nums[i]);
        }
        else{
            my_map[nums[i]] = diff;
        }
    }
    vector<int> final_win_num;
    for(int i = 0; i < win_num.size(); i++){
        final_win_num.push_back(win_num[i]);
        final_win_num.push_back(scores.size() - win_num[i]-1);
    }
    // if(scores.size() % 2 == 0){
    //     auto it = find(nums.begin(), nums.end(), scores.size() / 2);
    //     if(it!= nums.end()){
    //         final_win_num.push_back(scores.size()/2);
    //     }
    // }
    for(int i = 0; i < final_win_num.size(); i++){
        cout << final_win_num[i] << endl;
    }
    cout << final_win_num.size() << endl;

    // sort(final_win_num.begin(), final_win_num.end());
    // cout << scores[final_win_num[0]] << endl;

    // int min_score_split = INT_MAX;
    // // for(int i = 0; i < final_win_num.size(); i++){
    // //     int cut_pos = final_win_num[i];
    // //     if(cut_pos < 0 || cut_pos >= scores.size()){
    // //         if(min_score_split == INT_MAX){
    // //             cout << -1 << endl;
    // //             return 0;
    // //         }
    // //     }
    // //     else{
    // //         min_score_split = min_score_split < scores[cut_pos] ? min_score_split : scores[cut_pos];
    // //     }
    // // }
    // if(min_score_split == INT_MAX){
    //     cout << -1 << endl;
    //     return 0;
    // }
    // cout << min_score_split << endl;


    return 0;

}
   
