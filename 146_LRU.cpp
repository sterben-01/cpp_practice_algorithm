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

class Node{ //新建双链表结构
public:
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int _key, int _value):key(_key), value(_value), pre(nullptr), next(nullptr){}; //构造函数
};


class LRUCache {
public:
    int _capacity; //容量
    Node* virtualhead; //虚拟头结点
    Node* virtualtail; //虚拟尾结点

    unordered_map<int, Node*> map; //注意map存的是int和node，不是int 和 int。因为要通过int对node操作！

    void removeNode(Node* node){    //这里的remove函数仅仅是把这个要删除的节点的前后节点连起来，并没有真正删除
    // 三个节点一共四个指针 四个节点一共六个指针，两个节点只有俩指针！！
        node->pre->next = node->next; // 断开前指针
        node->next->pre = node->pre;
        node->pre = nullptr; //置空节点前后指针。
        node->next = nullptr;
    }
/*  三个节点一共四个指针 四个节点一共六个指针，两个节点只有俩指针！！
                    VH ⇄ P ⇄ VT
        删除顺序：  
                    VH ← P → VT
                    VH ⇄ VT
                     先把p的前面的后面的这个箭头指向p的后面节点
                     然后把p的后面的前面的这个箭头指向p的见面节点
                     这样的话P的箭头会被断开，但是P节点还在 P->pre 和 p->next 还在

*/                  
    void insertNode(Node* node){ //在头部添加
        node->next = virtualhead->next; //将新节点的next指针指向虚拟头节点的下一个节点
        node->pre = virtualhead; //将新节点的pre指针指向虚拟头结点
        virtualhead->next->pre = node; //这一步是操作原来的虚拟头结点的下一个节点的前指针指向新加的节点
        virtualhead->next = node; //链接虚拟头结点和新加的节点。
        
    }
    /*  三个节点一共四个指针 四个节点一共六个指针，两个节点只有俩指针！！
                    VH ⇄ VT
        加入顺序：      
                        P → VT  首先p的next指向虚拟头结点的下一个节点
                    VH ← P → VT p的pre指向虚拟头结点。因为虚拟头结点永远在最前面
                    VH ← P ⇄ VT 虚拟头结点的下一个的前一个指回P这样P和tail就双向连接了
                    VH ⇄ P ⇄ VT 然后虚拟头结点的下一个指向P 这样虚拟头结点和P就双向连接了
*/
    LRUCache(int capacity) {
        _capacity = capacity;
        virtualhead = new Node(-1,-1); //初始化虚拟头
        virtualtail = new Node(-1,-1); //初始化虚拟尾
        virtualhead->next = virtualtail; //头尾链接
        virtualtail->pre = virtualhead;
    }
    //UPDATE 7/18 析构函数
    ~LRUCache(){
        while(virtualhead->next != nullptr){
            Node* temp = virtualhead->next;
            virtualhead->next->pre = nullptr;
            delete virtualhead;
            virtualhead = temp;
        }
        if(virtualhead != nullptr){
            delete virtualhead;
            virtualhead = nullptr;
            virtualtail = nullptr;
        }
    }
    int get(int key) {
        if(map.find(key) == map.end()){ //如果key是不存在的，返回-1
            return -1;
        }
        else{
            Node* node = map[key]; // 通过key值获取node
            removeNode(node); //队伍中取出
            insertNode(node); //放回头部
            //注意这里不要delete。我们仅仅是对节点进行了位置调整。
            //%没有new就不要delete
            return node->value;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){ //如果找到key
            Node* node = map[key]; //通过key获取node
            node->value = value; //更新value
            removeNode(node);//队伍中取出
            //注意这里不要delete。我们仅仅是对节点进行了位置调整。
            //%没有new就不要delete
            insertNode(node);//放回头部
        }
        else{
            if(map.size() == _capacity){ //如果缓存满了，删掉最后的节点。
                Node* node = virtualtail->pre; //最后的节点是虚拟尾结点的前一个节点
                removeNode(node); //这里的remove函数仅仅是把这个要删除的节点的前后节点互相连起来，并没有真正删除这个要删除的节点
                map.erase(node->key); //删除map里面的这个节点的记录。注意删掉的是节点的key不是节点本身。
                delete node; //这里才真正删除了节点本身
                node = nullptr; //指针置空
                //&这里注意一下删除顺序。先removenode断开节点链接。然后从map里删除节点的key。最后再删除节点本身，置空指针。
            }
            //之后插入新节点
            Node* node = new Node(key, value);  //创建新节点
            map[key] = node; //创建map 键值对
            insertNode(node); //插入头部。
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */