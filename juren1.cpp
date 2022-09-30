#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

unsigned int getLongest(string& s) {
    stack<char> mystk;
    unsigned int maxval = 0;
    unsigned int pos = 0;
    while (pos < s.size()) {
        unsigned int count = 0;
        while (!mystk.empty()) {

            if (pos < s.size() && !mystk.empty() && s[pos] == '0' && mystk.top() == '1') {
                count+=2;
                mystk.pop();
                pos++;
                if (pos >= s.size()) {
                    maxval = max(maxval, count);
                    break;
                }
                continue;
            }
            else {

                maxval = max(maxval, count);
                count = 0;
            }
            if (pos >= s.size()) {
                maxval = max(maxval, count);
                break;
            }
            mystk.push(s[pos]);
            pos++;
        }
        if (mystk.empty()) {
            mystk.push(s[pos]);
            pos++;
        }

    }


    //cout << maxval << endl;
    return maxval;
}

int main() {
    string s;
    cin >> s;
    int maxval = getLongest(s);
    cout << maxval << endl;
    return 0;
}