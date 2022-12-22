#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
using namespace std;



class myobj{
    public:
        myobj(){
            val = 12;
        }
        myobj(int x){
            val = x;
        }
    int val;
};
// class comp{
//     public:
//     bool operator()(const pair<int,myobj>& lhs, const pair<int, myobj>& rhs) const{
//         return lhs.second.val > rhs.second.val;
//     }
// };
class comp1{
    public:
    bool operator()(const int& lhs, const int& rhs) const{
        return lhs > rhs;
    }
};
class classcomp {
    public:
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};
int main()
{
    //unordered_map<int,myobj, comp> we;
    
    map<int,myobj, comp1> we;  
    myobj a(20);
    myobj b(30);
    if(we[2].val == a.val){
        cout << "true1" << endl;
    }
    for(auto t:we){
        cout << t.first << t.second.val << endl;
    }
    cout << we.size() << endl;
}