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
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;
bool is_perfect(int num)
{
    int num1 = 1;
    while (num > 0)
    {
        num -= num1;
        num1 += 2;
    }
    return num == 0;
}
bool dfs(int c, int curx, int cury, int tarx, int tary) {

    if (is_perfect(curx + cury)) {
        return false;
    }
    if (curx == tarx && cury == tary) {
        return true;
    }
    if (curx > tarx || cury > tary) {
        return false;
    }
    bool a = dfs(c, curx + cury, cury, tarx, tary);
    bool b = dfs(c, curx, curx + cury, tarx, tary);
    bool s = dfs(c, curx + c, cury + c, tarx, tary);

    if (a == true || b == true || s == true) {
        return true;
    }
    return false;

}
string canReach(int c, int x1, int y1, int x2, int y2) {
    if (dfs(c, x1, y1, x2, y2) == true) {
        return "Yes";
    }
    else {
        return "No";
    }
}

int main() {
    canReach(1, 1, 4, 7, 6);
    return 0;
}