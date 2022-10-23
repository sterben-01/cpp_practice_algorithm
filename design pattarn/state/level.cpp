#include "level.h"

//CLASS - 抽象状态类。
Level::Level(){}

void Level::playCard(){
    level_1_skill();
    level_2_skill();
    level_3_skill();
    level_4_skill();
}

void Level::level_1_skill(){
    cout <<"use level 1 skill" << endl; 
}

void Level::setGameAccount(shared_ptr<GameAccount> ga){
    gameAccount = ga;
    cout <<"设置账户成功" << endl;
}

shared_ptr<GameAccount> Level::getGameAccount(){
    return gameAccount;
}

//CLASS - 具体状态类 - 第1级

Level_1::Level_1(){}

Level_1::Level_1(shared_ptr<Level> level){
    getGameAccount()->setLevel(level);
}
Level_1::Level_1(shared_ptr<GameAccount> ga){
    this->setGameAccount(ga);
}

void Level_1::level_2_skill(){
    return;
}
void Level_1::level_3_skill(){
    return;
}
void Level_1::level_4_skill(){
    return;
}

void Level_1::level_up(){
    if(this->getGameAccount()->getScore() > 150){
        this->getGameAccount()->setLevel(make_shared<Level_2>(this));
        cout <<"您已升级至Level2" <<endl;
    }
}


Level_2::Level_2(){}

Level_2::Level_2(shared_ptr<Level> level){
    this->setGameAccount(level->getGameAccount());
    getGameAccount()->setLevel(level);
}

void Level_2::level_2_skill(){
    cout <<"use level 2 skill" << endl;
}

void Level_2::level_3_skill(){
    return;
}

void Level_2::level_4_skill(){
    return;
}

void Level_2::level_up(){
    if(this->getGameAccount()->getScore() < 150){
        this->getGameAccount()->setLevel(make_shared<Level_1>(this));
        cout <<"降级到1" <<endl;
    }
    else if(this->getGameAccount()->getScore() > 200){
        this->getGameAccount()->setLevel(make_shared<Level_3>(this));
        cout <<"升级到3" <<endl;
    }
}



Level_3::Level_3(){}

Level_3::Level_3(shared_ptr<Level> level){
    this->setGameAccount(level->getGameAccount());
    getGameAccount()->setLevel(level);
}

void Level_3::level_2_skill(){
    cout <<"use level 2 skill" << endl;
}

void Level_3::level_3_skill(){
    cout <<"use level 3 skill" << endl;

}
void Level_3::level_4_skill(){
    return;
}

void Level_3::level_up(){
    if(this->getGameAccount()->getScore() < 200){
        this->getGameAccount()->setLevel(make_shared<Level_2>(this));
        cout <<"降级到2" <<endl;
    }
    else if(this->getGameAccount()->getScore() > 250){
        this->getGameAccount()->setLevel(make_shared<Level_4>(this));
        cout <<"升级到4" <<endl;
    }
}


Level_4::Level_4(){}

Level_4::Level_4(shared_ptr<Level> level){
    this->setGameAccount(level->getGameAccount());
    getGameAccount()->setLevel(level);
}

void Level_4::level_2_skill(){
    cout <<"use level 2 skill" << endl;
}

void Level_4::level_3_skill(){
    cout <<"use level 3 skill" << endl;

}
void Level_4::level_4_skill(){
    cout <<"use level 4 skill" << endl;
}

void Level_4::level_up(){
    if(this->getGameAccount()->getScore() < 250){
        this->getGameAccount()->setLevel(make_shared<Level_3>(this));
        cout <<"降级到3" <<endl;
    }
}