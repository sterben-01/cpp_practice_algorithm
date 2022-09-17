#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
using namespace std;

mutex mylock;

void request(const function<void(int)>& callback){
    int input_param;
    callback(input_param);
    mylock.unlock(); //解锁（这个是一次锁）

}

void testfunc(int){

}

vector<int> request_sync(){
    mylock.lock(); //一次加锁
    thread th(request, testfunc);
    mylock.lock(); //二次重复加锁，强制死锁
    mylock.unlock();//获取二次加锁后记得再解锁一次
    th.join();
}

// void threadfunc(){
//     cout << "begin" << endl;
//     Sleep(1000);
//     mylock.unlock();
//     cout << "end..unlockedfunc" << endl;
// }

// void testfunc(){
//     mylock.lock();
//     cout <<"locked1" << endl;
//     thread th(threadfunc);
//     cout <<"called func.." << endl;
//     mylock.lock();
//     cout <<"locked2" << endl;
//     mylock.unlock();
//     cout <<"unlocked2" << endl;
//     th.join();

// }

int main(){
    testfunc();
    return 0;

}

