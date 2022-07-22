#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*
本题其实步骤很简单。分割区间 → 区间内翻转 → 接回原链表
有几个地方需要注意。本题需要四个指针 分别是：指向翻转区间开始的前一个节点；也就是头部链表的尾结点 本题叫pre
                                            指向翻转区间尾部的后一个节点；也就是尾部链表的头结点 本题叫next
                                            指向翻转区间开始的节点；也就是翻转区间的第一个节点 本题是while代码块内的临时变量 叫start
                                            指向翻转区间尾部的节点；也就是翻转区间的最后一个节点 本题是while代码块内的临时变量 叫temp
                                            注意：反转过后，翻转区间的头结点start会和尾部链表的头结点cur的下一个结点也就是next链接。而翻转区间的尾结点temp会被头部链表的尾结点也就是pre链接
第五个指针是cur 做为遍历使用。cur的主要作用是新建next结点用于指向翻转区间尾部的后一个节点
此图不够严谨。理论上应该是123区间翻转。懒得改了。
    翻转之前
            start↓           
    0  →  1  →  |2  →  3  →  4|     5  →  6  →  NULL     4和5之间已经被断开了 64行
          ↑pre               ↑cur   ↑next       
    
    翻转之后
             temp↓           ↓start
    0  →  1  →  |4  →  3  →  2|  →  5  →  6  →  NULL
          ↑pre   ↑cur               ↑next       

*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == nullptr){ //判断一下如果输入链表长度是1或者没东西就直接返回
            return head;
        }
        ListNode* virtualhead = new ListNode(0); //新建虚拟头结点
        virtualhead->next = head;                                                      //     VH↓
        ListNode* pre = virtualhead; //此节点作用是保留要反转的链表的前一个节点便于接回去。例如  0 → 1 → |2 → 3| → 4 → NULL
                                    //                                                           pre↑ 
                                    //                                                          0 → 1   |3 → 2|   4 → NULL
                                    //                          作用在这：                          ↑ pre->next = 3    0 → 1 → |3 → 2|  4 → NULL
        ListNode* cur = virtualhead; //此节点作用是遍历
        while(cur->next != nullptr){ //记得加判断next是否是空的 不然会reach nullptr
            for(int i = 0; i < k && cur!=NULL; i++){ //记得循环里也要加判断next是否是空的 不然会reach nullptr
                cur = cur->next;
                
            }
            if(cur == NULL){ //这里是判断是不是到了最后一个。到了最后一个了后面没东西了就不翻转
                break;
            }
            ListNode* next = cur->next;      
            /*                                                                  cur↓
            此节点作用是保留要反转的链表的后一个节点便于接回去。例如    0 → 1 → |2 → 3| → 4 → NULL   
                                                                                    next↑                                                                
            */    
           //                                                                                                cur↓                    
            cur->next = nullptr;           // 断开要翻转的部分的最后一个节点于后续链表的连接      例如 0 → 1 → |2 → 3|  4 → NULL                                                                                                      start↓  cur↓ 
            ListNode* start = pre->next; // 这个结点在翻转后变成了翻转区间的最后一个结点。指明要翻转的部分的第一个节点用于后续链表的链接。此处必须要有，不然反转回来的尾部没有指向了。而且此处因为有虚拟头结点所以可以这么写 例如  0 → 1 → |2 → 3|  4 → NULL   
            ListNode* temp = reverselinklist(start); //反转链表 temp保存的是翻转之后链表的头结点
            /*
                0 → 1 → |2 → 3| → 4 → NULL
                0 → 1 → |2 ← 3| → 4 → NULL
                             ↑ pre   (这里的pre是翻转函数里的返回值pre也就是翻转部分的最后一个节点。这里的pre在函数外面==temp)
                0 → 1 → |3 → 2| → 4 → NULL 
                         ↑ pre(temp)
            */                                                                                                  
           //                                                                                                              
            pre->next = temp;// 接回头部链表.
            /*
            不要把内外函数的pre搞混了。这里的pre是刚才定义的反转链表的前一个节点
                                  start↓   ↓next
                        0 → 1  →  |3 → 2|  4 → NULL
                         pre↑  temp↑  
            */                                                                                 
            start->next = next;//接回尾部链表
            /*
                              start↓    ↓next
                    0 → 1  →  |3 → 2| → 4 → NULL
                     pre↑  temp↑ 
            */
            pre = start; //推到下一个要翻转区间的前一个节点。为什么是前一个呢因为我们统一用了虚拟头结点。
            cur = start;
            /*
                    0 → 1  →  3 → 2 → |4 → 5| → NULL
                               pre↑ 保存下一个翻转区间的头结点的前一个节点
                               cur↑ 遍历用节点 约等于找到尾部
            */

        }
        return virtualhead->next;

    }
    ListNode* reverselinklist(ListNode* head){ //就是一个反转链表的函数。和那个题是一样的
        if(head == NULL || head->next == nullptr){ //判断一下如果反转区间是1或者没东西就直接返回
            return head; 
        }
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};