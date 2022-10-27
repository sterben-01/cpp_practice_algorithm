#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;
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
                if(p == nullptr || p->is_word == false){ //&本题唯一修改的地方是这样。因为题目要求单词必须是逐个字母增加的。翻译过来就是这个路径上，到达每一个节点都要能组成一个节点。
                    break;
                }
            }
            return p;
        }


};

/*
text 字典树应用入门题目。照着模板复制粘贴。
&本题唯一修改的地方是search。因为题目要求单词必须是逐个字母增加的。翻译过来就是这个路径上，到达每一个节点都要能组成一个节点。
举个例子就是
a ap app appl apple
这样的话字典树路径a->p->p->l->e每一个节点上 is_word都是true
但是ban
b->a->n 只有到了n的时候 is_word才是true
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        string ret = "";
        for(int i = 0; i < words.size(); i++){ //把单词塞进去
            t.insert(words[i]);
        }
        for(int i = 0; i < words.size(); i++){
            if(t.search(words[i]) == true){ //看有没有这个单词。并且满足逐个字母增加的条件
                if(words[i].size() > ret.size() || (words[i].size() == ret.size() && words[i] < ret)){ //看谁长，一样长按照字典序。
                    ret = words[i];
                }
            }
        }
        return ret;

        
    }
};