#include "colleague.h"
#include "mediator.h"

//具体同事类 租客
Tenant::Tenant(){
	name = "none";
	setPersonType(DEFAULT);
}

Tenant::Tenant(string iName){
	name = iName;
	setPersonType(TENANT);
}

void Tenant::answer(){
	printf("租客姓名：%s\n", name.c_str());
}
void Tenant::ask(){
	printf("租客%s获取全部房东信息\n", name.c_str());
	(this->getMediator())->operation(this);
}
