#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

struct LinkNode{
        int val;
        LinkNode* next;
        LinkNode(int val): val(val), next(nullptr) {}
};
class MyLinkedList {
public:
    LinkNode* virtualhead; // 名字叫vitrualhead 差不多就是head 但是是虚拟头结点，他的下一个才是真正的head
    int _size;
    MyLinkedList() {
        virtualhead = new LinkNode(0);
        _size = 0;
        
    }
    
    int get(int index) {
        if(index < 0 || index >= _size){
            return -1;
        }
        LinkNode* cur = virtualhead->next;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        cout << "get: " << cur->val << endl;
        return cur->val;

    }
    
    void addAtHead(int val) {
        LinkNode* newnode = new LinkNode(val);
        newnode->next = virtualhead->next; // 这里一定要注意 不能newnode->next = virtualhead 如果直接这样的话就得重新创建虚拟头结点然后指向newnode。newnode后面会多出来一个之前的虚拟头结点。所以先指到virtualhead的下一个然后再把virtualhead指到newnode
        virtualhead->next = newnode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkNode* newnode = new LinkNode(val);
        LinkNode* cur = virtualhead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newnode;
        _size++;

    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        }
        if(index <= 0){
            addAtHead(val);
            return;
        }
        if(index == _size){
            addAtTail(val);
            return;
        }
        LinkNode* newnode = new LinkNode(val);
        LinkNode* cur = virtualhead;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        _size++;

    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= _size){
            return;
        }
        LinkNode* cur = virtualhead;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        LinkNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;



    }
    void getsize(){
        cout << "size: " <<_size << endl;
    }
    void printlinkedlist(){
        LinkNode* cur = virtualhead;
        while(cur->next != nullptr){
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout << cur->val << endl;
        cout << "------" << endl;
    }
};
int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->getsize();
    obj->printlinkedlist();
    obj->addAtTail(3);
    obj->getsize();
    obj->printlinkedlist();
    obj->addAtIndex(1,2);
    obj->printlinkedlist();
    obj->get(1);
    obj->deleteAtIndex(1);
    obj->get(1);
    
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */