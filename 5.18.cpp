#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

class a{
    public:
    int _v1;
    int _v2;
    int _v3;
    a(int v1, int v2, int v3) : _v1(v1), _v2(v2), _v3(v3){
        _v1 = _v2 + _v3;
    }

};

bool test1(bool* lock)
{
    bool old = false;
    old = *lock;
    *lock = true;
    return old;
}


int main(){
    bool r = true;
    bool*rr = &r;
    test1(rr);



}