#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <type_traits>
using namespace std;

class Bill{ //请求类。也就是所谓的client
    public:
        Bill() = default;
        Bill(int a, int b, int c):amount(a), req_ID(b), account(c){};
        double getAccount(){
            return account;
        }
        void set_apprID(int id){
            this->appr_ID = id;
        }
        void get_info(){
            cout <<"Bill ID: "<< req_ID << " was approved by "<< appr_ID << ". Amount is " << amount << ", account num is: " << account << endl;
        }
        int get_amount(){
            return amount;
        }
    private:
        double amount = 0;
        double req_ID = 0;
        double appr_ID = 0;
        double account = 0;
};

class Approver{ //抽象处理者
    public:
        Approver() = default;
        Approver(int x):appr_ID(x){
            cout <<" int const called" << endl;
        };
        Approver(Approver* p):next_level_approver(p){
            cout <<"ptr const called" << endl;
        }
        Approver(int x, Approver* p):appr_ID(x), next_level_approver(p){
            cout <<"double const called" << endl;
        }
        virtual ~Approver(){

        }
        void setApprover(Approver* ptr){
            next_level_approver = ptr;
        }
        void set_apprID(int x){
            appr_ID = x;
        }
        int get_apprID(){
            return appr_ID;
        }
        virtual void handler(Bill*) = 0; //处理接口。

    protected:
        Approver* next_level_approver = nullptr; //抽象处理者需要接收另一个处理者指针来完成链条。可以理解为添加上（下）级。

    private:
        int appr_ID = 0;
};

class T5Manager: public Approver{ //具体处理者1
    public:
        T5Manager() = default;
        T5Manager(int x):manager_id(x){};
        T5Manager(int x, Approver* p):Approver(x, p), manager_id(x){};//具体处理者的构造函数。直接调用父类的即可。
        void handler(Bill* msg){ //处理函数
            if(msg->get_amount() < 500){ //如果可以处理，则直接处理。
                cout <<"T5 approved" << endl;
                msg->set_apprID(manager_id);
                msg->get_info();
            }
            else{ //如果不能处理
                cout <<"T5 doesn't have permission. Re-send to T6..." << endl;
                this->next_level_approver->handler(msg); //转发给链条上的下一个对象。
            }
        }

    private:
        int manager_id = 0;
};

class T6Manager: public Approver{ //具体处理者2
    public:
        T6Manager() = default;
        T6Manager(int x):manager_id(x){};
        T6Manager(int x, Approver* p):Approver(x, p), manager_id(x){}; //具体处理者的构造函数。直接调用父类的即可。
        void handler(Bill* msg){ //处理函数
            if(msg->get_amount() >= 500 && msg->get_amount() < 1000){
                cout <<"T6 approved" << endl;
                msg->set_apprID(manager_id);
                msg->get_info();
            }
            else{
                cout <<"T6 doesn't have permission. Re-send to T7..." << endl;
                this->next_level_approver->handler(msg);
            }
        }

    private:
        int manager_id = 0;
};
class T7Manager: public Approver{ //具体处理者3
    public:
        T7Manager() = default;
        T7Manager(int x):manager_id(x){};
        T7Manager(int x, Approver* p):Approver(x, p), manager_id(x){}; //具体处理者的构造函数。直接调用父类的即可。
        void handler(Bill* msg){ //处理函数
            cout <<"T7 approved" << endl;
            msg->set_apprID(manager_id);
            msg->get_info();
        }

    private:
        int manager_id = 0;
};


int main(){
    Bill my_bill(1000, 3260, 8705);

    T7Manager* T7 = new T7Manager(1003);
    T6Manager* T6 = new T6Manager(1002, T7);
    T5Manager* T5 = new T5Manager(1001, T6);


    T5->handler(&my_bill);

    delete T5;
    delete T6;
    delete T7;

    return 0;
}
