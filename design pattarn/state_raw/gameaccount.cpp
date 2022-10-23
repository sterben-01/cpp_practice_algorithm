#include "gameaccount.h"
#include "level.h"
#define random(x) (rand()%x)
GameAccount::GameAccount(){
    level = nullptr;
    cout <<"角色创建完毕" << endl;
    score = 100;
    name = "None";
    setLevel(new Level_1(this));
}
GameAccount::GameAccount(const string& s){
    level = nullptr;
    cout <<"角色创建完毕" << endl;
    score = 100;
    name = s;
    setLevel(new Level_1(this)); //&设定一个初始的等级类。
}
GameAccount::~GameAccount(){
    if(level != nullptr){ //&析构函数释放资源。
        delete level;
        level = nullptr;
    }
}
void GameAccount::setLevel(Level* lv){
    if(level != nullptr){ //&每次给账户类绑定新的等级类的时候，要释放原来的等级类的资源。
        delete level;
        level = nullptr;
    }
    this->level = lv;
}

string GameAccount::getName(){
    return name;
}

void GameAccount::playCard(){ //&游玩。这里level由于会被设置为不同的子类，所以这里有天然的多态行为。
    level->playCard();
    int res = random(2);
    // if(res % 2 == 0){
    //     win();
    // }
    // else{
    //     lose();
    // }
    win();
    level->level_up();
}

void GameAccount::win(){
    this->setScore(getScore()+50);
    cout <<"胜利，积分+50" << endl;
}

void GameAccount::lose(){
    this->setScore(getScore()-50);
    cout <<"失败，积分-50" <<endl;
}

int GameAccount::getScore(){
    return score;
}
void GameAccount::setScore(int s){
    score = s;
}