#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

/*
text 22括号生成。回溯
回溯和DFS个人理解，回溯是带有状态记录的DFS/BFS。
优先搜索都是，有一个return状态，选择满足什么条件的时候停止。停止可以是单纯地停下，然后满足某个条件后可以加入结果集。
然后函数体是每次需要处理的逻辑。这个逻辑里面可以有for循环，比如startindex啊 比如队列啊之类的。然后有这些限制条件后，把你想尝试的方法写进去，递归调用就行。
*/

class Solution {
public:
    vector<string>ret;
    vector<string> generateParenthesis(int n) {
        if(n <= 0){
            return ret;
        }
        string temp;
        backtracking(0, 0, n, temp);
        return ret;
    }
    void backtracking(int left, int right, int n, string& s){
        if(left > n || right > left){
            return;
        }
        if(s.size() == n*2){
            ret.push_back(s);
            return;
        }
        s.push_back('(');
        backtracking(left+1, right, n, s);
        s.pop_back();

        s.push_back(')');
        backtracking(left, right+1, n, s);
        s.pop_back();
    }
};