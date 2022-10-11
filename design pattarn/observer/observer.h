#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include<vector>
#include<string>
#include "common.h"
#include "group.h"
using namespace std;

//aqua - 这个文件是抽象观察者和具体观察者。抽象观察者是observer，具体观察者是player

class Observer{
    public:
        Observer(){}
        virtual ~Observer(){}
        virtual void call(INFO_TYPE infoType,  Group* player) = 0;
        string getName(){
            return m_name;
        }
        void setName(const string& name){
            m_name = name;
        }

    protected:
        string m_name;
};

//@ - 具体观察者实现了call方法。这个方法的作用是玩家可以主动调用来发出对应的消息。
//text - 这里的概念比较奇怪。每一个玩家不仅是一个观察者，也是被观察者的组成部分。被观察者就是整个小队。
class Player: public Observer{ //具体观察者
    public:
        Player(){
            setName("None");
        }
        Player(const string& name){
            setName(name);
        }
        void call(INFO_TYPE infoType, Group* player){
            switch (infoType)
            {
            case RECOURCE:
                cout <<getName() << ": 我这里有物资!" << endl;
                /* code */
                break;
            case HELP:
                cout<<getName() << ": 救救我!" << endl;
                break;

            default:
                cout <<"default message" << endl;
                break;
            }
            player->notify(infoType, getName()); //调用抽象被观察者的通知方法。用于进行广播通信，也就是通知其他的观察者。
            //这里举个例子：整个小队是被观察者。玩家是小队的组成部分。
            //aqua - 如果玩家想要通知其他玩家，那么此时当前调用这个call方法的玩家在其他玩家眼里就是被观察者。
            //那么这个被观察者会调用notify去通知观察者（也就是小队的其他玩家）。然后观察者会调用对应的update方法。这里就是help和come。
        }
        void help(){
            cout<<getName() << ": 坚持住, 我来救你了!!" << endl; //具体观察者的一些自我行为。也就是update
        }
        void come(){
            cout<<getName() << ": 这个AWM是我的, 我来了! 别和我抢!!" << endl; //具体观察者的一些自我行为。
        }
};
#endif