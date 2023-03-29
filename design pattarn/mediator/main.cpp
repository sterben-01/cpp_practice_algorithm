#include "mediator.h"
#include "colleague.h"

int main()
{
	// 创建中介者 
	Agency* mediator = new Agency();

	// 创建3位房东（同事类A）
	Landlord* fangdong1 = new Landlord("刘备", 1350, "成都市双流区", "1351025");
	Landlord* fangdong2 = new Landlord("关羽", 1500, "成都市武侯区", "1378390");
	Landlord* fangdong3 = new Landlord("张飞", 1000, "成都市龙泉驿", "1881166");

	//房东选择特定的中介者。
	fangdong1->setMediator(mediator);
	fangdong2->setMediator(mediator);
	fangdong3->setMediator(mediator);
	// 房东通过中介者登记
	mediator->registerColleague(fangdong1);
	mediator->registerColleague(fangdong2);
	mediator->registerColleague(fangdong3);

	// 创建两位租客（同事类B）
	Tenant* jungle = new Tenant("miku");
	Tenant* jianmengtu = new Tenant("luka");

	//租客选择特定的中介者。
	jungle->setMediator(mediator);
	jianmengtu->setMediator(mediator);
	// 租客通过中介者登记
	mediator->registerColleague(jungle);
	mediator->registerColleague(jianmengtu);


	//具体业务逻辑。同事类A和同事类B
	jungle->ask();
	fangdong1->ask();


	delete mediator;
	delete fangdong1;
	delete fangdong2;
	delete fangdong3;
	delete jungle;
	delete jianmengtu;
	mediator   = nullptr;
	fangdong1  = nullptr;
	fangdong2  = nullptr;
	fangdong3  = nullptr;
	jungle     = nullptr;
	jianmengtu = nullptr;

	return 0;
}