#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

/*
两个虚拟头。一个奇数一个偶数。
两个遍历指针oddhead和evenhead
两个标记指针oddbegin evenbegin
&遍历过之后，如果有剩余的一个一定是偶数后面的那个，那个没用。所以需要断开。
然后奇数链表尾部和偶数链表头部连起来就行
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead = new ListNode(-1);
        ListNode* evenhead = new ListNode(-1);
        ListNode* evenbegin = evenhead;
        ListNode* oddbegin = oddhead;
        ListNode* cur = head;
        int count = 1;

        while(cur!=nullptr){
            if(count%2 != 0){
                oddhead->next = cur;
                oddhead = oddhead->next;
                cur = cur->next;
                count++;
            }
            else{
                evenhead->next = cur;
                evenhead = evenhead->next;
                cur = cur->next;
                count++;
            }
        }
        
        oddhead->next = evenbegin->next;
        evenhead->next = nullptr; //一定要记得断开最后一个设置为null。
        return oddbegin->next;
    }
};