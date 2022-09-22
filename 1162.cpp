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
text BFS 地图分析。这个和那个最短的桥也有点相似又不完全一样。
&0是海洋，1是陆地。不要被题目的曼哈顿距离啥的迷惑了，和我们之前的一层一层扩展是一样的。
&我们只要先把所有的陆地都入队，然后从各个陆地同时开始一层一层的向海洋扩散，那么最后扩散到的海洋就是最远的海洋！并且这个海洋肯定是被离他最近的陆地给扩散到的！
*/


class Solution {

public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> pos;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    pos.push({i,j}); //找到所有的陆地，放入队列
                    grid[i][j] = 2; //标记为2防止重复查询
                }
            }
        }
        int distance = 0;
        while(!pos.empty()){ //标准BFS模板

            int size = pos.size(); //填海造陆模板
            while(size > 0){
                int row = pos.front().first;
                int col = pos.front().second;
                pos.pop();
                
                if(is_valid(grid, row+1, col) && grid[row+1][col] == 0){ //判断是不是海洋。只要是海洋就往前走。
                    pos.push({row+1, col}); //入队
                    grid[row+1][col] = 2; //标记为走过了
                }   
                if(is_valid(grid, row-1, col) && grid[row-1][col] == 0){
                    pos.push({row-1, col});
                    grid[row-1][col] = 2;
                }
                if(is_valid(grid, row, col+1) && grid[row][col+1] == 0){
                    pos.push({row, col+1});
                    grid[row][col+1] = 2;
                }
                if(is_valid(grid, row, col-1) && grid[row][col-1] == 0){
                    pos.push({row, col-1});
                    grid[row][col-1] = 2;
                }
                size--;
            }
            distance++;
        }
        if(distance-1 == 0){ //如果distance是0证明全是陆地或者全是海洋
            return -1;
        }
        return distance-1; //记得减掉1。因为最后一轮的时候已经找到了，但还是会+一次distance
    }



    bool is_valid(vector<vector<int>>& grid, int row, int col){
        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()){
            return true;
        }
        return false;
    }
};