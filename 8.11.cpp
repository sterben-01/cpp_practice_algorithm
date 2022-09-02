#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
using namespace std;


int main(){
    int param[3];
    for(int i = 0; i < 3; i++){
        int temp;
        cin >> temp;
        param[i] = temp;
    }
    vector<int> scores;
    for(int i = 0; i < param[0]; i++){
        int score;
        cin >> score;
        scores.push_back(score);
    }

    sort(scores.begin(), scores.end());

    int num_begin = param[1];
    int num_end = param[2];
    //算出淘汰+晋级的可能性
    vector<int> nums;
    for(int i = num_begin; i <= num_end; i++){
        nums.push_back(i);
    }
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
        final_win_num.push_back(scores.size() - win_num[i] - 1);
    }
    if(scores.size() % 2 == 0){
        auto it = find(nums.begin(), nums.end(), scores.size() / 2);
        if(it!= nums.end()){
            final_win_num.push_back(scores.size()/2);
        }
    }
    // for(int i = 0; i < final_win_num.size(); i++){
    //     cout << final_win_num[i] << endl;
    // }
    int min_score_split = INT_MAX;
    for(int i = 0; i < final_win_num.size(); i++){
        int cut_pos = final_win_num[i];
        if(cut_pos < 0 || cut_pos >=scores.size()){
            if(min_score_split == INT_MAX){
                cout << -1 << endl;
                return 0;
            }
        }
        else{
            min_score_split = min_score_split < scores[cut_pos] ? min_score_split : scores[cut_pos];
        }
    }
    if(min_score_split == INT_MAX){
        cout << -1 << endl;
        return 0;
    }
    cout << min_score_split << endl;
    return 0;
}