#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include<stack>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

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
 迭代法主要是要把左右分隔开。我们都是把中间结点先push，但是中序是左中右。先左，咋办
 一开始中间的先进来，然后又因为栈先进后出，要把入栈顺序换成右中左。
 然后把中间的拿出去，把右侧的放进来（如果不为空）。
 然后再把当前节点（中间）放进来。
 紧跟着要放一个空节点，为了把左右分隔开。
 然后把左侧的放进来。

 直到遇到了一个空节点，先把空节点pop出去，然后把栈顶放进来。然后把当前元素拿走。
 这个过程会有多次放置空节点的过程。比如有几个节点是连续的话，也得是一个一个放。就是拿走一个，然后插入一个空节点。然后发现空节点了就拿走，拿走后面的元素，不为空了就在放空。。依次类推。
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        if(root == nullptr){
            return ret;
        }
        stack<TreeNode*> my_stk;
        my_stk.push(root);
        while(!my_stk.empty()){
            TreeNode* temp = my_stk.top();
            if(temp != nullptr){
                my_stk.pop();

                if(temp->right != nullptr){
                    my_stk.push(temp->right);
                }

                my_stk.push(temp);
                my_stk.push(nullptr);
                if(temp->left != nullptr){
                    my_stk.push(temp->left);
                }
            }
            else{
                my_stk.pop();
                ret.push_back(my_stk.top()->val);
                my_stk.pop();
            }
        }
        return ret;
    }
};