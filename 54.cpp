#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


/*
text 螺旋矩阵
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans;      //若数组为空，直接返回答案
        int u = 0;                          //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; i++){
                ans.push_back(matrix[u][i]); //向右移动直到最右
            }


            u = u + 1;                      //上边界下移。注意往下移就是+，因为从上往下数字越来越大
            if(u > d){
                break;                      //若上边界大于下边界，则遍历遍历完成，下同
            } 
            for(int i = u; i <= d; i++) {
                ans.push_back(matrix[i][r]); //向下
            }


            r = r - 1;                      //右边界左移
            if(r < l){
                break;                      //若右边界小于左边界，则遍历遍历完成，下同
            }
            for(int i = r; i >= l; i--){
                ans.push_back(matrix[d][i]); //向左
            } 


            d = d - 1;                      //下边界上移
            if(d < u){
                break;                      //如果下边界小于上边界，则遍历遍历完成，下同
            }
            for(int i = d; i >= u; i--){
                ans.push_back(matrix[i][l]); //向上
            }


            l = l + 1;                      //左边界右移
            if(l > r){
                break;                      //如果左边界大于右边界，则遍历遍历完成
            }
            //&注意这里没有for循环，因为在开头。
        }
        return ans;
    }
};

