#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <stack>
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
三部曲：
1. 将左子树插入到右子树的地方
2. 将原来的右子树接到左子树的最右边节点
3. 考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
    1
   / \
  2   5
 / \   \
3   4   6

将 1 的左子树插入到右子树的地方
    1
     \
      2         5
     / \         \
    3   4         6        
将原来的右子树接到左子树的最右边节点
    1
     \
      2          
     / \          
    3   4  
         \
          5
           \
            6
            
 将 2 的左子树插入到右子树的地方
    1
     \
      2          
       \          
        3       4  
                 \
                  5
                   \
                    6   
        
 将原来的右子树接到左子树的最右边节点
    1
     \
      2          
       \          
        3      
         \
          4  
           \
            5
             \
              6         
  

*/


class Solution {
public:
    void flatten(TreeNode* root) {
        while(root != nullptr){
            if(root->left == nullptr){ //如果左子树空的，就往右边找。
                root = root->right;
            }
            else{
                TreeNode* temp = root->left; //找到左子树的最右侧节点。
                while(temp->right != nullptr){
                    temp = temp->right;
                }
                temp->right = root->right; //把当前根节点的右子树接到左子树的最右侧节点
                root->right = root->left;   //因为目前的操作都是在左子树上面。我们要把左子树掰成右子树。这里就简单赋值即可
                root->left = nullptr;       //把左子树置空
                root = root->right;         //继续走。
            }
        }
    }
};