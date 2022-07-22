#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
/*
岛屿问题理解为递归DFS遍历四叉树即可。每个格子的前进就是上下左右四种。唯一区别就是遍历过的需要设置为2避免递归时重复遍历。

理论上因为需要在area函数修改grid的数据。但是不知道修改原grid会不会出问题。所以复制了一次这样每一次新格子调用area函数的时候用的都是原始数组。
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> tt = grid;
        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int temp = area(tt, i, j);
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