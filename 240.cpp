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
text 和74一模一样。只不过74是从左下角开始，比数字大向右，比数字小向上。这道题是从右上角开始。比数字大向下，比数字小向左。
&因为74是这一行的第一个数字一定大于上一行的最后一个数字。
&而这道题是这一行的最后一个数字一定大于上一行的最后一个数字。
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //!唯一区别，JI反过来。
        int i = 0;
        int j = matrix[0].size()-1;
        while(i < matrix.size() && j>=0){
            if(target > matrix[i][j]){ 
                i++;
            }
            else if(target < matrix[i][j]){
                j--;
            }
            else if (target == matrix[i][j]){
                return true;
            }
        }
        return false;
    }
};