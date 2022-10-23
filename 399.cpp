#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <sstream>
using namespace std;

/*
text 并查集魔改版。复杂很多。
*/

class findunion{
    public:
        unordered_map<string,string> father;
        unordered_map<string, double> weight; //&本题特有。用于储存权重，因为本题是有权并查集。
        vector<double> ret;
        findunion(vector<vector<string>>& f){
            for(int i = 0; i < f.size(); i++){ //初始化。每一个节点的溯源节点都是自己。默认权重是1
                father[f[i][0]] = f[i][0];
                father[f[i][1]] = f[i][1];
                weight[f[i][0]] = 1;
                weight[f[i][1]] = 1;
            }
        }
        string find(string& x){
            //以递归的方式寻找这个节点的溯源节点。并实施路径压缩。
            if(father[x] != x){
                string t = find(father[x]); //这里不可按照模板写在同一行。因为结构会随时变化
                weight[x] = weight[x] * weight[father[x]]; //更新权重。
                father[x] = t; //路径压缩。
            }
            return father[x]; //返回这个节点的溯源节点。
        }
        void merge(string& x, string& y, double value, vector<string>& queries){ //合并。
            string rootx = find(x);
            string rooty = find(y);
            if(rootx == rooty){
                //如果溯源节点相同证明有环。需要跳过。
            }
            if(rootx != rooty){//如果两个节点的溯源节点不是同一个，可以进行下一步操作，具体操作视题目而定。
                father[rootx] = y; //更新溯源节点。注意这里不是rooty。
                weight[rootx] = value / weight[x]; //更新权重。
            }
            

        }
        void calc(vector<string>&queries){ //合并后计算，本题特有、
            if(!father.count(queries[0]) || !father.count(queries[1]) || find(queries[0]) != find(queries[1])){
                ret.push_back(-1.0);
                //如果请求的值我们找不到，或者是溯源节点不同就是-1
                //溯源节点不同证明二者之间无任何关联。
            }
            else{
                ret.push_back(weight[queries[0]] / weight[queries[1]]); //放入结果数组。
            }
        }
        vector<double> get(){
            return ret;
        }
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        findunion f(equations); //初始化
        for(int i = 0; i < equations.size(); i++){ //合并
            f.merge(equations[i][0], equations[i][1], values[i], queries[i]);
        }
        for(int i = 0; i < queries.size(); i++){ //计算
            f.calc(queries[i]);
        }
        return f.get(); //返回。
    }
};