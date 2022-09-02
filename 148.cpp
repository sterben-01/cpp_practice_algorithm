#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;


/*
text 都说这玩意和归并排序很像，我只能说底层逻辑相似，但是实际上差别很大
三个主要模块
&sortlist函数对应归并排序的主函数和sort函数。注意这里不能加虚拟头结点！因为我们有递归调用，加了虚拟头结点直接就窜稀了。要注意！
&split函数，对应寻找链表的中间结点 题号876
%这个函数注意一点在哪呢，寻找中间结点的时候，比如12345我们要拿到123和45。我们为了避免多用一个pre来记录，我们会让一开始的fast多走一格。
%这样我们slow会是3，slow的next是4然后我们把slow的next也就是4当做第二段，然后给前半段接上一个null
&merge函数就是单纯的新开个虚拟头结点，然后看哪个数小就先串哪个。和mergesort一样了。
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* head1 = head;
        ListNode* head2 = split(head);

        head1 = sortList(head1);
        head2 = sortList(head2);

        return merge(head1, head2);
    }



    ListNode* split(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        return second;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* virtualhead = new ListNode(0);
        ListNode* cur = virtualhead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        while(list1 != nullptr){
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        while(list2 != nullptr){
            cur->next = list2;
            list2 = list2->next;
            cur = cur -> next;
        }
        return virtualhead->next;
    }
};