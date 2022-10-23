#ifndef __GROUP_H__
#define __GROUP_H__

#include "common.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Observer; //&注意这里我们使用了前向声明。所以我们这个文件没有include observer.h这个文件，因为我们只是在定义，并且只使用了指针或引用。并没有访问这个类的对象。
class Player;



class Group{ //抽象被观察者。在这里，整个小队就是一个被观察者，因为每个人和其他人都会有消息互动。
    public:
        Group(){
            cout << "小队初始化成功..." << endl;
        }
        virtual ~Group(){}

        virtual void notify(INFO_TYPE intoType, const string& name) = 0;

        void join(shared_ptr<Player> player); //被观察者要有能力管控观察者的加入和退出。这里就是增加观察者。

        void remove(shared_ptr<Player> player);
        void get_playerList();
    protected:
        //vector<shared_ptr<Player>> playerList;
        unordered_set<shared_ptr<Player>> playerList; //观察者的容器
};


class GroupController : public Group{ //具体被观察者。
    public:
        GroupController(){};
        void notify(INFO_TYPE infoType, const string& name); //具体被观察者需要在自身状态被改变的时候通知其他的观察者。
};
#endif