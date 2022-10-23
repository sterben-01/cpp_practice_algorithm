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





int main() {
    int l, r;
    cin >> l >> r;
    vector<char>final;
    final.reserve(r);
    final.push_back('1');
    final.push_back('0');
    int current = 2;
    while(current < r){
        for(int i = 0; i < current; i++){
            char tmp = final[i] == '0' ? '1':'0';
            final.push_back(tmp);
        }
        current = current*2;
    }
    int count = 0;
    for (int pos = l - 1; pos <= r - 1; pos++) {
        if (final[pos] == '1') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
   
}