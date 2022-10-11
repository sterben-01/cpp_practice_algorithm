#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool transformArray(string a, string b) {
    vector<int> avec;
    vector<int> bvec;
    avec.reserve(a.size());
    bvec.reserve(b.size());
    size_t pos = 0;
    size_t curpos = 0;
    while ((pos = a.find(" ")) != a.npos) {

        bool neg = false;
        if (a[curpos] == '-') {
            neg = true;
        }
        if (neg == true) {
            avec.push_back(0 - stoi(a.substr(curpos+1, pos - curpos)));
        }
        else {
            avec.push_back(stoi(a.substr(curpos, pos - curpos)));
        }
        a.erase(curpos, pos + 1);
    }

    if (a.size() > 0) {
        if (a[0] == '-') {
            avec.push_back(0 - stoi(a.substr(1, a.size() - 1)));
        }
        else {
            avec.push_back(stoi(a.substr(0, a.size())));
        }
    }
    pos = 0;
    curpos = 0;
    while ((pos = b.find(" ")) != b.npos) {

        bool neg = false;
        if (b[curpos] == '-') {
            neg = true;
        }
        if (neg == true) {
            bvec.push_back(0 - stoi(b.substr(curpos + 1, pos - curpos)));
        }
        else {
            bvec.push_back(stoi(b.substr(curpos, pos - curpos)));
        }
        b.erase(curpos, pos + 1);
    }
    if (b.size() > 0) {
        if (b[0] == '-') {
            bvec.push_back(0 - stoi(b.substr(1, b.size() - 1)));
        }
        else {
            bvec.push_back(stoi(b.substr(0, b.size())));
        }
    }

    // for(int i = 0; i < avec.size(); i++){
    //     cout << avec[i] <<endl;
    // }
    sort(avec.begin(), avec.end());
    sort(bvec.begin(), bvec.end());
    for (int i = 0; i < avec.size(); i++) {
        if (avec[i] != bvec[i]) {
            if (avec[i] + 1 != bvec[i]) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    string a = "-10 -10 -10 -10";
    string b = "-9 -9 -10 -9 9 100 -10";
    //transformArray(b, a);

    vector<int>v1(5);
    vector<int>v2(5,0);
    vector<int>v3;
    vector<int>v4;
    v4.reserve(5);
    v1.push_back(100);
    v2.push_back(100);
    v3.push_back(100);
    v4.push_back(100);

    vector<int>v5;
    v5.resize(5);
    v5.push_back(100);
    for(auto i:v5){
        cout << i << endl;
    }
    for(auto i:v2){
        cout << i << endl;
    }
    for(auto i:v3){
        cout << i << endl;
    }
    for(auto i:v4){
        cout << i << endl;
    }
    return 0;
}