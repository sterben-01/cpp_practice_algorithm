#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <queue>
#include <array>
using namespace std;

//定义树的节点
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};

//构建二叉树
//参数：int类型节点值。以-1代替null
//返回值：树的根节点。
TreeNode* init_tree(const vector<int>& nodes) {

    if (nodes.empty()) {
        return nullptr;
    }
    queue<TreeNode*> my_que;
    int index = 0;
    TreeNode* root = nullptr;
    if (nodes[index] != -1) {
        root = new TreeNode(nodes[index]);
        my_que.push(root);
    }
    while (!my_que.empty()) {
        TreeNode* temp = my_que.front();
        my_que.pop();
        index++;
        if (index >= nodes.size()) {
            break;
        }
        if (nodes[index] == -1) {
            temp->left = nullptr;
        }
        else {
            temp->left = new TreeNode(nodes[index]);
            my_que.push(temp->left);
        }
        index++;
        if (index >= nodes.size()) {
            break;
        }
        if (nodes[index] == -1) {
            temp->right = nullptr;
        }
        else {
            temp->right = new TreeNode(nodes[index]);
            my_que.push(temp->right);
        }
    }
    return root;
}

//辅助函数判断树是否建立正确。
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            else vec.push_back(-1);
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

/*
这题的核心思想是这是一个二叉树。我们不能同时挖走一对相应的父子节点。所以我们知道，挖不挖当前节点是取决于挖不挖子节点。
所以我们采用后序遍历也就是左右中。因为要通过子节点状态决定父节点状态。
我们有一个长度为2的vector储存的是挖和不挖当前节点的值。初始化其实是在递归函数的终止语句上。
因为我需要从最底下往上走，然后上面一层依靠着我当前这层的这个数组。所以我要在最底下一层初始化他然后弹上去。
当我上一层接住了我这一层的结果之后我这一层的结果就可以不要了。

当我们不挖当前节点的时候，我们只需要取两个子节点数组的最大值即可
所以不挖的公式是 max(left[0],left[1]) + max(right[0],right[1]) 左子节点挖不挖的最大值+右子节点挖不挖的最大值
挖的公式是 cur->val + left[0] + right[0]。因为挖了当前节点则字节点必然不能挖。
*/

//递归计算函数
vector<int> triverse(TreeNode* node){
    if(node == NULL){
        return {0,0}; //这里我们初始化了弹回去的数组。
    }
    vector<int> left = triverse(node->left); //递归 用一个vector接住子节点那一层的返回的vector
    vector<int> right = triverse(node->right);
    int val1 = node->val + left[0] + right[0]; // 挖当前节点
    int val2 = max(left[0], left[1]) + max(right[0],right[1]); //不挖当前节点
    return {val2,val1}; //这里是决定我们挖是第一位还是挖是第二位的地方。我们想要[0]是不挖，[1]是挖。就用对应顺序弹回。
}

//调用计算的函数。
int rob(TreeNode* root) {
    vector<int> res = triverse(root);
    return max(res[0], res[1]);
}


int main() {
    vector<int> vec = { 5,4,8,9,-1,11,4,7,2, -1,-1,5,1,8,-1,7,3,6,-1,-1,-1 };
    TreeNode* root = init_tree(vec);
    print_binary_tree(root);
    cout <<"Result is: " << rob(root) << endl;

    delete root;
    return 0;
}
