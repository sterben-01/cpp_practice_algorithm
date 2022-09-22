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

class findunion{
    public:
        unordered_map<int,int> father;
        vector<int> ret;
        void add(int x){            //相当于初始化数组，每一个节点的溯源节点都是-1，理论上应该是自己，你也可以换成father[x] = x, 但是记得下面find也要换。
            if(father.count(x) == 0){
                father[x] = -1;
            }
        }
        bool is_connected(int x, int y){ //判断这两个节点是否是连在一起的。这里的连在一起并不一定是直接连接。意思是溯源节点是否是同一个。
            int node1 = find(x);
            int node2 = find(y);
            if(node1 == node2){
                return true;
            }
            return false;
        }
        int find(int x){                //找这个节点的溯源节点。只要这个节点的溯源节点是-1了，证明找到头了。如果不是就继续找
                                        //第一次进来的时候，因为大家都是-1，所以自己的父节点是自己。
            int root = x;
            while(father[root] != -1){
                root = father[root];
            }
            return root;
        }
        void merge(int x, int y){
            int node1 = find(x);
            int node2 = find(y);
            if(is_connected(node1, node2)){ //如果两个节点的溯源节点是同一个，可以进行下一步操作，具体操作视题目而定。
                //这里题目是找到一条边。也就是俩节点
                ret.push_back(x);
                ret.push_back(y);
            }
            if(!is_connected(node1, node2)){ //如果两个节点的溯源节点不是同一个，可以进行下一步操作，具体操作视题目而定。
                father[node1] = node2; //这里溯源节点不是同一个节点，就记录这个节点的溯源节点是谁。 我们是通过行代码去更新每一个节点的溯源节点是什么的。
            }
        }
        vector<int> getret(){
            return ret;
        }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        findunion ff;
        for(int i = 0; i < edges.size(); i++){
            ff.add(i);
        }
        for(int i = 0; i < edges.size(); i++){
            ff.merge(edges[i][0], edges[i][1]);
        }
        return ff.getret();
    }
};