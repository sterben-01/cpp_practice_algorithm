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
text amason OA medium
& WIFI router 使用了差分数组
具体就是把wifi覆盖范围的人数做差分数组。然后累加后比较即可
*/

void solution(vector<int>&building, vector<int>&wifi, vector<int>& wifirange){
    vector<int> cover(building.size(),0);
    int size = building.size();
    for(int i = 0; i < wifi.size(); i++){
        int start = max(wifi[i] - wifirange[i]-1, 0); //防止路由器信号越界，也就是小于楼的数量
        int end = min(wifi[i] + wifirange[i], size); //防止路由器信号越界，也就是大于楼的数量
        cover[start] += 1;
        if(end < building.size()){
            cover[end] -= 1;            //不需要的部分减回去
        }
    }
    int ret = 0;
    for(int i = 1; i < cover.size(); i++){
        cover[i] = cover[i-1] + cover[i]; //累加
    }
    for(int i = 0; i < cover.size(); i++){
        if(cover[i] >= building[i]){ //比较
            ret++;
        }
    }
    cout << ret << endl;
}




int main(){
    vector<int>building{1,2,1,2,2};
    vector<int>wifi{3,1};
    vector<int>range{1,2};
    solution(building, wifi, range);
    return 0;
}