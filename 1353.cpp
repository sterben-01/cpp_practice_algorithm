#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <stack>
using namespace std;


/*
text 优先队列
思路
    1.按照会议开始日期对 events 排序，使用默认排序算法就可以
    2.再使用一个优先队列，根据日期，将今天开始的会议全都加入到优先队列中
        &细节：只需要找出今天开始的会议，然后只放入会议的结束日期即可。因为我们每天都固定会参加一个会议。
    3.优先队列的排序以会议的结束日期为标准，保证越接近结束日期的越靠前
    4.每一天如果优先队列里还有会议，就去参加一个
        & 每天固定参加一个会议，前提是队列有剩余会议。
    5.新的一天，先把优先队列里已经过期的会议清除掉
        & 如果队列中有会议的结束日期是早于今天的，也就是已经过期就需要移除

*/

class my_comp{
    public:
        bool operator()(const int a, const int b) const{
            if(a > b){
                return true;
            }
            return false;
        }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, my_comp> my_que;
        int count = 0;
        sort(events.begin(), events.end());
        int pos = 0;
        int date = 0;

        while(pos < events.size() || !my_que.empty()){ //&此处条件不可更改。数组里的内容必须全部放完，并且队列里不能有剩余会议。
            date++; //天数增加。
            while(!my_que.empty() && my_que.top() < date){ //如果队列不为空且队列里有过期会议
                my_que.pop();
            }
            while(pos < events.size() && events[pos][0] == date){ //如果不越界的，并且会议的起始日期是当天则加入队列
                my_que.push(events[pos][1]);
                pos++;
            }
            if(my_que.empty()){ //为空了跳过本轮
                continue;
            }
            my_que.pop(); //每日固定参加一个会议
            count++; //计数
            
        }
        return count;
    }
};