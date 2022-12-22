#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
using namespace std;


std::condition_variable cv;
std::mutex gMtx;

bool send = false;
void Sender()
{
     std::cout << "Ready Send notification." << std::endl;
     send = true;
     cv.notify_one();   // 发送通知
 }

void Receiver()
{
     std::cout << "Wait for notification." << std::endl;
     std::unique_lock<std::mutex> lck(gMtx);
     cv.wait(lck, [](){return send;});    // 等待通知并唤醒继续执行下面的指令
     std::cout << "Process." << std::endl;
}
void Receiver1()
{
     std::cout << "Wait for notification." << std::endl;
     std::unique_lock<std::mutex> lck(gMtx);
     while(send == false){
        cv.wait(lck);
     }
    //  cv.wait(lck, [](){return send;});    // 等待通知并唤醒继续执行下面的指令
     std::cout << "Process." << std::endl;
}

template<typename T1, typename T2 = int>
class obj{
     public:
     obj(T1 a, T2 b):val1(a), val2(b){};
     T1 val1;
     T2 val2;
};


 int main()
 {
     obj<double> myobj(2.234, 4);
     cout << myobj.val1 << endl;
     cout << myobj.val2 << endl;
     return 0;
}