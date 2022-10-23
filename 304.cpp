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
text 二维前缀和。主要是记住几个公式。
https://leetcode.cn/problems/range-sum-query-2d-immutable/solution/ru-he-qiu-er-wei-de-qian-zhui-he-yi-ji-y-6c21/
我们定义 preSum[i][j]preSum[i][j] 表示 从 [0,0][0,0] 位置到 [i,j][i,j] 位置的子矩形所有元素之和
*/

class NumMatrix {
public:
    vector<vector<int>> presum;
    NumMatrix(vector<vector<int>>& matrix) {
        presum.resize(matrix.size()+1, vector<int>(matrix[0].size()+1));
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return;
        }
        for(int i = 1; i <= matrix.size(); i++){
            for(int j = 1; j <=matrix[0].size(); j++){
                presum[i][j] = presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1]+matrix[i-1][j-1]; //套用公式算出presum前缀和
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2+1][col2+1] - presum[row2+1][col1] - presum[row1][col2+1] + presum[row1][col1]; //套用公式返回具体数字。
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */