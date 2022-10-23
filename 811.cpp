#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

/*
text 不难，注意思路。针对字符串类问题不要总想着如何去切割出来，要思考技巧。不能纯模拟。比如这个题
9001 discuss.leetcode.com
我们明显要切成这么几段

9001
discuss.leetcode.com
        leetcode.com
                 com

第一段非常好切。从0切到第一个空格。
后面文字部分我们肯定想到用find。但是find没那么好用。我们这种情况下用遍历+substr来实现
首先我们必须要记住判断是否是空格。因为如果当前位置是空格，我们才能把后面一整段discuss.leetcode.com切出来放到里面，也就是从空格位置+1切到末尾。
然后我们判断是否是点. 只要是.我们就可以从.后面一位一直切到末尾。比如leetcode.com 和 com。这样省去了find。
*/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int>my_map;
        for(int i = 0; i < cpdomains.size(); i++){
            string& s = cpdomains[i];
            int pos = s.find(' ');
            int v = stoi(s.substr(0, pos)); //先把数字切出来
            for(; pos < s.size(); pos++){
                if(s[pos] == ' ' || s[pos] == '.'){ //然后用遍历下标的方式。遇到空格或者点就切到末尾。
                    my_map[s.substr(pos+1)] += v;
                }
            }
        }
        vector<string> ans;
        for(auto t:my_map){
            ans.emplace_back(to_string(t.second) + " " + t.first); //放到数组就可以了。
        }
        return ans;
    }
};