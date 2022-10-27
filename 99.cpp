#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


/*
text 这道题核心是二叉搜索树+恰好两个节点数值需要交换。
&二叉搜索树的中序遍历是有序的。中序遍历是左中右。二叉搜索树是父节点的左子节点比父节点小，右子节点比父节点大。
&我们利用中序遍历的方式遍历这颗二叉搜索树，我们再增加一个辅助的pre指针，记录 上一个 节点的值。如果 当前节点的值，小于 上一个节点的值。
具体就是中序遍历是一直走到最左侧。然后开始遍历。如果我们发现pre的数大于当前数了。就是找到问题了。因为中序遍历应该是递增。
找到之后记住当前这个节点，是我们要交换的节点。
&由于恰好有两个，而且我们要和对应的子树的根节点交换。所以我们x只会在第一次遇到的的时候记录为pre。之后只更新y也就是遍历的节点。
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
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* pre = nullptr;
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(x!=nullptr && y != nullptr){
            swap(x->val, y->val);
        }
    }
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        if(pre == nullptr){
            pre = root;
        }
        else{
            if(pre->val > root->val){
                y = root;
                if(x == nullptr){
                    x = pre;
                }
            }
            pre = root;
        }

        dfs(root->right);
    }
};