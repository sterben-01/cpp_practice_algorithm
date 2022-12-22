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
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

/*
text DFS 注意终止条件

*/

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        temp.push_back(0);
        dfs(graph, 0, temp);
        return ret;
    }

    void dfs(vector<vector<int>>& graph, int index, vector<int>& added){
        if(added.back() == graph.size() - 1){
            ret.emplace_back(added);
            return;
        }
        for(int i = 0; i < graph[index].size(); i++){
            added.push_back(graph[index][i]);
            dfs(graph, graph[index][i], added);
            added.pop_back();
        }

    }
};