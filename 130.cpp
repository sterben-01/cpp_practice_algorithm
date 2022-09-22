
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

/*
text 这题很类似于岛屿题，但是我们要换一个思路
我们的思路是
&所有的不和四周相邻的区域的O都可以被换成X。也就是说这个O只要不在边上，也不和边上的O挨着，就都换成X。
&那我们逆向思考，把所有边上的O和 和边上O连着的O标记为P，然后把所有的O都换成X，再把所有的P换成O就完了。
!说白了就是找到和四周的O相连的区域。
%所以很简单。
&还是有一个valid函数，不过我们这个函数只负责检查是否越界。 
&然后我们就进入主函数，如果越界了返回，如果是X或者是P就返回。也就是标注过的或者是本来就是X的就不用动了。
&然后如果遇到O了，就把O换成P，然后向四周扩展DFS。和岛屿一样
todo 关键点在于我们要从哪儿开始遍历。我们只从在四周的O开始遍历。因为我们只需要找到四周的O的连续区域即可。
*/

using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1){
                    if(board[i][j] == 'O'){
                        triverse(board, i,j);
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'P'){ //注意这里俩if不能倒过来写。
                    board[i][j] = 'O';
                }
            }
        }
        

    }
    void triverse(vector<vector<char>>& board, int col, int row){
        if(!is_valid(col, row, board)){
            return;
        }
        if(board[col][row] == 'X' || board[col][row] == 'P' ){
            return;
        }
        if(board[col][row] == 'O'){ //这个if可以不要
            
            board[col][row] = 'P';
            triverse(board, col, row+1);

            triverse(board, col, row-1);

            triverse(board, col+1, row);

            triverse(board, col-1, row);
        }
    }

    bool is_valid(int col, int row, vector<vector<char>>& board){
        if(col >= 0 && col < board.size() && row >= 0 && row < board[0].size()){
            return true;
        }
        return false;
    }
};