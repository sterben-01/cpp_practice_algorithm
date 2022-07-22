#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
   
int a = 1;
int &b = a; // 正确 左值引用
int &b = 1; // 错误 右值引用了
int &&b = 1; // 正确 正确的右值引用
int &&b = a; //错误 右值引用只能引用右值
int &&b = move(a); //正确 move（移动语义）可以将左值转换为右值然后进行右值引用。
int &&b = (int&&)a; // 正确 强制将左值a转换为右值(临时变量)形式并引用。
string an = "abcde";
if(an[3] == "d"){ // 错误。字符串比较只能通过compare比较。==比较是比较地址
    cout << 0 << endl;
}
int a = an.find("d"); //用find找到下标
cout << a << endl;
an[3] = "t"; // 错误。string是一种const chat*数组。你没办法在一个char位置塞一个string。
an[3] = 't'; // 正确。替换，注意这里要用char
cout << an << endl;


int &&a = 1; // 这叫右值引用

void test(int && a){} //这也叫右值引用

auto &&b = 1; // 这不叫右值引用，这叫万能引用。因为是auto关键词修饰。所有的auto&&都是万能引用，因为总是有参数的推导过程

template<typename t>
void func(vector<t>&& param){}// 这是右值引用。虽然有推导过程，但是这里模板只推导t的类型。但实际上param的类型一直都是vector<t>&&

template<typename n>
void func(n&& param){} // 这不是右值引用，这是万能引用。因为整个param的类型都需要被推导。