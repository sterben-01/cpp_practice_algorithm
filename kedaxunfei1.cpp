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

int calc(vector<vector<int>>& grid, vector<vector<int>>& kernel, int l, int r, int t, int b){
    int xsize = grid[0].size()-1;
    int ysize = grid.size()-1;
    int sum = 0;
    for(int i = max(0,t); i <= min(ysize, b); i++){
        for(int k = max(0, l); k <= min(xsize, r); k++){
            sum = sum + grid[i][k] * kernel[i-t][k-l];
        }
    }
    return min(255,max(0, sum));
}



int main(){
    int m, n,k, l;
    cin >> m >> n >> k >> l;
    vector<vector<int>> my_vec;
    vector<vector<int>> kernel;
    vector<vector<int>> ret(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        vector<int> tempvec;
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            tempvec.push_back(temp);
        }
        my_vec.push_back(tempvec);
    }
    for(int i = 0; i < k; i++){
        vector<int> tempvec;
        for(int j = 0; j < l; j++){
            int temp;
            cin >> temp;
            tempvec.push_back(temp);
        }
        kernel.push_back(tempvec);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int l = j-1;
            int r = j+1;
            int t = i-1;
            int b = i+1;
            int sum = calc(my_vec, kernel, l, r, t, b);
            ret[i][j] = sum;
        }
    }
    
    for(auto i:ret){
        for(auto j:i){
            cout << j <<" ";
        }
        cout << endl;
    }

    return 0;
}