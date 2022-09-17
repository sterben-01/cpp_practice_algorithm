#include <vector>
#include <iostream>
using  namespace std;


/*
这道题最需要注意的地方是两点。
&首先取余操作来计算到底应该移动几个。假如长度是5，需要移两个。那么是2%5不是5%2
&我们一定要遍历一次链表算一下长度
&然后用双指针。不赘述了
&最最重要的是链接的顺序。slow的下一个应该是新链表的头。必须要先设置fast的下一个是head，然后再添加新的指针指向slow->next,最后让slow->next置空
因为假如如果我们有1,2然后移动2位。则slow和fast都会指向2。如果不限fast->next = head，那么新指针的slow->next会变成空指针。
&记住，slow和fast都是指向节点。我们是让fast指向的节点的next指向head。因为slow和fast指向同一个节点。所以slow->next也会变成head。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr){
            return head;
        }

        int length = calcLength(head);
        int rotate = k % length;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < rotate; i++){
            fast = fast->next;
        }
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        ListNode* newListbegin = slow->next;
        slow->next = nullptr;
        
        return newListbegin;


    }
    int calcLength(ListNode* head){
        int count = 0;
        while(head!=nullptr){
            head = head->next;
            count++;
        }
        return count;
    }
};