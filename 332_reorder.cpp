#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

class Solution {
private:
// unordered_map<出发机场, map<到达机场, 航班次数>> targets
unordered_map<string, map<const string, int>> targets; // 此处添加const是有区别的。在语义上，map的key确实是const的。但是map<string,int> 和 map<const string, int> 是两种类型。此处的const和非const会引申出
                                                        //两种类型的map。所以如果有接受该map的函数，则一定要区分开是否加const
                                                        // 但是此处没有接受函数，所以显式声明key为const是可以的。
bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum + 1) {
        return true;
    }
    // 下面这里用的pair不要忽略。map里面存的是pair
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) { //这的const的原因是使用的是引用，target存的是存在targets里面的map，map里面的是const string，int 所以这里也要const
                                                                                //或者可以不用引用，就可以不用const 可以：pair<string, int> target 当然，也可以pair<const string, int>.但是没什么意义
                                                                                // 这里到了result.size()-1是因为我是从0开始的所以每次只需要访问当前(最后一个)就可以
        if (target.second > 0 ) { // 记录到达机场是否飞过了
            result.push_back(target.first);
            target.second--; //不要忘记更新剩余飞行次数
            if (backtracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets) { // const&防止传值时拷贝构造函数的调用开销
            targets[vec[0]][vec[1]]++; // 记录映射关系 其实是一个网格 长得像是这样 这位置一定要分开看。
            // targets[vec[0]][vec[1]]不是一个整体。vec[0]是target的key;vec[1]是里面map的key。比如 第一个JFK是targets的其中一个key。然后 SFO是 taegets里面的一个的key。1就是里面的SFO对应的value 整个map又是JFK的value
            cout << targets["SFO"]["ATL"] << endl;
            /*
                    JFK     SFO     ATL     
                JFK         1       2

                SFO                 1

                ATL 1       1
            */
        }
        unordered_map<string,map<const string,int>>::iterator iter;
        map<string,int>::iterator inneriter;
        for(iter = targets.begin(); iter!= targets.end(); iter++){
            for(inneriter = iter->second.begin(); inneriter!= iter->second.end(); inneriter++ ){
                cout << iter->first << "," << inneriter->first << ":" << inneriter->second << endl;
            }

        }


        result.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), result);
        return result;
    }
};
int main(){
    Solution* obj = new Solution();
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"},{"JFK","ATL"}};
    obj->findItinerary(tickets);
    

}