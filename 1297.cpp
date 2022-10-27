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
text 滑动窗口+哈希表
&这道题最精髓的地方在于maxSize没有用，因为长的串重复它的子串一定也重复。也就是说子串的次数一定大于等于长串。举个例子
假设我们有ABCDE ABCDE ABCDF这个字符串，要找最多4个不同字母，min是4max是5
我们一眼就能看出来 窗口大小 = 5的时候 ABCDE出现两次，BCDEA出现两次 CDEAB出现两次 DEABC出现两次 EABCD出现两次。 ABCDF出现一次
但是窗口大小是4的时候，明显能看到ABCD是3次。BCDE是两次，CDEA两次，DEAB两次E, EABC两次，BCDF一次。
所以说我们看到长的串重复比如ABCDE ABCDE，那么他的子串ABCD也会重复。同时ABCDE虽然不和ABCDF重复，但是都包含ABCD。
&所以我们这道题的滑动窗口其实是固定窗口，也就是固定住看最短的符合要求的窗口大小就好，也就是minSize。
&然后我们用一个数组去保存每个字母出现的次数。随着窗口滑动而进行增减。然后满足条件就放入map，最后返回max value的元素即可。细节较多。
*/
class mymax {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second < b.second) {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int count_unique(const int(&a)[26]) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) {
                count++;
            }
        }
        return count;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> my_map;
        int left = 0;
        int right = 0;
        int times[26]{ 0 };

        for (; right < s.size(); right++) { 
            if (right - left+1 < minSize) { //todo 如果窗口不够大，扩大。 细节1 right-left+1 要+1。因为0~2是3个数。
                times[s[right] - 'a']++; //记录字母出现次数
            }
            else if (right - left+1 > minSize) { //todo 如果窗口超了，缩小
                times[s[left] - 'a']--; //todo 细节2：必须先减掉计数然后再缩小窗口
                left++;
                
            }
            if (right - left + 1 == minSize) { //!核心：此处不可以else if。因为上面条件判断的是负责移动窗口，在移动窗口后如果满足大小条件了就要统计子串了。
                times[s[right] - 'a']++; //todo 细节3，窗口移动完毕后，因为我们是for循环，所以right是在for条件中加的。所以如果当前right不够大，然后for循环中加了，然后下一轮进来的时候会跳过<minsize的这个判断直接进入==。
                //todo 这样就会漏掉当前指向的这个字母。所以我们一定要在==这个分支里把当前字母的统计加上。
                if (count_unique(times) <= maxLetters) {
                    my_map[s.substr(left, right - left + 1)]++;
                }
            }
        }

        auto t = max_element(my_map.begin(), my_map.end(), mymax());
        if(t != my_map.end()){
            return t->second; //有可能找不到，所以记得判空。
        }
        return 0;
    }
};
