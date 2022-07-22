#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
text 这道题极度难算。

text 首先我们假设有两个数组

1   3   4   9

1   2   3   4   5   6   7   8   9   10

text 假设我们要找第K小的数字，这个k将会是我们未来的中位数下标。假设现在k是7，我们可以每次找两个数组的第k/2个数字。如果某个数组的第k/2个数字比较小，那么那个数组的前k/2个就都不是第K小的数字。而是比k小的数字

k = 7, k/2 = 3
&注意第K位的下标是K-1 第3小的数字的下标是2

1   3   4   9
        ↑
1   2   3   4   5   6   7   8   9   10
        ↑

text 我们发现第2个数组的第k/2个数字比较小，那么它之前的 1 2 3 则都小于K 所以我们去掉1 2 3 （代码实现就是数组2的start往后推）
text 我们要找第7小，现在已经找到了3个，仅需找到四个。（代码实现就是k - (i - start2 + 1)) 这里比较复杂。i在下面写了。这里算就是 7 - [0 + min(10, (7/2)) - 1 - 0 + 1] = 7 - (0 + 3 - 1 - 0 + 1) = 7 - 3 = 4
text 以此类推

@ 几点注意的要点
&1. left 和 right单独拿出来的原因是什么？
% 我们为了让总长度为奇数和偶数的时候统一计算。
% 假如总长度是偶数 4+10 = 14，那么中位数应该是7+8/2。 所以left是(4+10+1)/2 = 7, right 是(4+10+2)/2 = 8。这样就可以return7 + 8 /2 
% 假如总长度是奇数 3+10 = 13，这里会计算两次。那么中位数是3+10/2 + 1 = 7 （第七个）， 所以left是(3+10+1)/2 = 7， right是(3+10+2)/2 = 7
&2. 注意永远让其中一个数组长度比较小。这里我们用的num1
&3. 注意如果数组空了，就找第二个数组的start+k-1个即可。
&4. 所有的操作都要用start和end找相对位置。因为我们用下标进行截取了。
&5. 取min是为了爬k/2比长度还小。
&6. 具体数学实现比较难算，背一下吧。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num1len = nums1.size();
        int num2len = nums2.size();
        int left = (num1len + num2len + 1)/2;
        int right = (num1len + num2len + 2)/2;
        
        int leftnum = getKthnum(nums1, 0, num1len - 1, nums2, 0, num2len - 1, left);
        int rightnum = getKthnum(nums1, 0, num1len - 1, nums2, 0, num2len - 1, right);
        
        return (leftnum + rightnum) * 0.5;

    }
    int getKthnum(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k){
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if(len1 > len2){
            return getKthnum(nums2, start2, end2, nums1, start1, end1, k);
            //这一步的目的是我们永远让nums1这个数组是短的。如果有数组空了一定是nums1
        }
        if(len1 == 0){
            return nums2[start2 + k - 1];
            //如果nums1空了，直接返回nums2数组里面第k大的数就可以了。我们的K是动态变化的。
        }
        if(k == 1){
            return min(nums1[start1], nums2[start2]);
            //如果找第一小的，直接在两个数组开头的位置找小的就可以
            //&注意一定要用start 因为我们会用下标进行截断。
        }
        int i = start1 + min(len1, k/2) - 1;
        int j = start2 + min(len2, k/2) - 1; //这里用min的意思是因为我们len是依照start和end变化的，为了防止k/2比长度还要大。
        if(nums1[i] > nums2[j]){
            return getKthnum(nums1, start1, end1, nums2, j + 1, end2, k-(j - start2 + 1)); //假如数组1的第K/2位比数组2的第K/2位大。
        }
        else{
            return getKthnum(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};