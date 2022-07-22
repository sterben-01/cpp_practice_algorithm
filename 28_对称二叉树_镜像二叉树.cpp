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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        return (triverse(root->left, root->right));
        
    }
    bool triverse(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }
        else if(left!=NULL && right == NULL){
            return false;
        }
        else if(left == NULL && right != NULL){
            return false;
        }
        else if(left->val != right->val){
            return false;
        }
        // else if(left->val == right->val){ 这里不能加这个判断。首先，这是从上往下逐层遍历的。而不是走到底再往回弹出的。是2-2 -> 3-3 4-4这种。如果这里一旦比较值了，那么只要走到第一层值一样的就会返回true就没了。
        //     return true;
        // }
        bool leftans = triverse(left->left, right->right);
        bool rightans = triverse(left->right,right->left);
        //这种遍历模式是什么意思呢。就是只要这里的递归还在继续，那就隐含着这一层已经是true的这一条件。因为前面false的都return掉了。不继续走了。
        //那么一旦可以继续走就证明这之前的都满足条件，一直走到底。所以走到底了直到空了都没有false那就证明这一条路的都是true所以根本不需要比较值。
        //然后就可以弹出来看另一个分支满足不满足了。
        //整体就是比较每一个子树是不是return true了。一直比较到叶子结点了都没有return false那就证明这条路一直到底下都是true的那么这个子树就是true。
        //左子树和右子树都是true了那我这个父节点就是true的。两个父节点都是true的那么爷节点也是true的。
        if(leftans == true && rightans == true){ //所有分支都是对的那就对。
            return true;
        }
        else{
            return false;
        }




    }
};