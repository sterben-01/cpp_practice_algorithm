#include <vector>
#include <iostream>
using  namespace std;
using  namespace std;



template<typename T, bool option>
class myclass; //主模板不实现

template<typename T>
class myclass<T, true>{ //偏特化1，注意语法。T在这里依旧要写上。
    public:
    void func(){
        cout <<"true one" << endl;
    }
};


template<typename T>
class myclass<T, false>{ //偏特化2，注意语法。T在这里依旧要写上。
    public:
    void func(){
        cout <<"false one" << endl;
    }
};

int main(){
    cout << 2%5<< endl;
    return 0;
}