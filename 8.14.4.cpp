#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <map>
#include <limits.h>
using namespace std;


int main(){
    int longsize, width;
    cin >> longsize;
    cin >> width;
    vector<vector<int>> game_map(longsize, vector<int>(width,0));
    int paint_num;
    cin >> paint_num;
    for(int i = 0; i < paint_num; i++){
        string temp;
        cin >> temp;
        int index = 0;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] != ','){
                index++;
            }
            else{
                break;
            }
        }
        // string N = temp.substr(0,index);
        // string M = temp.substr(index+1,temp.size());
        int N = atoi(temp.substr(0,index).c_str());
        int M = atoi(temp.substr(index+1,temp.size()).c_str());
        game_map[N][M] = 1;
    }

    // int index =0 ;
    // for(int i = 0; i < temp.size(); i++){
    //     if(s[i] != ','){
    //         index++;
    //     }
    //     else{
    //         break;
    //     }
    // }
    // cout << index << endl;
    // string N = s.substr(0,index);
    // string M = s.substr(index+1,s.size());
    // cout << N << M << endl;
    return 0;

}