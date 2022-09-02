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
text 这题是DFS。用栈做。
这道题的核心有点难以理解。建议下次看不会的话先去力扣看讲解。我说一下当前一些注意点。
&1. 如果是数字为何乘10.
这个是预防如果是64a的这种情况。第一次传进来是0*0然后0+6。第二次就是6*10 + 4所以是64
&2. ret是怎么做到一个字符串就能弄出来的。
%我们把每一个[]包裹的区域当做一个子区间。我们遇到了[就把[之前的记录下来的数字和这个数字之前的字符串也放进去。这个字符串不是从头算的。是当前的[ 和 上个[之间的字符串。

3[a2[c]]
这个例子来说，我们栈第一次放进去的是 3,""。第二次是2,"a"。这个a是在这个[和上个[之间的。
更明显的例子：
3[a2[c2[d]]]
这个里面栈会是
3,""
2,"a"
2,"c"
这个c就是当前括号和上个括号中间的字符串，因为我们是每遇到一个[就会push一次。数字也是每一个[区间的数字

%我们push进去之后，因为我们的ret在整体遍历期间仅作为一个临时变量储存每一个区间的子字符。然后它会把每个区间的字符和数字push进去。所以每一次push都要给数字和字符清零。

&3.弹出阶段
最后我们每次遇到]就表示可以弹出了。理论就是当前这个]框住的部分（这个部分一定是最内层的部分，res当前是有记录的。）乘以栈顶的元素的数字部分。就是这个字符串应该被重复几次。
这里我们需要拼接。所以是用栈顶元素的字符部分+乘过的当前字符部分。然后再把这个字符串赋值回给ret。因为当前区间处理完毕。我们ret是保存的每一个[之间区间分割的子部分。
*/

class Solution {
public:

    string decodeString(string s) {
        stack<pair<string, int>> stk;
        int num = 0;
        string ret = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10; 
                num = num + (s[i]- '0');
            }
            else if(s[i] == '['){
                stk.push(make_pair(ret, num));
                num = 0;
                ret = "";
            }
            else if(s[i] ==']'){
                int mult = stk.top().second;
                string prev = stk.top().first;
                stk.pop();
                for(int j = 0; j < mult; j++){
                    prev = prev + ret;
                }
                ret = prev;

            }
            else{
                ret = ret + s[i];
            }
        }
        return ret;

    }
};