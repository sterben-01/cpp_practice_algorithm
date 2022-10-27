#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

/*
text 桶排序+优化过的数据结构。
这道题的核心是桶排序。什么是桶排序？
设置 26 个桶，将每个 word 按照 word[0] （也就是第一个字母）放入自己所属的桶。
遍历 S ，每遍历一个字符，就将这个字符的桶里的那些 word “驱赶”到下一个该去的桶里。
每当一个 word 走到尽头时， ans++ 。
也就是假如现在字符串是abcde，单词列表是ace ae bb cd
那么此时26个桶里面的桶 a会有ace和ae，桶b会有bb，桶c会有cd
现在匹配第一个字符a，我们发现ace和ae符合要求，则把ace和ae从桶a拿走，去掉第一个a然后再放入对应的桶，也就是桶c此时增加一个ce，桶e增加一个e。以此类推
&优化数据结构就是字符串的分割和移动非常耗时。我们使用pair。第一位是这个单词在单词表的位置（下标），第二位是当前遍历到了这个单词的第几位。这一步模拟的是上一个例子里的去掉第一个a
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> word(26, vector<pair<int, int>>(0));
        for (int i = 0; i < words.size(); i++) {
            word[words[i][0] - 'a'].emplace_back(i, 0); //把单词表的单词放入桶。
        }

        int count = 0;

        for (int i = 0; i < s.size(); i++) { //这一层是开始对字符串进行匹配。
            auto& item = word[s[i] - 'a']; //todo 细节1 此步是把对应字符的桶里的单词拿出来。因为我们把使用过的单词的pair的第一位设置为-1了，又用pushback添加到新的桶内。所以我们逆序遍历会节省时间
            //todo同时因为增强for循环很难逆向遍历，所以采用传统遍历。
            int size = item.size(); //todo这步骤一样必须。因为假如有bb ccc这样的字符串，拿走后还会放回对应的桶。这样如果用增强for循环就会出问题。所以我们的size一开始就确定好。也就是排除掉运行这轮的时候放入的新的pair
            for (int j = size - 1; j >= 0; j--) { //逆序遍历
                if (item[j].first == -1) { //如果第一位是-1证明是废弃的。直接停止本轮。因为每次一定会把一个桶内遍历完毕，所有的都会是-1.新的都是在这些-1后面的。所以遇到一个-1，则他前面的全是-1
                    break;
                }
                if (words[item[j].first][item[j].second] == s[i]) { //如果字母匹配
                    item[j].second++; //该单词的起始位置+1
                    if (item[j].second > words[item[j].first].size() - 1) { //如果+1后发现超出了单词长度，则证明匹配完毕，是一个子序列。统计+1
                        count++;
                        item[j].first = -1; //标记为废弃。
                        continue;
                    }
                    word[words[item[j].first][item[j].second] - 'a'].push_back({ item[j].first, item[j].second }); //如果没有超出长度，因为已经调整过起始位置，则直接放入对应的桶内。
                    
                    item[j].first = -1; //标记为废弃。
                }
            }
        }
        cout << count << endl;
        return count;
    }
};