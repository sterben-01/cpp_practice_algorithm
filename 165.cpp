#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

/*
@比较版本号。
*这题有意思的是忽略0。也就是1.01和1.1是一样的。所以这一点比较反直觉，也需要注意一下以后的题在这一点是不是有区别
我们采用双指针分段比较 + 转换成数字的方式
首先我们假设1.05.6 和1.06.7两个数字
我们先按照.进行分割
&第一层while是判断是否到了末尾
&里面的第一个while是判断第一个版本号是否到了每一个按照.分割的末尾了。如果到了就转换成数字。
%乘10是为了进位。然后用字符形式的数字ASCII码减掉0的ASCII码就得到了相对数字
todo 这里忽略0的原因是0的ascii减掉0的ascii是0，加入累积的数字大小不会改变。因为是+0。
!不要忘了指针移动-即 ++ 
&里面的第一个while是判断第二个版本号是否到了每一个按照.分割的末尾了。如果到了就转换成数字。
%乘10是为了进位。然后用字符形式的数字ASCII码减掉0的ASCII码就得到了相对数字
!不要忘了指针移动-即 ++ 
&然后我们就可以按照每一段来比较大小。
!记得最外层while也要移动指针 即 ++
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1ptr = 0;
        int ver2ptr = 0;
        while (ver1ptr < version1.length() || ver2ptr < version2.length()){
            long long ver1 = 0;
            long long ver2 = 0;
            while(ver1ptr < version1.length() && version1[ver1ptr] !='.'){
                ver1 = ver1*10 + version1[ver1ptr] - '0'; //计算每个区间的数字
                ver1ptr++; //移动指针
            }
            while(ver2ptr < version2.length() && version2[ver2ptr] != '.'){
                ver2 = ver2*10 + version2[ver2ptr] - '0';//计算每个区间的数字
                ver2ptr++;//移动指针
            }
            if(ver1 < ver2){
                return -1;
            }
            else if(ver1 > ver2){
                return 1;
            }
            ver1ptr++;//移动指针
            ver2ptr++;//移动指针
        }
        return 0;
    }
};

int main(){
    Solution sol;
    bool ace = true;
    cout << ace << endl;
    cout << sol.compareVersion("20.9.1", "3.11.0")<< endl;
    return 0;
}