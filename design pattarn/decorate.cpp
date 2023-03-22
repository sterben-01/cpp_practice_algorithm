#include <iostream>
#include <vector>
#include <memory>
#include <type_traits>
using namespace std;

// 抽象构件类
class Component{
public:
	Component(){}
	virtual ~Component(){}
	virtual void operation() = 0;
};

// 具体构件类
class Phone :public Component
{
public:
	Phone(){}
	void operation(){
		printf("手机\n");
	}
    void another_func(){
        cout << "another func" << endl;
    }
};

// 抽象装饰类
class Decorator : public Component
{
public:
	Decorator(){}
	Decorator(Component *c){ //接受一个抽象构建入参。
		this->component = c;
	}
	void operation(){
		this->component->operation();
	}
	Component *getComponent(){
		return this->component;
	}
	void setComponent(Component *c){
		this->component = c;
	}
private:
	Component* component; //抽象装饰类蕴含一个抽象构件对象
};

// 具体装饰类：手机壳
class DecoratorShell:public Decorator
{
public:
	DecoratorShell(){}
	DecoratorShell(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("安装手机壳\n");
	}
};
 
 
// 具体装饰类：手机贴纸
class DecoratorSticker :public Decorator
{
public:
	DecoratorSticker(){}
	DecoratorSticker(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("贴卡通贴纸ֽ\n");
	}
};
 
//  具体装饰类：挂绳
class DecoratorRope :public Decorator
{
public:
	DecoratorRope(){}
	DecoratorRope(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("系手机挂绳\n");
	}
};

int main()
{
    cout << "first phone" << endl;
	Component *Phone1 = new Phone();
	Component *PhoneShell = new DecoratorShell(Phone1);
	PhoneShell->operation();
 
    cout << "second phone" << endl;
	Component *Phone2 = new Phone();
	Component *PhoneShell2 = new DecoratorShell(Phone2);
	Component *PhoneSticker1 = new DecoratorSticker(PhoneShell2);
	PhoneSticker1->operation();
 
    cout << "third phone" << endl;
	Component *Phone3 = new Phone();
	Component *PhoneShell3 = new DecoratorShell(Phone3);
	Component *PhoneSticker2 = new DecoratorSticker(PhoneShell3);
	Component *PhoneRope = new DecoratorRope(PhoneSticker2);
	PhoneRope->operation();
	/*
	 此处有两个核心问题 decorator继承自component
	 这样做的两个好处是我们可以把装饰器类的指针当成component的指针。也就是把装饰器对象当做一个component对象去使用
	 第二点是，不继承的话不符合链式装饰语义。因为每一个具体装饰器类都是接受component来构造。
	 而链式装饰要求把每一个装饰过的装饰器指针当做component传入
	 如果不继承component的话，无法当做component传入。因为没有多态性。
	 比如115行的Decorator *PhoneRope = new DecoratorRope(PhoneSticker2);
	 这是一种递归的函数调用。
	 每次我们先getComponent，所以先拿到贴纸的装饰器对象，然后调用对应的函数调用运算符。
	 然后在里面继续拿，拿到了手机壳的装饰器对象，然后继续调用对应的函数调用运算符，直到拿到了component类对象，这时候不拿了，直接调用。然后再依次弹出
	*/
 
 
    delete Phone1;
    delete Phone2;
    delete Phone3;
    delete PhoneShell;
    delete PhoneShell2;
    delete PhoneShell3;
    delete PhoneSticker1;
    delete PhoneSticker2;
    delete PhoneRope;
	
	return 0;
}