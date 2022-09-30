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
text 这道题是并查集变种。
todo 这道题关键点在于，消耗的能量不是路径上所有的差值加一起。而是路径上的差值的最大值。而且这道题我们每一个点都可以进行上下左右来走。所以
&第一步是把每个节点之间的权重，这里就是消耗的能量记录下来。
&第二步是开始填充。因为我们一定是从左上角走到右下角。
    &首先填充权重为0的，然后看一下左上角和右下角是否连接起来了。如果没有连接起来则继续填充1的
    &然后填充权重为1的，看一下左上角和右下角是否连接起来了。如果没有连接起来则继续填充2的
    &....
    &如果链接起来了，则说明最大值就是2。
*如何记录呢？我们这里用到了并查集。
*我们首先有一个二维数组。二维数组里面的小数组填充的是： 当前节点，要连接的节点和节点间的权重
    %这里要注意，我们每次的节点，都是从当前节点往下延伸一条边，然后往右侧延伸一条边。所以我们需要判断：
        &如果走到了最右侧一格，无法继续向右侧延伸，则跳过向右侧延伸的步骤。
        &如果走到了最下册一格，无法继续向下侧延伸，则跳过向下侧延伸的步骤。
    %其次，由于我们使用了并查集。我们仅需要把节点抽象成编号即可。也就是当前节点是1号节点，他的下侧节点的编号是 1 + 二维数组中的小数组的长度。
    @也就是当前节点下面的节点编号是 当前节点编号 + heights[0].size()

1 2 3
4 5 6
7 8 9

1-2 3
|
4 5 6
7 8 9

1-2-3
| |
4 5 6
7 8 9

1-2-3
| | |
4 5 6
7 8 9
...以此类推。
&然后我们要对数组进行排序，排序的依据是按照边的权重来排序。
&下面到并查集部分。我们这时候并查集初始数组就要设置为整个数组的大小了。也就是 heights.size()*heights[0].size() 因为我们有这么多的点。
% 然后，进行for循环。for循环的数量按照我们储存边的数组的数量来确定
    todo 每一次，把一条边的两个点进行合并。 如果合并这条边后，突然可以连通了，证明找到返回值了。因为我们路径上2 1 0导致连通了，因为要取最大值，所以依旧是2。


 
*/

class findunion{
    public:
        vector<int> father; //储存节点
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
        bool find(int x, int y){
            //&本题独有部分。
            int rootx = find(x);
            int rooty = find(y);
            if(rootx == rooty){
                return true;
            }
            return false;
        }
        void merge(int x, int y){
            //按秩合并。
            int rootx = find(x);
            int rooty = find(y);
            if(rootx == rooty){ //&这个部分根据题意来可以增加辅助变量。相等证明这条路径的两个点有同一个溯源节点，证明出现了环路。
            //这道题这里是要求求出导致环路的两个节点。
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
};
class mycomp{
    public:
    bool operator()(vector<int>& lhs, vector<int>& rhs){
        if(lhs[2] < rhs[2]){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> edges;
        vector<int> temp;
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                int pos = i * heights[0].size() + j; //计算当前节点位置。
                if( i < heights.size() - 1){ //如果没有走到最下侧
                    temp.push_back(pos); //当前节点编号
                    temp.push_back(pos + heights[0].size());//当前节点下面的节点的编号
                    temp.push_back(abs(heights[i][j] - heights[i+1][j])); //节点间权重
                    edges.emplace_back(temp);
                }
                temp.clear();
                if(j < heights[0].size() - 1){  //如果没有走到最右侧
                    temp.push_back(pos);//当前节点编号
                    temp.push_back(pos + 1);//当前节点右侧的节点的编号
                    temp.push_back(abs(heights[i][j] - heights[i][j+1]));//节点间权重
                    edges.emplace_back(temp);
                }
                temp.clear();
            }
        }

        sort(edges.begin(), edges.end(), mycomp());
        findunion ff(heights.size()*heights[0].size()); //这里注意大小要是整个矩阵大小。
        for(int i = 0; i < edges.size(); i++){
            ff.merge(edges[i][0], edges[i][1]); //对这条边进行merge，也就是合并。
            if(ff.find(0, heights.size()*heights[0].size()-1) == true){ //如果合并这条边后，左上角和右下角连通了，也就是有同一个祖先节点了，就找到了。
                return edges[i][2];
            }
        }
        return 0;

    }
};