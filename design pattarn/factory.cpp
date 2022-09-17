#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

//& 抽象产品类
class AbstractSportProduct
{
public:
	AbstractSportProduct(){
 
	}
	virtual ~AbstractSportProduct(){};
	//抽象方法：
	// virtual void printName(){};
	virtual void printName() = 0;
	// virtual void play(){};
	virtual void play() = 0;
};

//&具体产品类Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
		printName();
		play();
	}
	~Basketball()
	{
 
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Basketball\n");
	}
	void play(){
		printf("Jungle play Basketball\n");
	}
};
 
//&/具体产品类Football
class Football :public AbstractSportProduct
{
public:
	Football(){
		printName();
		play();
	}
	~Football()
	{
 
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Football\n");
	}
	void play(){
		printf("Jungle play Football\n");
	}
};
 
//&具体产品类Volleyball
class Volleyball :public AbstractSportProduct
{
public:
	Volleyball(){
		printName();
		play();
	}
	~Volleyball()
	{
		
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Volleyball\n");
	}
	void play(){
		printf("Jungle play Volleyball\n");
	}
};

//&抽象工厂类
class AbstractFactory{
    public:
        virtual ~AbstractFactory(){}
        virtual AbstractSportProduct* getSportProduct() = 0;
};
//&具体工厂类BasketballFactory
class BasketballFactory :public AbstractFactory
{
public:
	BasketballFactory(){
		printf("BasketballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		printf("basketball");
		return new Basketball();
	}
};
 
//& 具体工厂类FootballFactory
class FootballFactory :public AbstractFactory
{
public:
	FootballFactory(){
		printf("FootballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
        printf("football");
		return new Football();
	}
};
 
//& 具体工厂类VolleyballFactory
class VolleyballFactory :public AbstractFactory
{
public:
	VolleyballFactory(){
		printf("VolleyballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
        printf("volleyball");
		return new Volleyball();
	}
};

int main(){

    AbstractFactory* Basketballfac = new BasketballFactory(); //抽象工厂类指针指向具体工厂类对象。
    AbstractSportProduct* Basketball = Basketballfac->getSportProduct(); //通过抽象工厂类指针调用具体工厂类的生产方法返回一个指向具体产品类的抽象产品类指针。

    Basketball->play();



    return 0;
}