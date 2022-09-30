
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <set>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

// class find_union{
//     public:
//         unordered_map<int,int> father;//key是节点下标也就是123456，value初始是-1，因为自己没有祖先节点。之后会变成自己的祖先节点。

//         void add(int x){
//             if(!father.count(x)){
//                 father[x] = -1;         //添加节点的时候，如果没找到就添加。初始祖先节点是-1

//             }
//         }

//         int find(int x){
//             int root = x;
//             while(father[root] != -1){
//                 root = father[root];
//             }
//             return root;
//         }
//         void merge(int x, int y){
//             int node1 = find(x);
//             int node2 = find(y); //这里要找一次是因为虽然有可能相连接但是要找到最祖先的节点。
//             // if(node1 == node1){
//             //     //这里对于图来说就是找到环路了。
//             // }
//             //如果最祖先节点是一个就不用管了，如果不是的话更新最祖先节点。这里的前提是这两个节点已经相连了。但是我们现在发现虽然相连，但是这俩节点的最祖先节点不是一个，我们就要把其中一个节点的最祖先节点设置为另一个节点
//             if(node1 != node1){
//                 father[node1] = node2;
//             }
//         }
        
//         bool is_connected(int x, int y){
//             if(find(x) == find(y)){
//                 return true;
//             }
//             return false;
//         }
// };

/*
text 重新采用通用模板。
*/

class findunion{
    public:
        vector<int> father; //储存节点
        int count = 0; //&此题特有变量
        vector<int> rank; //可以理解为储存的是这个节点距离子节点的深度。按秩合并。
        findunion(int x): father(vector<int>(x)), rank(vector<int>(x)){
            //初始化数组。每个节点一开始的父节点和溯源节点都是自己。
            for(int i = 0; i < x; i++){
                father[i] = i;
            }
            count = x; //&此题特有变量
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
                count--;//&此题特有部分。我们要找到有多少个独立节点。也就是一旦发生合并，独立节点数量会减少1.
            }
        }
        int getret(){
            return count;
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        findunion ff(isConnected[0].size());
        for(int i = 0; i <isConnected.size(); i++){
            for(int j = 0; j < isConnected[0].size(); j++){
                if(isConnected[i][j] == 1){
                    ff.merge(i, j);
                }
            }
        }
        return ff.getret();
    }
};
