#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <unordered_map>
using namespace std;

class myclass{
    public:
        void print(){
            cout <<"myclass" << endl;
        }

        int vala = 10;//类成员没有被print函数访问。

};


class myobj{
    public:
        myobj(){}
        myobj(int a, int b){
            cout <<"two" << endl;
        }
};

template<typename T1, typename T2>
void func(T1 a, T2 b){
    cout << a << b << endl;
}

int main(){
    func<string, int>("abc",3);
    return 0;
}