#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <map>
using namespace std;


int main() {
    int n = 2;
    //cin >> n;
    int m = 3;
    //cin >> m;
    int instruction = 5;
    //cin >> instruction;
    vector<vector<int>> my_vec(m, vector<int>(n, 0));
    my_vec[0][0] = 1;
    string ins = "SSDWW";
    //cin >> ins;
    int curn = 0;
    int curm = 0;
    int cleannum = 0;
    int totalcount = m * n - 1;
    for (int i = 0; i < instruction; i++) {


        if (ins[i] == 'S') {
            if (curn < my_vec.size()) {
                curn++;
                if (my_vec[curn][curm] != 1) {
                    totalcount--;
                }
                if (totalcount == 0) {
                    cout << "YES" << endl;
                    cout << i + 1 << endl;
                    return 0;
                }
                my_vec[curn][curm] = 1;
            }
        }
        else if (ins[i] == 'W') {
            if (curn > 0) {
                curn--;
                if (my_vec[curn][curm] != 1) {
                    totalcount--;
                }
                if (totalcount == 0) {
                    cout << "YES" << endl;
                    cout << i + 1 << endl;
                    return 0;
                }
                my_vec[curn][curm] = 1;
            }
        }
        else if (ins[i] == 'A') {
            if (curm > 0) {
                curm--;
                if (my_vec[curn][curm] != 1) {
                    totalcount--;
                }
                if (totalcount == 0) {
                    cout << "YES" << endl;
                    cout << i + 1 << endl;
                    return 0;
                    
                }
                my_vec[curn][curm] = 1;
            }
        }
        else if (ins[i] == 'D') {
            if (curm < my_vec[0].size()) {
                curm++;
                if (my_vec[curn][curm] != 1) {
                    totalcount--;
                }
                if (totalcount == 0) {
                    cleannum = i;
                    cout << "YES" << endl;
                    cout << i + 1 << endl;
                    return 0;
                }
                my_vec[curn][curm] = 1;
            }
        }
    }
    int nocount = 0;
    for (int i = 0; i < my_vec.size(); i++) {
        for (int j = 0; j < my_vec.size(); j++) {
            if (my_vec[i][j] == 0) {
                nocount++;

            }
        }
    }
    if (nocount != 0) {
        cout << "NO" << endl;
        cout << nocount << endl;
    }

}