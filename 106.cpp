#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
中序和后序构建二叉树
核心思想几步走：
&第一步 后序数组的最后一位就是当前节点（然后把这个数字扔掉）
&第二步 在中序数组中找到后序数组的这个数字，找到下标（下标对应的值要扔掉）
&第三步 依靠这个下标给中序数组分割，分为前后两半部分
&第四步 依靠此下标获得八个值（左闭右开）
4.1 中序：
        左数组：
                起点：入参（中序数组起点）
                终点：分割下标
        右数组：
                起点：分割下标 + 1 （因为下标对应的分割点要扔掉，没有意义）
                终点：入参（中序数组终点）

    后序
        左数组：
                起点：入参（后序数组起点）
                终点：我们后序数组没有明确的位置来分割，我们只能靠找到中序数组分割的大小找到对应位置看看把数组分成了大小为几的两部分。
                    也就是找到了中序数组的左侧size就可以，按照这个size分割后序数组即可。
                    这里就是：后序左数组起点 + （中序左数组终点 - 中序左数组起点）[这部分其实就是中序左数组的大小]
        右数组：
                起点：后序左数组终点。 （这里不加一因为我们不需要扣掉这个值）
                终点：入参（后序数组终点）-1。 这里要-1因为要抠掉后续数组的最后一位。这个点已经当做当前节点的值了。

&第五步，递归即可
    
%由于我们优化了性能，只依靠下标来计算，所以我们有几步需要注意
update1 回溯return条件看的是后序下标是否相等。也就是走到头了。而不是判断size
update2 找到后序数组的最后一位的时候也不是用的size - 1，要用end。因为我们的end是动态变化的。
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return nullptr;
        }
        return triverse(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    TreeNode* triverse(vector<int>& inorder, int inorder_start, int inorder_end, vector<int>& postorder, int postorder_start, int postorder_end){
        if(postorder_start == postorder_end){
            return nullptr;
        }
        int rootval = postorder[postorder_end - 1];
        TreeNode* root = new TreeNode(rootval);
        if(postorder_end - postorder_start == 1){
            return root;
        }

        int cutindex;
        for(cutindex = inorder_start; cutindex < inorder_end; cutindex++){
            if(inorder[cutindex] == rootval){
                break;
            }
        }
        int leftInorderBegin, leftInorderEnd, rightInorderBegin, rightInorderEnd;
        int leftPostorderBegin, leftPostorderEnd, rightPostorderBegin, rightPostorderEnd;

        leftInorderBegin = inorder_start;
        leftInorderEnd = cutindex;
        rightInorderBegin = cutindex + 1;
        rightInorderEnd = inorder_end;


        leftPostorderBegin = postorder_start;
        leftPostorderEnd = leftPostorderBegin + (leftInorderEnd - leftInorderBegin);
        rightPostorderBegin = leftPostorderEnd;
        rightPostorderEnd = postorder_end - 1;

        root->left = triverse(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = triverse(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin,rightPostorderEnd);

        return root;





    }
};