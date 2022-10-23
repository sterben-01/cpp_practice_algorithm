#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unistd.h>
#include <unordered_map>
#include <memory>
#include <queue>
#include <sstream>
using namespace std;

/*
text 哈希表是一种思想。不一定非要使用map或者set的方式去重。我们DFS中的标记也算是哈希表的一种。哈希表的核心思想就是查表。
这道题只需要查看一行一列和一个box内是否有重复数字即可。所以只需要有三张表。每张表的第一位代表当前的行数或者列数或者是box数，第二位是具体数字。
[9][10]的原因：
9是因为最多9*9
10是因为数字最多到9，我们为了有下标9，方便计算。
col_hash[5][3] = 1的意思是 第五列中出现过了3这个数字。
& 核心其实是把数字下表转换为第几个box转换方式就是 列数/3 + 行数/3*3 比如第三行第九列应该是第六个box。就是9/3 + 3/3*3 = 3+3 = 6
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col_hash [9][10] {0};
        int row_hash [9][10] {0};
        int box_hash [9][10] {0};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }

                int num = board[i][j] - '0';
                if(col_hash[j][num] == 1){
                    return false;
                }
                col_hash[j][num] = 1;
                if(row_hash[i][num] == 1){
                    return false;
                }
                row_hash[i][num] = 1;
                int cur_box = j/3 + i/3*3;
                if(box_hash[cur_box][num] == 1){
                    return false;
                }
                box_hash[cur_box][num] = 1;

            }
        }
        return true;
    }
};