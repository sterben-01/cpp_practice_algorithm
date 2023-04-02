#include <iostream>
#include <string>
using namespace std;



struct Strategy{
    Strategy() = default;
    virtual ~Strategy(){}
    virtual void my_add(int a, int b) = 0;
};

struct normal_add : Strategy{
    normal_add() = default;

    void my_add(int a, int b){
        cout <<"normal add a + b = " << a + b << endl;
    }
};

struct ten_times_add:Strategy{
    ten_times_add() = default;

    void my_add(int a, int b){
        cout <<"ten_times_add add a + b = " << (a + b)*10 << endl;
    }
};

struct Context{
    int a;
    int b;
    Context() = default;
    Context(int x, int y):a(x), b(y){};
    void setStrategy(Strategy* ptr){
        my_strategy = ptr;
    }
    void my_add(){
        my_strategy->my_add(a, b);
    }
    void my_add(int x, int y){
        my_strategy->my_add(x, y);
    }
    Strategy* my_strategy = nullptr; //一般而言，上下文类含有一个策略类的指针。

};


int main(){
    Strategy* normal = new normal_add;
    Strategy* ten_times = new ten_times_add;

    Context obj(2,3);
    obj.setStrategy(normal);
    obj.my_add();

    obj.setStrategy(ten_times);
    obj.my_add();

    delete normal;
    delete ten_times;
}