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
text 单纯bfs 腐烂的橘子。要和934作对比。

*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int count = 0;
        queue<pair<int, int>>rotten;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fresh++; //统计新鲜橘子
                }
                else if(grid[i][j] == 2){
                    rotten.push({i,j}); //把所有烂橘子都放到队列里面
                }
            }
        }
        while(!rotten.empty()){
            int size = rotten.size();
            if(fresh == 0){
                return count;
            }
            while(size > 0){
                int row = rotten.front().first;
                int col = rotten.front().second;
                rotten.pop();
                if(is_valid(grid, row+1, col) && grid[row+1][col] ==1 ){ //BFS 如果不出界而且是新鲜橘子，把新鲜橘子标记为烂掉，新鲜橘子数量减一，并放入队列
                    grid[row+1][col] = 2;
                    fresh--;
                    rotten.push({row+1,col});
                }
                if(is_valid(grid, row-1, col) && grid[row-1][col] ==1 ){
                    grid[row-1][col] = 2;
                    fresh--;
                    rotten.push({row-1,col});
                }
                if(is_valid(grid, row, col+1) && grid[row][col+1] ==1 ){
                    grid[row][col+1] = 2;
                    fresh--;
                    rotten.push({row,col+1});
                }
                if(is_valid(grid, row, col-1) && grid[row][col-1] ==1 ){
                    grid[row][col-1] = 2;
                    fresh--;
                    rotten.push({row,col-1});
                }
                size--;
            }
            count++;
        }
        if(fresh > 0){ //走到最后发现新鲜橘子有剩余，那就是-1;
            return -1;
        }
        return count;
        
    }
    bool is_valid(vector<vector<int>>& grid, int row, int col){
        if(row >=0 && col>=0 && row< grid.size() && col < grid[0].size()){
            return true;
        }
        return false;
    }
};