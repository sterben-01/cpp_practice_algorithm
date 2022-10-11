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










class myclass{
    public:
    void calla(int a) & {
        cout << a << endl;
    }
    void calla(int a) && {
        cout << a <<"r" <<endl;
    }
};
int main(){
    myclass obj;
    int s = 4;
    obj.calla(s);
}