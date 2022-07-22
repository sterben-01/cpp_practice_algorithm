#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* cur = head;
        //复制一遍链表从1→2→3变成1→1→2→2→3→3
        while(cur!=NULL){
            Node* newnode = new Node(cur->val);
            newnode->next = cur->next;
            cur->next = newnode;
            cur = newnode->next; //1→1→2 从1直接跳到2 第一个1是cur 第二个1是newnode 让cur=2就是cur = newnode->next
        }

        cur = head; //reset一下

        //构建random指针的值
        while(cur!=NULL){
            if(cur->random!=nullptr){ //需要判断是否为空。注意没有cur->random->val==null这种东西。这里我们新建的所有节点的random指针一开始都是nullptr。如果原链表的某一个节点的random指针指向了nullptr，那么我们不赋值给新链表的这个节点的random指针就可以了。
                cur->next->random = cur->random->next; //cur是原链表的节点 cur->next是复制过的链表的节点所以要cur->next->random
            // 因为是复制过的1→1→2→2→3→3 所以复制过的节点的random值一定要指向源节点的下一个也就是复制过的节点也就是cur->random节点的下一个也就是cur->random->next 不然就指回去了

            }
            cur = cur->next->next; // 一样，需要跳过去 cur是1, cur->next是第二个1, cur->next->next是2
        }
        //开始链表拆分
        cur = head;
        Node* newlist = head->next;
        Node* res = newlist; //记得保存一下新链表的头结点的指针，不然回不去了。。。
        while(newlist->next!=nullptr){
            cur->next = cur->next->next; //注意这两行一定不能写反！！！写反了就是先断开后部分了。前部分找不到了！！
            newlist->next = newlist->next->next;
            /*
            1 → 1 → 2 → 2 → 3 → 3 → 4 → 4 → NULL
            如果写反了先断开后面的就变成 1 → 1 x 2 → 2 → 3 → 3 → 4 → 4 → NULL
                                            ↓ → → → ↑
            然后你第一个1的下一个就变成了第二个2了就乱了。断开的顺序一定要写对。

            正常应该是1 x 1 → 2 → 2 → 3 → 3 → 4 → 4 → NULL
                      ↓ → → → ↑
            然后      1 x 1 x 2 → 2 → 3 → 3 → 4 → 4 → NULL
                          ↓ → → → ↑

            */                   
            newlist = newlist->next;
            cur = cur->next;
        }
        cur->next = nullptr;
        return res;
    }
};