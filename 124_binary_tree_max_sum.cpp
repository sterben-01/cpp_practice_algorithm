#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int totalMAX = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        triverse(root);
        return totalMAX;
    }
    int triverse(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lvalue = triverse(root->left); //左子树值
        int rvalue = triverse(root->right);//右子树值
        int currentpathsum = lvalue + rvalue + root->val; //这里是因为可以不从根节点开始。子树路径和是左和+右和+当前值
        /*
                        -10
                    9           20                  这里路径和可以是20+15+7。 所以是左+右+当前（20）
                            15      7    


        */
        totalMAX = max(currentpathsum, totalMAX);//注意一共要取4次最大值。这里是第一次。看当前路径组合值是否是历史最大。
        int returnvalue = max(0,max(lvalue, rvalue)) + root->val; //这里要注意。如果要往上弹回去的话就只能找一条边 要么左侧要么右侧，然后加上当前节点值。
        //还要注意。max(0,max(lvalue, rvalue))这里外侧和0比取max的原因是节点值可能为负。如果小于0直接不要，按照0返回。因为我们这里仅仅求最大值而不是求路径。所以可以直接忽略小于0部分。
        // 如果不和0比较直接用来计算的话，负值会对整体值做贡献，说白了负数路径会被统计。比如 -2 1这种情况，如果统计负数的话会变成差值。所以负数单位一律算0.
        /*
                        -10
                    9           20                  这里如果要弹回去的话 要么是 -10 20 15， 要么是-10 20 7. 你不可能-10 20 15 7 不能走回头路。所以选左右最大值
                            15      7    


        */
        return max(returnvalue,0); //这里第四次取最大值是因为加上根节点之后也有可能为负。所以再和0比较一次。
    }
};