#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include<stack>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>

using namespace std;
/*
这题坑很多。
主要思路：我们用vector模拟一个栈。如果当前进来的数字比栈顶的要小，而且是在删除数量的范围内，就把栈顶的去掉，让这个数字进来。因为我们要让数字尽可能小。
第一个坑在，不要真的用栈。字符串拼接会很麻烦。
第二个坑是里面一定要用while。不然加入我们有1234567890 k=1
如果用的是if，就只会删掉9，然后截取的时候会把1截出来。我们的目的是，只要在删除数量的范围内，只要栈顶的数字比当前数字大，就要进行删除。所以要用while

第三个坑就是前导0。我们用库函数判断第一个不是0的数的位置，如果没找到就return 0，
如果找到了，就erase掉从第一位到第一位不是0的那一段。
*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> my_stk;
        for(int i = 0; i < num.size(); i++){

            while(!my_stk.empty() && my_stk.back() > num[i] && k > 0){
                my_stk.pop_back();
                k--;
            }
            my_stk.push_back(num[i]);
        }
        string ret = string(my_stk.begin(), my_stk.end()-k);
        int pos = ret.find_first_not_of('0');
        if(pos == ret.npos){
            ret = "0";
        }
        else{
            ret.erase(0, pos);
        }
        return ret;
    }
};