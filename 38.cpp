#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


int main(){

    vector<char> s = {'a','c','t','v','b','d','b'};
    sort(s.begin(), s.end());

    for(auto i : s){
        cout << i << endl;
    }

    return 0;
}