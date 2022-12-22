#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

/*
假设输入数组是 [1,3,5,7];
则不同数字的概率应该是

1/16
3/16
5/16
7/16

最朴素的想法，我们可以构建一个如下的数组。
1 3 3 3 5 5 5 5 5 7 7  7  7  7  7  7
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
然后从0~15中随机取一个数字。比如取到了10，则意味着找到了7，我们去原来数组看7所在的下标即可。

但是这个做法过于原始，我们可以使用更简洁的方式。比如建立映射关系。

my_vec数组   1   4   9   16
w数组        1   3   5   7
映射下标      0   1~3 4~8 9~15

my_vec是前缀和数组。也就是1,4,9,16。则最后一个数字就是数组和。这个是题目要求的我们概率的分母是数组的和。
我们映射为index 0 为 w[0], index1~3位w[1]。index4~8为w[2]以此类推

那么如何去做呢

我们rand出来的是index。rand()% my_vec.back()会保证这个数字在合法的区间内。这个例子也就是0~15。因为back是16。
15%16 = 15， 16%16 = 0了。

所以我们rand出来的这个index，比如如果是2，则在区间1~3内，则应该返回下标1。
换句话说就是我们要在my_vec数组中找到第一个比这个rand出来的数字大的数字所在的位置。
假设我们rand出来的数字是5，则在my_vec中第一个比5大的数字是9。然后应该返回9所在的位置也就是2
可以使用upper_bound方法。他会返回一个指向第一个比给定数字大的数字的的迭代器。
最后我们迭代器相减即可获得位置。
*/

class Solution {
public:
    Solution(vector<int>& w) {
        int accumu = 0;
        for(int i = 0; i < w.size(); i++){
            accumu += w[i];
            my_vec.push_back(accumu);
        }
    }
    
    int pickIndex() {

        int num = rand()% my_vec.back();
        return upper_bound(my_vec.begin(), my_vec.end(), num) - my_vec.begin();
    }
    vector<int> my_vec;
};
