#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
text 这道题非常非常牛逼。是字符串+计数。记住必须要有效的croak。也就是不能多其他字符也不能少字符。
此题表面一看是哈希表+贪心。但是这都是弟弟做法。真正的做法在这里。
croak是一个固定搭配。我们先假设字符串中只有croak，并且完全按照顺序。但是中间会插入其他的croak

我们知道，如果蛤想叫出r，则他必须先叫过c。如果想叫o则必须先叫过r。依次类推。因为必须按序。
&核心就是假设croak是五种情况。也就是当前叫这个字母的蛤的数量。蛤想叫r代表他叫过了c。那么我们可以把叫r的蛤的数量+1，叫c的蛤的数量-1。因为状态从蛤叫c->蛤叫r
我们先看基本情况croakcroak。我们的蛤叫c，此时没有蛤，则必须创建一个蛤。这个创建就是ret。我们以此类推。叫r的时候c--，r++。然后一直叫到k。这时候接着叫c。此时发现有蛤叫k，叫到k代表此时蛤会闲下来。所以可以重复用这个蛤。

假设现在是cro cr croak oak ak
假如我们现在第一个蛤叫到了o。这时候又有一个c，此时k是0所以没有空闲的蛤，就必须再创建一个蛤。ret++。以此类推

&在每一次循环的时候，如果发现了是其他字符则直接停止。比如croab。
&在每一次循环的时候，如果发现了croa这四种有一种小于0，代表这个青蛙不是从c开始叫的。直接停止。比如rcrock
&如果最后发现croa这四种都不是0，证明有青蛙没叫到k。所以返回-1.比如croakcro。这种是非法组合。
*/


class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0,r = 0,o = 0,a = 0,k = 0;
        int ret = 0;
        for(int i = 0; i < croakOfFrogs.size(); i++){

            if(croakOfFrogs[i] == 'c'){
                if(k > 0){ //如果开始叫的时候有空闲的蛤，则转移一下状态。
                    k--;
                }
                else{ //如果没有空闲蛤，则创造一个空闲蛤。
                    ret++;
                }
                c++;
            }
            else if(croakOfFrogs[i] == 'r'){
                c--;
                r++;
            }
            else if(croakOfFrogs[i] == 'o'){
                r--;
                o++;
            }
            else if(croakOfFrogs[i] == 'a'){
                o--;
                a++;
            }
            else if(croakOfFrogs[i] == 'k'){
                a--;
                k++;
            }
            else{
                return -1;
            }
            if(c < 0 || r < 0 || o < 0 || a < 0){
                return -1;
            }
        }
        if(c != 0 || r != 0 || o != 0 || a != 0){
            return -1;
        }
        return ret;

    }
};