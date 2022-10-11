#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <stack>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1index = num1.size()-1;
        int num2index = num2.size()-1;
        int x, y;
        int addon = 0; //进位
        string res = "";
        while(num1index>=0 || num2index>=0){
            if(num1index < 0){ //看看是不是有越界。意思是如果某一个数比另一个数短，那么index会到负数。这里的index不是真正的访问作用，而是为了方便计算。
                x = 0;
            }
            else{
                x = num1[num1index] - '0';
            }
            if(num2index < 0){
                y = 0;
            }
            else{
                y = num2[num2index] - '0';
            }
            int ans = x + y + addon;
            addon = ans/10; //大于10了就进位。这里算进位。
            int realcalc = ans%10; //去掉进位剩下的 小于10的部分
            res.push_back('0'+realcalc);
            num1index--;
            num2index--;
            
        }
        if(addon!=0){
            res.push_back('0'+1); // 这里是头一位。如果还剩一个进位就在头一位加1.
        }
        reverse(res.begin(), res.end());
        return res;
    }
};