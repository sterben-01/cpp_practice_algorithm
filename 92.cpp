#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
text 每日一句：递归你妈了个逼递归。瞎几把用递归的不是傻逼就是脑瘫。
这道题核心是区间翻转。我们用到了三个指针
pre 这个指针永远指向翻转区间的前一个节点
cur 这个指针指向当前节点 此节点会变化
next 这个节点指向当前节点的下一个节点。此节点会变化

假设现在链表是这样
1   →   2   →   3   →   4   →   5   →   6
我们要翻转2-4 也就是让链表变成
1   →   4   →   3   →   2   →   5   →   6

这个翻转区间我们逐步进行调整
我们的调整顺序是
1   →   3   →   2   →   4   →   5   →   6
1   →   4   →   3   →   2   →   5   →   6
%也就是每遍历到一个节点，让这个新节点来到反转部分的起始位置。下面的图展示了整个流程。
&所以我们的顺序是这样
1   →   2   →   3   →   4   →   5   →   6
pre     cur     next
我们想象一下，1 234 56变成1 324 56。我们要先把2(cur)和4(next->next)接上，然后把3(next)和2(这里不是cur！是pre->next)接上，最后把1(pre)和3(next)接上
第一步：cur->next = next->next
第二步：next->next = pre->next
第三部：pre->next = next
&为什么3和2接上不是next->next = cur? 
1   →   3   →   2   →   4   →   5   →   6
pre             cur     next

&因为我们是这个新节点来到反转部分的起始位置。假如我们是next->next = cur, 那么我们下一次遍历的cur会后移。那么如上图，cur变成了2。那么 next就会和2接上。然后1和4接上。节点3就没了。
&所以我们要保证next的下一个节点是pre的下一个节点，也就是把当前节点的下一个节点变成翻转区域的起点。因为我们交换了顺序。23变成32。2是当前节点，让3变成pre的下一个节点。



&其余注意事项1：记得用虚拟头结点。这种题都要用这个。2.下面的next节点文字替换成了next_node
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* virtualhead = new ListNode(-1);
        virtualhead->next = head;
        ListNode* pre = virtualhead;
        for(int i = 0; i < left - 1; i++){
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for(int i = 0; i < right - left; i++){
            ListNode* next_node = cur->next;
            cur->next = next_node->next;
            next_node->next = pre->next; //注意不可next_node->next = cur
            pre->next = next_node;
        }
        return virtualhead->next;
    }
};