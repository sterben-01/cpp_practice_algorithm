#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include<stack>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int ret = 0;
bool is_valid(string& s, string& t, int startindex){
    for(int i = 0; i < t.size(); i++, startindex++){
        if(t[i] != s[startindex]){
            return false;
        }
    }
    return true;
}

void backtracking(string& s, vector<string>& req, int startindex){
    if(req.empty()){
        ret++;
        return;
    }
    for(int i = 0; i < req.size(); i++){
        if(is_valid(s, req[i], startindex)){
            string temp = req[i];
            req.erase(req.begin()+i);
            backtracking(s, req, startindex + temp.size());
            req.insert(req.begin()+i, temp);
        }
    }
}

int main(){
    int length;
    cin >> length;
    int req_nums;
    cin >> req_nums;
    string s;
    cin >> s;
    vector<int>req;
    vector<string> req_detail;
    for(int i = 0; i < req_nums; i++){
        int temp;
        cin >> temp;
        req.push_back(temp);
    }
    for(int i = 0; i < req_nums; i++){
        string temp;
        cin >> temp;
        req_detail.push_back(temp);
    }
    int sum = accumulate(req.begin(), req.end(), 0);
    if(sum > length){
        return 0;
    }
    backtracking(s, req_detail, 0);
    cout << ret << endl;
    return 0;
}
