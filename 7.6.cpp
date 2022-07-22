
#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <stdarg.h>
using namespace std;

//& 装饰器模式

class Pancake//基类
{
public:
    string description = "Basic Pancake";
    virtual string getDescription(){ return description; }
    virtual double cost() = 0;
};

class CondimentDecorator: public Pancake//装饰器基类
{
public:
    Pancake* basepancake;
    string getDescrition();
};

class MeatPancake :public Pancake//肉煎饼
{
public:
    MeatPancake(){ description = "MeatPancake"; }
    double cost(){ return 6; }
};
class EggPancake :public Pancake//鸡蛋煎饼
{
public:
    EggPancake(){ description = "EggPancake"; }
    double cost(){ return 5; }
};

class Egg :public CondimentDecorator//额外加鸡蛋
{
public:
    Egg(Pancake* d){

        basepancake = d; 
    }
    string getDescription(){ 

        return basepancake->getDescription() + ", Egg"; 
    }
    double cost(){
        return basepancake->cost() + 1.5; 
    }
};
class Potato :public CondimentDecorator//额外加土豆
{
public:
    Potato(Pancake* d){ 

        basepancake = d; 

    }

    string getDescription(){ 

        return basepancake->getDescription() + ", Potato"; 
        
    }
    double cost(){ 
        return basepancake->cost() + 1; 
    }
};
class Bacon :public CondimentDecorator//额外加培根
{
public:
    Bacon(Pancake* d){ 
        basepancake = d; 
    }
    string getDescription(){ 
        return basepancake->getDescription() + ", Bacon"; 
    }
    double cost(){ 
        return basepancake->cost() + 2; 
    }
};


int main()
{
    Pancake* pan = new EggPancake();
    cout << pan->getDescription() << "  $ : " << pan->cost() << endl;
    pan = new Bacon(pan); //不够吃 加培根
    cout << pan->getDescription() << "  $ : " << pan->cost() << endl;
    pan = new Potato(pan); //还不够吃，加土豆
    cout << pan->getDescription() << "  $ : " << pan->cost() << endl;
    system("pause");
    return 0;
}