#include "level.h"

//CLASS - 抽象状态类。
Level::Level(){}

void Level::playCard(){ //&游玩。这里我们账户类内维护的等级类实例是不同的子类，所以不同的level调用这个函数的时候会有不同的行为。是天然多态。
    level_1_skill();
    level_2_skill();
    level_3_skill();
    level_4_skill();
}

void Level::level_1_skill(){
    cout <<"use level 1 skill" << endl; 
}

void Level::setGameAccount(GameAccount* ga){
    gameAccount = ga;
    cout <<"设置账户成功" << endl;
}

GameAccount* Level::getGameAccount(){
    return gameAccount;
}

//CLASS - 具体状态类 - 第1级

Level_1::Level_1(){}

Level_1::Level_1(Level* level){         //&最开始从1级开始，所以需要多一个构造函数。也就是给账户设定一个当前的1级的等级。
    //getGameAccount()->setLevel(level);
    this->setGameAccount(level->getGameAccount());
}
Level_1::Level_1(GameAccount* ga){ //&用于给等级类绑定账户类。
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

void Level_1::level_up(){ //检查升级。
    if(this->getGameAccount()->getScore() > 150){
        this->getGameAccount()->setLevel(new Level_2(this)); //&这里在等级类的构造函数内把新的等级类和账户类绑定，然后把当前帐户的等级类设置为新的等级类。
        cout <<"您已升级至Level2" <<endl;
    }
}


Level_2::Level_2(){}

Level_2::Level_2(Level* level){
    this->setGameAccount(level->getGameAccount()); //&给当前等级类绑定账户类。
    //getGameAccount()->setLevel(level);
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
        this->getGameAccount()->setLevel(new Level_1(this));
        cout <<"降级到1" <<endl;
    }
    else if(this->getGameAccount()->getScore() > 200){
        this->getGameAccount()->setLevel(new Level_3(this));
        cout <<"升级到3" <<endl;
    }
}



Level_3::Level_3(){}

Level_3::Level_3(Level* level){
    this->setGameAccount(level->getGameAccount());
    //getGameAccount()->setLevel(level);
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
        this->getGameAccount()->setLevel(new Level_2(this));
        cout <<"降级到2" <<endl;
    }
    else if(this->getGameAccount()->getScore() > 250){
        this->getGameAccount()->setLevel(new Level_4(this));
        cout <<"升级到4" <<endl;
    }
}


Level_4::Level_4(){}

Level_4::Level_4(Level* level){
    this->setGameAccount(level->getGameAccount());
    //getGameAccount()->setLevel(level);
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
        this->getGameAccount()->setLevel(new Level_3(this));
        cout <<"降级到3" <<endl;
    }
}