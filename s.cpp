#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <memory>
#include <functional>
using namespace std;


enum INFO_TYPE{
    NONE,
    RECOURCE,
    HELP
};

class Observer;
class Player;

class Group{
    public:
        Group(){
            cout << "小队初始化成功..." << endl;
        }
        virtual ~Group(){}

        virtual void notify(INFO_TYPE intoType, const string& name) = 0;

        void join(shared_ptr<Player>& player){
            if(playerList.size() >= 4){
                cout <<"小队玩家已满，您无法加入该小队.." << endl;
                return;
            }

            cout << "玩家" << player->getName() << "已加入小队" << endl;
            playerList.push_back(player);

            if(playerList.size() == 4){
                cout << "小队组建完毕，可以开始游戏。" << endl;
            }

        }

        void remove(shared_ptr<Player>& player){
            cout << "玩家" << player->getName() << "已退出小队" << endl;
        }
        void get_playerList(){
            for(auto& t:playerList){
                cout << t->getName() << endl;
            }
        }
    protected:
        vector<shared_ptr<Player>> playerList;
};


class GroupController : public Group{
    public:
        GroupController(){};
        void notify(INFO_TYPE infoType, const string& name){
            switch (infoType)
            {
            case RECOURCE:
                for (shared_ptr<Player>& ober: playerList){
                    if(ober->getName() != name){
                        ober->come();
                    }
                }
                /* code */
                break;
            case HELP:
                for(shared_ptr<Player>& ober: playerList){
                    if(ober->getName() != name){
                        ober->help();
                    }
                }

            default:
                cout << "Nothing" << endl;
                break;
            }
        }
};



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

class Player: public Observer{
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

            default:
                cout <<"default message" << endl;
                break;
            }
            player->notify(infoType, getName());
        }
        void help(){
            cout<<getName() << ": 坚持住, 我来救你了!!" << endl;
        }
        void come(){
            cout<<getName() << ": 这个AWM是我的, 我来了! 别和我抢!!" << endl;
        }
};


int main(){

    GroupController* controller = new GroupController();

    shared_ptr<Player> zzq = make_shared<Player>("zzq");
    shared_ptr<Player> lxy = make_shared<Player>("lxy");
    shared_ptr<Player> syh = make_shared<Player>("syh");
    shared_ptr<Player> fh = make_shared<Player>("fh");

    controller->join(zzq);
    controller->join(lxy);
    controller->join(syh);
    controller->join(fh);

    controller->get_playerList();

    zzq->call(RECOURCE, controller);

    lxy->call(HELP, controller);



    return 0;
}
