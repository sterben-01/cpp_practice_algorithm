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
脑残题目。
text Amazon OA
首先我们就是有一件事要确认。这道题也是要遍历的。就是假设出现最少次数的字母是a-z的一个，出现最多次数的字母是a-z中的一个。我们从aa遍历到zz
&但因为不可以一整个字符串仅出现一个字符。比如aaaaaaa。这样无意义。所以所有的aa bb cc dd...都可以略过。
&我们一定要假设first是出现的最多的字符，second是出现最少的字符。这样我们维护两个变量
%第一个是diff。记录了first出现的次数和second出现的次数的差
%第二个是diff_with_second。记录了包含了second的时候，first出现的次数和second出现的次数的差。
举例子：
假设是aaabbb。我们从first = a, second = b开始遍历。因为aa重复
第一个字母是a，diff++，diffwithsecond++。意思是当前状态下，出现了first出现的次数和second出现的次数的差是1.因为a出现了一次，b没出现。所以diff++。
为什么diffwithsecond也要++呢？
&关键点1. 当我们没有遇到second的字符，也就时second指定的字符没有出现的时候，diffwithsecond++是无意义的。因为初始值是负无穷。直到遇到了第一个second指定的字符的时候，才会变为diff--后的值
%所以按照刚才的例子。第一个字母是a，diff = 1, diffwithsecond = 负无穷+1
%第二个字母是a, diff = 2， diffwithsecond = 负无穷+2.
%第三个字母是b, diff = 2-1, diffwithsecond = diff = 1
&我们每次遇到second指定的字符时候，出现差距减少了1。aa的时候差距是2， aab就是1了。
&关键点2。diff在赋值后需要需要去取max。为什么？因为如果diff是负的。对整个字符串没有正贡献。
%详细解释就是我们要找最大波动。我们这里没有字符串的截取。我们靠这个来去掉负贡献。
举例子：
aabbaaaa，first = b, second = a
一开始second为负了。没有正贡献。我们不记录负值就等于截掉了第一个a
直到遇到了bb。这时候diff是正的、正常记录。
又遇到了四个a, diff逐渐转为负的。我们不会记录负值。所以小于0的时候按照0计算。这样不会对我们的累计值进行一个相减操作。
&关键点3：为何要先赋值后取max。
!首先关键点要理解。假设字符串为aab，first = a, second = b。在这种情况下，aa的时候只会走第一个if。这时候所有对diff_with_second的操作都可以忽略，无意义。因为一定小于0
!假设遍历到了first = b, second = a。在这种情况下aa的时候只会走第二个if。这时候所有对diff_with_second也都可以忽略。无意义，因为上来diff就--了。diff_with_second也是负的
update 直到遍历的时候，两个字符（first和second指定的字符）都出现了的时候 diff_with_second才有意义！
*/


class Solution {
public:
    int largestVariance(string s) {
        int maxans = 0;
        for(char first = 'a'; first <= 'z'; first++){
            for(char second = 'a'; second <= 'z'; second++){
                if(first == second){
                    continue;
                }
                int diff = 0;
                int diff_with_second = INT32_MIN;
                for(char item : s){
                    if(item == first){
                        diff++;
                        diff_with_second++;
                    }
                    else if(item == second){
                        diff--;
                        diff_with_second = diff;
                        diff = max(diff,0);
                        
                    }
                    maxans = maxans >= diff_with_second ? maxans : diff_with_second;
                }
            }
        }
        return maxans;
    }
};