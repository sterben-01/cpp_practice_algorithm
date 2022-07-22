#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class delelement{
public:
    void operator()(int* p){//你只能删掉指针。其实不能叫删掉指针 delete删掉的是指针指向的的值 也就是指针指向的内存空间。
        delete p; //delete 释放掉指针指向的值。也是释放掉指针指向的内存空间
        p = NULL;//将指针置空。
 
    }
};


class testing{
public:
    int _val;
    testing(): _val(0){}
    testing(int x): _val(x){}
    // testing& operator+(int a){
    //     this->_val = this->_val + a;
    //     return *this;
    // }

    void setpri(int x){
        this->pri = x;
    }
    const int& getpri() const{
        cout << this->pri << endl;
        return this->pri;
    }
    friend testing operator+(testing& s, const int& a);
    friend testing operator+(const int& a, testing& s); //+号都应该写const const引用可以传字面值。
    friend testing operator+(const testing& a, const testing& s);
    private:
        int pri;
};
testing operator+(testing& s, const int& a){
    return s._val + a;
}
testing operator+(const int& a, testing& s){
    return s+a;
}
testing operator+(const testing& a,const testing& s){ //这里函数返回值是个临时对象。而且是右值，所以重载参数得加const才能接受右值
    return a._val+s._val;
}

int main(){
    testing f = testing(5);
    f.setpri(5);
    f = f + 8;
    cout << "f:" << f._val << endl;
    testing g;
    g = f + 10 + f; //这种 f+10返回的是一个testing类对象 所以需要两个都是testing的重载了重载+的函数。50行。
    cout << "f:" << f._val << endl;
    cout << "g:" << g._val << endl;
}