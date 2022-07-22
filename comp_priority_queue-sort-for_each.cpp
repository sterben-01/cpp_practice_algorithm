#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
//for_each， sort， priority queue 三者的自定义函数使用方式整理
class mycomp{
public:
    bool operator()(int val) const{
        if(val > 3){
            return true;
        }
        return false;
    }
    
};
class mycomp2{
public:
    bool operator()(const int& val1, const int& val2)const{
        if(val1 > val2){
            return true;
        }
        return false;
    }
    
};
bool cmp(int val){
    if(val > 3){
        return true;
    }
    return false;
}
int main(){
    vector<int> test = {1,2,3,4,5};
    // for_each(test.begin(), test.end(), cmp()); //错误  这叫函数调用
    // for_each(test.begin(), test.end(), cmp);  //正确
    // sort(test.begin(), test.end(), mycomp); //错误 不能直接用类型名。和priority queue刚好相反
    // sort(test.begin(), test.end(), mycomp()); //正确 使用匿名对象
    // set<int, cmp()> test2; //错误 和priority queue一样 只能用类型名
    // set<int, cmp> test2; //错误 和priority queue一样只能用类型名  
    set<int, mycomp2> test2; // 正确 注意set的自定义比较函数必须要加const
    // set<int, mycomp2()> test4; // 错误 
    // priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp2> pri_que; //正确 priority queue用类型名
    // priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp()> pri_que; //错误 priority queue用类型名,加了括号叫对象


    //priority_queue<int, vector<int>, mycomp2> pri_que;
    //              ↑       ↑          ↑     尖括号里面的是类型名。所以传入的都是类型名 比如set priority queue。 mycomp是类型名，mycomp()是类的匿名对象
    //sort(test.begin(), test.end(), mycomp2()); //正确 使用匿名对象
    //            ↑       ↑          ↑     圆括号里面的是对象。所以传入的都是对象 比如for_each。 mycomp是类型名，mycomp()是类的匿名对象。
    
    

}