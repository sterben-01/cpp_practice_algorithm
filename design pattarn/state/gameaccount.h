#ifndef __GAMEACCOUNT_H__
#define __GAMEACCOUNT_H__

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Level; //前向声明 抽象状态类。



//CLASS - 上下文类。拥有多种状态的对象。
class GameAccount{
    public:
        GameAccount();
        GameAccount(string& s);

        GameAccount(const GameAccount&) = delete;
        GameAccount& operator=(const GameAccount&) = delete;
        ~GameAccount(){}

        string getName();
        void win();
        void lose();
        void playCard();
        void setLevel(shared_ptr<Level>);
        int getScore();
        void setScore(int);


    private:
        string name;
        shared_ptr<Level> level; //内部维护一个抽象状态类指针。
        int score;

};


#endif