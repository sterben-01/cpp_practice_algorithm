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

using namespace std;
//text amazom medium 
//& maximum number of engineering teams

void solution(int maxdiff, int teamsize, vector<int>& people){
    sort(people.begin(), people.end());
    vector<vector<int>>my_vec;
    vector<int>temp;
    int res = 0;
    int firstpos = 0;
    int lastpos = 1;
    while(lastpos < people.size()){
        if(lastpos - firstpos+1 == teamsize){
            my_vec.push_back(temp);
            temp.clear();
            res++;
            firstpos = lastpos;
        }
        if(people[lastpos] - people[firstpos] <= maxdiff){
            temp.push_back(people[lastpos]);
            lastpos++;
        }
        else{
            firstpos++;
            lastpos = firstpos+1;
        }
    }
    for(auto i:my_vec){
        for(auto j:i){
            cout <<j << " ";
        }
        cout << endl;
    }
    cout << res << endl;
}




int main(){
    vector<int>s{7,18,1,65,32,72,90,98,100,113,146};
    vector<int>s1{34,5,72,48,15,2};
    solution(30,3,s);
    return 0;
}