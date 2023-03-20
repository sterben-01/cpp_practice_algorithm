#include<iostream>
#include <utility>
#include <memory>
#include <type_traits>
#include <vector>
#include <functional>

using namespace std;

/*
在这个实例里，
手机是抽象类Abstraction，
具有玩游戏这样的实现类接口lmplementor，
不同的手机品牌扩充抽象类RefinedAbstraction，
多个不同的游戏则是具体实现类Concretelmplementor。

*/


//实现类接口，游戏类。
class Game{
    public:
        Game() = default;
        virtual ~Game() = default;
        virtual void gameStart() = 0;
};
//具体实现类
class GameA:public Game{
    public:
        GameA() = default;
        void gameStart(){
            cout << "game A" << endl;
        }
};
//具体实现类
class GameB:public Game{
    public:
        GameB() = default;
        void gameStart(){
            cout <<"game B" << endl;
        }
};

//抽象类
class Phone{
    public:
        Phone() = default;
        virtual void setupGame(Game* game){
            _game = game;
        }
        void setGame(Game* game){ //因为是private的对象，所以需要有对应的get和set。
            _game = game;
        }
        Game* getGame(){  
            return _game;
        }
        virtual void play() = 0;    //需要有玩游戏的虚函数
        virtual ~Phone() = default; 
    private:
        Game* _game; //注意，抽象类包含一个实现类的对象（指针）
};

//扩充抽象类
class PhoneA: public Phone{
    public:
        PhoneA() = default;
        void play(){
            cout << "phone A playing:";
            getGame()->gameStart(); //玩游戏，可以针对手机蕴含的游戏（多态对象）进行多态调用对应的游戏。
        }
};
//扩充抽象类
class PhoneB: public Phone{
    public:
        PhoneB() = default;
        void play(){
            cout << "phone B playing:";
            getGame()->gameStart();
        }
};

int main(){
    Phone* phoneA = new PhoneA();
    Phone* phoneB = new PhoneB();
    Game* gameA = new GameA();
    Game* gameB = new GameB();

    phoneA->setupGame(gameA); //AA组合
    phoneA->play(); //玩游戏
    
    phoneB->setupGame(gameA); //BA组合
    phoneB->play(); //玩游戏

    phoneA->setupGame(gameB);
    phoneA->play();
    
    phoneB->setupGame(gameB);
    phoneB->play();

    delete phoneA;
    delete phoneB;
    delete gameA;
    delete gameB;
    
}