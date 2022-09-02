
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

/*
判断是否为二叉搜索树，即左边小右边大。
利用中序遍历 左中右的特性
首先终止条件是到空节点就返回。
然后先一路走到最左侧的节点，然后记录当前值。和之前的值比较，如果比之前的大没问题，比之前的小就false
然后走到最右侧。按照左 中（当前）右来遍历。
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
    long long target = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        return backtracking(root);
    }
    bool backtracking(TreeNode* node){
        if(node == nullptr){
            return true;
        }
        bool left = backtracking(node->left);
        if(target < node->val){
            target = node->val;
        }
        else{
            return false;
        }
        bool right = backtracking(node->right);
        return left && right;
    }
};