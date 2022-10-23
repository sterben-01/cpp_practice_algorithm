#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
text 这道题非常繁琐。我们需要分别计算空格
&明确几个前提条件:
0. 空格分为三种：单词后必须添加的空格 spaceSuffix; 平均分给每个单词的额外空格 spaceAvg; 无法平均分给每个单词的额外空格 spaceExtra
1. 每一行最后一个单词后不加空格
2. 由于1, 所以三个单词有两个空格
3. 需要添加的空格是 每个单词后必须添加的空格 + 平均分给每个单词的额外空格 + 把无法平均分给每个单词的额外空格分配给前n个单词每个单词一个
也就是spaceSuffix + spaceAvg + ((当前单词下标-开始下标) < spaceExtra)
(当前单词下标-开始下标)的意思是。假如有8个空位，现在剩余5个空格，我们需要给前5个单词每人一个空格。(当前单词下标-开始下标)刚好可以算出现在是第几个单词。
由于我们把无法平均分给每个单词的额外空格分配给前n个单词每个单词一个，所以spaceExtra可以理解为应该分给几个单词。
所以
((当前单词下标-开始下标) < spaceExtra)就是判断当前单词是否是 <应该被分配无法平均分给每个单词额外空格的单词>。如果是那么就是+1，如果不是就是+0。
那么极端条件下也就是除了最后一个间隔，前面的间隔都加了一个空格
如果想右边的空格数大于左边，可以从end_index遍历到begin_index，然后(end_index - i) < spaceExtra即可

&注释1. spaceCount和下面的for循环如何搭配看待？ spaceCount计算后是额外应该分配的空格
text 例子：Science_is_what_we, width = 20;

我们如何计算需要额外分配的空格？
首先，四个单词需要三个空格。这三个空格不是额外分配的。
其次，计算出一共有多少非空格字符。
最后，用总长度 - （每个单词后面应有的空格 - 1 [最后一个单词后不需要分配空格]） - 非空格字符

&20 长度 - (4 - 1)[四个单词有三个空格，所以一共应有3个非额外空格] - (7 + 2 + 4 + 2)[这部分是非空格字符] = 2个额外空格

&注释2
spaceSuffix 是单词尾部必须有的空格

&注释3 
如果当前行只有一个单词，那么额外平均空格是1
如果当前行有多个单词，那么额外平均空格是 （额外空格总数 / 单词数量）。wordCount - 1是因为最后一个单词后无空格。四个单词只有3个分配位置(空格)
%当前例子下，额外平均空格是 2 / (4-1) = 0
&注释4
如果当前行只有一个单词，那么额外空格的余数是0
如果当前行有多个单词，那么额外空格的余数是 （额外空格总数 % 单词数量）。wordCount - 1是因为最后一个单词后无空格。四个单词只有3个分配位置(空格)
%当前例子下，额外空格的余数是 2 % (4-1) = 2。意思是给前两个分配位置每一个位置分配一个额外空格。

&注释5 6
@back_inserter是迭代器适配器。叫尾部插入迭代器。参数是支持push_back()方法的容器。在指定容器的尾部插入新元素
todo 用法是获取一个 <第一个参数的容器> 的 尾部插入迭代器。
todo 该迭代器重载了 '='运算符， 所以凡在赋值迭代器时（使用等号），它都会调用容器的 push_back() 成员函数（无论是否解引用）。
@fill_n的第一个参数是迭代器，第二个参数是填充元素的数量，第三个参数是填充元素。
todo 该函数从<迭代器指向的元素开始> 将 <指定数量的元素> 设置为 <给定的值>
!格外注意fill_n 和 fill 只能对输入范围内已存在的元素进行操作。如果试图对空容器或容器内非已有位置（容器外）进行fill_n操作，会导致严重的运行错误。也就是说不可以在容器尾部进行追加操作。
!所以我们才需要插入迭代器。因为fill_n的底层可以理解为对迭代器解引用，然后使用 = 对该迭代器指向的位置赋值。而back_inserter尾部插入迭代器重载了 = 。无论是否对其解引用，在使用等号对其赋值的时候都会调用容器的 push_back() 成员函数
%在当前例子下，fill_n(back_inserter(ans), 1, ' ');的意思是： 首先获取ans的尾部插入迭代器用于定位插入位置。然后从迭代器位置开始（ans的尾部）插入1个空格。


& 注释7 已经在3处解释。
在单词尾部插入 应有的一个空格 + 额外平均分配的空格 + （如果是前n个）额外的无法平均分配的空格。

&注释8
这里需要额外注意细节。不可改为1.因为这一段在for循环外部。如果是最后一行，需要在尾部额外插入空格直到填满。
如果不是最后一行，一般理论情况下maxWidth - ans.size()永远为0。因为无需补上最后的空格。


*/


class Solution {
public:
    string fillSingleLine(vector<string>& words, int begin_index, int end_index, int maxWidth, bool lastLine){
        int wordCount = end_index - begin_index +1; //看看这一行应该塞几个单词。+1是因为第3个到第5个是5-3+1 三个单词。
        int spaceCount = maxWidth - (wordCount - 1); //注释1。
        for(int i = begin_index; i <= end_index; i++){
            spaceCount -= words[i].size();
        }
        //计算后spaceCount就是额外空格。
        int spaceSuffix = 1; //单词尾部必须有的空格 注释2
        int spaceAvg = (wordCount == 1) ? 1 : (spaceCount / (wordCount - 1)); //额外空格的平均值。wordCount - 1是因为最后一个单词后无分配位置(空格)。注释3
        int spaceExtra = (wordCount == 1) ? 0 : (spaceCount % (wordCount - 1)); //额外空格的余数。因为可能额外空格无法平均分布，只能给前几个单词。注释4
        string ans;
        for(int i = begin_index; i < end_index; i++){
            ans += words[i];
            if(lastLine){
                fill_n(back_inserter(ans), 1, ' '); //向字符串末尾添加一个空格。注释5,6
                continue;
            }
            fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - begin_index) < spaceExtra), ' '); //给每个单词后添加对应数量的空格。注释7
        }

        ans += words[end_index]; //插入每一行最后一个单词。
        fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); //补上每一行最后的空格。注释8
        return ans;


    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int count = 0;
        int begin_index = 0;
        for(int i = 0; i < words.size(); i++){
            count += words[i].size() + 1; //加1是为了计算单词后应有的空格。
            if(i == words.size()-1 || count + words[i+1].size() > maxWidth){ //如果这一行是最后一行（最后一个单词）。或者加上下一个词就超过长度了，即可凑成一行
                //&细节1：这里的words[i+1].size()没有+1。因为我们假设当前是最后一个可以添加到该行的单词。但是最后一个单词不加空格。
                ret.push_back(fillSingleLine(words, begin_index, i, maxWidth, (i+1 == words.size())));
                begin_index = i + 1; //&更新开始位置。
                count = 0; //&更新累加字符数量。
            }
        }
        return ret;
    }
};

int main(){
    return 0;
}