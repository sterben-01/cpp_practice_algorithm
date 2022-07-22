#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

/*
构造函数默认值可以是：
都设置默认值 如  test1(int x = 5, int y = 6, int z = 7):a(x), b(y), c(z){}
都不设置默认值 如  test1(int x, int y, int):a(x), b(y), c(z){}
部分设置默认值
!注意。部分设置默认值必须是在某一个参数前都不设置默认值，参数后都设置默认值
TODO: test1(int x, int y = 6, int z = 7):a(x), b(y), c(z){} 这样可以
TODO: test1(int x = 5, int y, int z = 7):a(x), b(y), c(z){} 这样不可以

*/
class test1{
    public:
    int a;
    int b;
    int c;
    //test1(int x = 5, int y = 6, int z = 7):a(x), b(y), c(z){} 可以 都设置
    //test1(int x, int y, int):a(x), b(y), c(z){} 可以 都不设置
    //test1(int x = 5, int y, int z = 7):a(x), b(y), c(z){} 不可以 顺序错误
    test1(int x, int y = 6, int z = 7):a(x), b(y), c(z){} //可以 部分设置

    void output()
    {
        cout << a << b << c << endl;
    }
};
class Complex{
    public:
    int _real;
    int _imag;
    Complex(int real = 0, int imag = 0):_real(real), _imag(imag){}
    Complex operator+ (const Complex& x){
        return Complex((_real + x._real), (_imag + x._imag));
    }
    void output(){
        cout << _real<< "," << _imag << endl;
    }
};

class Complex2{
    public:
    int _real;
    int _imag;
    explicit Complex2(int real = 0, int imag = 0):_real(real), _imag(imag){}
    Complex2 operator+ (const Complex2& x){
        return Complex2((_real + x._real), (_imag + x._imag));
    }
    void output(){
        cout << _real<< "," << _imag << endl;
    }
};


void callback(int* (*func)(int&, int&), int& a, int& b){
    func(a,b);
    cout << a << "," << b << endl;
}

int* testa(int& a, int& b){
    a = a + b;
    return &a;
}


int main(){
    Complex c1(12,5);
    Complex c2 = c1 + 5;
    // c1.output();
    // c2.output();
    int a = 2;
    int b = 4;
    //testa(a,b);
    callback(testa, a, b);
    cout << a << ",.," << b << endl;

/*
在这里我们发现Complex的构造函数是有默认值的。也就是说如果我有一个 //@ 12
构造函数会自动帮我转换成//@ Complex(12,0) 这样的格式。也就是可以调用+运算符重载
如果构造函数加了explicit关键字，这就表示禁止构造函数进行隐式转换
我们看Complex2的构造函数虽然也有默认值，但是我如果不显式调用构造函数的话类型就无法转换。
*/
    Complex2 d1(12);
    Complex2 d2 = d1 + Complex2(5); //使用匿名对象 显式调用构造函数。可以通过构造函数和其默认值转换成(5,0)
    //Complex2 d3 = d1 + 5; //explicit禁用了隐式转换，所以无法使用+运算符重载。
    //Complex2 d3 = d1 + dynamic_cast<Complex2>(5);  不能这么写 dynamic cast 尽可以子类转父类。
    // d1.output();
    // d2.output();

}