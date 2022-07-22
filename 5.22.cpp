#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

template<typename T1>
void test(T1 arg1){
    vector<T1> testvec = {arg1};
    cout << testvec[0].my_val << endl; //一个类的公有成员在任何地方都可以被访问。

}

template<typename T2>
class tmpclass{
    public:
    T2 my_val;
    tmpclass() = default;
    tmpclass(T2 val) : my_val(val){}

};

int main(){
    test(tmpclass<string>("abc"));
    test(tmpclass<int>(5));
    tmpclass<double> yy(5.6);
    test(yy);
}