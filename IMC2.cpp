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
#include <stack>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;






vector<int> getResult(vector<int> arrival, vector<int> street) {
    queue<pair<long long, long long>> stmain;
    queue<pair<long long, long long>> st1;
    for (int i = 0; i < arrival.size(); i++) {
        if (street[i] == 0) {
            stmain.push({ arrival[i], i });
        }
        else if (street[i] == 1) {
            st1.push({ arrival[i], i });
        }
    }
    vector<int> ret(arrival.size(), -1);
    bool prev1 = true;
    bool prev_has_car = false;
    long long cursec = 0;
    while (!st1.empty() || !stmain.empty()) {

        if (st1.empty()) {
            while (!stmain.empty()) {
                cursec = cursec > stmain.front().first ? cursec : stmain.front().first;
                ret[stmain.front().second] = cursec;
                stmain.pop();
                cursec++;
            }
            break;
        }
        else if (stmain.empty()) {
            while (!st1.empty()) {
                cursec = cursec > st1.front().first ? cursec : st1.front().first;
                ret[st1.front().second] = cursec;
                st1.pop();
                cursec++;

            }
            break;
        }
        
        if(min(st1.front().first, stmain.front().first) - cursec > 1) {
            prev1 = true;
        }
        cursec = max(cursec, min(st1.front().first, stmain.front().first));
        if (st1.front().first <= cursec && stmain.front().first <= cursec) {
            if (prev1 == true) {
                ret[st1.front().second] = cursec;
                st1.pop();
                cursec++;
            }
            else {
                ret[stmain.front().second] = cursec;
                stmain.pop();
                cursec++;
                prev1 = false;
            }
        }
        else {
            if (st1.front().first<= cursec) {
                ret[st1.front().second] = cursec;
                st1.pop();
                cursec++;
                prev1 = true;
            }
            else {
                ret[stmain.front().second] = cursec;
                stmain.pop();
                cursec++;
                prev1 = false;
            }
        }



    }

    return ret;

}

int main() {
    vector<int> a = { 0,0,1,4 };
    vector<int> b = { 0,1,1,0 };
    vector<int> temp;
    temp = getResult(a, b);
    for (auto i : temp) {
        cout << i << endl;
    }
    return 0;
}