#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
long long solution(vector<string> queryType, vector<vector<int>> query) {
    unordered_map<int, int> my_map;
    long long sum = 0;
    for(int i = 0; i < queryType.size(); i++){
        if(queryType[i] == "insert"){
            //my_map.insert(make_pair(query[i][0], query[i][1]));
            my_map[query[i][0]] = query[i][1];
        }
        else if(queryType[i] == "addToKey"){
            unordered_map<int, int> temp;
            for(auto t = my_map.begin(); t!=my_map.end(); t++){
                temp.insert(make_pair(t->first+query[i][0],t->second));
            }
            my_map = temp;
        }
        else if(queryType[i] == "addToValue"){
            for(auto t = my_map.begin(); t!=my_map.end(); t++){
                t->second = t->second + query[i][0];
            }
        }
        else if(queryType[i] == "get"){
            auto t = my_map.find(query[i][0]);
            if(t != my_map.end()){
                sum = sum + t->second;
            }
        }
        
    }
    return sum;
}


int main(){
    vector<string>queryType = {"insert", "addToValue", "get", "insert", "addToKey", "addToValue", "get"};
    vector<vector<int>>q = {{1, 2}, {2}, {1}, {2, 3}, {1}, {-1}, {3}};
    solution(queryType,q);
}