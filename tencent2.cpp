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
#include <stdarg.h>
#include <future>
#include <thread>
#include <numeric>
#include <bitset>
using namespace std;


class mymax {
public:
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) const {
        if (abs(a.first - a.second.first) <= abs(b.first - b.second.first)) {
            return true;
        }
        return false;
    }
};


int main() {

    vector<int> vec = { 8,7,1024 };
    int num = 2;
    unordered_map<int, pair<int,int>> my_map;
    for (int i = 0; i < vec.size(); i++) {
        bitset<32>mb(vec[i]);
        if (my_map.find(vec[i]) != my_map.end()) {
            my_map[vec[i]].second++;
        }
        else {
            my_map[vec[i]] = make_pair<int, int>(mb.count(), 1);
        }
    }

    for (int i = 0; i < num; i++) {
        auto t = max_element(my_map.begin(), my_map.end(), mymax());
        int num = t->first;
        int ones = bitset<32>(t->first).count();
        int times = t->second.second;
        bool find = false;
        if (my_map.find(ones) != my_map.end()) {
            my_map[ones].second++;
            my_map.erase(t->first);
        }
        else {
            my_map[ones] = make_pair<int, int>(bitset<32>(ones).count(), 1);
            my_map.erase(t->first);
        }
    }
    long long  sum = 0ll;

    for (auto t = my_map.begin(); t != my_map.end(); t++)
    {
        for (int i = 0; i < t->second.second; i++) {
            sum = sum + (long long)t->first;
        }
    }
    cout << sum << endl;
    return 0;
   
}