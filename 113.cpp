#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
和随想录写的差别比较大。还是我们是走到叶子节点为止，在终止条件里面把叶子结点做判断
&注意，我们用了一个临时的path的局部变量。所以要么不按照引用传递。如果按照引用传递，则44行必须在假如到结果集后把记录集的最后一个也pop出来。
*/


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
    vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return ret;
        }
        vector<int>path;
        backtracking(root, path, targetSum, 0);
        return ret;
    }
    void backtracking(TreeNode* root, vector<int>& path, int targetsum, int sum){

        if(root->left == nullptr && root->right == nullptr){
            if(root->val + sum == targetsum){
                path.push_back(root->val);
                ret.push_back(path);
                path.pop_back();
            }

            return;
        }
        path.push_back(root->val);
        sum = sum + root->val;
        if(root->left != nullptr){
            backtracking(root->left, path, targetsum, sum);
        }
        if(root->right != nullptr){
            backtracking(root->right, path, targetsum, sum);
        }
        path.pop_back();
        sum = sum - root->val;
    }
};