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


/*
这题的核心思想是这是一个二叉树。我们知道不能一起偷一对相应的父子节点。所以我们知道，偷不偷当前节点是取决于偷不偷子节点。
所以我们采用后序遍历也就是左右中。因为要通过子节点状态决定父节点状态。
我们有一个长度为2的vector储存的是偷和不偷当前节点的值。初始化其实是在递归函数的终止语句上。
!因为我需要从最底下往上走，然后上面一层依靠着我当前这层的这个数组。所以我要在最底下一层初始化他然后弹上去。
!当我上一层接住了我这一层的结果之后我这一层的结果就可以不要了。

当我们不偷当前节点的时候，我们是可以 //!考虑偷当前节点。并不一定偷。我们只需要取最大值即可
所以不偷的公式是 max(left[0],left[1]) + max(right[0],right[1])
偷的公式是 cur->val + left[0] + right[0]



*/


class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = triverse(root);
        return max(res[0], res[1]);
    }
    vector<int> triverse(TreeNode* node){
        if(node == NULL){
            return {0,0}; //这里我们初始化了弹回去的数组。
        }
        vector<int> left = triverse(node->left); //递归 用一个vector接住子节点那一层的返回的vector
        vector<int> right = triverse(node->right);
        int val1 = node->val + left[0] + right[0]; // 偷当前节点
        int val2 = max(left[0], left[1]) + max(right[0],right[1]); //不偷当前节点
        return {val2,val1}; //这里是决定我们偷是第一位还是偷是第二位的地方。我们想要[0]是不偷，[1]是偷就用对应顺序弹回。
    }
};

/*
数组的第一位是不偷，第二位是偷
                            3  [3+3, 3+3+1]  这里的不偷是3+3是因为我们不偷当前节点，左子节点最大值是3，右子节点最大值是3.所以是3+3
                          /   \                     偷是3+3+1是因为偷了当前就不能偷子节点。左子节点不偷是3，右子节点不偷是1，当前是3.所以是3+3+1
                  [3,2]  2       3   [1,3]
                          \       \
                            3       1
                        [0,3]       [0,1]




*/