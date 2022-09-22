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

bool is_valid(vector<vector<int>>& image, int row, int col){
    if(row >= 0 && col >= 0 && row <= image.size()-1 && col <= image[0].size() - 1){
        return true;
    }
    return false;
}

int dfs(vector<vector<int>>& image, int row, int col){
    if(!is_valid(image, row, col)){
        return 0;
    }
    if(image[row][col] != 1){
        return 0;
    }
    image[row][col] = 2;
    int up = dfs(image, row-1, col);
    int down = dfs(image, row+1, col);
    int left = dfs(image, row, col-1);
    int right = dfs(image, row, col+1);
    return up+down+left+right+1;
}



int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> image;
    vector<vector<int>> mod;
    for(int i = 0; i < m; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            int inp;
            cin >> inp;
            temp.push_back(inp);
        }
        image.push_back(temp);
    }
    for(int i = 0; i < m; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            int inp;
            cin >> inp;
            temp.push_back(inp);
        }
        mod.push_back(temp);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(image[i][j] != mod[i][j]){
                image[i][j] = 0;
            }
            else{
                image[i][j] = 1;
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(image[i][j] == 1){
                int temp = dfs(image, i, j);
                ret = ret > temp ? ret:temp;
            }
        }
    }

    cout << ret << endl;



    return 0;

}