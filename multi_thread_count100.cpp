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

void printodd(int& num){
    while(1){
        my_mutex.lock();
        if(num >= MAXNUMBER){
            my_mutex.unlock();
            break;
        }
        if(num % 2 == 0){
            num++;
            cout << "Thread A: " << num << endl;
        }
        my_mutex.unlock();
    }
    cout <<"threadA finish" << endl;
}

void printeven(int& num){
    while(1){
        my_mutex.lock();
        if(num >= MAXNUMBER){
            my_mutex.unlock();
            break;
        }
        if(num % 2 == 1){
            num++;
            cout << "Thread B: " << num << endl;
        }
        my_mutex.unlock();
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