#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
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
    vector<vector<int>> res;
    vector<int> path; //一定要注意这个path一定要全局变量。如果写入递归函数内部则会每次清空。
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == NULL){
            return res;
        }
        path.push_back(root->val);//注意这里放进的是root的值。因为返回数组是带值的。
        triverse(root, target - root->val); //注意这个地方因为root已经放进去了，所以要把root值减掉在放进去。
        return res;
    }
    void triverse(TreeNode* root, int target){
        if(root->left == nullptr && root->right == nullptr && target == 0){
            res.push_back(path);
            return;
        }
        if(root->left == nullptr && root->right == nullptr && target != 0){ //一样，走到根节点了还是target不为空就直接返回
            return;
        }
        if(root->left!=nullptr){ //回溯
            target = target - root->left->val;
            path.push_back(root->left->val);
            triverse(root->left, target);
            target = target + root->left->val;
            path.pop_back();
        }
        if(root->right != nullptr){//回溯
            target = target - root->right->val;
            path.push_back(root->right->val);
            triverse(root->right, target);
            target = target + root->right->val;
            path.pop_back();       
        }
        return;
    }
};