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



void spiralOrderfunc1(vector<vector<int>>& matrix){
    while(true){
        my_mutex.lock();
        if(global_count %2 == 0){
            if(upperind > downind || rightind < leftind || downind < upperind || leftind > rightind){
                global_count++;
                my_mutex.unlock();
                break;
            }
            vector<int> temp;
            for(int i = leftind; i <= rightind; i++){
                ans.push_back(matrix[upperind][i]);
                temp.push_back(matrix[upperind][i]);
            }
            upperind = upperind + 1;
            for(int i = upperind; i <= downind; i++){
                ans.push_back(matrix[i][rightind]);
                temp.push_back(matrix[i][rightind]);
            }
            rightind = rightind - 1;
            for(int i = rightind; i >= leftind; i--){
                ans.push_back(matrix[downind][i]);
                temp.push_back(matrix[downind][i]);
            }
            downind = downind - 1;
            for(int i = downind; i >= upperind; i--){
                ans.push_back(matrix[i][leftind]);
                temp.push_back(matrix[i][leftind]);
            }
            leftind = leftind + 1;
            cout << "thread for odd" << endl;
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
            vector<int> temp;
            for(int i = leftind; i <= rightind; i++){
                ans.push_back(matrix[upperind][i]);
                temp.push_back(matrix[upperind][i]);
            }
            upperind = upperind + 1;
            for(int i = upperind; i <= downind; i++){
                ans.push_back(matrix[i][rightind]);
                temp.push_back(matrix[i][rightind]);
            }
            rightind = rightind - 1;
            for(int i = rightind; i >= leftind; i--){
                ans.push_back(matrix[downind][i]);
                temp.push_back(matrix[downind][i]);
            }
            downind = downind - 1;
            for(int i = downind; i >= upperind; i--){
                ans.push_back(matrix[i][leftind]);
                temp.push_back(matrix[i][leftind]);
            }
            leftind = leftind + 1;
            cout << "thread for even" << endl;
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
    thread th1(spiralOrderfunc1, ref(vec));
    thread th2(spiralOrderfunc2, ref(vec));
    th1.join();
    th2.join();

    return 0;
}