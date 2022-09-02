
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
text 这题不能用传统思想解决。1 2 3 3 4 4 5需要把3和4都删掉，而不是去重，是删除重复节点。要变成1 2 5
这道题核心思想是首先添加虚拟头结点避免边界问题
&pre是当前节点
&cur是pre的下一个
&如果cur的值和cur的下一个节点的值一样（此时有重复节点），则cur直接后移，使用while循环直到和下一个节点不相等
&如果cur的值和cue的下一个节点值不同（此时没有重复节点），则按照如下规则：
%如果此前cur曾经跳过，则pre一定和cur之间有空隙。这时pre的下一个节点切到cur的下一个节点 pre->next = cur->next。因为cur是重复节点的最后一位
%如果此前cur没有跳过，或已经处理完跳过的节点，则pre和cur之间没有空隙。这时候按照常规移动，pre = pre->next

&由于最外层是while循环，所以最后需要移动cur。cur = cur->next;

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* virtualhead = new ListNode(0);
        virtualhead->next = head;
        ListNode* pre = virtualhead;
        ListNode* cur = head; //pre->next;
        while(cur != nullptr){
            while(cur->next != nullptr && cur->val == cur->next->val){
                cur = cur->next;
            }
            
            if(pre->next != cur){
                pre->next = cur->next;
            }
            if(pre->next == cur){
                pre = pre->next;
            }
            cur = cur->next;
        }
        return virtualhead->next;
    }
};