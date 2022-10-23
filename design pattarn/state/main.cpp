#include"gameaccount.h"
#include"level.h"

int main(){
    shared_ptr<GameAccount> myaccount = make_shared<GameAccount>("miku");
    for(int i = 0; i < 5; i++){
        myaccount->playCard();
    }
}