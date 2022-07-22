#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

/*
text 这题思路很巧妙。也是利用了栈。首先我们要知道这道题只有（）小括号。其次是我们要找子串，也就是必须要连续的有小括号。所以和单纯的判断有小括号有一定差距
%我们可以把道题拆解成找到最长的连续为0的子串。
&我们让不能创造有效括号的位置为1，可以创造有效括号的位置为0。所以我们有一个vector放1和0
&然后我们要注意，我们为了能让vector的对应的位置来储存该位置的括号是否可以创造有效括号，所以我们的stack存的是下标。所以是stack<int>
&然后我们遍历字符串。如果当前是左括号 '(' 则放入栈。
如果是右侧括号')' 则我们需要判断栈是否为空。如果不为空证明创造了有效字符串。则直接取出。vector不更新是因为我们默认vector元素是0而且0是有效位置
如果此时为空则我们将字符串对应下标的vector的位置置为1。
&当遍历一遍之后，栈内有可能还剩很多左括号的下标 比如一开始的字符串是(((((((())))。匹配完最后一个的时候还会剩下几个(((
所以我们遍历一下栈。因为栈储存的是下标。所以我们只要在vector的对应下标位置把元素设置为1即可。
就假如栈现在还有1 4 6 7 8，则证明下标1 4 6 7 8的是剩余的左括号，不能做为有效位。所以把vector里面下标为1 4 6 7 8的元素置为1

&然后我们就可以遍历一遍vector了。找到连续的0区间
具体做法就是如果当前位置是0则长度++ 如果是1了则长度置为0。每一轮循环的时候判断一下最大值即可。

*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk; //注意栈存的是下标。
        vector<bool> vec(s.length(), 0);
        int maxval = 0;
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){ //左括号入栈
                stk.push(i);
            }
            else{
                if(!stk.empty()){ //遇到右括号，如果栈非空则提出
                    stk.pop();
                }
                else{//栈空则vector对应位置设为1
                    vec[i] = 1;
                }
            }
        }
        while(!stk.empty()){ //处理剩余的左括号
            vec[stk.top()] = 1;
            stk.pop();
        }

        for(int i = 0; i < s.length(); i++){ //遍历一遍vector 找到最长的连续有效（0）区间
            if(vec[i] == 1){
                temp = 0;
            }
            else{
                temp++;
            }
            maxval = maxval >= temp? maxval : temp;
        }
        return maxval;


    }
};