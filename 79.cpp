#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
using namespace std;
/*
text 单词搜索 经典DFS+回溯
&要点注意！，这个valie和DFS函数必须引用传参，否则超时。由于是引用传参，所以需要回溯。标记了*的需要记录原来的值，然后再最后面return之前赋值回去。
&必须赋值回去的原因是如果顺着一条路，走到某个地方后整条路标记为*了最后发现不行，那么我们回去之后走过的地方依旧还是*则会被堵死。
经典的例子就是假设在i处同时可以向下或者向左走，然后先向下走，绕了一圈后走到i的左边了然后接着走。此时i的下面和左边都是* 结果发现此路不通，然后回到i。
此时由于左侧已经被标记为*了就被误判为左边已经走过了。所以会出问题、
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) { //从board的某一个点开始。如果和字符串的第一个字符相等，就开始遍历。
                if (DFS(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool is_valid(vector<vector<char>>& board, int row, int col) {
        if (row >= 0 && row <= board.size() - 1 && col >= 0 && col <= board[0].size() - 1) { //判断是否越界
            return true;
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, int row, int col, string& world, int index) {
        if (index > world.size() - 1) { //如果已经等于或者超过字符串长度了。就是true
            return true;
        }
        if (!is_valid(board, row, col)) { //越界 false
            return false;
        }
        if (board[row][col] == '*') { //如果已经走过了，false
            return false;
        }
        else if (board[row][col] != world[index]) { //如果字符不相等，false
            return false;
        }

        char temp = board[row][col]; //为了回溯，记录原值
        board[row][col] = '*'; //标记

        bool a = DFS(board, row + 1, col, world, index + 1); //四叉树遍历。下面的判断条件是做为优化的。
        if (a == true) {
            return true;
        }

        bool b = DFS(board, row, col + 1, world, index + 1);
        if (b == true) {
            return true;
        }

        bool c = DFS(board, row - 1, col, world, index + 1);
        if (c == true) {
            return true;
        }

        bool d = DFS(board, row, col - 1, world, index + 1);
        if (d == true) {
            return true;
        }


        board[row][col] = temp; //回溯赋值回去。
        return false; //return
    }
};
