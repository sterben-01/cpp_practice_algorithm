#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
/*
岛屿问题理解为递归DFS遍历四叉树即可。每个格子的前进就是上下左右四种。唯一区别就是遍历过的需要设置为2避免递归时重复遍历。

岛屿问题核心就是DFS遍历。遍历过的位置标记为2， 不需要重复遍历。所以直接修改原grid没有问题。
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int temp = area(grid, i, j);
                    ret = (ret >= temp) ? ret : temp;
                }
            }
        }
        return ret;
    }


    int area(vector<vector<int>>& grid, int row, int col){
        if(!is_area(grid, row, col)){ //对应越界
            return 0;
        }
        if(grid[row][col] != 1){       //对应海洋或遍历过了
            return 0;
        }

        grid[row][col] = 2; //更新遍历过的值

        int up = area(grid, row - 1, col);
        int down = area(grid, row + 1, col);
        int left = area(grid, row, col - 1);
        int right = area(grid, row, col + 1);
        return 1 +left + right + up + down;

    }


    bool is_area(const vector<vector<int>>& grid, int row, int col){
        if(0 <= row && row < grid.size() && 0 <= col && col < grid[0].size()){
            return true;
        }
        return false;
    }

};