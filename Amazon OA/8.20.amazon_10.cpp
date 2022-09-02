#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;


/*
text Amazon OA
&Prime air route
&这题核心在于把所有重复的挑出来。因为会有不同的组合能达成等于或者小于目标值的方案。我们需要挑出来。
&所以我们用优先队列。然后把ID和sum放进去。按照sum从高到低排序。队头一定是满足条件的第一个值。然后我们找到所有相等的拿出来放到vector里面就行了。
*/




class mysort{
    public:
        bool operator()(const vector<int>& a, const vector<int>& b) const{
            if(a[1] > b[1]){
                return true;
            }
            return false;
        }
};

class mycomp{
    public:
        bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) const{
            if(a.first > b.first){
                return false;
            }
            return true;
        }
};


void solution(vector<vector<int>>& forward, vector<vector<int>>& backward, int target){
    sort(forward.begin(), forward.end(), mysort());
    sort(backward.begin(), backward.end(), mysort());
    vector<vector<int>> ret;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, mycomp> my_queue;
    int forwardindex = 0;
    int backindex = backward.size()-1;
    int max = -1;

    for(int forwardindex = 0; forwardindex < forward.size(); forwardindex++){
        for(int backindex = 0; backindex < backward.size(); backindex++){
            if(forward[forwardindex][1] + backward[backindex][1] > target){
                continue;
            }
            else if(forward[forwardindex][1] + backward[backindex][1] <= target){
                my_queue.push(make_pair(forward[forwardindex][1] + backward[backindex][1], vector<int>{forward[forwardindex][0], backward[backindex][0]}));
            }
        }
    }
    while(!my_queue.empty()){
        pair<int, vector<int>> current = my_queue.top();
        ret.push_back({current.second[0], current.second[1]});
        my_queue.pop();
        while(current.first == my_queue.top().first){
            ret.push_back({my_queue.top().second[0], my_queue.top().second[1]});
            my_queue.pop();
        }
        break;
    }
    for(auto i : ret){
        for(auto j:i){
            cout << j;
        }
        cout << endl;
    }
    

}



int main(){
    vector<vector<int>> vec1{{1,2000},{2,3000},{3,4000}};
    vector<vector<int>> vec2{{1,5000},{2,3000},{3,4000}};
    solution(vec1, vec2, 6000);
    return 0;
}