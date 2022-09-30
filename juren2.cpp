#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> ret;


bool is_valid(vector<vector<int>>& grid, int row, int col) {
    if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()) {
        return true;
    }
    return false;
}

void dfs(vector<vector<int>>& grid, int row, int col, int sum) {
    if (!is_valid(grid, row, col)) {
        return;
    }
    sum = sum + grid[row][col];
    if (row == grid.size() - 1 && col == grid[0].size() - 1) {
        ret.push_back(sum);
        return;
    }
    dfs(grid, row + 1, col, sum);
    dfs(grid, row, col + 1, sum);
}

int result(vector<vector<int>>& grid) {
    dfs(grid, 0, 0, 0);
    sort(ret.begin(), ret.end(), greater<int>());
    //cout << ret[0] << endl;
    return ret[0];
}
int main(){
    vector<int> temp;
    char a;
    while(cin >> a){
        if(a == '[' || a == ',' || a==']'){
            continue;
        }
        temp.push_back(a-'0');
        if(cin.get() == '\n'){
            break;
        }
    }
    int size = sqrt(temp.size());
    int count = 0;
    vector<vector<int>> grid;
    for(int i = 0; i < size; i++){
        vector<int>a;
        for(int j = 0; j < size; j++){
            a.push_back(temp[count]);
            count++;
        }
        grid.push_back(a);   
    }
    // for(auto j:grid){
    //     for(auto i:j){
    //         cout << i;
    //     }
    //     cout << endl;
    // }
    int s = result(grid);
    cout << s << endl;
    return 0;
}