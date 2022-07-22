#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
void Foreach(const vector<int>& values, const function<void(int)>& func){
    for(int value:values){
        func(value);
    }
}
int main(){
    // vector<int> test = {1,2,3,4,5,6,7};
    // int b = 5;
    // auto lambda = [=](int a){ cout << "hello"<< a << b << endl;};
    // Foreach(test, lambda);
    // int testing[5] = {1,2,3,4,5};
    // char rr[6] = "apple";
    // cout << *rr << endl;
    string test = "0123456789";
    string empty = "";
    const int start = 3;
    const int end = 6;
    int start_notconst = 3;
    int end_notconst = 6;
    // 如下两种方式。栈的必须要常量，编译时确定+const
    // new的可以随意 在堆上
    char c [end - start]; // 这样会死循环。char*数组的大小如果刚好等于string的index，string最后的\0会消失，编译时会一直等待结束但是没法结束。所以必须+1
    char ch[end - start + 1]; //正确方式
    char* d = new char[end_notconst - start_notconst + 1]; // new在堆上
    string substrng = test.substr(start,(end-start));
    strcpy(ch, substrng.c_str());
    // strcpy(d, substrng.c_str());
    int res1 = atoi(ch);
    cout << res1 << endl;
    delete [] d; // 记得delete
}