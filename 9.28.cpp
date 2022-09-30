#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <stack>
using namespace std;


int main(){
    stack<int> my_stk;
    my_stk.push(1);
    my_stk.push(2);
    cout << my_stk.size() << endl;
    stack<int>().swap(my_stk);
    cout << my_stk.size() << endl;

}