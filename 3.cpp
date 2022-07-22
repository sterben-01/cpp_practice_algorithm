#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

/*
text 每日感悟：我们要培养一种思维。一种很傻逼又很牛逼的思维 7/18
这到底感觉还挺好思考的。双指针。然后用一个map储存每个字符出现的位置。注意是储存位置而不是下标。一旦找到重复了就记录住当前的最大长度然后移动左指针到重复的字符的位置上

&比如
A   B   C   B   D
↑↑
left&right

&然后不断移动
A   B   C   B   D
↑           ↑
left        right
发现重复！因为在map里面找到了b。提取出b出现的位置 即下标为1

&左指针移动
A   B   C   B   D
        ↑   ↑
    left    right
left移动到重复字符出现的位置+1。一定要加1。因为新的字符串需要从重复的字符的下一位开始。ABC，要加B发现B重复，则移动到没有B的时候即B的下一位开始
然后记录临时长度。临时长度此时为1.


&在没有重复出现的情况下，不断记录字符出现的位置，移动右指针和记录长度。每次while循环比较一下临时长度和记录的最大长度。

*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;
        int maxlength = 0;
        int temp = 0;
        while(right < s.length()){
            char tempchar = s[right];
            if(map.find(tempchar) != map.end() && map[tempchar] >= left){
                left = map[tempchar] + 1;
                temp = right - left;
            }
            map[tempchar] = right;
            right++;
            temp++;
            maxlength = maxlength>=temp ? maxlength : temp;
        }
        return maxlength;

    }
};