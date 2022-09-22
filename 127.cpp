#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
text 单词接龙 BFS 填海造陆类型。
&首先有一个哈希表储存字典。
一开始先判断endword在不在哈希表，不在就返回0.
&然后把开始词语入队。同时也是填海造陆类型的一圈一圈遍历。
&我们每一个字母都可以改变26次。那么只要这个改变了的字符串在字典里，就把这个改变过的字符串放入队列。并且需要把哈希表内的这个字符串移除。因为防止重复改动。相当于used数组。
%填海造陆的核心就是步长。在最短的桥中就是距离，这里就是看从字符串a到字符串b需要改动几次。每一次入队的都是改动的相同次数，也就是所谓的一圈。
&依旧有很多细节，下面看代码注释
*/





class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.empty() || words.count(endWord) == 0){ //检查如果endword不合法直接返回0
            return 0;
        }
        queue<string> my_que;
        my_que.push(beginWord); //入队
        int count = 1; //&要从1开始。因为改动四次的长度是5。
        while(!my_que.empty()){ //标准BFS
            int size = my_que.size(); //拿到size
            while(size > 0){ //填海造陆
                string target = my_que.front();
                my_que.pop();
                for(int i = 0; i < target.size(); i++){ //&这里改动的是每一位
                    char cur_char = target[i]; //&拿到这个字符串当前的这位的字母
                    for(int j = 0; j < 26; j++){ //&把这个字母从a改到z
                        if(char('a' + j) == cur_char){ //&如果改的过程中，发现这个字母就是原始的入队的字母，就跳过
                            continue;
                        }
                        else{
                            target[i] = 'a' + j; //&把字符串进行改动
                            if(words.count(target) == 1){ //&和哈希表作对比。如果找到了
                                if(target == endWord){ //&如果是endworld，return即可
                                    return count+1;
                                }
                                else{
                                    my_que.push(target); //&如果不是最终结果，当前字符串入队
                                    words.erase(target); //!并且必须把其从哈希表中移除，防止重复查找。
                                }
                            }
                        }
                    }
                    target[i] = cur_char; //!必须要复原。因为 aaa最后一位改变为aaz后，开始改动第二位，必须要变成aaa到aza。也就是要进行复原。
                }
                size--;
            }
            count++;
        }
        return 0;

    }
};