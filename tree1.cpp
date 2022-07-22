#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <memory>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>res;
        stack<Node*> stk;
        if(root!= NULL){
            stk.push(root);
        }
        while(stk.empty() == false){
            Node* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            cout << node->val << endl;
            for(int i = 0; i < node->children.size();i++){
                if(node->children[i] != nullptr){
                    stk.push(node->children[i]);
                }
            }

        }
        return res;

        
    }
};
int main(){
    Node* newnode = new Node(5,{NULL});
    Node* newnode2 = new Node(6,{NULL});
    Node* newnode1 = new Node(3,{newnode,newnode2});
    Node* newnode3 = new Node(2,{NULL});
    Node* newnode4 = new Node(4,{NULL});
    Node* newnode5 = new Node(1,{newnode1, newnode3, newnode4});//常规指针
    unique_ptr<Node> newnode6(new Node(1,{newnode1, newnode3, newnode4})); //智能指针没有使用make_unique 危险操作。容易抛异常之后引发内存泄漏
    unique_ptr<Node> newnode7 = make_unique<Node>(1,{newnode1, newnode3, newnode4}); //使用了make_unique。注意，make_unique无法使用初始化列表来进行构造函数重载。
    auto lists = {newnode1, newnode3, newnode4}; //必须用auto先推导出来一个list initializer
    unique_ptr<Node> newnode7 = make_unique<Node>(1,lists); //使用了make_unique。然后把初始化列表传入。
    Solution* test = new Solution();
    test->preorder(newnode7.get()); //必须使用.get()来获取智能指针包装的原是指针。不然类型不匹配。
}