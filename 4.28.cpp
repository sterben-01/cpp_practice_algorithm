#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

int main(){
    int a = 5;
    int* b = &a;
    int& c = a; //引用关系一旦确立，不可更改
    int aa = 10;
    c = aa; //这里的意思不是把c做为a的引用变成把c做为aa的引用。这里的意思是把aa的值赋值给c也就是赋值给a。这里不是更换引用对象
    aa = 20; //因为没有重新绑定引用，所以改变aa的值不会改变abc的值。
    cout << c << endl; //所以这里c = a = 10
    cout << a << endl; //所以这里c = a = 10
    cout << *b << endl; //所以这里c = a = *b = 10
}