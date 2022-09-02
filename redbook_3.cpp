#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <memory>
#include <algorithm>
using namespace std;


void function(vector<vector<int>>& my_vec, unordered_map<int, vector<int>> my_map) {
    int maxcount = 0;
    for (int i = 0; i < my_vec.size(); i++) {
        int key = my_vec[i][0];
        int another = my_vec[i][1];
        auto t = my_map.find(key);
        if (t != my_map.end()) {
            for (auto item : t->second) {
                my_map.erase(item);
            }
            my_map.erase(key);
        }
        maxcount = maxcount > (1 + my_map.size()) ? maxcount : (1 + my_map.size());
    }
    cout << maxcount << endl;
}
int main() {
    int total = 6;
    vector<int>pre{ 1,2,2,3,3 };
    unordered_map<int, vector<int>> my_map;
    vector<vector<int>> my_vec;
    for (int i = 0; i < pre.size(); i++) {
        my_vec.push_back(vector<int>{pre[i], i + 2});
    }

    for (int i = 0; i < my_vec.size(); i++) {
        auto t = my_map.find(my_vec[i][0]);
        if (t == my_map.end()) {
            my_map.insert(make_pair(my_vec[i][0], vector<int>{my_vec[i][1]}));
        }
        else {
            t->second.push_back(my_vec[i][1]);
        }
    }
    function(my_vec, my_map);
    return 0;
}