#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <type_traits>
using namespace std;


// 抽象主题角色
class Subject{
public:
	Subject(){}
    virtual ~Subject(){}
	virtual void request() = 0;
};

// 真实主题角色
class RealSubject :public Subject{
public:
	RealSubject(){}
	void request(){
		cout <<"调用业务方法" <<endl;
	}
};

// Log类
class Log{
    public:
        Log(){}
        string getTime(){
            time_t t = time(NULL);
            char ch[64] = { 0 };
            //年-月-日 时:分:秒
            strftime(ch, sizeof(ch)-1, "%Y-%m-%d %H:%M:%S", localtime(&t));     
            return ch;
        }
};
 
// 代理类
class Proxy:public Subject{
public:
	Proxy(){
		realSubject = new RealSubject();
		log = new Log();
	}
	Proxy(const Proxy& o) = delete;
	Proxy& operator=(const Proxy&) = delete;
	~Proxy(){
		delete realSubject;
		delete log;
		realSubject = nullptr;
		log = nullptr;
	}
	void preCallMethod(){
		printf("方法request()被调用，调用时间为%s\n",log->getTime().c_str());
	}
	void request(){
        /*
        代理对象的request函数会包含真实对象的request。同时在幕后执行其他所需的事情。比如记录日志，捕获异常等等。
        */
		preCallMethod(); 
		realSubject->request();
		postCallMethod();
	}
	void postCallMethod(){
		printf("方法request()调用调用成功!\n");
	}
private:
	RealSubject* realSubject; //代理类在一般情况下会蕴含真实对象
	Log* log; //代理类在一般情况下同时会蕴含所有需要在幕后执行操作的对象。
};


void function_call(Subject* obj){
    obj->request();
}

 
int main(){
	Subject* subject= new Proxy();
    function_call(subject);
 
	delete subject;
	subject = nullptr;
	return 0;
}