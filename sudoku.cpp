#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){  // 遍历行
            for(int j = 0; j < board[0].size(); j++){ //遍历列
                if(board[i][j]!='.'){ //如果已经有数字了就跳过
                    continue;
                }
                for(char temp='1'; temp<='9';temp++){ //注意这是char 而且是1-9不是0到9
                    if(is_valid(i,j,temp,board) == false){
                        continue;
                    }
                    board[i][j] = temp;
                    if(backtracking(board) == true){ //找到一组解就返回。
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false; //一个位置试了9种都放不下那就说明这题无解。
            }
        }
        return true;

    }
    bool is_valid(int row, int col, char insertnum, vector<vector<char>>& board){ //这块注意不要写反了 先行后列 而且这种是找到一组解就返回所以有bool返回
        for(int i = 0; i < 9; i++){ //看行内是否有重复
            if(board[row][i] == insertnum){
                return false;
            }
        }
        for(int j = 0; j < 9; j++){
            if(board[j][col] == insertnum){ //看列内是否有重复
                return false;
            }
        }
        int startrow = (row/3)*3; //看当前9宫格内。此处很巧妙 例：8/3=2 2*3=6 所以8的从6开始看看678这三个地方(从0到8)
        int startcol = (col/3)*3;
        for(int i = startrow; i < startrow+3;i++){
            for(int j = startcol; j<startcol+3;j++){
                if(board[i][j] == insertnum){
                    return false;
                }
            }
        }
        return true;
    }
};