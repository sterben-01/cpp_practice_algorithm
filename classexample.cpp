#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

class player{
public:
    string name;
    const string stringnameconst;

    player()
        :name("name"), stringnameconst("name3"){}
    
    player(const string& name1){
        name  = name1;
    }


};
int main(){
    string s = "abc";
    player p (s);
    
   player sb("asasa"); // 可以 因为const修饰的常量编译时确定所以可以作为引用。
    player* ss = new player("sjsjs");
}