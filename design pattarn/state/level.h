#include "gameaccount.h"



//CLASS - 抽象状态类。
class Level{
    public:
        Level();
        virtual ~Level(){}

        void playCard();

        void level_1_skill();
        virtual void level_2_skill() = 0;
        virtual void level_3_skill() = 0;
        virtual void level_4_skill() = 0;

        virtual void level_up() = 0;

        void setGameAccount(shared_ptr<GameAccount>);
        shared_ptr<GameAccount> getGameAccount();

    private:
        shared_ptr<GameAccount> gameAccount;

};


//CLASS - 具体状态类 - 第1级
class Level_1: public Level{
    public:
        Level_1();

        Level_1(shared_ptr<Level>);
        Level_1(shared_ptr<GameAccount>);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};

//CLASS - 具体状态类 - 第2级
class Level_2: public Level{
    public:
        Level_2();

        Level_2(shared_ptr<Level>);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};

//CLASS - 具体状态类 - 第3级
class Level_3: public Level{
    public:
        Level_3();

        Level_3(shared_ptr<Level>);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};

//CLASS - 具体状态类 - 第4级
class Level_4: public Level{
    public:
        Level_4();

        Level_4(shared_ptr<Level>);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};