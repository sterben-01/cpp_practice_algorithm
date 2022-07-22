#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;


/*
合并K个升序链表。
这题就是把链表头（vector里面存的）先放进优先队列。然后优先队列排序的时候拿到了一个节点如果有的话就把他的下一个节点也放进去。
&注意两点
&1. 注意优先队列的底层实现。这部分是基于自己的理解可能有错误：优先队列是基于vector/deque的然后采用了堆排序。意思就是我们每次调整元素，整个优先队列都会被重新排列。
& 所以我们提供的自定义排序函数是交给每次重新排列的时候使用的。就是插入了新元素->整个队列重新排列（排列顺序依照自定义排序函数操作）
&2. 注意一开始放链表头的时候要判空，不然会reach nullptr。
&3. 注意语法。
&4. 注意const&的含义。记住 const&这个整体本身没有特殊意义。它的本质是&使用引用传递防止拷贝。const防止修改。所以我们也可以用const*来及避免拷贝又防止修改
&所以没有const Listnode*& 这个玩意。传指针已经防止拷贝了。仅需加const防止修改即可。

*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class mycomp{
    public:
        bool operator()(const ListNode* node1, const ListNode* node2) const{ //自定义比较 注意没有const Listnode*&这玩意。
            if(node1->val > node2->val){
                return true;
            }
            return false;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycomp> que;

        vector<ListNode*>::iterator iter = lists.begin();
        for(; iter != lists.end(); iter++){
            if(*iter != nullptr){ //注意要判空。不然会报错
                que.push(*iter); //注意语法。此处较为抽象。iter是指向listnode*的迭代器。所以我们要iter解引用
            }
        }

        ListNode* virtualhead = new ListNode(0);
        ListNode* cur = virtualhead;

        while(!que.empty()){
            ListNode* temp = que.top();
            que.pop();
            cur->next = temp;
            cur = cur->next;
            if(temp->next != nullptr){ //记得判空
                que.push(temp->next);
            }
        }

        return virtualhead->next;

    }
};