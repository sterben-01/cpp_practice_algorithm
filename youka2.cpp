#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;






class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @param k int整型
     * @return string字符串
     */
    string removeDuplicates(string s, int k) {
        // write code here

        stack<pair<char, int>> my_stk;
        for (int i = 0; i < s.size(); i++) {
            if (my_stk.empty()) {
                my_stk.push(make_pair(s[i], 1));
                continue;
            }
            else{
                if(s[i] == my_stk.top().first){
                    my_stk.push({s[i], my_stk.top().second+1});
                    if(my_stk.top().second >= k){
                        char c = my_stk.top().first;
                        int idx = i+1;
                        while(idx < s.size() && s[idx] == c){
                            my_stk.push({s[i], my_stk.top().second+1});
                        }
                        i = idx - 1;
                        while(!my_stk.empty() && my_stk.top().first == c){
                            my_stk.pop();
                        }
                    }
                }
                else{
                    my_stk.push({s[i], 1});
                }
            }
        }
        string res;
        while(!my_stk.empty()){
            res = my_stk.top().first+res;
            my_stk.pop();
        }
        return res;
    }
};



int main() {

    Solution s;
    string ss = "deeedbbcccbdaa";
    s.removeDuplicates(ss, 3);




    return 0;

}