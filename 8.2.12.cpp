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
#include <limits.h>
using namespace std;


int solution(vector<int> &A, int X, int Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int min_cost = INT_MAX;
    for(int pos = 0; pos < Y; pos++){
        int slow = pos;
        int fast = pos;
        int current_cost = 0;
        int t = 0;
        while(t < X && fast < A.size()){
            current_cost = current_cost + A[fast];
            fast = fast + Y;
            t++;
        }
        if(fast >= A.size() && t < X){
            break;
        }
        min_cost = min_cost < current_cost? min_cost:current_cost;
        while(fast < A.size()){
            current_cost = current_cost - A[slow] + A[fast];
            min_cost = min_cost < current_cost? min_cost:current_cost;
            slow = slow + Y;
            fast = fast + Y;
        }
    }
    cout << min_cost << endl;
    return min_cost;
}

int main(){
    vector<int>A{10,3,4,7};
    solution(A, 2, 3);
    return 0;
}