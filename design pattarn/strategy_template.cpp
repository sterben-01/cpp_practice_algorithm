#include <iostream>
#include <string>
using namespace std;


struct normal_add_Strategy{
    static void my_add(int a, int b){
        cout <<"normal add a + b = " << a + b << endl;
    }
};

struct ten_times_add_Strategy{
    static void my_add(int a, int b){
        cout <<"ten_times_add add a + b = " << (a + b)*10 << endl;
    }
};
template<typename Policy = normal_add_Strategy>
struct Context{
    int a;
    int b;
    Context() = default;
    Context(int x, int y):a(x), b(y){};
    void my_add(){
        Policy::my_add(a, b);
    }
    void my_add(int x, int y){
        Policy::my_add(x, y);
    }
};


int main(){

    Context<normal_add_Strategy> normal_obj(2,3);
    normal_obj.my_add();
    Context<ten_times_add_Strategy> ten_obj(2,3);
    ten_obj.my_add();
}