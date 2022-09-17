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
#include <future>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

/*
text 不同岛屿的数量。我们需要做的是记录一下走过的路径。看有多少种就可以了。因为我们一定是从一个有效岛屿开始找的。
&唯一的核心就是下面离开每一层递归的时候需要进行一下"回溯“.这里的回溯是模拟回溯，就是把往回走的路径也算上。
&为什么？
假设我们有如下地图
1 1 0
0 1 1
0 0 0
1 1 1
0 1 0
&如果我们不记录撤回的话，那么字符串永远记录的是单向有效路径。也就是下面的那块岛屿，走到下面的1的时候会记录2，然后走不通了往回走，不会记录。会回溯到中间的1的那个地方继续判断，发现右侧可以走，记录4. 所以两个岛都是424
&如果记录撤回的话，那么下面的岛屿会是42，然后发现下面的1的位置四个方向走不出去，就要return出去了。注意，我们走到下面的1的时候，函数的入参是2。所以走到那一个格子的时候才会把2加上去。所以撤回的时候自然也就是-2。
*/

class Solution {
public:
    set<string> counts;
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> counts;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    string temp;
                    backtracking(grid, i, j, temp, '.');
                    counts.insert(temp);
                    cout << temp << endl;
                }
            }
        }
        return counts.size();
    }
    void backtracking(vector<vector<int>>& grid, int row, int col, string& str, char direct) {

        if (!is_valid(grid, row, col)) {
            return;
        }
        if (grid[row][col] == 0) {
            return;
        }
        if (grid[row][col] == 2) {
            return;
        }
        grid[row][col] = 2;
        str = str + direct;
        backtracking(grid, row - 1, col, str, '1'); //上
        backtracking(grid, row + 1, col, str, '2'); //下
        backtracking(grid, row, col - 1, str, '3'); //左
        backtracking(grid, row, col + 1, str, '4'); //右
        str = str + '-' + direct;

    }
    bool is_valid(vector<vector<int>>& grid, int row, int col) {
        if (row >= 0 && col >= 0 && row <= grid.size() - 1 && col <= grid[0].size() - 1) {
            return true;
        }
        return false;
    }


};


int main() {
    Solution s;
        
    vector<vector<int>> my_vec{ {1, 1, 0},{0, 1, 1},{0, 0, 0},{1, 1, 1},{0, 1, 0} };
    s.numDistinctIslands(my_vec);
    return 0;
}