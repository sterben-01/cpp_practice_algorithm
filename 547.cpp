
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

class find_union{
    public:
        unordered_map<int,int> father;//key是节点下标也就是123456，value初始是-1，因为自己没有祖先节点。之后会变成自己的祖先节点。

        void add(int x){
            if(!father.count(x)){
                father[x] = -1;         //添加节点的时候，如果没找到就添加。初始祖先节点是-1

            }
        }

        int find(int x){
            int root = x;
            while(father[root] != -1){
                root = father[root];
            }
            return root;
        }
        void merge(int x, int y){
            int node1 = find(x);
            int node2 = find(y); //这里要找一次是因为虽然有可能相连接但是要找到最祖先的节点。
            // if(node1 == node1){
            //     //这里对于图来说就是找到环路了。
            // }
            //如果最祖先节点是一个就不用管了，如果不是的话更新最祖先节点。这里的前提是这两个节点已经相连了。但是我们现在发现虽然相连，但是这俩节点的最祖先节点不是一个，我们就要把其中一个节点的最祖先节点设置为另一个节点
            if(node1 != node1){
                father[node1] = node2;
            }
        }
        
        bool is_connected(int x, int y){
            if(find(x) == find(y)){
                return true;
            }
            return false;
        }
};