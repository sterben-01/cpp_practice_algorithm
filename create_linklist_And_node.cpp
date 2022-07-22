#include <iostream>
#include <string>
#include<memory>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

int main(){
    //-----土方法-------
    ListNode* newnode4 = new ListNode(4);
    ListNode* newnode3 = new ListNode(3);
    ListNode* newnode2 = new ListNode(2);
    ListNode* newnode1 = new ListNode(1);
    newnode4->next = nullptr;
    newnode3->next = newnode4;
    newnode2->next = newnode3;
    newnode1->next = newnode2;

    //-----方法1--------
    ListNode* cur = new ListNode(1);
    ListNode* headcur = cur; //保存头结点
    cur->next = new ListNode(2);
    cur->next->next = new ListNode(3);
    cur->next->next->next = new ListNode(4);
    cur = headcur;//指回头结点
    while(cur!=NULL){
        cout << cur->val << endl;
        cur = cur->next;
    }
    //------方法2--------
    ListNode* cur1 = new ListNode(1);
    ListNode* headcur1 = cur1;//保存头结点
    for(int i = 2; i < 5; i++){
        cur1->next = new ListNode(i);
        cur1 = cur1->next;
    }
    cur1 = headcur1;////指回头结点

    while(cur1!=NULL){
        cout << cur1->val << endl;
        cur1 = cur1->next;
    }
}