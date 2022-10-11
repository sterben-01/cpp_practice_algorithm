#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <string>
#include <bitset>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> my_map;
        vector<vector<string>> ret;
        map<char, int> tempmap;
        for (int i = 0; i < strs.size(); i++) {
            int sum = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                tempmap[strs[i][j]]++;
            }

            string key;
            for (auto& i : tempmap) {

                key+= i.first + to_string(i.second);
            }
            my_map[key].push_back(strs[i]);
            tempmap.clear();
        }

        vector<string> temp;
        for (auto& i : my_map) {
            for (auto& j : i.second) {
                temp.emplace_back(j);
            }
            ret.emplace_back(temp);
            temp.clear();
        }
        return ret;
    }
};
