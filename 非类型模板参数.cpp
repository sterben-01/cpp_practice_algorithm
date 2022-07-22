#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
/*
※ 固定类型是有局限的，只有整形，指针和引用才能作为非类型形参；
※ 而且绑定到该形参的实参必须是常量表达式，即编译期就能确认结果。
表达式参数有一些限制，可以为整型、枚举、引用或者指针。double m不合法，但是double* m和double& m合法。
②模板代码不能修改表达式的值，也不能使用使用参数的地址。
③实例化模板时，用作表达式参数的值必须是常量表达式。

非类型形参的局限：
1.浮点数不可以作为非类型形参，包括float，double。具体原因可能是历史因素，也许未来C++会支持浮点数；
2.类不可以作为非类型形参；
3.字符串不可以作为非类型形参；
4.整形，可转化为整形的类型都可以作为形参，比如int，char，long，unsigned，bool，short（enum声明的内部数据可以作为实参传递给int，但是一般不能当形参）；
5.指向对象或函数的指针与引用（左值引用）可以作为形参。

非类型实参的局限：
1.实参必须是编译时常量表达式，不能使用非const的局部变量，局部对象地址及动态对象；
2.非const的全局指针，全局对象/全局变量（下面可能有个特例）都不是常量表达式；
3.由于形参的已经做了限定，字符串，浮点型即使是常量表达式也不可以作为非类型实参 ；
4.非类型模板参数限制——不可以使用内部链接对象 ※
*/
template<int index, typename T1, typename T2> 
//这就是非类型模板参数。<>里面的是类型模板参数，但是int index这里不是类型模板参数而是一个值。这里的类型推导不是基于类型了而是基于值了所以叫非类型模板参数
//这里的int index 就是表示一个固定类型的常量而不是一个类型
//模板参数直到模板被实例化这些参数细节才真正被确定。
//当要使用基于值的模板时，你必须显式地指定这些值，模板方可被实例化。
void testing(T1 t1, T2 t2){
    t1 = index + t1 + t2;
    cout << t1 << endl;
}
template<typename T1, typename T2>
void testing2(int index, T1 t1, T2 t2){
    t1 = index + t1 + t2;
    cout << t1 << endl;
}
int main(){
    testing<5>(1,2);  //必须显式地指定index的值，模板方可被实例化。
    testing2(5,1,2);
}
