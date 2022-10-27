#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <sstream>
using namespace std;

bool is_valid(vector<vector<int>>& grid, int row, int col){
    if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()){
        return true;
    }
    return false;
}
bool is_ok(vector<vector<int>> grid){
    int direction[4][2]{{0,1},{0,-1},{1,0},{-1,0}};
    queue<tuple<int,int,int>>my_que;
    vector<vector<bool>>used(grid.size(), vector<bool>(grid[0].size(),false));
    my_que.push({0,0,-1});
    used[0][0] = true;
    bool skip = true;
    while(!my_que.empty()){
        auto cur = my_que.front();
        if(get<0>(cur) == grid.size()-1 && get<1>(cur) == grid[0].size()-1){
            cout << "true" << endl;
            return true;
        }
        my_que.pop();
        if(grid[get<0>(cur)][get<1>(cur)] == 1){
            skip = true;
        }
        else if(grid[get<0>(cur)][get<1>(cur)] == 0){
            skip = false;
        }
        for(int i = 0;i < 4; i++){
            if(grid[get<0>(cur)][get<1>(cur)] == 1){
                if(is_valid(grid, get<0>(cur)+direction[i][0],get<1>(cur)+direction[i][1])){
                    if(used[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] == false && grid[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] == 1){
                        my_que.push({get<0>(cur)+direction[i][0],get<1>(cur)+direction[i][1], i});
                        used[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] = true;
                    }
                    else if(used[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] == false && grid[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] == 0){
                        if(skip == true){
                            my_que.push({get<0>(cur)+direction[i][0],get<1>(cur)+direction[i][1],i});
                        }
                        used[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] = true;
                    }
                }
            }
            else if(grid[get<0>(cur)][get<1>(cur)] == 0){
                if(is_valid(grid, get<0>(cur)+direction[i][0],get<1>(cur)+direction[i][1])){
                    if(get<2>(cur) == i && used[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] == false && grid[get<0>(cur)+direction[i][0]][get<1>(cur)+direction[i][1]] == 1){
                        my_que.push({get<0>(cur)+direction[i][0],get<1>(cur)+direction[i][1],i});
                    }
                }
            
            }
        }
    }
    cout<<"false" << endl;
    return false;


}


int main(){
    vector<vector<int>> a{{1,0,1},{0,0,0},{1,0,1}};
    vector<vector<int>> b{{1,1,0},{0,0,0},{0,1,1}};
    vector<vector<int>> c{{1,1,0,1,0,1,0},{0,0,0,0,0,0,0},{0,1,0,1,0,1,1}};
    vector<vector<int>> t4{{1,0,0,0,0,1},{1,0,0,1,1,1},{0,1,0,1,0,1},{1,1,0,0,0,0},{1,1,0,0,0,1}};
    vector<vector<int>> f4{{1,0,0,1,0,0},{1,1,0,1,1,0},{1,1,1,1,1,1},{0,0,0,0,0,0},{1,1,1,1,1,1},{1,0,0,1,0,0},{0,1,0,0,1,0},{0,0,1,0,0,1}};
    vector<vector<int>> f1{{1,0,0,0},{1,1,0,0},{0,0,1,1},{1,0,0,1}};
    vector<vector<int>> f2{{1,1,1,1},{1,0,1,0},{1,1,0,0},{1,0,0,1}};

    vector<vector<int>> f3{{1,0,1,0},{0,1,0,1},{1,0,1,0},{0,1,0,1}};

    is_ok(t4);

    return 0;
}