#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

class mymax{
    public:
    bool operator()(const pair<char, int>& a, const pair<char,int>& b) const{
        return a.second < b.second;
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    int minOperations(string str) {
        // write code here
        vector<int> num(26,0);
        for(auto item :str){
            num[item - 'a']++;
        }
        set<int>my_set;
        for(int i = 0; i < 26; i++){
            if(num[i] == 0){
                my_set.insert(i);
            }
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(num[i] == 0 || num[i] == 1){
                continue;
            }
            while(num[i] != 1){
                count++;
                num[i] = num[i] - 2;
                if(num[i] == 0){
                    num[i] = 1;
                }
                else{
                    if(my_set.empty()){
                        num[i]++;
                    }
                    else{
                        auto t = my_set.begin();
                        my_set.erase(*t);
                        num[*t]++;
                    }
                }
            }
        }



        return count;
    }
};
int main(){
    Solution s;
    s.minOperations("abab");
    return 0;
}