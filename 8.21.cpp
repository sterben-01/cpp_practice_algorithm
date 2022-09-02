
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

class mycomp2{
public:
    bool operator()(const int& val1, const int& val2) const {
        if(val1 > val2){
            return true;
        }
        return false;
    }
    
};
int main(){
    set<int, mycomp2> test2; // 正确 传入类型名。注意set的自定义比较函数必须要加const
    //set<int, mycomp2()> test4; // 错误 传入了一个对象。这里需要类型名
    
}