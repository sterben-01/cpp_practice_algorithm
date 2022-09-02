#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include<stack>
#include <queue>
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
    queue<int> stka;
    for(int i = 1; i <= number; i++){
        stka.push(i);
    }

    for(int i = 0; i < manipulate; i++){
        queue<int> stkb;
        queue<int> stkc;
        int current = order[i];
        while(!stka.empty()){
            if(stka.front() != current){
                stkb.push(stka.front());
                stka.pop();
            }
            else{
                stkc.push(stka.front());
                stka.pop();
            }
        }
        while(!stkb.empty()){
            stkc.push(stkb.front());
            stkb.pop();
        }
        stka = stkc;
    }
    int size = stka.size()-1;
    for(int i = 0; i < size; i++){
        cout << stka.front() << " ";
        stka.pop();
    }
    cout << stka.front() << endl;
    stka.pop();

}
