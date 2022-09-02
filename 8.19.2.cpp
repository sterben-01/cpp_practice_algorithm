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


bool isvalid(int size, int x, int y) {
    if (x < size && y < size && x >= 0 && y >= 0) {
        return true;
    }
    return false;
}

bool triverse(vector<vector<int>> chart, int x, int y, int step, vector<vector<int>>& res) {

    if (!isvalid(chart.size(), x, y)) {
        return 0;
    }
    if (chart[x][y] == -1) {
        return 0;
    }
    if (step == 0) {
        res.push_back({ x,y });
        return 0;
    }
    step--;
    chart[x][y] = -1;
    triverse(chart, x + 1, y, step, res);
    triverse(chart, x, y + 1, step, res);
    triverse(chart, x - 1, y, step, res);
    triverse(chart, x, y - 1, step, res);
}

int main() {
    int size = 3;
    //cin >> size;
    int pos1_x = 2;
    int pos1_y = 1;
    int pos2_x;
    int pos2_y;
    int pos3_x;
    int pos3_y;

    int mht1 = 2, mht2, mht3;

    vector<vector<int>> p1;
    vector<vector<int>> p2;
    vector<vector<int>> p3;
    vector<vector<int>> my_map(size, vector<int>(size, 0));
    triverse(my_map, pos1_x - 1, pos1_y - 1, mht1, p1);
    for (auto i : p1) {
        for (auto k : i) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}