#include "group.h"
#include "observer.h" //这里我们使用了observer文件内也就是player类指针指向的对象，也就是有访问，那么就必须要包含observer这个文件了。


void Group::join(shared_ptr<Player> player){
    if(playerList.size() >= 4){
        cout <<"小队玩家已满，您无法加入该小队.." << endl;
        return;
    }

    cout << "玩家" << player->getName() << "已加入小队" << endl;
    playerList.insert(player);

    if(playerList.size() == 4){
        cout << "小队组建完毕，可以开始游戏。" << endl;
    }

}

void Group::remove(shared_ptr<Player> player){
    cout << "玩家" << player->getName() << "已退出小队" << endl;
    playerList.erase(player);
}

void Group::get_playerList(){
    for(auto& t:playerList){
        cout << t->getName() << endl;
    }
}


void GroupController::notify(INFO_TYPE infoType, const string& name){
    //通知其他观察者。
    switch (infoType)
    {
    case RECOURCE:
        for (const auto& ober: playerList){
            //在容器内遍历所有的观察者，调用观察者的行为。这里观察者的行为就是所谓的update。
            if(ober->getName() != name){ //自己不用通知自己了。
                ober->come();
            }
        }
        break; //不要忘记break
    case HELP:
        for(const shared_ptr<Player>& ober: playerList){
            if(ober->getName() != name){
                ober->help();
            }
        }
        break;

    default:
        cout << "Nothing" << endl;
        break;
    }
}