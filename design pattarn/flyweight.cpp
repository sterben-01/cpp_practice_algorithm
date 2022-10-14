#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <map>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <sstream>
using namespace std;


//text 这个设计是我们有多台电脑可以共用一个router路由器和一个hub集线器。可以采用享元模式。
//CLASS - 抽象享元类。
//@ - print方法向外部提供享元对象的内部状态数据。
class NetDevice{
     public:
     NetDevice(){};
     virtual ~NetDevice(){}
     virtual string getName() = 0;

     void print(int portNumber){
          cout << "Device name:" << this->getName() << "port: " << portNumber << endl;
     }
};

//CLASS - 具体享元类 - 集线器 理论应该是单例，但是懒得写。
class Hub: public NetDevice{
     public:
          Hub(){};
          string getName(){
               return "Hub";
          }
};

//CLASS - 具体享元类 - 路由器 理论应该是单例，但是懒得写。
class Router: public NetDevice{
     public:
          Router(){};
          string getName(){
               return "Router";
          }
};


//text 这个例子没有非共享具体享元类


//CLASS - 享元工厂类。创建并管理享元对象。单例模式。

class NetDeviceFactory{
     public:
          static NetDeviceFactory& getInstance(){ //&单例模式返回工厂类实例。
               static NetDeviceFactory myInstance;
               return myInstance;
          }
          
          shared_ptr<NetDevice> getNetDevice(char input){ //&从享元池中返回一个具体享元对象。
               if(input == 'H'){
                    return devicePool[0];
                    //返回一个智能指针，此时引用计数+1。但是马上被析构。
               }
               if(input == 'R'){
                    return devicePool[1];
               }
               return nullptr;
          }
     private:
          NetDeviceFactory(){
               shared_ptr<Hub> my_hub = make_shared<Hub>(); //&创建一个指针指向一个具体享元类对象
               shared_ptr<Router> my_router = make_shared<Router>(); //&创建一个指针指向一个具体享元类对象
               //注意上面的两个智能指针是临时变量。
               devicePool.emplace_back(my_hub); //&享元对象指针放入享元池
               devicePool.emplace_back(my_router);
               //两个智能指针被构建出来的时候，count是1
               //放入容器后count是2,
               //因为最开始的两个是临时对象，所以构造函数结束后两个智能指针被释放。此时全局只有容器内的两个智能指针。每一个的count都是1
          }
          ~NetDeviceFactory(){};
          NetDeviceFactory(const NetDeviceFactory&);
          NetDeviceFactory& operator= (const NetDeviceFactory&);

          vector<shared_ptr<NetDevice>> devicePool; //&享元池
};

//CLASS - 调用类。为了具体说明享元模式创建的对象模拟调用。、
//@ - 电脑有自己的ip和端口，但是共用路由器和集线器。
class Computer{
     public:
          Computer(int x, int y): my_port(x), my_ip(y){};
          int my_port; //&自己的ip
          int my_ip; //&自己的端口
          shared_ptr<NetDevice> my_hub; //&享元的集线器。
          shared_ptr<NetDevice> my_router; //&享元的路由器。
          void set_hub(shared_ptr<NetDevice> ptr){ //&设置集线器
               //使用值传递，引用计数+1变成2
               my_hub = ptr;
               //赋值后引用计数再+1变成3
               //然后值传递的临时对象出作用域，计数回到2。
          }
          void set_router(shared_ptr<NetDevice> ptr){ //&设置路由器
               my_router = ptr;
          }

          void get_info(){ //&返回信息
               cout <<"您的设备信息如下:" << endl;
               cout <<"ip: " << my_ip << endl;
               my_hub->print(my_port);
               my_router->print(my_port);
               cout << my_hub << endl;
               cout << my_router << endl;
          }

};


int main(){
     
     NetDeviceFactory& factory = NetDeviceFactory::getInstance(); //工厂类创建并管理享元对象。

     Computer mydevice1(1234, 8888);
     Computer mydevice2(4321, 9999);
     mydevice1.set_hub(factory.getNetDevice('H'));  //注意此时调用链。给电脑设置集线器。
     mydevice1.set_router(factory.getNetDevice('R'));
     mydevice2.set_hub(factory.getNetDevice('H'));
     mydevice2.set_router(factory.getNetDevice('R'));

     mydevice1.get_info();
     mydevice2.get_info();


     /*
     我们一开始创建了一个指针，计数1
     放入容器，计数2
     第一个指针是临时对象所以出作用域计数-1，计数1
     get函数返回一个临时对象指针，计数+1。set函数值传递，计数再+1，但是这个临时对象放入set函数的时候，拷贝的同时自己也被析构-1。所以只有值传递的那一份。也就是1 +1（return的）+1（值传递）-1（return的）所以计数只+1。所以计数是2
     传递给对象，计数+1，计数3
     出作用域，值传递的临时对象析构。计数-1，计数2。
     至此，全局只有两个指针，一个是容器内，一个是对象内。
     */
     /*
     您的设备信息如下:
     ip: 8888
     Device name:Hubport: 1234
     Device name:Routerport: 1234
     0x7b1500
     0x7b18e0
     您的设备信息如下:
     ip: 9999
     Device name:Hubport: 4321
     Device name:Routerport: 4321
     0x7b1500
     0x7b18e0
     */
    //text 我们可以发现，两个对象的集线器和路由器的地址是一个。所以两个设备共用了集线器和路由器这两个享元对象。
     return 0;

}