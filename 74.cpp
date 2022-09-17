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
根据题意已知，二维数组从左往右递增，从上往下递增，所以得出以下结论：

某列的某个数字，该数之上的数字，都比其小；
某行的某个数字，该数右侧的数字，都比其大；
所以，解题流程如下所示：

以二维数组左下角为原点，建立直角坐标轴。
若当前数字大于了查找数，查找往上移一位。
若当前数字小于了查找数，查找往右移一位。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size()-1;
        int j = 0;
        while(i >= 0 && j < matrix[0].size()){
            if(target < matrix[i][j]){
                i--;
            }
            else if(target > matrix[i][j]){
                j++;
            }
            else if(target == matrix[i][j]){
                return true;
            }
        }
        return false;
    }
};