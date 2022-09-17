#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>

using namespace std;

/*
text 662 二叉树最大宽度。这个可以用BFS也可以用DFS。 DFS好理解一点。
&首先节点的值和我们没关系。忽略节点值。其次我们说过规律：
看到完全二叉树可以想成一个堆。如果给的输入是二叉树的层序遍历，则
对于任意节点, 若其下标为i
则父节点下标k为 i/2 - (i%2 == 0 ? 1 : 0);
若当前为i, 两个子节点下标为 i*2 + 1 和i*2+2
所以每一个节点左子节点就是i*2, 右子节点就是i*2+1
&注意这个i是节点的编号，和值没关系。所以我们可以用两个编号相减然后+1确定这个层的最大距离。
我们假设根节点为1号节点。层从0开始和1开始都行，没关系。我们有一个map。map的key是层数，value是这个层的最左侧节点的编号。
所以我们每次访问到这个层的时候，都可以和这个层最左边的那个节点的编号相减。也就是map里的那个相减就行。然后记录最大值就行。
最后就是DFS。
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
    unordered_map<int, unsigned long long> my_map;
    unsigned long long res = 0;
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        DFS(root, 1, 1); //编号从1开始，层从0或者1都行。
        return res;
    }
    void DFS(TreeNode* node, unsigned long long index, int level){
        if(node == nullptr){
            return;
        }
        auto t = my_map.find(level);
        if(t == my_map.end()){
            my_map[level] = index; //如果没找到，就证明这层没到呢。我们是DFS从左边一直走到头。我们保证这个节点是最左侧的。就把他放进来。注意是层数和编号
        }
        res = max(res, index - my_map[level] + 1); //记录最大值。编号相减
        DFS(node->left, index*2, level + 1); //DFS 注意左子节点是i*2, 层数+1
        DFS(node->right, index*2 + 1, level + 1);//DFS 注意左子节点是i*2+1, 层数+1
    }
};