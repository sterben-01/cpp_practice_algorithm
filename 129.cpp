#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
这里和岁线路差距挺带感的。首先我的思路是按照当前节点值判断。
&所以遇到叶子结点的时候，需要在遇到叶子节点的条件里面把叶子结点本身的值加进去。
&逼的就没啥了。push和pop可以各条件都写一次也可以只在外面写一次。没区别
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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        vector<int> temp;
        vector<int> val;
        backtracking(root, temp, val);
        return accumulate(temp.begin(), temp.end(), 0);

    }
    void backtracking(TreeNode* root, vector<int>& temp, vector<int>& val){

        if (root->left == nullptr &&  root->right == nullptr){
            int tempval = 0;
            for(int i = 0; i < val.size(); i++){
                tempval = tempval*10 + val[i];
            }
            tempval = tempval*10 + root->val;
            temp.push_back(tempval);
            return;
        }

        if(root->left != nullptr){
            val.push_back(root->val);
            backtracking(root->left, temp, val);
            val.pop_back();
        }
        if(root->right != nullptr){
            val.push_back(root->val);
            backtracking(root->right, temp, val);
            val.pop_back();
        }
    }
};