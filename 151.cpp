#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;


/*
text 151 经典题目
核心思想三步走。
&核心：把the sky is blue 去掉多余空格后彻底反转，eulb si sky eht, 然后再翻转每个单词变成 blue is sky the
&第一步去掉多余空格。快慢指针法。细节很多
&第二步整体翻转
&第三部把每一个单词反转回来

*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.length() <= 1){
            return s;
        }
        removespace(s);
        swapstring(s, 0, s.length()-1);
        int start = 0;
        for(int i = 0; i <= s.length(); i++){
            if(s[i] == ' ' || i == s.size()){ //如果是空格了，代表是一个单词。注意一个edgecase就是整个句子是一个单词的时候。
                swapstring(s, start, i-1);      //这里swap的起点是start。就是空格的下一个下标（单词起点）。初始值是0。注意区间是左闭右闭，所以结尾是i-1。因为空格是i，空格前面的字符是i-1，后面的就是i+1
                start = i + 1; //所以单词起点是i+1.
            }
        }
        return s;
    }

    void removespace(string& s){
        if (s.length() <= 0){
            return;
        }
        int slow = 0;
        int fast = 0;
        while(fast < s.length() && s[fast] == ' '){
            fast++;
        }
        for(; fast < s.length(); fast++){
            if(fast > 1 && s[fast] == ' ' && s[fast] == s[fast-1]){ //如果是多余的空格，也就是当前是空格而且前一位也是空格，则fast接着走slow不动
                continue;
            }
            else{
                s[slow] = s[fast];  //如果不是多的空格了，则fast当前的字符拷贝到slow当前的位置上
                slow++; //!这里注意，我们是先拷贝，后++。所以我们下面判断最后一位是不是空格的时候，下标是slow-1而不是slow。因为我们把最后的空格复制过去后，slow又前进了一步
            }
        }
        if(slow > 1 && s[slow - 1] == ' '){         //这就是以上面说的，一定是slow-1.因为slow在最后一次会多走一步。
            s.resize(slow - 1);                 //resize函数的参数 里面的下标是不包括那一位的。
        }
        else{
            s.resize(slow);                     //因为slow会多走一步，resize掉slow是刚好的，因为resize是不要下标为slow的那一位的。
        }
    }
    void swapstring(string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){ //单纯两两互换 注意区间是左闭右闭
            swap(s[i], s[j]);
        }
    }
};