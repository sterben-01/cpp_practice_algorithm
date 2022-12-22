#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;


/*
red:
    left: {1,2,...}
    right:{4,5,...}
blue:
    left:
    right:
*/


void process(vector<vector<string>>& input) {
    unordered_map<string, map<string, vector<string>>> my_map;
    vector<vector<string>> ret;
    for (int i = 0; i < input.size(); i++) {
        my_map[input[i][2]][input[i][1]].push_back(input[i][0]);
    }

    for (auto t = my_map.begin(); t != my_map.end(); t++) {

        if (t->second.size() > 1) { //必须左右都有过。
            auto firstit = t->second["left"].begin();
            auto secondit = t->second["right"].begin();
            while (firstit != t->second["left"].end() && secondit != t->second["right"].end()) { //左右数组同时开始遍历。直到其中一个为空。
                ret.emplace_back(vector<string>{*firstit, * secondit});
                firstit++;
                secondit++;
            }
        }
    }

    for (auto& i : ret) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

}


int main() {
    vector<vector<string>> input{ {"1","left","red"}, {"2","left","red"},{"3","left","red"},{"4","right","red"},{"5","right","red"},{"6","right","red"}, {"7","right","yellow"} };
    process(input);
    return 0;
}

