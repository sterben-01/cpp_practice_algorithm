#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
using namespace std;


int main() {
    int a[] = { 1,2 };
    int* ptr = a;
    cout << *(long long*)(a) << endl;
/*
    这里输出结果为8589934593
    为什么呢？
    首先我们用longlong也就是8字节去读。所以会读到两个数。一个int是4字节
    int a[]内存长这样：01 00 00 00 02 00 00 00
    如果按照大端序去读就是0100000002000000
    但是我们计算机是小端序，所以要倒过来。
    所以就是0000000200000001
    这是个16进制，转换过来就是8589934593

    !注意。unsigned char可以表示0-255。所以我们可以说在数字小于255的时候，unsigned char数组和int数组是一样的。
    虽然int确实是4字节，char是1字节。但是1字节的int可以表示最大255 也就是0xff。
    !类型可以这么去想。255用int可以正确描述，用unsigned char也可以正确描述。但是255555555555555555555用int就无法正确描述。因为超出了表示范围。
*/
    return 0;

}