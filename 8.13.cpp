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
    // int size;
    // cin >> size;
    // int minuts;
    // cin >> minuts;
    int size = 6;
    int minuts = 5;
    vector<int> my_vec = { 5,6,7,8,9,10 };

    int count = 0;
    int non_magic = 0;
    int spendtime = 0;
    for (int i = 0; i < size; i++) {

        int val = my_vec[i];
        // int val;
        // cin >> val;
        if(val - spendtime >= minuts){
            non_magic++;
        }
        if(val - spendtime < minuts){
            count++;
        }
        spendtime = spendtime + minuts;
    }

    cout << count << endl;

    return 0;
}
