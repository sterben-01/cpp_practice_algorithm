#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

void test(int a, int b){
    cout << "普通函数" << endl;
}

template <typename T>
void test(T a, T b){
    cout << "模板函数" << endl;
}

template <typename T>
void test(T a, T b, T c){
    cout << "重载的模板函数" << endl;
}

template<>
void test(char a, char b){
    cout << "char 特化版本函数" << endl;
}






int main(){
    test(1,2); //输出普通函数
    test<>(1,2); //使用空模板参数列表 输出模板函数
    test(1,2,3); //输出重载的模板函数
    test('a', 'b'); //输出char 特化版本函数
}