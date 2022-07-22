#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;



/* 
text 假如我们有两个字符串 ADOBECODEBANC。 和 ABC 我们用两个哈希表记录每一个字符出现的次数。
&我们先遍历字符串T。获得目标字符串的每一个字符的数量 得到一个T表 如下图
A: 1
B: 1
C: 1
&还有一个变量记录有多少个字符已经被找到了
cnt = 0
&然后我们遍历字符串C。我们采用双指针法。指针j用于收缩窗口，指针i用于拓展窗口。然后进行查找。也就是遍历。
&指针j先动，记录S表。记录的过程中，如果发现这个字符在T表里不存在，则跳过。如果在T表存在，证明是一个目标字符串的对应字符。则cnt++
%这里的语法实现比较特殊。假设我们现在s[i] = 'D' 因为我们是hs[s[i]]++; 意思是表S对应的key为s[i]的value + 1。这里是已经加1过的。
todo map的语法非常特殊。map[i]，我们在使用[]下标访问操作符的时候等于已经在调用了 find这种寻找方法。但是map如果找不到对应的键值对，也就是如果i在map里不存在，则会直接创建一个键值对，key = i, value = 默认值（0）。
%所以这里hs[s[i]]++ 的意思是，因为hs[s[i]]调用了下标访问（寻找）,因为还不存在，找不到了，则新建一个key = s[i], value = 0 的键值对。然后hs[s[i]] + 1，这时候hs里面访问s[i]这个key，现在有了，则提取出值然后+1
&所以我们的第一个if判断是否存在是怎么判断的呢，现在hs['D'] = 1, 我们if比较的时候依旧使用了下标访问（寻找）t表里面的'D'。但是t表里面没有d，则新建一个键值对 key = 'D', value = 0 然后我们比较，hs['D'] = 1, ht['D'] = 0。
这样因为1>0 所以认定当前字符没有在ht里面出现过，则不需要这个字符。不需要记录cnt
@注意，这里我们模拟的是仍旧未发生找到重复字符的情况。即没有触发窗口收缩。

&然后我们一直找到了字符串s的s[5]即 C。发现cnt达到了3， 这样表明我们找到了一个合格的字符串区间。用substr切割并记录。这里的if是为了判断以后满足条件的字符串和现在的哪个更短，也就是结果哪个最优。

&然后我们继续遍历，直到字符串s的s[10]即A.
!此处较难理解! 我们要注意，我们的收缩指针i一直在位置0。直到我们字符串s的第一个字符出现的次数大于字符串t的对应字符的需求的时候才会触发收缩。
这句话比较sb。我们举例说明
&这里我们case比较特殊。因为字符串S的第一个字符是t所需，所以一直不收缩。如果S的第一个字符不是t所需的，则一开始就会收缩。
我们hs[s[j]] 和 ht[s[j]]都是hs[0] ht[0] 也就是A的数量相比较。
我们s[9]的第二个B不会触发收缩。因为A在那卡着呢。不过不要紧。
我们走到s[10]的时候 表S的A项变成了2， 2>1触发收缩。j移动，这里是while。
我们模拟一下，收缩开始了。
A多了，收缩
D不需要，收缩
O不需要，收缩
B多了，收缩
E不需要，收缩
到C停了。因为表S中c的数量不大于表t中c的数量了
由于cnt不--，所以只要找到第一个满足的字符串后永远都会进入这个if判断。但是这个字符串一定比第一个满足的长。
这时候字符串是CODEBA。但是这个比ADOBCE长，所以不更新

然后走到s[12]。C多了，开始收缩
我们模拟一下
C多了，收缩，
O不要，收缩，
D不要，收缩，
E不要，收缩。
然后到B停了。因为这时候表S只剩下一个b。不大于了。
然后这时候截取字符串是BANC。比CODEBA短。所以最后答案是BANC。
*/ 

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto c: t) ht[c] ++ ;
        string res;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i ++ ) {

            hs[s[i]] ++ ;
            if (hs[s[i]] <= ht[s[i]]){
                cnt++;
            }

            while (hs[s[j]] > ht[s[j]]){

                hs[s[j]] -- ;
                j++;
            } 
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    s.minWindow("ADOBECODEBANC。", "ABC");
    return 0;

}