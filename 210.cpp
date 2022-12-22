#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, vector<int>>my_map;
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            my_map[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>my_que;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                my_que.push(i);
            }
        }
        vector<int>ret;
        int taken = 0;
        while(!my_que.empty()){
            int current = my_que.front();
            ret.push_back(current);
            my_que.pop();
            taken++;
            vector<int> rely = my_map[current];
            if(!rely.empty()){
                for(int i = 0; i < rely.size(); i++){
                    indegree[rely[i]]--;
                    if(indegree[rely[i]] == 0){
                        my_que.push(rely[i]);
                    }
                }
            }
        }
        if(taken != numCourses){
            return {};
        }
        return ret;
    }
};