#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

bool solution(vector<vector<int>> grid) {
    set<int> my_set;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            my_set.insert(grid[i][j]);
        }
        if(my_set.size() != 9){
            return false;
        }
        my_set.clear();
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            my_set.insert(grid[j][i]);
        }
        if(my_set.size() != 9){
            return false;
        }
        my_set.clear();
    }
    for(int i = 0; i < 7; i+=3){
        for(int j = 0; j < 7; j+=3){
            for(int k = 0; k < 3; k++){
                for(int m = 0; m < 3; m++){
                    my_set.insert(grid[i+k][j+m]);
                }
            }
            if(my_set.size() != 9){
                return false;
            }
        }
    }
    
    return true;
}
