#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

/*
text 环形链表2 背口诀：
& 一快一慢一起走，两个碰头慢回头，一步走，一步走。再相遇，就是goal。
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){ //先判空
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){ //因为fast走得快，判空fast 
            fast = fast->next->next;           
            slow = slow->next;
            // &一快一慢一起走

            if(slow == fast){//&两个碰头慢回头
                slow = head; //慢回头
                break;
            }
        }
        if(fast == nullptr || fast -> next == nullptr){ //判空，和上面一样。不能和while合在一起。背下来就行。
            return nullptr;
        }
        while(slow != fast){ //&一步走，一步走，再碰头
            slow = slow->next;
            fast = fast->next;
        }
        return slow; //&就是头
    }
};