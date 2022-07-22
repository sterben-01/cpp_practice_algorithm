#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
*也可以写两种。这里含前导0因为简单。第二种懒得写了。注意数组错位。
这道题也不是比较了，也不是查找子串了，是单纯的删除。啥意思呢，就是当当前位字母相等的时候我们无需操作，因为这时候字符串是一样的。
当当前位字符不同的时候，我们就需要删除字母来达到两个字符串相同的目的
*dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。
我们有三种操作。分别是去掉word1的当前位保留word2当前位。或去掉word2当前位保留word1当前位。或去掉word1和word2的当前位。
所以我们有dp[i-1][j] + 1 /dp[i][j-1] + 1/ dp[i-1][j-1] + 2
为啥前两个是+1？ 因为我们删除一个字母就要操作数+1。我们dp数组储存的是//!次数
为啥最后一个+2？ 因为我们两个字符串都删掉了一个所以要+2

?如何初始化
举个例子 word1 = "", word2 = "abcd";
abcd想要和空串相等就要删掉四次。
所以我们初始化的时候将第0行和第0列的数字初始化为字符串长度也就是i

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i = 0; i < word1.size() + 1; i++)
        {
            dp[i][0] = i;
        }
        for(int i = 0; i < word2.size() + 1; i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i < word1.size() + 1; i++){
            for(int j = 1; j < word2.size() + 1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1]+1, dp[i-1][j-1] + 2});
                }
            }
        }
        return dp[word1.size()][word2.size()];


    }
};