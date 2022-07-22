#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
核心是遍历四叉树

*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    if(area(grid, i, j)){
                        //只要这块陆地有遍历价值，证明以当前方块为核心的陆地已经拓展完毕，如果可以拓展证明是一块独立的岛屿。数量+1
                        count ++ ;
                    }
                }
            }
        }
        return count;
    }




    bool area(vector<vector<char>>& grid, int row, int col){
        if(!in_area(grid, row, col)){
            return 0;
        }
        if(grid[row][col] != '1'){
            return 0;
        }

        grid[row][col] = '2'; //这行是核心。将遍历过的位置标为2.

        /*
        下面的目的是四叉树遍历。核心目的是从当前的这个陆地方块，围绕这块陆地向四个方向拓展。把拓展过的标为2.
        直到遇到水 或 出界了 或 遇到2了就停止往那个方向扩展。
        返回值的目的是，我们遍历整个地图时，判断遇到的陆地是否还有价值，也就是是否遍历过了或者不满足条件。
        */
        area(grid, row+1, col);
        area(grid, row - 1, col);
        area(grid, row, col - 1);
        area(grid, row, col+1);

        return 1;

    }


    bool in_area(vector<vector<char>>& grid, int row, int col){
        if(row>=0 && row < grid.size() && col >=0 && col < grid[0].size()){
            return true;
        }
        return false;
    }

};