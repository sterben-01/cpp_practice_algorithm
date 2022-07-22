#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <memory>
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
private:
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
    int yinyong(const int& a , const int& b){
        int c = a;
        return c;
    }
    int& yinyong2(int& a , int& b){
        cout << &a<<endl;
        cout << &b << endl;
        return a;
    }
    int yinyong3(int& a , int& b){
        cout << &a<<endl;
        cout << &b << endl;
        return a;
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    // vector<int> test(inorder.begin(),inorder.begin()+1);
    // vector<int> test2(inorder.begin()+2,inorder.begin()+5);
    // for(int i=0;i<test2.size();i++){
    //     cout << test2[i] << endl;
    // }
    Solution* obj = new Solution;
    unique_ptr<Solution> obj = make_unique<Solution>();
    // obj->buildTree(inorder,postorder);
    // TreeNode* node = new TreeNode();
    // TreeNode testnode;
    // node->val = 5;
    // testnode.val = 8;
    // cout << node->val << endl;
    // int ff = 4;
    // int fff = 40;
    // cout <<&ff << endl;
    // cout << &fff << endl;
    // cout << "newline----" << endl;
    // int& test2 = obj->yinyong2(ff,fff);
    // cout << test2 << endl;
    // cout << &test2 << endl;
    // cout<<"-----" << endl;
    // int &&test3 = obj->yinyong3(ff,fff);
    // cout << test3 << endl;
    // cout << &test3 << endl;
    // int a = 1;
    // int &b = a; // 正确 左值引用
    // int &b = 1; // 错误 右值引用了
    // int &&b = 1; // 正确 正确的右值引用
    // int &&b = a; //错误 右值引用只能引用右值
    // int &&b = move(a); //正确 move（移动语义）可以将左值转换为右值然后进行右值引用。

}