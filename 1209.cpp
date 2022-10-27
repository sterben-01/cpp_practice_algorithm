#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

/*
text 我总记得我在哪做过这个题。应该是某一个的笔试。但是忘了具体了。
&栈模拟。
text 思路要放开。别忘了除了算法以外还有数据结构。
栈储存字符和其连续出现次数。这里格外要注意出现次数的定义。因为我们只能删掉粘在一起的字符。
举个例子：deeedbbcccbdaa
&如果当前字符和栈顶字符相同，则将栈顶字符的出现次数+1。注意这里。栈里面应该储存的是d1,e3而不是d1,e1,e2,d3。
当更新完次数后发现等于k了，则直接从栈中去掉这个元素。所以现在是d1。
如果当前字符和栈顶不同，则插入新元素。出现次数为1。
&细节注意栈要判空。
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> my_stk;
        for(int i = 0; i < s.size(); i++){
            if(!my_stk.empty() && my_stk.top().first == s[i]){
                my_stk.top().second++;
                if(my_stk.top().second == k){
                    my_stk.pop();
                }
            }
            else{
                my_stk.push({s[i],1});
            }
        }
        string ret = "";
        while(!my_stk.empty()){ //拼接回字符串。逆向。
            for(int i = 0; i < my_stk.top().second; i++){
                ret += my_stk.top().first;
            }
            my_stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};