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
using namespace std;


class stone{
    public:
    stone(){};
    int vala;
    int valb;
    stone(int a, int b):vala(a), valb(b){};
    bool operator()(const stone& a, const stone& b) const{
        if(a.vala < b.vala){
            return true;
        }
        return false;
    }
};

int main(){
    stone s1(2,3);
    stone s2(3,4);
    stone s3(1,4);

    set<stone, stone> thisset;
    thisset.insert(s1);
    thisset.insert(s2);
    thisset.insert(s3);

    for(auto a:thisset){
        cout << a.vala << endl;
    }

    set<stone, stone>::iterator iter = thisset.begin();

    for(; iter!= thisset.end(); iter++){
        cout << iter->vala << endl;
        cout << (*iter).vala << endl;
    }


    return 0;
}