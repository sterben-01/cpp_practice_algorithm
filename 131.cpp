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
这题也是经典的组合题目。首先也是需要startindex
&几个需要注意的点
&1是终止条件。我们的终止条件就是我们不能继续分割了。即startindex已经等于字符串长度了。就返回了。因为我们要一直找到尾部
&2是用双指针判断是否回文
&3是取substr的时候第一个参数是起始下标，第二个参数是长度这个长度是从1开始的。
&4是如果是回文的话，就push进去。如果不是回文直接跳过进入下一次循环。
*/

class Solution {
public:
    vector<string> vec;
    vector<vector<string>> ret;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ret;
    }



    void backtracking(const string& s,int startindex){
        if(startindex >= s.length()){
            ret.push_back(vec);
            return;
        }
        for(int i = startindex; i < s.length(); i++){
            if(is_par(s, startindex, i)){
                string temp = s.substr(startindex, i-startindex+1);
                vec.push_back(temp);
            }
            else{
                continue;
            }
            backtracking(s, i+1);
            vec.pop_back();
        }
    }
    bool is_par(const string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};