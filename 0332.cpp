#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
int main(){
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"},{"JFK","ATL"}};
    // unordered_map<vector<string>, int> target;

    // for(const vector<string>& vec : tickets){
    //     target[vec]++;
    // }
    // unordered_map<string, map<string,int>> target;
    // unordered_map<string, map<string,int>>::iterator itertest;
    // for(itertest = target.begin(); itertest!= target.end(); itertest++){
    //     cout << itertest->first[0] <<itertest->first[0] << itertest->second << endl;
    // }
    unordered_map<string, map<string,int>> target; //嵌套容器。俩都有迭代器 较为司马
    for(const vector<string>& vec : tickets){
        target[vec[0]][vec[1]] = target[vec[0]][vec[1]] + 1;
    }
    unordered_map<string, map<string,int>>::iterator iter; //第一层unordered map的迭代器
    map<string,int>::iterator mapiter;  //第二层map的迭代器！！
    for(iter = target.begin(); iter != target.end(); iter++){ //第一层从头到尾
        cout << iter->first << endl;
        for(mapiter = iter->second.begin(); mapiter != iter->second.end(); mapiter++){ //第二层从头到尾
            cout << mapiter->first << ':' << mapiter->second << endl;
        }
    }
    // unordered_map<int, map<int,int>> testing2;
    // vector<vector<int>> testing = {{1,2},{3,4},{5,6},{5,7},{6,7}};
    // for(const vector<int>& vec : testing){
    //     testing2[vec[0]][vec[1]]++;
    // }    
    // unordered_map<int, map<int,int>>::iterator iter2;
    // map<int,int>::iterator mapiter2;
    // for(iter2 = testing2.begin(); iter2 != testing2.end(); iter2++){
    //     cout << iter2->first << endl;
    //     for(mapiter2 = iter2->second.begin(); mapiter2 != iter2->second.end(); mapiter2++){
    //         cout << mapiter2->first << ':' << mapiter2->second << endl;
    //     }
    // }
    // [a:1,b:2,c:3]
}