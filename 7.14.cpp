#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <stdarg.h>
#include <future>
#include <thread>
using namespace std;

// void accumulate(vector<int>& vec,promise<vector<int>> accumulate_promise){
//     vector<int> accumulated;
//     vector<int>::iterator iter = vec.begin();
//     for(; iter!= vec.end(); iter++){
//         accumulated.push_back(*iter * 5);
//     }

//     accumulate_promise.set_value(accumulated);
// }


// int main(){

//     vector<int> vec = {1,2,3,4,5,6,7};
//     promise<vector<int>> accu_promise;
//     future<vector<int>> accu_future = accu_promise.get_future();
//     thread work_thread(accumulate, ref(vec), move(accu_promise)); //注意线程函数如果需要传递引用需要加ref。promise要用move因为禁用了拷贝构造。当然引用也可以只不过需要改函数头而且不符合设计。
//     accu_future.wait();
//     vector<int> ret = accu_future.get();
//     for(auto i:ret){
//         cout << i << endl;
//     }
//     work_thread.join();
//     getchar();

//     return 0;
// }


// vector<int> accumulate(vector<int>& vec){
//     vector<int> accumulated;
//     vector<int>::iterator iter = vec.begin();
//     for(; iter!= vec.end(); iter++){
//         accumulated.push_back(*iter * 5);
//     }
//     return accumulated;
// }

// int main(){
//     vector<int> vec = {1,2,3,4,5,6,7};
//     packaged_task<vector<int>(vector<int>&)> packaged_miku(accumulate);
//     future<vector<int>> accumulate_future = packaged_miku.get_future();
//     thread work_thread(move(packaged_miku), ref(vec));
//     accumulate_future.wait();
//     vector<int> res = accumulate_future.get();
//     for(auto i:res){
//         cout << i << endl;
//     }
//     work_thread.join();
//     getchar();
//     return 0;
// }

vector<int> accumulate(vector<int>& vec){
    vector<int> accumulated;
    vector<int>::iterator iter = vec.begin();
    for(; iter!= vec.end(); iter++){
        accumulated.push_back(*iter * 5);
    }
    return accumulated;
}



int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    future<vector<int>> accumulate_future = async(launch::async, accumulate, ref(vec)); //async 也要ref

    vector<int> ret = accumulate_future.get();

    for(auto i : ret){
        cout << i << endl;
    }
    getchar();

    return 0;
}