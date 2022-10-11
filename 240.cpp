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
        int i = matrix[0].size()-1;
        int j = 0;
        while(i>=0 && j < matrix.size()){
            if(target > matrix[j][i]){ //!唯一区别，JI反过来。
                j++;
            }
            else if(target < matrix[j][i]){
                i--;
            }
            else if (target == matrix[j][i]){
                return true;
            }
        }
        return false;
    }
};