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
using namespace std;
/*
text 核心是分析有几种可能性。第一种是（），第二种是（...）
第一种的话，也就是我们遇到)的时候栈顶是(。那么我们可以把栈顶元素去掉然后把1push进去
第二种也就是我们遇到)的时候栈顶是数字。那么我们就一直找，直到找到(为止。然后把(拿走，这段的和*2push进去
技巧就是我们把(换成-1。
最后我们的vector模拟的栈只剩下数字了。数字加和即可。
*/


class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> vec;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                vec.push_back(-1);
            }
            else{
                if(vec.back() == -1){
                    vec.pop_back();
                    vec.push_back(1);
                }
                else{
                    int score = 0;
                    while(vec.back() != -1){
                        score = score + vec.back();
                        vec.pop_back();
                    }
                    vec.pop_back();
                    vec.push_back(score*2);
                }
            }
        }
        return accumulate(vec.begin(), vec.end(), 0);

    }
};