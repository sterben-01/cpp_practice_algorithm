#include <iostream>
#include <string>
#include<memory>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

/*
text 栈
&栈内存放所有的左括号( 的下标
&数组内存放 所有的 无效括号。
& 如果当前是左括号(，标记为失效括号，因为左括号不能脱离右括号单独存在
& 如果当前是右括号)，
    %如果此时栈为空，标记为失效括号。因为右括号出现早于左括号
    %如果此时栈不为空，但是栈顶不是左括号(，那就依然是标记为失效括号，因为两个右括号））连续了。
    %如果此时栈不为空，并且栈顶是左括号(，则这是一组有效括号。把栈顶的左括号从栈弹出，并且把左括号标记为有效的括号。
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> my_stk;
        vector<int> my_vec(s.size(), -1);

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '('){
                my_stk.push(i);
                my_vec[i] = 0;
            }
            else if(s[i] == ')'){
                if(!my_stk.empty() && s[my_stk.top()] == '('){
                    my_vec[my_stk.top()] = 1;
                    my_stk.pop();
                }
                else{
                    my_vec[i] = 0;
                }
                
            }
        }
        string ret;
        for(int i = 0; i < s.size(); i++){
            if(my_vec[i] == 0){
                continue;
            }
            else{
                ret += s[i];
            }
        }
        return ret;
    }
};