#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <queue>
using namespace std;


/*
text 哈希表 + 滑动窗口
非常质朴的想法。我们从头开始遍历字符串，如果当前字符不是<我们当前想要保持的字符> 且 <还剩余替换次数>，则我们需要<把当前字符替换为想要保持的字符> 且 <剩余次数减1>。
并且滑动窗口右侧指针右移。
&如果当前剩余次数为0了怎么办? 
我们此时窗口的左侧依旧是起始点。并且我们知道，只有字符不是我们想要保持的字符的时候，才需要替换。所以我们现在的目的是“回收“替换过的字符。这个回收的过程也就是缩小窗口。
这时候我们可以开始使用while循环，只要剩余次数为0，则窗口左侧指针回缩。
&规则有点不同。如果当前字符是我们想要保持的字符，则继续回缩，剩余次数不增加。因为字符没有被替换过。只有当前字符并不是我们想要保持的字符的时候，剩余次数才增加。
&每一次移动当前字符的时候，就记录一次窗口最大值。窗口最大值是 <右侧位置-左侧位置+1>

&这样核心问题解决了。但是我们怎么知道我们到底想要<保持住哪个字符呢>？
我们不知道，但是字符只有26种，那么我们只需要依次遍历即可。也就是第一次假设保持A，第二次B。。。以此类推。
这样就用到了哈希表。这里可以用一个数组简化。记录每一个字符出现的次数。
%只要这个字符出现次数不是0次（因为0次没有意义），我们就假设这个字符是我们现在想要保持的字符。

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int my_map[26]{0};
        int ret = 0;
        for(int i = 0; i < s.size(); i++){
            my_map[s[i]-'A']++;
        }

        for(int i = 0; i < 26; i++){
            if(my_map[i] == 0){
                continue;
            }
            int cur_pos = 0;
            int start_pos = 0;
            int added = 0;
            char cur_char = i + 'A';
            while(cur_pos < s.size()){
                if(s[cur_pos] != cur_char){
                    added++;
                }
                while(added > k){
                    if(s[start_pos]!=cur_char){
                        added--;
                    }
                    start_pos++;
                }
                ret = max((cur_pos - start_pos + 1), ret);
                cur_pos++;
            }
        }
        return ret;
    }
};