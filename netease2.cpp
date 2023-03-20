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
using namespace std;

struct find_union {
    vector<int> father;
    vector<pair<int, int>> node;
    vector<int> node_v2;
    vector<int> rank;
    find_union(int x) :father(vector<int>(x)), rank(vector<int>(x)) {
        for (int i = 0; i < x; i++) {
            father[i] = i;
        }
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (rank[root_x] < rank[root_y]) {
                father[root_x] = root_y;
            } 
            else {
                father[root_y] = root_x;
            }
            if (rank[root_x] == rank[root_y]) {
                rank[root_x] = rank[root_x] + 1;
            }
            node.emplace_back(root_x, root_y);
            node_v2.emplace_back(root_y);
        }
    }
    vector<pair<int, int>> getret() {
        return node;
    }
    vector<int> getret_v2() {
        return node_v2;
    }
};

struct mysort {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second > b.second) {
            if (a.first < b.first) {
                return true;
            }
            return true;
        }
        return false;
    }
};

//int main() {
//    vector<int> color{ 1,2,2,3,3 };
//    vector<vector<int>> edge{ {0,1,0,0,0},{1,0,1,0,0},{0,1,0,1,1},{0,0,1,0,1},{0,0,1,1,0} };
//    vector<pair<int, int>> node;
//    unordered_map<int, int>color_map;
//    for (int i = 0; i < color.size(); i++) {
//        color_map[i] = color[i];
//    }
//    find_union ff(edge[0].size());
//    for (int i = 0; i < edge.size(); i++) {
//        for (int j = 0; j < edge[0].size(); j++) {
//            if (edge[i][j] == 1) {
//                ff.merge(i, j);
//            }
//        }
//    }
//    vector<pair<int, int>> ret = ff.getret();
//    vector<int> ret_v2 = ff.getret_v2();
//    //int cur_node = 1;
//    //for (auto& i : edge) {
//    //    for (int index = 0; index < i.size(); index++) {
//    //        if (i[index] == 1) {
//    //            node.emplace_back( cur_node, index+1 );
//    //        }
//    //    }
//    //    cur_node++;
//    //}
//    //int cur_pivot = 1;
//    //vector<int> ans;
//    //int num = 0;
//    //for (auto& i : node) {
//    //    if (cur_pivot = i.first) {
//    //        if (color_map[i.first] == color_map[i.second]) {
//
//    //        }
//    //    }
//    //}
//
//    vector<vector<int>> candidate;
//    int cur_val = -1;
//    vector<int> temp;
//    for (int i = 0; i < ret.size(); i++) {
//        if (ret[i].first != cur_val) {
//            candidate.emplace_back(temp);
//            temp.clear();
//            temp.push_back(ret[i].first);
//            temp.push_back(ret[i].second);
//        }
//        else {
//            temp.push_back(ret[i].second);
//        }
//        cur_val = ret[i].first;
//    }
//    candidate.emplace_back(temp);
//
//    int maxans = 0;
//    vector<int> ansnum;
//    for (auto& i : candidate) {
//        if (!i.empty()) {
//            vector<int> temppoint;
//            for (int j = 0; j < i.size(); j++) {
//                if (temppoint.empty()) {
//                    temppoint.push_back(i[j]);
//                }
//                else {
//                    if (color_map[i[j]] != color_map[temppoint.back()]) {
//                        break;
//                    }
//                    else {
//                        temppoint.push_back(i[j]);
//                    }
//                }
//            }
//
//            
//        }
//    }
//
//
//
//
//    cout << "e" << endl;
//    return 0;
//}

int find_sub(const string& target, const string& source) {
    for (int i = 0; i < source.size() - target.size(); i++) {
        int j = 0;
        while (j < target.size() && source[i + j] == target[j]) {
            j++;
        }
        if (j == target.size()) {
            return i;
        }
    }
    return -1;
}


int main() {
    string source = "string";
    string target = "tr";
    cout << find_sub(target, source) << endl;
    return 0;
}