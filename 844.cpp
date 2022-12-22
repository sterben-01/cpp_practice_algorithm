#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <unordered_map>
using namespace std;
/*
text 栈也可以。但是用双指针更好。
双指针从后往前扫。
首先最外侧while是二者选一没到头就行。
记录两个的#数量。
然后选一个扫。如果扫到了#，增加#数量，同时往前推
                如果不是#，看是否有#，如果有就往前推然后减少#数量
                其余的break
另一个和这个一样

这样做的目的是下面我们比较的时候，这两个比较的字母一定是不可去除的。因为无法去除了。
紧接着比较。这里的比较必须二者pos都大于等于0。
!因为扫到头了的话pos会是-1
这时候看两个字母是不是一样，不一样直接false
如果二者pos不是都大于等于0，那么只要有一个小于0，证明到头了。这时候一个扫到头了另一个只要没到头就证明是false。直接return false

然后两个pos--

最外层是true


*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_space = 0;
        int t_space = 0;
        int s_pos = s.size()-1;
        int t_pos = t.size()-1;
        while(s_pos >= 0 || t_pos >= 0){

            while(s_pos >= 0){
                if(s[s_pos] == '#'){
                    s_space++;
                    s_pos--;
                }
                else if(s[s_pos] !='#' && s_space > 0){
                    s_space--;
                    s_pos--;
                }
                else{
                    break;
                }
            }
            while(t_pos >= 0){
                if(t[t_pos] == '#'){
                    t_space++;
                    t_pos--;
                }
                else if(t[t_pos] != '#' && t_space > 0){
                    t_space--;
                    t_pos--;
                }
                else{
                    break;
                }
            }
            if(s_pos >= 0 && t_pos >= 0){
                if(s[s_pos] != t[t_pos]){
                    return false;
                }
            }
            else{
                if(s_pos >= 0 || t_pos >= 0){
                    return false;
                }
            }
            s_pos--;
            t_pos--;
        }
        return true;
    }
};