#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;



/*
text 经典dfs。
我们知道水往低处流，如果看这个点的水流能不能流到两侧，可以从高处往低走。也就是遍历每一个点。
但是我们可以逆向思考。也就是从边上往中间逆向遍历。我们把四周一圈的点进行逆向遍历，也就是往地图中间遍历。
&我们有两个数组，一个数组负责保留最左边和最上边的点的遍历结果，另一个保留最右侧和最下侧的遍历结果
&然后把每一个可以走得到的点都标记为true。最后同时遍历两个数组。如果某一个点在两个数组中都是true也就是都走得到，那么就说明这个点是我们要的点。
*/
class Solution {
public:
    int direction[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; //&储存四个方向。不用像以前DFS那样写四个if了。
    bool is_valid(vector<vector<int>>& matrix, int row, int col){
        if(row >= 0 && col >= 0 && row < matrix.size() && col < matrix[0].size()){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col){
        if(visited[row][col] == true){ //&标记为true不仅可以筛选结果，而且可以防止走回头路
            return;
        }
        visited[row][col] = true; //当前点标记为true
        for(int i = 0; i < 4; i++){ //&改用for循环进行dfs，不需要在写四个if了
            int next_row = row + direction[i][0]; //&找到下一个点的横纵坐标。也就是比如5,5的下一步的四个坐标分别是[5+(-1),5],[5+1,5],[5,5+(-1)],[5,5+1]
            int next_col = col + direction[i][1];
            if(!is_valid(heights, next_row, next_col)){ //&判断这个坐标是否出界。出界就跳过。
                continue;
            }
            if(heights[row][col] > heights[next_row][next_col]){ //&判断这个坐标是否满足要求。我们的下一个点需要比当前的点大，也就是爬高高。如果比当前点小就跳过。
            //当前格子比下一个格子大就可以往下走。所以逆向思维就是当前格子是正向思维的当前格子的下一个格子。所以也就是反过来。当前格子需要比下一个格子小。
                continue;
            }
            dfs(heights, visited, next_row, next_col); //坐标符合要求就进行DFS。
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> p_visited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> a_visited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> ret;
        for(int i = 0; i < heights.size(); i++){ //DFS遍历周围四边，这里是其中之二。
            dfs(heights, p_visited,i, 0); //最左侧一列
            dfs(heights, a_visited,i, heights[0].size()-1); //最右侧一列
        }
        for(int i = 0; i < heights[0].size(); i++){ //DFS遍历周围四边，剩下的两个。
            dfs(heights, p_visited, 0, i); //最上面一行
            dfs(heights, a_visited,heights.size()-1,i); //最下面一行
        }

        for(int i = 0; i < heights.size(); i++){ //判断如果有某个坐标在两个数组内都是true，证明是我们要的点。
            for(int j = 0; j < heights[0].size(); j++){
                if(a_visited[i][j] == true && p_visited[i][j] == true){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;

    }
};