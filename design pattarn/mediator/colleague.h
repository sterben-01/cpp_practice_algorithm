#ifndef __COLLEAGUE_H__
#define __COLLEAGUE_H__

#include "common.h"
using namespace std;

/*
这个头文件是所有同事类的头文件。包括抽象和具体。
*/

// 前向声明
class Mediator;

// 抽象同事类
class Colleague
{
public:
	Colleague(){}
	virtual ~Colleague(){}
	void setMediator(Mediator* iMediator){ // 对特定的同事注册中介者。
		this->mediator = iMediator;
	}
	Mediator* getMediator(){ //获取中介者
		return this->mediator;
	}
	void setPersonType(PERSON_TYPE iPersonType){ //设置人员身份
		this->personType = iPersonType;
	}
	PERSON_TYPE getPersonType(){ //获取人员身份
		return this->personType;
	}
	virtual void ask() = 0; //具体业务接口
	virtual void answer() = 0;
private:
	PERSON_TYPE personType;
	Mediator* mediator; // 同事类也需要维护一个中介者类的指针
};

// 具体同事类：房东
class Landlord :public Colleague
{
public:
	Landlord();
	Landlord(string iName, int iPrice, string iAddress, string iPhoneNum);
	void ask();
	void answer();
private:
	string name;
	int price;
	string address;
	string phoneNumber;
};

// 具体同事类：租客
class Tenant :public Colleague
{
public:
	Tenant();
	Tenant(string name);
	void ask();
	void answer();
private:
	string name;
};

#endif //__COLLEAGUE_H__
