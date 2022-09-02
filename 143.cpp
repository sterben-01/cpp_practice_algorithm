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
text 此题非常非常经典。涉及到了链表翻转，快慢指针和链表合并。
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
    void reorderList(ListNode* head) {
        if(head == nullptr){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next!= nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* first_head = head;
        ListNode* first_end = slow;
        ListNode* second_head = first_end->next; //注意这个和reverse不能写在一行。因为要先赋值（找到第二段链表的头部），然后断开。之后再翻转
        first_end->next = nullptr;
        second_head = reverse_list(second_head);
        merge_list(first_head, second_head);
    }
    void merge_list(ListNode* N1, ListNode* N2){
        ListNode* tmp1;
        ListNode* tmp2;
        while(N1 != nullptr && N2 != nullptr){
            tmp1 = N1->next;
            tmp2 = N2->next;

            N1->next = N2;
            N1 = tmp1;

            N2->next = N1;
            N2 = tmp2;
        }
    }

    ListNode* reverse_list(ListNode* head){

        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};