#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//前缀树

#define NODE_NUMBER 26
class TrieNode{
    public:
        bool is_word;
        vector<TrieNode*> subnode; //二叉树只有左右所以二叉树节点会有left和right指针。我们这里是N叉树所以用一个容器储存指针
    public:
        TrieNode():is_word(false), subnode(26, nullptr){}
        ~TrieNode(){
            for(TrieNode* item : subnode){
                if(item != nullptr){
                    delete item;
                }
            }
        }
    private:


};

class Trie{
    public:
        Trie(): root(new TrieNode()){}

        ~Trie(){
            delete root;
        }

        void insert(const string& word){
            TrieNode* p = root; //字典树的根节点本身是不储存东西的。根节点里的容器储存的是指向待匹配字符串第一个字母的节点指针
            for(const char item:word){
                if(p->subnode[item - 'a'] == nullptr){
                    p->subnode[item - 'a'] = new TrieNode();
                }
                p = p->subnode[item - 'a'];
            }
            p->is_word = true; //这个标记的作用是如果有单词app和apple，则app位置要加true证明到这里为止是一个单词，而不是非得到子节点才是。
        }

        bool search(const string& word) const{
            const TrieNode* p = find(word);
            return p && p->is_word;

        }

        bool startsWith(const string& prefix) const{
            return find(prefix) != nullptr;
        }



    public:
        TrieNode* root;
    private:
        const TrieNode* find(const string& prifix) const{
            TrieNode* p = root;
            for(const char item : prifix){
                p = p->subnode[item - 'a'];
                if(p == nullptr){
                    break;
                }
            }
            return p;
        }
};





int main(){
    Trie t;
    t.insert("app");
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;

    return 0;
}