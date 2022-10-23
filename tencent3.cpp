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
    int nums;
    cin >> nums;
    deque<int> my_deque;
    for (int i = 0; i < nums; i++) {
        int temp;
        cin >> temp;
        my_deque.push_back(temp);
    }
    vector<int>ret;
    for (int i = 1; i <= nums; i++) {
        if (i % 2 != 0) { //奇数
            int num = my_deque.front();
            int num2 = my_deque.back();
            if (num > num2) {
                ret.push_back(my_deque.front());
                my_deque.pop_front();
                
            }
            else {
                ret.push_back(my_deque.back());
                my_deque.pop_back();
            }
        }
        else {
            int num = my_deque.front();
            int num2 = my_deque.back();
            if (num < num2) {
                ret.push_back(my_deque.front());
                my_deque.pop_front();
            }
            else {
                ret.push_back(my_deque.back());
                my_deque.pop_back();
            }
        }
    }
    for (auto& i : ret) {
        cout << i << " ";
    }
    return 0;
   
}