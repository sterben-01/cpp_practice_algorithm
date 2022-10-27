#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;
/*
text 基本计算器。没有乘法除法所以简单一些。
&基本规则：
    %res 表示左边表达式除去栈内保存元素的计算结果；
    %sign 表示运算符；
    %num 表示当前遇到的数字，会更新到 res 中；
    %用栈保存遇到左括号时前面计算好了的结果和运算符。
&步骤：
    %如果当前是数字，那么更新计算当前数字；
    %如果当前是操作符+或者-，那么需要更新计算当前计算的结果 res，并把当前数字 num 设为 0，sign 设为正负，重新开始；
    %如果当前是 ( ，那么说明遇到了右边的表达式，而后面的小括号里的内容需要优先计算，所以要把 res，sign 进栈，更新 res 和 sign 为新的开始；
    %如果当前是 ) ，那么说明右边的表达式结束，即当前括号里的内容已经计算完毕，所以要把之前的结果出栈，然后计算整个式子的结果；
    %最后，当所有数字结束的时候，需要把最后的一个 num 也更新到 res 中。
&总结：
1. 如果当前是数字，则正常累加至num。此处是处理有2344这样的多位数字。
2. 如果当前是操作符，则更换对应的sign值。并且保存数字至res，num清0。
todo格外细节注意：为什么是先res+sign*num再更新sign而不是先更新呢？我们遇到表达式2+4的时候可以理解为+2+4。也就是操作符是对后面的数字负责。和前面无关。
todo又因为负号会被显式表示出来，如果是-2-4的时候，遇到-了，sign就会被切换为-1。然后对后面的2负责。
3. 如果是左括号，证明需要优先计算括号后面的。把当前到现在为止的res（计算过的内容）和括号前面的符号（这个符号对括号内的计算结果负责）入栈。然后重置res和sign
4. 如果是右括号，证明计算完毕。并且保存计算结果数字至res，num清0。然后把计算结果乘以这一组括号前面的操作符。也就是这个右括号对应的左括号前面的操作符。然后加上之前计算过的数字。
5. 最后一位的时候一定要再次计算一次res。不然会漏结果。因为我们是每次遇到操作符或者是右侧括号才更新值。

&举例：1+(4+5+2)-3
第一次入栈的时候，是1和1。第一个1是第一个左括号前面的计算结果。第二个1是这个左括号前面的操作符。
然后计算4+5+2 遇到右侧括号的时候此时res是9，num是2，这时候必须更新res。所以会有res = res + sign * num;此时res是11
然后把这个右括号对应的左侧括号的前面的操作符拿出来，也就是栈顶元素。因为这个操作符是对这个结果负责的。然后应用这个操作符。
最后再加上前面的那个1，也就是这一组括号之前已经计算过的内容。
*/
class Solution {
public:
    bool is_digit(char& s){
        if(s >= 48 && s <= 57){
            return true;
        }
        return false;
    }
    int calculate(string s) {
        stack<int> my_stk;
        int res = 0;
        int sign = 1;
        int num = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(is_digit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            else if(s[i] == '+' || s[i] == '-'){ //!一定要注意，操作符是对后面的数字结果负责。和前面无关。所以先更新结果再更新sign
                res = res + sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
            }
            else if(s[i] == '('){
                my_stk.push(res);
                my_stk.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                res = res + sign * num;
                num = 0;
                res = res * my_stk.top();
                my_stk.pop();
                res = res + my_stk.top();
                my_stk.pop();
            }
        }
        res = res + sign * num;
        return res;
    }
};