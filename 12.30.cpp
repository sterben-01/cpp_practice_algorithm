#include <utility>
#include <string>
#include <iostream>
#include <initializer_list>
#include <assert.h>
using namespace std;
// template<typename T>
// using EnableIfString =
// std::enable_if_t<std::is_convertible_v<T,std::string>>;

// class Person
// {
//     private:
//         string name;
//     public:
//     template <typename T, typename = EnableIfString<T>>
//     explicit Person(T&& n) : name(forward<T>(n)) {
//         cout << "万能引用+forward兼顾左值和右值。" << name << endl;
//     }
//     // copy and move constructor:
//     Person (Person const& p) : name(p.name) { //没有变化
//         cout << "此处是拷贝person对象进来 " << name << endl;
//     }
//     // Person (Person& p) : name(p.name) { //没有变化
//     //     cout << "此处是拷贝person对象进来, 非const的拷贝构造" << name << endl;
//     // }
//     Person (Person&& p) : name(move(p.name)) { //没有变化
//         cout << "此处是移动person对象进来 " << name << endl;
//     }
// };

// int main(){
//     string names = "miku";
//     Person p1(names); //拷贝字符串
//     // Person p2("miku");//"miku"是字面值，虽然字符串字面值是左值，但是现在它是个临时对象。所以会触发移动。这里是移动字符串。
//     Person p3(p1); //拷贝对象
//     // Person p4(move(p1));//移动对象。

//     // const Person cp1("miku");
//     // Person cp2(cp1);
// }
// struct A { };
// struct B : A { };


// class myobj{
//     public:
//     int val;
//     char single;
//     string name;
//     myobj(){}
//     myobj(int a):val(a){};
//     myobj(int a, char b, string c): val(a), single(b), name(move(c)){};

// };


// class myobj2{
//     public:
//         int val;
//         myobj2() = default;
//         explicit myobj2(int a):val(a){};
//         // operator int(){
//         //     return val;
//         // }

// };

// class myobj3{
//     public:
//         int val;
//         myobj3() = default;
//         myobj3(int a):val(a){};
// };

// int main() {
//     std::cout << std::boolalpha; /* 输出流将bool输出true/false, 而不是1/0 */
//     std::cout << "is_constructable:" << std::endl;
//     //   std::cout << "int => float: " << std::is_convertible<int,float>::value << std::endl;
//     //   std::cout << "int = >const int: " << std::is_convertible<int,const int>::value << std::endl;
//     //   std::cout << "A => B: " << std::is_convertible<A,B>::value << std::endl; /* A不能转换为B */
//     //   std::cout << "B => A: " << std::is_convertible<B,A>::value << std::endl; /* B能转换为A */
//     // cout << is_constructible<myobj, int>::value << endl;
//     // cout << is_constructible<myobj, int, char, string>::value << endl;
//     // cout << is_constructible<myobj, int, char, string&>::value << endl;
//     //cout << "myobj2 => int: " << is_convertible<myobj2, int>::value << endl;
//     cout << "int => myobj2: " << is_convertible<int, myobj2>::value << endl;
//     // cout << "A => B: " << is_constructible<myobj2, int>::value << endl;
//     // cout << "A => B: " << is_convertible<myobj2,int>::value << endl;
//     // myobj2 ttt(1023456);
//     // myobj3 another(ttt);
//     // cout << another.val << endl;
//     cout << "is_convertible:" << std::endl;
//     cout << "int => myobj2: " << is_constructible<myobj2,int>::value << endl;
//     return 0;
// }

// template<typename T>
// void func(T a){
//     cout << a << endl;
// }

// template
// void func<float>(float a); //2 显式实例化

class C{
    public:
        int val;
        C() = default;

        C(int a):val(a){};

        C(const volatile C&) = delete;

        template<typename T>
        C(const T&){ //这是构造函数模板不是拷贝构造函数模板。
            cout <<"template" << endl;
        }
};

class myobj{
    public: 
        myobj(int x):cal(x){
            cout <<"const" << endl;
        }
        int cal;
};
void func1(myobj& a){
        cout << "non const" << endl;
        }
void func1(volatile myobj&  a){
    cout <<"const" << endl;
}

void func(myobj a = 10){
    cout << "tutre" << endl;
}


int main(){
    func();
    // C obj1(10);
    // C obj2(obj1); //template
}