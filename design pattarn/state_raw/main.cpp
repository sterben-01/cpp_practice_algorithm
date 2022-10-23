#include"gameaccount.h"
#include"level.h"

int main(){
    GameAccount* myaccount = new GameAccount("miku"); //创建账户
    for(int i = 0; i < 5; i++){
        myaccount->playCard(); //玩游戏。
    }

    delete myaccount;
    myaccount = nullptr;
    return 0;
}