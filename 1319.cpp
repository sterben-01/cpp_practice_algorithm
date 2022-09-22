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
text 1319并查集。可以参考684。
%标注的是本题特有的部分。
*/
class findunion{
    public:
        vector<int> father; //储存节点
        vector<int> rank; //可以理解为储存的是这个节点距离子节点的深度。按秩合并。
        int count = 0; //%多余网线的数量。
        int fenliang = 0; //%一共有几个分量。也就是有几个子图。
        findunion(int x): father(vector<int>(x)), rank(vector<int>(x)){
            //初始化数组。每个节点一开始的父节点和溯源节点都是自己。
            for(int i = 0; i < x; i++){
                father[i] = i;
            }
            fenliang = x; //%开始每个节点都是独立的，所以有x个分量
        } 
        int find(int x){
            //以递归的方式寻找这个节点的溯源节点。并实施路径压缩。
            if(father[x] != x){
                father[x] = find(father[x]);
            }
            return father[x]; //返回这个节点的溯源节点。
        }
        void merge(int x, int y){
            //按秩合并。
            int rootx = find(x);
            int rooty = find(y);
            if(rootx == rooty){ //&这个部分根据题意来可以增加辅助变量。相等证明这条路径的两个点有同一个溯源节点，证明出现了环路。
                count++;//%这道题每有一个环路就等于多了一根网线。
            }
            if(rootx != rooty){//&这个部分根据题意来可以增加辅助变量。不相等证明不存在环路，可以新增链接，实施按秩合并。
                if(rank[rootx] < rank[rooty]){ //把深度小的树的溯源节点设置为深度大的树的溯源节点
                    father[rootx] = rooty;
                }
                else{ 
                    father[rooty] = rootx; 
                }
                if(rank[rootx] == rank[rooty]){ //!这个if不能和上面合并。
                    rank[rootx] = rank[rootx] + 1; //这里的意思是：假如有0,1和0,2两条路。一开始的秩都是0，我们就把1的溯源节点设置为0。注意这时候0为根的树深度增加了，所以0为根的秩+1。
                    //说白了就是，一个根节点的秩想要加1，那必定有一个与该节点秩相等的根节点与其合并。
                }
                fenliang--;//%分量减少1。因为溯源节点不相同证明这条路径不是冗余的。所以这个节点被放到了一个图的里面，那么连通分量（子图）自然就会减少1
            }
        }
        int getret(){ //% 根据题意更改。
            //这道题问我们需要多少操作次数。
            //& 这里的意思是，如果网线的数量比剩余连通分量-1（剩余的没联网的节点）还要少，证明网线不够了。
            //这道题连通分量理解为有多少个节点（树）。减掉1是因为已经连接起来的那部分也算是一个节点（树）。
            if(count < fenliang-1){
                return -1;
            }
            return fenliang - 1; //返回有几个剩余分量即可。因为网线可能会比分量多。
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        findunion ff(n);
        for(int i = 0; i < connections.size(); i++){
            ff.merge(connections[i][0], connections[i][1]);
        }
        return ff.getret();
    }
};