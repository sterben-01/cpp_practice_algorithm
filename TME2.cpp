#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param inOrder int整型vector 
     * @return TreeNode类vector
     */
    bool none = false;
    bool find = true;
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        vector<int> used(inOrder.size(), 0);
        vector<TreeNode*> ret;
        while(none != true){
            TreeNode* temp = triverse(inOrder, 0, inOrder.size(), preOrder, 0, preOrder.size(), used);
            ret.push_back(temp);
        }
        return ret;

    }
    TreeNode* triverse(vector<int>& inOrder, int inorderbegin, int inorderend, vector<int>& preorder, int preorderbegin, int preorderend, vector<int>& used){
        if(preorderbegin == preorderend){
            return nullptr;
        }
        int rootval = preorder[preorderbegin];
        TreeNode* root = new TreeNode(rootval);

        if(preorderend - preorderbegin == 1){
            return root;
        }
        int splitindex = -1;
        for(splitindex = inorderbegin; splitindex < inorderend; splitindex++){
            if(inOrder[splitindex] == rootval){
                if(used[splitindex] == 0){
                    used[splitindex] = 1;
                    find = true;
                    break;
                }
                else{
                    continue;
                }
            }
        }
        if(find == false){
            none = true;
            return nullptr;
        }
        int leftinorderbegin = inorderbegin;
        int leftinorderend = splitindex;
        int rightinorderbegin = splitindex + 1;
        int rightinorderend = inorderend;

        int leftpreorderbegin = preorderbegin + 1;
        int leftpreorderend = leftpreorderbegin + splitindex - leftinorderbegin;
        int rightpreorderbegin = leftpreorderbegin + (splitindex - leftinorderbegin);
        int rightpreorderend = preorderend;

        root->left = triverse(inOrder, leftinorderbegin, leftinorderend, preorder, leftpreorderbegin, leftpreorderend, used);
        root->right = triverse(inOrder, rightinorderbegin, rightinorderend, preorder, rightpreorderbegin, rightpreorderend, used);
        return root;
    }
};

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 
//      * @param preOrder int整型vector 
//      * @param inOrder int整型vector 
//      * @return TreeNode类vector
//      */
//     map<int, vector<int>>index;
//     vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
//         int size = preOrder.size();
//         for(int i = 0; i < size; i++){
//             index[inOrder[i]].push_back(i);
//         }
//         vector<TreeNode*>ret;
//         bool allcheck = false;
//         while(!allcheck){
//             auto root = triverse(preOrder, inOrder, 0, size-1, 0, size - 1);
//             ret.push_back(root);
//             allcheck = true;
//             for(auto& item:index){
//                 if(item.second.size() > 1){
//                     allcheck = false;
//                 }
//             }
//         }
//         return ret;
//         // write code here
//     }

//     TreeNode* triverse(vector<int>& pre, vector<int>& ino, int pre_left, int pre_right, int in_left, int in_right){
//         if(pre_left > pre_right){
//             return nullptr;
//         }
//         TreeNode* root = new TreeNode(pre[pre_left]);
//         int root_index = index[pre[pre_left]][index[pre[pre_left]].size()-1];
//         if(index[pre[pre_left]].size() > 1){
//             index[pre[pre_left]].pop_back();
//         }
//         int leftsize = root_index - in_left;
//         root->left = triverse(pre, ino, pre_left+1, pre_left + leftsize, in_left, root_index - 1);
//         root->right = triverse(pre , ino, pre_left + leftsize + 1, pre_right, root_index+1, in_right);
//         return root;

//     }
// };