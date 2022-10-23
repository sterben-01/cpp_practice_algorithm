#include "gameaccount.h"
#include "level.h"
#define random(x) (rand()%x)
GameAccount::GameAccount(){
    level = nullptr;
    cout <<"角色创建完毕" << endl;
    score = 100;
    name = "None";
    setLevel(make_shared<Level_1>(this));
}
GameAccount::GameAccount(string& s){
    level = nullptr;
    cout <<"角色创建完毕" << endl;
    score = 100;
    name = s;
    setLevel(make_shared<Level_1>(this));
}

void GameAccount::setLevel(shared_ptr<Level> lv){
    level = lv;
}

string GameAccount::getName(){
    return name;
}

void GameAccount::playCard(){
    level->playCard();
    if(random(2) % 2 == 0){
        win();
    }
    else{
        lose();
    }
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