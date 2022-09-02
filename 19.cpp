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
删除倒数第N个。先让快的走N+1步。+1是因为我们要让快的为NULL为止。
记得虚拟头结点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtualhead = new ListNode(0);
        virtualhead->next = head;
        ListNode* slow = virtualhead;
        ListNode* fast = virtualhead;
        for(int i = 0; i < n+1; i++){ //别忘了+1因为算上了虚拟头结点
            fast = fast->next;
        }
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        delnode = nullptr;
        return virtualhead->next;
    }
};