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

//&工厂类
class Factory
{
public:
	AbstractSportProduct* getSportProduct(string productName)
	{
		AbstractSportProduct* item;
		if (productName == "Basketball"){
			item = new Basketball();
		}
		else if (productName == "Football"){
			item = new Football();
		}
		else if (productName == "Volleyball"){
			item = new Volleyball();
		}
		return item;
	}
};



int main(){
    Factory factory;
    AbstractSportProduct* item = factory.getSportProduct("Basketball");
    item->play();
}