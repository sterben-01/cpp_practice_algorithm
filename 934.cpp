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
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;
/*
text 934 最短的桥。和猿辅导二面一样的题。DFS+BFS
&第一步，使用DFS，找到第一个岛和他周围的一圈0，把这几个0的坐标放入队列。
!注意，这道题使用DFS的最核心原因是我们要找到岛周围的一圈0. 但是比如994腐烂的橘子，因为只要这个橘子在烂的边上，那么他一定会懒。所以只要找到烂橘子即可
!相当于，如果只找岛，显然不需要DFS，但是要找岛周围的一圈0，所以要DFS。所以994只需要找烂橘子，不需要周围一圈，自然不需要DFS
& 第二步，使用BFS，一圈一圈地向外扩张。直到找到1为止
举例：

0 1 0
0 0 0
0 0 1

第一次DFS后，我把找到的0标为2
2 1 2
3 2 3
0 3 1

我们在BFS的时候，注意，这3个2是一圈，也就是步长为1.
在这三个2的基础上，这些3统一是一圈，因为步长是2。
所以我们需要使用两个while进行BFS，第一个是老规矩看队列是否为空。
第二个while的意义是记录我们的圈数。所以我们有一个size去维护当前队列的大小
一开始3个点，所以队列大小为3。在遍历第一层的过程中，后续加入的点一定是第二层而不会是第三层。因为只走一步。
所以当第一层3个点遍历完毕后，此时队列的大小就是第二层的点的数量了。
!注意代码里面红色部分要额外标记2，是因为我们是通过第一个1找了一圈0.然后每一个0进行BFS。我们需要把自身的0的位置标记为2。不然会重复标记。
!994不需要额外标记是因为我们不是从烂橘子外面开始走的，是从烂橘子开始走的。每一个外围的好橘子会被标记为2再放入队列，所以不会重复标记。

*/

class Solution {
public:
    queue<pair<int,int>> zeros_pos;
    int shortestBridge(vector<vector<int>>& grid) {
        bool is_find  = false;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){

                    dfs(grid, i, j); //找到第一个岛后把第一个岛周围的0的位置拿出来即可。
                    is_find = true;
                    break;
                }

            }
            if(is_find == true){
                break;
            }

        }
        int count = 0;
        while(!zeros_pos.empty()){ //标准BFS的第一层while

            int size = zeros_pos.size(); //每一层有几个点。
            while(size > 0){
                int row = zeros_pos.front().first;
                int col = zeros_pos.front().second;
                zeros_pos.pop();
                if(grid[row][col] == 1){ //如果找到1了，就return
                    return count;
                }
                grid[row][col] = 2; //!记得标记为2，避免相同的点重复加入队列。
                if(is_valid(grid, row+1,col) && grid[row+1][col] != 2){ //&拆解四个方向的BFS。注意BFS只走一步。
                    if(grid[row+1][col] == 0){  //&这里要把为0和1分开判断。如果这个点是0，就加入队列并且标记为2。
                        grid[row+1][col] = 2;
                    }
                    zeros_pos.push({row+1,col});//&如果是1， 加入队列。因为我们会在下一圈进来的时候发现这个1，然后return。所以这个1不能标记为2。
                }
                if(is_valid(grid, row-1,col) && grid[row-1][col] != 2){ //%四个方向。注意判断是否是对应值的时候要先判断是否出界了。
                    if(grid[row-1][col] == 0){
                        grid[row-1][col] = 2;
                    }
                    zeros_pos.push({row-1,col});
                }
                if(is_valid(grid, row,col+1) && grid[row][col+1] != 2){
                    if(grid[row][col+1] == 0){
                        grid[row][col+1] = 2;
                    }
                    zeros_pos.push({row,col+1});
                }
                if(is_valid(grid, row,col-1) && grid[row][col-1] != 2){
                    if(grid[row][col-1] == 0){
                        grid[row][col-1] = 2;
                    }
                    zeros_pos.push({row,col-1});
                }
                size--;
            }
            count++;
        }

        return count;


    }
    void dfs(vector<vector<int>>& grid, int row, int col){ //使用DFS，找到第一个岛和他周围的一圈0，把这几个0的坐标放入队列。

        if(!is_valid(grid, row, col)){
            return;
        }
        if(grid[row][col] == 2){
            return;
        }
        if(grid[row][col] == 0){
            zeros_pos.push({row,col}); //如果是0就放入队列，又因为我们只找周围一层，所以遇到0放入队列后就return。
            return;
        }
        grid[row][col] = 2; //走过的依旧要标为2，避免死循环。
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
    bool is_valid(vector<vector<int>>& grid, int row, int col){
        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()){
            return true;
        }
        return false;
    }
};