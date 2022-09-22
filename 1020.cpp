#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>

/*
text 和130一样。看和边缘上的1连着的1有多少，然后把这些1换成0或者是别的。最后统计一下剩余的1就是不和边缘连着的1.
如果标记为0，直接把每个格子的值相加即可。如果标记为别的就需要遍历。
*/

using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size() - 1){
                    dfs(grid, i, j);
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid, int row, int col){
        if(!is_valid(grid, row, col)){
            return;
        }
        if(grid[row][col] == 0){
            return;
        }
        if(grid[row][col] == 2){
            return;
        }
        grid[row][col] = 2;
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
    bool is_valid(vector<vector<int>>& grid, int row, int col) {
        if (row >= 0 && col >= 0 && row <= grid.size() - 1 && col <= grid[0].size() - 1) {
            return true;
        }
        return false;
    }
};