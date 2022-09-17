#include <bitset>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

class mymax {
public:
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        return a.second < b.second;
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    int minOperations(string str) {
        // write code here
        unordered_map<char, int> my_map;
        for (int i = 0; i < str.size(); i++) {
            my_map[str[i]]++;
        }
        auto t = max_element(my_map.begin(), my_map.end(), mymax());
        int count = 0;
        int size = my_map.size();
        while (!my_map.empty()) {

            auto t = max_element(my_map.begin(), my_map.end(), mymax());
            if (t->second >= 2) {
                t->second = t->second - 2;
                count++;
                size = size + 1;
            }
            if (t->second == 0) {
                my_map.erase(t);
            }
            t = max_element(my_map.begin(), my_map.end(), mymax());
            if (t->second <= 1 || size >= 26) {
                break;
            }
        }
        cout << count << endl;
        return count;
    }
};
int main() {
    Solution s;
    s.minOperations("aaaabb");
    return 0;
}