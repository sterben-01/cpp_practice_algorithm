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
int upperind = 0;
int downind = 3 - 1;
int leftind = 0;
int rightind = 4 - 1;

int global_count = 0;
vector <int> ans;
mutex my_mutex;

void printfunc(vector<int>& vec, mutex& my_mutex){
    for(auto i:vec){
        cout << i << " ";
    }
    cout << endl;
    global_count++;        
    my_mutex.unlock();
}

void spiralOrderfunc1(vector<vector<int>>& matrix){
    while(true){
        my_mutex.lock();
        if(global_count %2 == 0){
            if(upperind > downind || rightind < leftind || downind < upperind || leftind > rightind){
                global_count++;
                my_mutex.unlock();
                break;
            }
            cout << "thread for odd" << endl;
            vector<int> temp;
            for(int i = leftind; i <= rightind; i++){
                ans.push_back(matrix[upperind][i]);
                temp.push_back(matrix[upperind][i]);
            }
            upperind = upperind + 1;
            if(upperind > downind){
                printfunc(temp, my_mutex);
                break;
            }
            for(int i = upperind; i <= downind; i++){
                ans.push_back(matrix[i][rightind]);
                temp.push_back(matrix[i][rightind]);
            }
            rightind = rightind - 1;
            if( rightind < leftind){
                printfunc(temp, my_mutex);
                break;
            }
            for(int i = rightind; i >= leftind; i--){
                ans.push_back(matrix[downind][i]);
                temp.push_back(matrix[downind][i]);
            }
            downind = downind - 1;

            if(downind < upperind){
                printfunc(temp, my_mutex);
                break;
            }

            for(int i = downind; i >= upperind; i--){
                ans.push_back(matrix[i][leftind]);
                temp.push_back(matrix[i][leftind]);
            }
            leftind = leftind + 1;

            if( leftind > rightind){
                printfunc(temp, my_mutex);   
                break;
            }
            for(auto i:temp){
                cout << i << " ";
            }
            cout << endl;
            global_count++;
            
        }
        my_mutex.unlock();
    }
}

void spiralOrderfunc2(vector<vector<int>>& matrix){
    while(true){
        my_mutex.lock();
        if(global_count %2 == 1){
            if(upperind > downind || rightind < leftind || downind < upperind || leftind > rightind){
                global_count++;
                my_mutex.unlock();
                break;
            }
            cout << "thread for even" << endl;
            vector<int> temp;
            for(int i = leftind; i <= rightind; i++){
                ans.push_back(matrix[upperind][i]);
                temp.push_back(matrix[upperind][i]);
            }
            upperind = upperind + 1;
            if(upperind > downind){
                printfunc(temp, my_mutex);
                break;
            }
            for(int i = upperind; i <= downind; i++){
                ans.push_back(matrix[i][rightind]);
                temp.push_back(matrix[i][rightind]);
            }
            rightind = rightind - 1;
            if( rightind < leftind){
                printfunc(temp, my_mutex);
                break;
            }
            for(int i = rightind; i >= leftind; i--){
                ans.push_back(matrix[downind][i]);
                temp.push_back(matrix[downind][i]);
            }
            downind = downind - 1;

            if(downind < upperind){
                printfunc(temp, my_mutex);
                break;
            }

            for(int i = downind; i >= upperind; i--){
                ans.push_back(matrix[i][leftind]);
                temp.push_back(matrix[i][leftind]);
            }
            leftind = leftind + 1;

            if( leftind > rightind){
                printfunc(temp, my_mutex);
                break;
            }
            for(auto i:temp){
                cout << i << " ";
            }
            cout << endl;
            global_count++;
            
        }
        my_mutex.unlock();
    }
}
int main(){
    vector<vector<int>> vec1{{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24}};
    vector<vector<int>> vec{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> vec2(20, vector<int>(20,0));
    int count = 0;
    for(int i = 0; i < 20;i++){
        for(int j = 0; j<20;j++){
            vec2[i][j] = count;
            count++;
        }
    }
    thread th1(spiralOrderfunc1, ref(vec));
    thread th2(spiralOrderfunc2, ref(vec));
    th1.join();
    th2.join();
    for(auto i:ans){
        cout << i << " ";
    }
    return 0;
}