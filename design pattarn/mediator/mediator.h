#ifndef __MEDIATOR_PATTERN_H__
#define __MEDIATOR_PATTERN_H__

#include "common.h"
#include "colleague.h"


/*
这个头文件是所有中介类的头文件。包括抽象和具体。
*/

// 抽象中介者
class Mediator{
public:
	Mediator() = default;
	virtual ~Mediator(){}
	// 声明注册方法
	virtual void registerColleague(Colleague*) = 0;
	// 声明抽象业务方法
	virtual void operation(Colleague*) = 0;
};

// 具体中介者
class Agency:public Mediator{
public:
	Agency() = default;
	void registerColleague(Colleague* person){ //实现注册方法
		switch (person->getPersonType()){
			case LANDLORD:
				landlordList.push_back(person);
				break;
			case TENANT:
				tenantList.push_back(person);
				break;
			default:
				cout << "wrong person" << endl;
		}
	}
	void operation(Colleague* person){ //实现具体业务方法。
	/*
		这里我们的业务就是简单的，获取所有租客或房东的信息。
	*/
		switch (person->getPersonType()){
			case LANDLORD:
				for (int i = 0; i < tenantList.size(); i++){
					tenantList[i]->answer();
				}
				break;
			case TENANT:
				for (int i = 0; i < landlordList.size(); i++){
					landlordList[i]->answer();
				}
				break;
			default:
				break;
			}
	}
private:
	//因为中介者通常维护一群同事类的对象。所以一般情况下需要有容器来存储同事类的对象。
	vector<Colleague*> landlordList; //包含同事类指针的容器
	vector<Colleague*> tenantList;
};


#endif //__MEDIATOR_PATTERN_H__