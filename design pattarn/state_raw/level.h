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

        void setGameAccount(GameAccount*);
        GameAccount* getGameAccount();

    private:
        GameAccount* gameAccount; //&维护一个账户的指针用于获取账户的信息。

};


//CLASS - 具体状态类 - 第1级
class Level_1: public Level{
    public:
        Level_1();

        Level_1(Level*);
        Level_1(GameAccount*);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};

//CLASS - 具体状态类 - 第2级
class Level_2: public Level{
    public:
        Level_2();

        Level_2(Level*);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};

//CLASS - 具体状态类 - 第3级
class Level_3: public Level{
    public:
        Level_3();

        Level_3(Level*);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};

//CLASS - 具体状态类 - 第4级
class Level_4: public Level{
    public:
        Level_4();

        Level_4(Level*);

        void level_2_skill();
        void level_3_skill();
        void level_4_skill();

        void level_up();
};