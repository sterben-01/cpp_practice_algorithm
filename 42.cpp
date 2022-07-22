#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <stack>
using namespace std;

/*
接雨水这道题还是比较经典的。我们使用了单调栈
首先我们要明确几点：
&1. stack里面存的是下标。举例子，我们知道vector里面第五个位置的墙比第二个位置的高。我们就记录这墙的位置来计算。
&2.规则： 如果这个新要加stack的墙比现在栈顶的墙矮，那就说明可以接水了。
&         如果这个新要加stack的墙和现在一样高，那我们把原来记得位置拿掉，换成新的。
%         按照下面题为例。我们发现1和2一样高我们就把1弄掉2放进去、然后发现3和4一样高就把3弄掉4放进去。因为我们算能接多少水就是算2-4的距离
&         如果这个新要加stack的墙比现在栈顶的墙高，那就说明凹槽出现了我们需要计算了。
%         具体计算的方法是记住当前栈顶的元素 因为这里是凹槽。高的墙还没入栈呢（这里是墙的下标因为我们都是存的下标）。
%         高度的计算方法是当前这个墙的高度（最高的） 和 栈顶的墙的高度相比，找到小的那一个，用小的那一个减掉中间凹槽的高度。就得到了整体高度。（因为最左边的墙高4， 凹槽高3， 右边高5，你只能接一格，因为是短板效应嘛。）
%         宽度的计算方法是当前下标 i （当前墙的位置） 减掉栈顶元素（我们栈存的是墙的位置） - 1 再减1的原因是4-1 = 3但是格子只差了俩。1到4中间空的是两个位置 即 2 3。
%         然后相乘即可
                        |
    |   |           |   |
    |   |   |   |   |   |
    |   |   |   |   |   |
0   1   2   3   4   5   6
----------------------
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; //记住stk存的是墙的下标。
        int sum = 0;
        stk.push(0);
        for(int i = 0; i < height.size(); i++){
            if(height[i] < height[stk.top()]){ //如果这个新要加stack墙比现在栈顶的墙矮，那就说明可以接水了。入栈
                stk.push(i);
            }
            if(height[i] == height[stk.top()]){  // 如果这个新要加stack的墙和现在一样高，那我们把之前的换成新的。
                stk.pop();
                stk.push(i);
            }
            else{
                while(stk.empty() == false && height[stk.top()] < height[i]){ //要用while循环。因为只要当前新要加的墙比栈顶的墙高，就证明还能接水。
                //所以要一直计算到栈空了（两个墙挨着了）或者是当前新要加的墙比栈顶的墙矮了（可以继续接水了）
                    int mid = stk.top(); //计算当前栈顶（凹槽）的下标
                    stk.pop();          //去掉凹槽，这时候栈顶剩下的是左边的墙的下标
                    if(stk.empty() == false){   //判空。为了预防两堵墙挨着。比如墙高3和墙高4挨着了，去掉3就没了。就代表不行了。
                        int h = min(height[i], height[stk.top()]) - height[mid];//计算高度。找到凹槽左边和右边比哪堵墙矮。（因为有可能左边比右边高。比如312，也有可能右边比左边高 比如213）然后减掉凹槽的高度。得到相对高度
                        int w = i - stk.top() - 1; //计算宽度。当前下标减掉左边的墙的下标再减1.再减1的原因是4-1 = 3但是格子只差了俩。1到4中间空的是两个位置 即 2 3。
                        sum = sum + h * w; //累加
                    }
                }
                stk.push(i); //然后把当前这面墙入栈。因为我们刚才一直计算到了栈空了（两个墙挨着了）或者是当前新要加的墙比栈顶的墙矮了（可以继续接水了）。到这一步就证明这面墙比栈顶的墙矮了。或者是栈空了，这面墙就是新的第一面墙。
            }
        }
        return sum;

    }
};