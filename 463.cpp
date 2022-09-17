#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


/*
岛屿周长和岛屿面积的核心差不多。不过需要注意几点
第一点是，如果下一个方块出界了或者是进入海里了，就返回1。因为对应了一条边。
&一个方块有四条边，向上向下向左向右走各对应一条边。
!因为恰好只有一个岛屿，所以只需要找到第一个1走一圈即可。
第二点是area函数return不需要+1。因为岛屿面积我们是有当前岛屿面积的也就是1。但是周长没有当前周长所以不需要+1。
*/




class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ret = area(grid, i, j);
                }
            }
        }
        return ret;

    }


    int area(vector<vector<int>>& grid, int row, int col){
        if(!in_area(grid, row, col)){
            return 1;               //如果这个地方出界了，那么就有了一条边
        }

        if(grid[row][col] == 0){
            return 1;               //如果这个地方是海，也证明有了一条边
        }

        if(grid[row][col] != 1){
            return 0;               //如果这个地方是遍历过的陆地格子，没用。返回0
        }

        grid[row][col] = 2;         //设置这个格子已遍历

        int up = area(grid, row + 1, col);
        int down = area(grid, row - 1, col);
        int left = area(grid, row, col - 1);
        int right = area(grid, row, col + 1);

        return up + down + left + right; //注意695要加1是因为算的是岛屿面积。当前这个岛屿就是1.但是这里是算周长，没有当前岛屿周长这个东西。

    }


    bool in_area (const vector<vector<int>>& grid, int row, int col){
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()){
            return true;
        }
        return false;
    }

};