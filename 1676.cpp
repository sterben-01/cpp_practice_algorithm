#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

/*
text 这题和236二叉树最近公共祖先一个妈生的，区别是那个题给了俩节点，这个题给了一个vector的节点。
看题解就完了。我们之前判断root = q或者root = p的话，这里用find就可以
然后其他逻辑都一样。
&注意一个可能难以理解的。为什么走到空了返回nullptr。假如3是叶子结点，我们第一反应可能以为走到3了会返回3，但是不是
&我们3不是nullptr，3的下一个才是nullptr。所以其实返回的是nullptr。没有问题。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(root == nullptr){
            return root;
        }
        if(find(nodes.begin(), nodes.end(), root) != nodes.end()){
            return root;
        }
        TreeNode* leftnode = lowestCommonAncestor(root->left, nodes);
        TreeNode* rightnode = lowestCommonAncestor(root->right, nodes);
        if(leftnode == nullptr && rightnode != nullptr){
            return rightnode;
        }
        if(leftnode != nullptr && rightnode == nullptr){
            return leftnode;
        }
        if(leftnode != nullptr && rightnode != nullptr){
            return root;
        }
        else{
            return nullptr;
        }

    }
    
};