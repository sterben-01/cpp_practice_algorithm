#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param p TreeNode类
     * @param q TreeNode类
     * @return TreeNode类vector
     */
    vector<TreeNode*> ret;
    bool find = false;
    vector<TreeNode*> findCommonAncestors2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return ret;
        }
        backtracking(root, p, q);
        reverse(ret.begin(), ret.end());
        for(int i = 0; i < ret.size(); i++){
            ret[i]->left = nullptr;
            ret[i]->right = nullptr;
        }
        return ret;
    }
    TreeNode* backtracking(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        if(root->val == q->val || root->val == p->val){
            return root;
        }
        TreeNode* left = backtracking(root->left, p, q);
        TreeNode* right = backtracking(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            //cout <<"find" <<endl;
            find = true;
            ret.push_back(root);
            return root;
        }
        else if (left == nullptr && right != nullptr) {
            //cout <<"1" <<endl;
            if (find == true) {
                //cout <<"find" <<endl;
                ret.push_back(root);
            }
            return right;
        }
        else if (left != nullptr && right == nullptr) {
            //cout <<"2" <<endl;
            if (find == true) {
                //cout <<"find" <<endl;
                ret.push_back(root);
            }
            return left;
        }
        else {
            //cout <<"3" <<endl;
            return nullptr;
        }

    }
};





class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p TreeNode类 
     * @param q TreeNode类 
     * @return TreeNode类vector
     */
    vector<TreeNode*> ret;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return 0;
        }
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);

        if(root->val == q->val || root->val == p->val){
            left+=1;
        }
        if((left + right) >=2){
            ret.push_back(root);
        }
        return left + right;


    }
    vector<TreeNode*> findCommonAncestors2(TreeNode* root, TreeNode* p, TreeNode* q) {
        // write code here
        dfs(root, p, q);
        reverse(ret.begin(), ret.end());
        for(int i = 0; i < ret.size(); i++){
            ret[i]->left = nullptr;
            ret[i]->right = nullptr;
        }
        return ret;
    }

};



int main(){

    TreeNode* n1 = new TreeNode(11);
    TreeNode* n2 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(2, n1, n2);
    TreeNode* n5 = new TreeNode(0);
    TreeNode* n6 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(5, n3, n4);
    TreeNode* n8 = new TreeNode(1, n5, n6);
    TreeNode* n9 = new TreeNode(9, n7, n8);
    Solution s;
    s.findCommonAncestors2(n9, n1, n3);

    return 0;
}