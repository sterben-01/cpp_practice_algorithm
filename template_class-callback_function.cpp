#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <cstring>
#include <functional>
#include <memory>
using namespace std;
template<typename T1>
class a{
    public:
        T1 _x;
        T1 _y;
        vector<int> temp;
        a(){};
        a(T1 x, T1 y){
            _x = x;
            _y = y;
            cout << "normalinit"  << endl;
        }
    
        a(initializer_list<T1> initlist){
            for(auto i : initlist){
                temp.push_back(i);
            }
            cout << "initlist" << endl;
        }
        void sss(){
            if(temp.size() == 0){
                cout << "bypassed"<< endl;
            }
            for(auto i : temp){
                cout << i;
            }
            cout << endl;
            
        }



};

int main(){
    a<int>* ptr = new a<int>({1,2,3,4}); //方法一 普通指针
    std::function<void(void)> callback = std::bind(&a<int>::sss, ptr);
    callback();
    /*
    bind绑定类成员函数时，第一个参数表示对象的成员函数的指针，第二个参数表示对象的地址，这是因为对象的成员函数需要有this指针。
    并且编译器不会将对象的成员函数隐式转换成函数指针，需要通过&手动转换；
    std::bind的返回值是可调用实体，可以直接赋给std::function。
    */

    std::shared_ptr<a<int>> ptr2 = std::make_unique<a<int>>(1,2); //方法二 智能指针
    //std::shared_ptr<a<int>> ptr2 = std::make_unique<a<int>>({1,2,3,4});//!语法错误。make_都不支持添加删除器，或者初始化列表。
    std::function<void(void)> callback2 = std::bind(&a<int>::sss, ptr2);
    callback2(); //这里不会输出初始化列表构造函数和vector的东西。因为make_方法不支持初始化列表

}
/*
TODO相关资料
https://blog.csdn.net/qq_38410730/article/details/103637778
https://blog.csdn.net/wangshubo1989/article/details/49134235
https://www.jianshu.com/p/c4c84b073413
*/