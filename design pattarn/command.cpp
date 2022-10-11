#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

//CLASS - 接收者类 - 风扇
class Fan{
    public:
        Fan(){
            current_state = false;
        }
        void on(){
            if(current_state == true){
                cout<<"您不可以重复打开。"<< endl;
                return;
            }
            current_state = true;
            cout <<"已打开电风扇"  << endl;
        }
        void off(){
            if(current_state == false){
                cout <<"您不可以重复关闭" << endl;
                return;
            }
            current_state = false;
            cout <<"已关闭电风扇" <<endl;
        }
        bool getFanState(){
            return current_state;
        }

    private:
        bool current_state;
};

//CLASS - 接收者类 - 电灯
class Lamp{
    public:
        Lamp(){
            current_state = false;
        }
        void on(){
            if(current_state == true){
                cout<<"您不可以重复打开。"<< endl;
                return;
            }
            current_state = true;
            cout <<"已打开电灯"  << endl;
        }
        void off(){
            if(current_state == false){
                cout <<"您不可以重复关闭" << endl;
                return;
            }
            current_state = false;
            cout <<"已关闭电灯" <<endl;
        }
        bool getFanState(){
            return current_state;
        }

    private:
        bool current_state;
};


//CLASS - 抽象命令基类
class Command{
    public:
        Command(){}
        virtual ~Command(){}

        virtual void execute() = 0;
}; 

//CLASS - 具体命令类 - 风扇
class FanCommand: public Command{
    public:
        FanCommand(){
            cout <<"控制电风扇" << endl;
            fan = make_shared<Fan>(); //初始化具体接收者类
        }
        FanCommand(const FanCommand& ) = delete; //无拷贝构造
        FanCommand& operator= (const FanCommand& ) = delete; //无拷贝赋值

        ~FanCommand(){
            //使用了共享指针所以不需要手动释放资源。
        }
        
        void execute(){         //具体命令类风扇的执行操作。里面会包含具体的执行命令
        //执行风扇命令
            if(fan->getFanState() == true){
                fan->off();
            }
            else{
                fan->on();
            }
        }

    private:
        shared_ptr<Fan> fan;//具体命令类内含一个它对应的具体接收者对象的指针(引用)。

};

//CLASS - 具体命令类 - 电灯
class LampCommand: public Command{
    public:
        LampCommand(){
            cout <<"控制电灯" << endl;
            lamp = make_shared<Lamp>();//初始化具体接收者类
        }
        LampCommand(const LampCommand& ) = delete; //无拷贝构造
        LampCommand& operator= (const LampCommand& ) = delete; //无拷贝赋值

        ~LampCommand(){
            //使用了共享指针所以不需要手动释放资源。
        }
        
        void execute(){ //具体命令类电灯的执行操作。里面会包含具体的执行命令
        //执行电灯命令
            if(lamp->getFanState() == true){
                lamp->off();
            }
            else{
                lamp->on();
            }
        }

    private:
        shared_ptr<Lamp> lamp; //具体命令类内含一个它对应的具体接收者对象的指针(引用)。

};

//CLASS - 调用者类 - 按钮
class Button{
    public:
        Button(){}
        void setCommand(shared_ptr<Command> cmd){ //这个就是我们说的注入方法。我们把不同的具体命令对象和调用者类产生关联。
            command = cmd;
        }

        void touch(){ //调用者类中实现调用具体命令对象的execute方法。实现间接请求。
            cout <<"使用开关" << endl;
            command->execute();
        }

    private:
        shared_ptr<Command> command; //指向抽象命令基类的指针。
};

//CLASS - 客户类 - 此处为main函数
int main(){

    shared_ptr<Button> button= make_shared<Button>(); //调用者
    shared_ptr<Command> fanCmd = make_shared<FanCommand>(); //具体命令类
    shared_ptr<Command> lampCmd = make_shared<LampCommand>(); //具体命令类

    button->setCommand(fanCmd); //注入命令
    button->touch(); //执行
    button->touch();
    button->touch();


    button->setCommand(lampCmd);//注入命令
    button->touch();//执行
    button->touch();
    button->touch();



    return 0;
}