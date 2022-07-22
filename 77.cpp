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
回溯的核心要点就是三部曲。确定终止条件，确定递归逻辑，进行回溯（撤销）

text这题是要找所有的组合。这题要记录一个起始值。也就是1234里面我们取两个两个的组合。
那么我们就是先取1，然后从234里面取一个2 或者3 或者4 这样就是12 13 14
然后取2，然后从34里面取3或者4 这样就是23 24
&所以需要startindex告诉递归我们第一位取完了，需要从第二位开始去取。因为不能重复取。
&第二个核心就是popback。如果我们不popback的话，我们取完了1和2之后，会变成直接取3然后4。
%所以我们需要popback，让1,2 数组满了达到return条件之后返回上一层，把2pop出去，然后3放进来。然后满了达到return条件，把3弹出去4放进来。以此类推。
%便于理解的一个小贴士。每一个for循环就是一个节点。（这块看随想录）

update 一个剪枝的优化动作
假如我们是从1-4里面取4个数的组合。也就是n=4 k=4。
我们发现我们从1234的1开始取，可以一直取到4。
因为我们取了1，从234里面取2，从34里面取3，从4里面取4已经是所有的可能了。只有这一条路下来的可能。
所以我们取完了之后，弹出来到，从234里面取2的这里，已经没有意义了。所以可以去掉。
1234 取1    取2 X无意义 ...
234  取2    取3 X 无意义 ...
34   取3    ...
4    取4
然后我们pop到最外层，从2开始取就没有意义了。
&所以我们的for循环可以优化为for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) // i为本次搜索的起始位置
就是总共的数量 - （一共可以取几个-已经取了的）+1

!注意，从单个集合中求组合的时候才需要startindex

*/



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;

    }
    void backtracking(int n, int k, int startindex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = startindex; i <= n-(k-path.size())+1; i++){
            path.push_back(i);
            backtracking(n, k, i+1); //注意这里是i+1 不是startindex+1
            path.pop_back();

        }
    }
};