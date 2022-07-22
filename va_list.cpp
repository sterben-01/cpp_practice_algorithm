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
#include <stdarg.h>
using namespace std;


void test(int a, ...){ //第一个参数表明后面一共有几个参数。
    va_list args; //定义一个可变参数列表
    va_start(args, a); //初始化可变参数列表
    for(; a > 0; a--){
        cout << va_arg(args, int) << endl; //使用va_arg访问下一个可变参数函数参数。第二个参数是传入参数类型
    }
    va_end(args); //释放args
}

void tt(int T){
    if(T){
        cout << "牛逼" << endl;
    }
    if(!T){
        cout << "不牛逼" << endl;
    }
    else{
        cout << "牛不牛逼" << endl;
    }
}




int main(){
    test(4,10,9,8,7);

    return 0;
    /*
    输出:
    10
    9
    8
    7
    */
}
/*
注意C语言里的printf就是这个效果。
C自带的printf函数是根据第一个参数format的占位符解析出后面的变参个数和类型，
通过va_arg迭代去获取变参再填充到占位符上输出。
*/