#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

#define MAXNUMBER 100
mutex my_mutex;
condition_variable my_cond;
bool flag = false;



void printodd(int& num){
    for(int i = 0; i < MAXNUMBER; i++){
        unique_lock<mutex> locker(my_mutex);
        while(flag == false){
            my_cond.wait(locker);
        }
        if(num >=100){
            flag = false; //不要忘记break之前通知另一个线程
            my_cond.notify_one();
            break;
        }
        num++;
        cout << "Thread A: " << num << endl;
        flag = false; //这里不要写反
        my_cond.notify_one();
    }
    cout <<"threadA finish" << endl;
}

void printeven(int& num){
    for(int i = 0; i < MAXNUMBER; i++){
        unique_lock<mutex> locker(my_mutex);
        while(flag == true){
            my_cond.wait(locker);
        }
        if(num >= 100){
            flag = true;
            my_cond.notify_one();
            break;
        }
        num++;
        cout << "Thread B: " << num << endl;
        flag = true;
        my_cond.notify_one();
    }
    cout <<"threadB finish" << endl;
}






int main(){
    int mynum = 0;
    thread my_thread1(printodd, ref(mynum));
    thread my_thread2(printeven, ref(mynum));

    my_thread1.join();
    my_thread2.join();

    return 0;
}