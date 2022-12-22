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
        string word = ""; //&本题独有变量。因为题目需要返回所有的单词。我们就可以在满足单词条件的节点上不仅储存这是一个单词，同时储存这个单词的具体内容。
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
            p->word = word;//&本题独有部分。当一个单词插入完毕后，不仅要设置is_word,同时储存单词具体内容方便返回。
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


/*
text 本题核心是字典树+DFS+回溯。
其中我们DFS过程中，判断当前节点是否有指向下一个字符对应节点的指针来判断是否有下一个字符。所以不需要index了。因为是移动指针。
&顺便一提，指针入参的时候指针本身会有浅拷贝。
*/

class Solution {
public:
    vector<string> ret;
    int dir[4][2]{{0,1},{1,0},{0,-1},{-1,0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(int i = 0; i < words.size(); i++){
            t.insert(words[i]); //插入单词
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, t.root, i,j); //dfs模板
            }
        }
        return ret;

    }
    bool is_valid(vector<vector<char>>& board, int row, int col){
        if (row >=0 && col >= 0 && row < board.size() && col < board[0].size()){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, TrieNode* root, int row, int col){
        if(!is_valid(board, row, col)){ //如果越界返回
            return;
        }
        char curchar = board[row][col];
        if(curchar == '*'){ //如果回头路了返回
            return;
        }
        if(root->subnode[curchar - 'a'] == nullptr){ //如果当前节点储存的指向下一个节点的指针没有对应字符，返回。
            return;
        }
        
        root = root->subnode[curchar - 'a']; //指针移动，也就是去往下一个对应字符。
        if(root->is_word == true){ //如果这个时候已经可以组成单词了，则放入结果数组
            ret.emplace_back(root->word); 
            root->is_word = false; //!访问过的单词需要置空，因为假如有oa oaa的话，我们第一次找oa会把oa放入结果。然后继续找oaa，然后发现这条路上面的下一个字符不在字典树内，则会回溯回去。
            //!如果此时回溯回去了，我们发现另一条路上还有OAA，则又会找一次oaa
            //!这个时候oa这个单词会被记录两次。
            root->word = "";
        }
        board[row][col] = '*'; //标记走过的路
        
        for(int i = 0; i < 4; i++){
            dfs(board, root, row+dir[i][0], col + dir[i][1]); //dfs。此处我们之前已经移动了指针已经去往了下一个字符。所以这里不需要再次移动。
        }

        board[row][col] = curchar; //回溯恢复回去。

    }
};