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
此题是148的一部分。可以参考。唯一区别是返回值。
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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
};