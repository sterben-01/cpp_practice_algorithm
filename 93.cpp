#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

using namespace std;


/*
text 复原IP 借着这道题回顾一下回溯。
回溯我们所谓的树层，也就是startindex，存在的原因就是看能不能重复用。显然这个不能。所以要有startindex。
for循环控制横向遍历。递归控制纵向遍历。
&所以我们在for里面操作startindex的时候是改的i而不是startindex。
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size() < 4 || s.size() > 12){ //字符串长度大于12小于4不合法
            return ret;
        }
        backtracking(s, ret, 0, 0);
        return ret;
    }
    

    void backtracking(string& s, vector<string>& ret, int startindex, int dotnum){
        if(dotnum == 3){        //如果分割出3段了，看第四段合法不合法。合法就放进去
            //&我们这道题的思路是把一整个字符串放进去，所以这里放进去的是一整个字符串，而且我们是在字符串的自身加点
            if(isvalid(s, startindex, s.size() - 1)){
                ret.push_back(s);
            }
            return;
        }
        for(int i = startindex; i < s.size(); i++){
            if(isvalid(s, startindex, i)){ //如果这一段合法，继续往深处走。

                s.insert(s.begin() + i + 1, '.'); //&给字符串自身加点。
                dotnum++;                           //统计加点次数 
                backtracking(s, ret, i + 2, dotnum); //&别改错了。都是i不是startindex。而且要+2，因为加了点了，+1就干到点上面了
                dotnum--;                           //撤销
                s.erase(s.begin() + i + 1);
            }
        }
    }

    bool isvalid(string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(start != end && s[start] == '0'){
            return false; //注意这里的start!=end 过滤的是一位数的情况。只要不是一位数的时候，start位置的数字是0就非法
        }
        int sum = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            sum = sum*10 + (s[i] - '0');
            if(sum > 255){
                return false;   //这里其实算是剪枝。不用等一大串数字比如110001010算完了之后在判断。可以直接每次计算一位之后就判断。
            }
        }
        return true;
    }
};