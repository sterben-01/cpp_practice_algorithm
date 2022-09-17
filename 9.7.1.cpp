
#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
using namespace std;

int main(){

    int i = 0;
    cout << i++ << endl;
    cout << i-- << endl;
    
    cout << ++i << endl;
    cout << --i << endl;
    return 0;
}