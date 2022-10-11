#include "observer.h"
#include "group.h"
using namespace std;
int main(){
    GroupController* controller = new GroupController(); //新建小队。这里就是被观察者。

    shared_ptr<Player> zzq = make_shared<Player>("zzq"); //新建玩家。玩家不仅是观察者，也是被观察者的一部分。
    shared_ptr<Player> lxy = make_shared<Player>("lxy");
    shared_ptr<Player> syh = make_shared<Player>("syh");
    shared_ptr<Player> fh = make_shared<Player>("fh");

    controller->join(zzq);
    controller->join(lxy); //玩家加入。也就是增加观察者。被观察者要能够控制观察者的加入和退出。
    controller->join(syh);
    controller->join(fh);

    controller->get_playerList();

    controller->remove(lxy);
    controller->get_playerList();

    zzq->call(RECOURCE, controller); //调用call方法的观察者此时的行为是被观察者。

    lxy->call(HELP, controller);

    delete controller;

    return 0;
}
