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

//CLASS - 作业内容，一个额外内容类。具体原型类包含的一个类。
class WorkModel{
    public:
        WorkModel(){};
        string workname;
        void setWorkModelName(const string& s){ //&作业的具体内容，因人而异。
            workname = s;
        }
};

//CLASS - 抽象原型类。
class PrototypeWork{
    public:
        PrototypeWork(){};
        virtual ~PrototypeWork(){};
        virtual shared_ptr<PrototypeWork> clone(const string& iname, int id, const string& modelname) = 0; //&实现一个克隆接口。
        virtual void printInfo() = 0;

};
//CLASS - 具体原型类。这里是一个作业。包含作业内容。
class ConcreteWork: public PrototypeWork{
    public:
        ConcreteWork(){};
        ConcreteWork(const string& iname, int id, const string& modelname):name(iname), ID(id){ //&作业里面要包含作业内容，姓名和ID。
            workModel = make_shared<WorkModel>();//&作业内容。
            workModel->setWorkModelName(modelname);//&写作业。
        }

        shared_ptr<PrototypeWork> clone(const string& iname, int id, const string& modelname){ //&克隆。
            shared_ptr<ConcreteWork> copiedWork = make_shared<ConcreteWork>(); //&这里我们要深拷贝，也就是新创建一份作业。毕竟俩人不能交同一份作业
            copiedWork->setName(iname);//&写名字
            copiedWork->setID(id);//&写学号
            copiedWork->setModel(this->workModel);//&抄作业内容。
            copiedWork->workModel->setWorkModelName(modelname);//&作业抄完了，更改作业内容因人而异的部分。
            //return copiedWork;
            return dynamic_pointer_cast<PrototypeWork>(copiedWork); //&智能指针的动态类型转换。
            //* 我们这里没有调用任何的拷贝构造。我们是直接构造了一个新的ConcreteWork，然后更改其参数后return出去。
        }

        void setName(const string& name){
            this->name = name;
        }
        void setID(int id){
            ID = id;
        }
        void setModel(shared_ptr<WorkModel> work){
            workModel = make_shared<WorkModel>(); //&俩人的作业是两份，那么作业包含的作业具体内容也应该是两份。所以也要新建。也就是深拷贝。
            workModel->setWorkModelName(work->workname);//&填充作业内容。先抄过来再说。
            
        }

        void printInfo(){ //&看看作业信息
            cout <<"name: "<< this->name <<endl;
            cout <<"ID: "<< this->ID <<endl;
            cout <<"modelname: "<< this->workModel->workname<<endl;
            cout <<"model address" << this->workModel<< endl;
        }


    private:
        string name;
        int ID;
        shared_ptr<WorkModel> workModel;
};

//CLASS - 客户端类。这里就是main

int main(){
    shared_ptr<PrototypeWork> myWork = make_shared<ConcreteWork>("Sky", 01, "Sky's HW1"); //&我的作业
    cout <<"作业1" << endl;
    shared_ptr<PrototypeWork> hisWork = myWork->clone("Lucy", 831, "Lucy's HW1"); //&有人抄了我的作业
    //* 我们这里没有调用任何的ConcreteWork的拷贝构造或拷贝赋值。调用的是智能指针的拷贝构造（移动构造）。
    //* 就算换成了元是指针类型，也没有调用任何拷贝构造
    //* 除非是引用类型。但是这样是不可能的，因为得弄个右值引用来接，没什么意义。
    cout <<"有人抄作业" << endl;
    cout <<"作业抄完记得更改姓名和学号" <<endl;

    myWork->printInfo();
    hisWork->printInfo();
    return 0;

    /*
    作业1
    有人抄作业
    作业抄完记得更改姓名和学号
    name: Sky
    ID: 1
    modelname: Sky's HW1
    model address 0x7918e0

    name: Lucy
    ID: 831
    modelname: Lucy's HW1
    model address 0x7919c0
    */
}