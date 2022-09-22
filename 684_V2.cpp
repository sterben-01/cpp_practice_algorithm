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
text 此为并查集通用模板
& 连通分量
个人理解的意思就是一张无向图的子图。
&路径压缩
路径压缩的意思是，如果3的溯源节点是4，4的溯源节点是2，则如果不压缩就会发生father[3] = 4, father[4] = 2。
这样我们查找3的溯源节点就会查找两次，直到查找到2的溯源节点是2自己为止。
这样由于树的深度过大，所以耗费时间
所以路径压缩说白了就是，不用再次每次都查找了。直接把father数组从储存自己的父节点变成储存自己的溯源节点。
也就是father[3] = 4, father[4] = 2 然后最终应用为father[3] = 2。
&按秩合并
按秩合并的意思就是，如果1为根节点的树是1 2 3，深度为3。4为根节点的树是4 5 6 7 8，深度为5。
如果这个时候出现一个路径[1,4]，就需要把节点1的溯源节点设置为4，避免树的深度增加。
&把深度小的树的溯源节点设置为深度大的树的溯源节点
!注意这里不是很完美，秩没有回缩。但是无伤大雅。
*/
class findunion{
    public:
        vector<int> father; //储存节点
        vector<int> ret;
        vector<int> rank; //可以理解为储存的是这个节点距离子节点的深度。按秩合并。
        findunion(int x): father(vector<int>(x)), rank(vector<int>(x)){
            //初始化数组。每个节点一开始的父节点和溯源节点都是自己。
            for(int i = 0; i < x; i++){
                father[i] = i;
            }
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
            //这道题这里是要求求出导致环路的两个节点。
                ret.push_back(x);
                ret.push_back(y);
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
            }
        }
        vector<int> getret(){
            return ret;
        }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        findunion ff(edges.size()+1); //这道题是从1开始，所以需要+1.
        for(int i = 0; i < edges.size(); i++){
            ff.merge(edges[i][0], edges[i][1]);
        }
        return ff.getret();
    }
};