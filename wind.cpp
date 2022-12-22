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


/*
int数组记录了节点的最大值
int[0] 是 自己 + 左孙节点 + 右孙节点
int[1] 是 左儿节点 + 右儿节点
int[2] 是 左儿节点 + 右孙节点
int[3] 是 左孙节点 + 右儿节点
int[4] 是 左孙节点 + 右孙节点
*/

//计算函数。
// 参数：树根节点。
//输出大小为5，元素类型为int的array
array<int, 5> triverse(TreeNode* node) {

    if (node->left == nullptr && node->right == nullptr) {
        return { node->val, 0, 0, 0, 0 };
    }
    array<int, 5>left = { 0,0,0,0,0 }, right = { 0,0,0,0,0 }, result = { 0,0,0,0,0 };
    if (node->left != nullptr) {
        left = triverse(node->left);
    }
    if (node->right != nullptr) {
        right = triverse(node->right);
    }

    //此刻，left和right数组，第一位是儿节点值，剩下的都是孙节点值。
    int L_max = *max_element(left.begin()+1, left.end()); //这里是选除了第一个数（自己）以外的最大值。这里就是最大孙节点的值。
    int R_max = *max_element(right.begin()+1, right.end());

    //儿节点的值是找自己和孙节点的最大值。
    result[4] = L_max + R_max; //左孙+右孙
    result[0] = result[4] + node->val; //自己+左孙+右孙
    result[1] = max(L_max, left[0]) + max(R_max, right[0]); //左儿+右儿
    result[2] = L_max + max(R_max, right[0]); //左孙+右儿
    result[3] = max(L_max, left[0]) + R_max; //左儿+右孙
    return result;

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
int main() {
    vector<int> vec = { 5,4,8,9,-1,11,4,7,2, -1,-1,5,1,8,-1,7,3,6,-1,-1,-1 };
    TreeNode* root = init_tree(vec);
    print_binary_tree(root);
    array<int, 5> result = triverse(root);
    cout << *max_element(result.begin(), result.end()) << endl;


    delete root;
    return 0;
}
