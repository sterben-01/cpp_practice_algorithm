#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
text 这道题和77很像，但是有如下区别：第一是数字从1-9选。所以startindex是1-9。二是带了个sum
所以逻辑是一样的，没啥说的
*/

class Solution {
public:
    vector<int> vec;
    vector<vector<int>> ret;
    int targetsum = 0;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1); //注意startindex从1开始
        return ret;
    }

    void backtracking(int k, int n, int startindex){
        if(vec.size() == k){ //先判断是不是k个
            if(targetsum == n){ //然后判断满足和不。
                ret.push_back(vec);
            }
            return;
        }

        for(int i = startindex; i <= 9; i++){ //注意startindex到9结束
            targetsum+=i;
            vec.push_back(i);
            backtracking(k,n,i + 1); //注意这里是i+1 不是startindex+1
            vec.pop_back();
            targetsum-=i;
        }

    }
};