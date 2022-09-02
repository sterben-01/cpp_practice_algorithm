
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;




bool solution(vector<int> &A, vector<int> &B, int S) {
    if(A.size() != B.size()){
        cout << "false" << endl;
        return false;
    }
    if(S < A.size()){
        cout << "false" << endl;
        return false;
    }
    vector<vector<int>> temp;
    for(unsigned int i = 0; i < A.size(); i++){
        int first = max(A[i], B[i]);
        int second = (first == A[i] ? B[i] : A[i]);
        temp.emplace_back(vector<int>{second, first});
    }
    sort(temp.begin(), temp.end());

    for(unsigned int i = 1; i < temp.size(); i++){
        if(temp[i-1] == temp[i]){
            if( i + 1 < temp.size() && temp[i] == temp[i+1]){
                cout << "false" << endl;
                return false;
            }
        }
    }
    cout<< "ture"<<endl;


}




int main(){
    vector<int> A = {1,1,3};
    vector<int> B = {2,2,1};
    solution(A, B, 3);
    return 0;
}