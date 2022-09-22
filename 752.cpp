#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <unistd.h>
#include <unordered_set>
#include <queue>
using namespace std;

/*
text BFS
这里bfs 搜索的是位数
假如0000开始 那么0001 0002 0003 0004.... 0009这样就是DFS了
BFS应该是 0001 0010 0100 1000 这样是BFS。
然后我们针对每一位可以向前或者向后旋转一次。也就是0000这个组合可以有0001 0010 0100 1000 0009 0090 0900 9000这八种。也就是每一个组合都有8种可能。
也就是每一位是两种。一共有四位
&用set放置已经标记为禁止到达和已经遍历过的组合。每一次选取进行向前和向后旋转的时候，判断这个组合是否在set里面，如果不在set里面就入队，并且加入set防止重复遍历。如果在set则丢弃进行下一次循环。
%注意一次只能旋转一位数字，意味着你可以0001 0002 0003.但是如果0002标记为禁止，则你必须通过0001 0009 0008逆向到达。所以如果这个数字是禁止的，就不能让其进入队列
&而且，因为只能旋转一位数字所以每次就是针对一个组合的特定位置进行加一减1。
%这个位置使用了一个巧妙的计算方式保证了在0-1这种特殊情况不需要特殊判断。比如0000可以旋转为0009

套用BFS模板如下：
创建队列和去重set。
如果0000初始化数字合法，0000入队。
进行while遍历。并且记录size。此处按照填海造陆方式（像最短的桥和腐烂的橘子那种方式，一圈一圈记录count）
针对当前队列的小于size（当前层）的内容进行遍历。4位，每位可以+1-1.
如果处理后的组合不合法，就是在set内，则丢弃。如果合法就入队并且加入set防止重复遍历。
*/



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> item;
        unordered_set<string> locked;
        locked.insert(deadends.begin(), deadends.end());
        if(locked.count("0000")){
            return -1;
        }
        int steps = 0;
        item.push("0000");
        while(!item.empty()){
            int size = item.size();
            while(size > 0){
                string current = item.front();
                item.pop();
                if(current == target){//找到了就return
                    return steps;
                }
                for(int i = 0; i < 4; i++){//这个操控四位

                    for(int addon = -1; addon < 2; addon+=2){ //这个操控了-1或者+1
                        char a = (current[i] - '0' + 10 + addon) % 10 + '0'; //特殊方式保证比如0-1的时候不会产生负数。比如0000可以旋转回0009.
                        string new_current = current;
                        new_current[i] = a;
                        if(!locked.count(new_current)){ //合法就入队并且加入set去重
                            locked.emplace(new_current);
                            item.push(new_current);
                        }
                    }
                }
                size--;
            }
            steps++; //按照层记录step。
        }
        return -1;
    }
};