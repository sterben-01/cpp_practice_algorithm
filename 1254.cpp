#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <future>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

/*
text 这题有毛病。封闭岛屿的数量。这个封闭的意思是完全由1包围的岛。
那么我们直接套用框架。注意我们只需要遍历0开始的地方。因为我们这里和之前不一样。之前1是岛，现在0是岛。
&注意，贴着边的岛不算。那么我们在判断出界的时候就return0就行，因为这个岛贴边了。剩下的都一样。
*/

class Solution {
public:
    //int flag;
    int closedIsland(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    //flag = 1;
                    sum = sum + triverse(grid, i, j);
                    //sum = sum + flag;
                }
            }
        }
        return sum;
    }
    int triverse(vector<vector<int>>& grid, int row, int col){
        if(!is_valid(grid, row, col)){
            //flag = 0;
            return 0;
        }
        if(grid[row][col] == 1){
            return 1;
        }
        if(grid[row][col] == 2){
            return 1;
        }
        grid[row][col] = 2;
        int a = triverse(grid, row+1, col);
        int b = triverse(grid, row-1, col);
        int c = triverse(grid, row, col+1);
        int d = triverse(grid, row, col-1);
        if(a == 0 || b == 0 || c == 0 || d == 0){
            return 0;
        }
        return 1;
    }
    bool is_valid(vector<vector<int>>& grid, int row, int col) {
        if (row >= 0 && col >= 0 && row <= grid.size() - 1 && col <= grid[0].size() - 1) {
            return true;
        }
        return false;
    }
};