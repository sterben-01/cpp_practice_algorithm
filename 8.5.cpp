#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;



// int solution(string &S, int B) {
//     // write your code in C++ (C++14 (g++ 6.2.0))
//     vector<int> holes;
//     int max = 0;
//     if(B <= 1){
//         return 0;
//     }
//     for(unsigned int i = 0; i < S.size(); i++){
//         if(S[i] == '.'){
//             if(max != 0){
//                 holes.push_back(max);
//             }
//             max = 0;
//         }
//         else{
//             max = max + 1;
//         }
//     }
//     if(S[S.size()-1] == 'x'){
//         holes.push_back(max);
//     }
//     sort(holes.begin(), holes.end());
//     int holesmax = 0;
//     for(int i = holes.size() - 1; i >= 0; i--){
//         if (B - (holes[i] + 1) >=0){
//             B = B - (holes[i] + 1);
//             holesmax += holes[i];
//             if(B <= 1){
//                 break;
//             }

//         }
//         else{
//             holesmax += B-1;
//             break;
//         }
//     }
//     return holesmax;


// }

int main(){
    vector<int> A = {3,2,3,1};
    vector<int> B = {1,3,1,2};
    vector<vector<int>> temp;
    temp.emplace_back(vector<int>{A[0], B[0]});
    for(auto i:temp){
        for(auto j:i){
            cout << j;
        }
        cout << endl;
    }
}