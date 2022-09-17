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
&这题注意理解性错误。我们DFS里面的返回值其实一点意义都没有。我们这个题的核心目的是：把遍历过的1连起来的区域给换成别的数字而已。然后找有几个是1的起点。
&所以这个题目的核心是从1开始找，把所有1的地方换成2。然后直到没有地方可以走了，我们就退出来。把结果+1。因为找到了一个岛屿。然后看看有没有下一个是1的地方，从那个地方继续走。
&所以我们也可以换成另一种方式写。注释掉的部分就是

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

/*
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){ //!注意这里。我们可以从1开始走。就不需要判断dfs返回值。
                area(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

void area(vector<vector<char>>& grid, int col, int row){ //!不需要返回值
    if(!is_valid(grid, col, row)){
        return;
    }
    if(grid[col][row] != '1'){
        return;
    }
    grid[col][row] = '2';
    area(grid, col+1, row);
    area(grid, col, row+1);
    area(grid, col-1, row);
    area(grid, col, row-1);
    return;

}
*/


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