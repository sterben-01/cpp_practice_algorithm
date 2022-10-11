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
#include <bitset>
#include <stack>
using namespace std;


int main()
{
    int a = 0x5;
    int b = 0x6;
    int s = (a&b) + (a|b);
    int s1 = (a^b) + (a&b)*2;
    cout << s << endl;
    cout << s1 << endl;
}