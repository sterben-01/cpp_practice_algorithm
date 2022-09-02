#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>


/*
text amazon OA medium
& Demolition robots
& 注释掉的是DFS
*/
using namespace std;
vector<int> ret;
bool is_valid(vector<vector<int>>& grid, int row, int col) {
    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
        return true;
    }
    return false;
}


// void triverse(vector<vector<int>>& grid, int row, int col, int count){
//     if(!is_valid(grid, row, col)){
//         return;
//     }
//     if(grid[row][col] == 0){
//         return;
//     }
//     if(grid[row][col] == -1){
//         return ;
//     }
//     if(grid[row][col] == 9){
//         ret.push_back(count);
//         return;
//     }
//     if(grid[row][col] == 1){
//         grid[row][col] = -1;
//         count++;
//     }
//     triverse(grid, row, col+1, count);
//     triverse(grid, row+1, col, count);
//     triverse(grid, row-1, col, count);
//     triverse(grid, row, col-1, count);

// }

int triverse(vector<vector<int>>& grid) {
    deque<vector<int>> my_deque;

    int row = 0;
    int col = 0;
    if (is_valid(grid, row + 1, col)) {
        if (grid[row + 1][col] == 1) {
            my_deque.push_back({ row + 1, col, 1 });
        }
    }
    if (is_valid(grid, row, col + 1)) {
        if (grid[row][col + 1] == 1) {
            my_deque.push_back({ row, col + 1, 1 });
        }
    }
    grid[0][0] = -1;
    while (!my_deque.empty()) {

        vector<int> temp = my_deque.front();
        my_deque.pop_front();
        if (grid[temp[0]][temp[1]] == 9) {
            return temp[2];
        }
        if (grid[temp[0]][temp[1]] == -1){
            continue;
        }
        if (grid[temp[0]][temp[1]] == 0) {
            continue;
        }
        grid[temp[0]][temp[1]] = -1;
        if (is_valid(grid, temp[0] + 1, temp[1])) {
            if (grid[temp[0] + 1][temp[1]] > 0) {
                my_deque.push_back({ temp[0] + 1, temp[1], temp[2] + 1 });

            }
        }
        if (is_valid(grid, temp[0], temp[1] + 1)) {
            if (grid[temp[0]][temp[1] + 1] > 0 ) {
                my_deque.push_back({ temp[0], temp[1] + 1, temp[2] + 1 });

            }
        }
        if (is_valid(grid, temp[0] - 1, temp[1])) {
            if (grid[temp[0] - 1][temp[1]] > 0) {
                my_deque.push_back({ temp[0] - 1, temp[1], temp[2] + 1 });
            }
        }
        if (is_valid(grid, temp[0], temp[1] - 1)) {
            if (grid[temp[0]][temp[1] - 1] > 0) {
                my_deque.push_back({ temp[0], temp[1] - 1, temp[2] + 1 });
            }
        }
    }
    return -1;

}

int solution(vector<vector<int>>& grid) {
    int res = triverse(grid);
    // for(auto i:ret){
    //     cout << i << endl;
    // }
    // sort(ret.begin(), ret.end());
    // cout << ret[0] <<endl;
    // return ret[0];
    cout << res << endl;
    return res;
}

int main() {
    vector<vector<int>>s{{1,0,0},{1,0,0},{1,9,1}};
    solution(s);


    return 0;
}