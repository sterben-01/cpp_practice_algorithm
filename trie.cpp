#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//前缀树

#define NODE_NUMBER 26
class TrieNode{
    public:
        bool is_word;
        vector<TrieNode*> subnode;
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
            TrieNode* p = root;
            for(const char item:word){
                if(p->subnode[item - 'a'] == nullptr){
                    p->subnode[item - 'a'] = new TrieNode();
                }
                p = p->subnode[item - 'a'];
            }
            p->is_word = true;
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