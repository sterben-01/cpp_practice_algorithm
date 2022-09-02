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
    int player_num;
    cin >> player_num;
    int pair_sum;
    cin >> pair_sum;
    vector<vector<int>> relation;
    for(int i = 0 ; i < pair_sum; i++){
        string inp;
        cin >> inp;
        auto pos = inp.find(",");
        if(pos != inp.npos){
            int first_num = stoi(inp.substr(0, pos));
            int second_num = stoi(inp.substr(pos+1, inp.size()));
            if(first_num <= player_num && second_num <= player_num){
                relation.push_back({first_num, second_num});
            }
        }
    }
    // for(auto i:relation){
    //     for(auto j : i){
    //         cout << j <<",";
    //     }
    //     cout << endl;
    // }

    return 0;

}
