
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
这道题使用单调队列做。基于deque
&我们让每次窗口新加进来的数字一定成为这个的队头数字。因为我们永远只关心最大的数字。
怎么做呢？假如新加进来的数字比队伍尾的要大，就把队伍尾部的数字拿出来，直到新加进来的数字比队伍尾部的数字要小了，再加进去
这个用代码实现就是下面的push函数
&pop函数为什么要判断data.front() == n呢
我们滑动窗口的大小固定为K。也就是最多有k个数在deque里面。我们每次滑动意味着需要有一个数加进去，一个数提出来。
但是我们上面提到了，我们加入数字的时候会把比加入数字小的数字拿出来，也就是说我们deque里面的数字可能某一时刻是小于k的。
我们要知道，我们提出来数字的意义是去掉“过期”的数字。也就是本来就不需要比较的数字。
假设为我们现在数组是[1,3,-1,-3,5,3,6,7] K = 3
deque的变化如下图
*[1]
*[3] 1被挤掉了
%这时候我们需要开始滑动了。即把-1加进去
*[3, -1]
%我们虽然发现1不在deque里面，但是是因为1是被挤掉的。假如这个数组是个单调递减的，比如 5 4 3这种，这个时候5 4 3将会都在队列里面
%假如现在加进来了个2，5就要被剔除。因为我们窗口是滑动窗口，5虽然大，但是它“过期”了，也就是不在窗口内了。所以我们可以pop_front
!我们pop的是nums数组的数字。也就是第一轮要去掉nums[0]
%但是假如这个5被挤掉了我们的nums[0]本来就不在deque里面了，这时候就不需要再从队列移除了。

&多以我们在pop的时候是nums[i-k+1]; 因为我们一开始会把窗口填满至k-1。这样我们再添加一个就达到了窗口大小，需要去取最值了。
&所以我们每次滑动就要去掉nums数组的第0个。也就是 当前位置 - 滑动窗口大小 + 1 加1是因为当前位置是k-1 我们只填满k-1个。
%第一轮的时候，当前位置是2 滑动窗口大小是3 我们需要移除nums[0]那么就是2-3+1。
*/


class monotonicQueue{
    public:
        deque<int> data;
        void push(int n){
            while(!data.empty() && n > data.back()){ //每次把队尾的比要添加的数字小的数字拿走。
                data.pop_back();
            }
            data.push_back(n);
        }
        void pop(int n){
            if(!data.empty() && data.front() == n){ //如果数字不在队列里就不用pop了
                data.pop_front();
            }
        }
        int max(){
            return data.front();
        }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monotonicQueue que;
        vector<int> ret;
        for(int i = 0; i < k - 1; i++){ //先填充至K-1
            que.push(nums[i]);
        }
        for(int i = k-1; i < nums.size(); i++){
            que.push(nums[i]); //放进去，此时窗口满了，开始取最值
            ret.push_back(que.max()); //取最值了。开始滑动，即从队列移除一个数字
            que.pop(nums[i-k+1]); //移除一个数字
        }
        //我们的顺序是 入循环的时候队列内容是k-1。所以先入队达到窗口大小，然后取最值，然后滑动（移除一位）[保证入队时队列内容是k-1]
        return ret;
    }
};