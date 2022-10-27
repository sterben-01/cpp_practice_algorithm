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
text 双指针 + 贪心
一般来说双指针+贪心都伴随着排序，但是这道题要理清思路。主要是到底是让船的数量+2还是永远+1
&我们为了减少边界判断，永远让船数量+1
@以前的错误想法：如果两个人重量加一起大于限制，则左右都移动，船数量+2。但是这样会有很多边界问题并且不满足贪心思想。
todo正确想法：排序后双指针。两头的人体重加一起如果不超重，则船数量+1，两侧指针都移动。
&如果超重了，则让重的那一个独自坐船。船数量+1，只移动右侧指针。

*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size()-1;
        int count = 0;
        sort(people.begin(), people.end());
        while(left <= right){ //!一定要包含等于的情况。因为可能中间剩下一个人。但是由于我们的船数量固定+1，所以自己加自己无论超重与否都是+1条船。

            if(people[left] + people[right] <= limit){ //不超重就两侧移动
                count++;
                left++;
                right--;
            } 
            else{ //超重只移动右侧。
                count++;
                right--;
            }
        }
        return count;
    }
};