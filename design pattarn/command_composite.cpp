#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

struct BankAccount{ //接收者
    int balance = 0;
    int overdraft_limit = -500;
    void deposit(int amount){
        balance += amount;
        cout << "deposited " << amount << ", balance now " <<
        balance << "\n";
    }

    bool withdraw(int amount){
        if (balance - amount >= overdraft_limit){
        balance -= amount;
        cout << "withdrew " << amount << ", balance now " <<
            balance << "\n";
        return true;
        }
        return false;
    }
};

struct Command{ //抽象命令 & 抽象构件
    bool succeeded;
    virtual void call() = 0;
    virtual void undo() = 0;
};

// should really be BankAccountCommand
struct BankAccountCommand : Command{ //具体命令 & 叶子构件
    BankAccount& account;
    enum Action { deposit, withdraw } action;
    int amount;
    BankAccountCommand(BankAccount& account, const Action action,const int amount): account(account), action(action), amount(amount){
        succeeded = false;
    }

    BankAccountCommand(const BankAccountCommand& rhs):account(rhs.account), action(rhs.action), amount(rhs.amount){
        cout <<"ba copy const" << endl;
    }

    BankAccountCommand& operator=(const BankAccountCommand& rhs) = delete;

    void call() override{
        switch (action){
        case deposit:
            account.deposit(amount);
            succeeded = true;
            break;
        case withdraw:
            succeeded = account.withdraw(amount);
            break;
        }
    }
    void undo() override{
        if (!succeeded) return;
        switch (action){
            case withdraw:
            if (succeeded)
                account.deposit(amount);
            break;
        case deposit:
            account.withdraw(amount);
            break;
        }
    }
};

struct CompositeBankAccountCommand : Command{ //具体命令 & 容器构件
    CompositeBankAccountCommand(const vector<BankAccountCommand>& vec): my_cmd(vec){}
    void call() override{
        //在当前业务中，由于有更具体的命令类存在，所以我们不会执行这个类的call函数。转而执行DependentCompositeCommand的call函数。
        for (auto& cmd : my_cmd){
            cmd.call();
        }
            
    }

    void undo() override{
        for (auto it = my_cmd.rbegin(); it != my_cmd.rend(); ++it)
            it->undo();
    }
    vector<BankAccountCommand> my_cmd; //容器构件蕴含叶子构件的内容
};

struct DependentCompositeCommand : CompositeBankAccountCommand{ //具体命令
    explicit DependentCompositeCommand(const vector<BankAccountCommand>& vec): CompositeBankAccountCommand{ vec } {}
    //这个类的目的是完善具体业务逻辑。构造函数是直接调用父类构造。把装有两个具体命令的vector传进去。
    void call() override{
        //这个具体执行接口是业务特化。因为我们一定是先从A账户取出，再给B账户加入。而只有A账户可能发生问题，比如超过额度。所以第一个命令永远可以执行，但是第二个命令如果发现前一个命令执行失败，则就不执行了。
        //第一个命令一定会执行，不代表它一定会执行成功。如果执行的结果是失败，则不会有任何影响。
        bool ok = true;
        for (auto& cmd : my_cmd){
            if (ok){
                cmd.call(); //调用容器内命令的执行函数。
                ok = cmd.succeeded;
            }
            else{
                cmd.succeeded = false;
            }
        }
    }
};

struct MoneyTransferCommand : DependentCompositeCommand //这个类的目的是特化转账的这个行为。让这个行为成为了一个对象。
{
  MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount): 
    DependentCompositeCommand{vector<BankAccountCommand>{{from, BankAccountCommand::withdraw, amount},{to, BankAccountCommand::deposit, amount}}} {}
    //直接调用父类构造。行为是构造出一个含有两个具体命令的容器。此处是业务特化，命令的顺序是，先从一个账户中提取，然后给另一个账户添加。
};
int main(){
    BankAccount ba, ba2;
    cout <<"---" << endl;
    ba.deposit(100);
    cout <<"---" << endl;
    MoneyTransferCommand cmd{ba, ba2, 5000};
    cout <<"---" << endl;
    cout << ba.balance << endl;
    cout << ba2.balance << endl;
    cmd.call();
    cout << ba.balance << endl;
    cout << ba2.balance << endl;
    cmd.undo();
    cout << ba.balance << endl;
    cout << ba2.balance << endl;
    /*vector<BankAccountCommand> commands{*/
    // CompositeBankAccountCommand commands{vector<BankAccountCommand>{{ ba, BankAccountCommand::deposit, 100 },{ ba, BankAccountCommand::withdraw, 200 }}};

    // cout << ba.balance << endl;

    // // apply all the commands
    // /*for (auto& cmd : commands)
    // {
    // cmd.call();
    // }*/
    // commands.call();

    // cout << ba.balance << endl;

    // /*for_each(commands.rbegin(), commands.rend(),
    // [](const BankAccountCommand& cmd) { cmd.undo(); });*/
    // commands.undo();

    // cout << ba.balance << endl;

    getchar();
  return 0;
}
