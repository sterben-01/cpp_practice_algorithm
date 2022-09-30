#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

/*
text 删除最外层的括号。这题这么写前提是保证了输入是有效的。也就是不存在)(这种情况
当"("入栈前，栈是空，说明 "(" 是『原语』的开头，因此不放入 res中。
当遇到 ")" 弹出栈顶以后，栈是空，说明 ")" 是『原语』的结束，因此不放入 res中。
&注意这三个if是并列的。
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;
        for(auto& c : s) {

            if (c == ')'){ //如果是)就弹出
               st.pop(); 
            }
            if (!st.empty()){ //如果非空就加入字符串
                res.push_back(c);
            } 
            if (c == '('){ //如果是左括号就入栈。
                st.emplace(c);
            }
        }
        return res;
    }
};