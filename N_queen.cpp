#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <cstring>
using namespace std;
//整体遍历方法是按照行，一行一行来

class Solution {
public:
    vector<vector<string>>res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n,'.'));     // 主方法。在这里声明而不在外部声明的原因是需要知道具体大小。
                                                    // 此处意思是vector的大小是n，里面填充着用n个.组成的string
                                                    //此处必须要string。第一点是因为返回要求是string，第二点是string的比较不能用==，要用compare
                                                    //这里面装的东西类似于[["......","......"...]["......","......"...]...]
                                                    //                     ↑每一个大组合是一个nxn的棋盘      ↑ 这是每一行的点
        backtracking(0,n, path);
        return res;
    }
    void backtracking(int row, int n,vector<string>& path){ //此处必须要把path传进来。因为没法在外部声明
        if(row == n){                                       //这里的意思是如果我已经到了最后一行，那么就返回。
            res.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){             //此处是第i行的n列。第一次就是第0行的n个位置
            if(is_valid(row, i, n, path) == false){
                continue;
            }
            path[row][i] = 'Q'; 
            backtracking(row+1,n,path);
            path[row][i] = '.';
        }

    }
    //这里验证注意：我们是逐行添加，所以不用看当前行下面的行（没有被添加的行）是否冲突
    bool is_valid(int row, int cow, int n,vector<string>& path){//此处必须要把path传进来。因为没法在外部声明
        for(int i = 0; i < row; i++){ // 从0行开始，到当前行（row)
            if(path[i][cow] == 'Q'){ //这里是验证一列是否有重复。从0行开始，到当前行（row），每行的第当前位置是否有Q
            /*
            cow→
        i↓  Q   .   .   .   .
            .   .   .   .   Q
            .   .   .   .   .
            .   Q   .   .   . ← 假设到了这一行 要从0行开始判断这个要放Q的列位置是否有Q了。当前行以下的行没有进行添加，所以不用看下面的，到当前row即可 
            .   .   .   .   .
            */
            //if(path[i][cow].compare('Q')){ 这里要用char compare 不能比较char. compare的全名是string::compare
                return false;
            }
        }
        for(int i = row-1, j=cow-1; i>=0&& j>=0;i--,j--){ //这地方看的是左上角的对角线部分。没有右下角！！因为下面的还没有填东西呢
            /*
            j = cow→
            ↓从这开始所以要-1
 row =  i↓  Q   .   .   .   .
            .   .   .   .   Q
           →*   .   .   .   . 从箭头处开始所以要-1 要比较的用*标注了
            .   Q   .   .   . 
            .   .   .   .   .

            */
            if(path[i][j] == 'Q'){ 
            //if(path[i][j].compare("Q")){
                return false;
            }
        }
        for(int i = row-1, j = cow+1; i>=0&& j<n; i--,j++){ //这地方看的是右上角的对角线部分。没有左下角！！因为下面的还没有填东西呢
            /*
            j = cow→
                    ↓从这开始所以要+1
 row =  i↓  Q   .   .   .   *
            .   .   .   *   Q ← 从箭头处开始所以要-1 要比较的用*标注了
            .   .   *   .   . 
            .   Q   .   .   .  
            .   .   .   .   .

            */
            if(path[i][j] == 'Q'){
            //if(path[i][j].compare("Q")){
                return false;
            }
        }
        return true;

    }
};

int main(){
    Solution* obj = new Solution();
    obj->solveNQueens(4);
    

}