#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
// int original_length;
//     cin >> original_length;
//     int target_length;
//     cin >> target_length;
//     string original;
//     cin >> original;
//     string target;
//     cin >> target;
//     int ret = 0;
//     for(int i = 0; i < original_length; i++){
//         if(original[i] == target[i]){
//             while(i+1 < original_length && )
//         }
//         for(int j = 0; j < target_length; j++){
            
//         }
//     }

class mycomp{
    public:
    bool operator()(const pair<int, int>&a, const pair<int,int>&b) const{
        return a.second < b.second;
    }
};




int main(){
    // int number;
    // cin >> number;
    // int manipulate;
    // cin >> manipulate;
    // vector<int>order;
    // for(int i = 0; i < manipulate; i++){
    //     int temp;
    //     cin >> temp;
    //     order.push_back(temp);
    // }
    int number = 5;
    int manipulate = 3;
    vector<int>order{2,3,4};

    unordered_map<int,int> my_map;
    for(int i = 1; i <= number; i++){
        my_map[i] = i;
    }
    // for(auto i:my_map){
    //     cout << i.first << i.second << endl;
    // }
    auto t = min_element(my_map.begin(), my_map.end(), mycomp());
    cout << t->first << t->second << endl;
    // queue<int> stka;
    // for(int i = 1; i <= number; i++){
    //     stka.push(i);
    // }
    for(int i = 0; i < manipulate; i++){
        int current = order[i];
        auto t = min_element(my_map.begin(), my_map.end(), mycomp());
        int temppos = my_map[current];
        my_map[current] = 1;
        t->second = temppos;

    }
    vector<int> res;
    for(int i = 0; i < number; i++){
        auto t = min_element(my_map.begin(), my_map.end(), mycomp());
        res.push_back(t->first);
        my_map.erase(t);
    }
    for(int i = 0; i < number; i++){
        cout << res[i] << endl;
    }

    // for(int i = 0; i < manipulate; i++){
    //     queue<int> stkb;
    //     queue<int> stkc;
    //     int current = order[i];
    //     while(!stka.empty()){
    //         if(stka.front() != current){
    //             stkb.push(stka.front());
    //             stka.pop();
    //         }
    //         else{
    //             stkc.push(stka.front());
    //             stka.pop();
    //         }
    //     }
    //     while(!stkb.empty()){
    //         stkc.push(stkb.front());
    //         stkb.pop();
    //     }
    //     stka = stkc;
    // }
    // int size = stka.size()-1;
    // for(int i = 0; i < size; i++){
    //     cout << stka.front() << " ";
    //     stka.pop();
    // }
    // cout << stka.front() << endl;
    // stka.pop();
    return 0;

}
