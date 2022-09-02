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
#include <limits.h>
#include <set>

using namespace std;

int ret = INT_MAX;

void backtracking(string& s1, string& s2, int counts){
    if(s1.empty() || s2.empty()){
        return;
    }
    int s1int = stoi(s1);
    int s2int = stoi(s2);
    if(s2int > s1int){
        swap(s1int, s2int);
    }
    if(s1int % s2int == 0){
        ret = min(ret, counts);
        return;
    }
    for(int i = 0; i < s1.size(); i++){
        auto temp = *(s1.begin()+i);
        s1.erase(s1.begin()+i);
        backtracking(s1, s2, counts+1);
        s1.insert(s1.begin()+i, temp);
    }
    for(int i = 0; i < s2.size(); i++){
        auto temp = *(s2.begin()+i);
        s2.erase(s2.begin()+i);
        backtracking(s1, s2, counts+1);
        s2.insert(s2.begin()+i, temp);
    }
}


int main(){
    string num1;
    cin >> num1;
    string num2;
    cin >> num2;
    backtracking(num1, num2, 0);
    if(ret == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ret << endl;
    }
    return 0;
    // string s1 = "1234";
    // string s2 = "99";
    // s1.erase(s1.begin()+1);
    // cout << s1 << endl;
    // s1.insert(s1.begin()+1, '1');
    // cout << s1 << endl;
}