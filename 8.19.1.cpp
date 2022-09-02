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

class mycomp{
    public:
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{
            if(p1.first > p2.first){
                return true;
            }
            return false;
        }
};

class mycomp1{
    public:
        bool operator()(int p1, int p2){
            if (p1 > p2){
                return true;
            }
            return false;
        }
};

int main() {
    int total_test;
    cin >> total_test;
    int review;
    cin >>review;

    vector<int> precentage;
    vector<int> scores;
    for(int i = 0; i < total_test; i++){
        int temp;
        cin >> temp;
        precentage.push_back(temp);
    }
    for(int i = 0; i < total_test; i++){
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }
    map<int,float,greater<int>> my_map;

    for(int i = 0; i < total_test; i++){
        my_map.insert(make_pair(scores[i], precentage[i]));
    }
    float totalscore = 0;
    int pos = 0;
    auto t = my_map.begin();
    for(; pos < review; pos++){
        int num = t->first;
        totalscore = totalscore + num;
        t++;
    }
    for(; pos < total_test; pos++){
        int sc = t->first;
        float precen = t->second / 100;
        totalscore = totalscore + sc*precen;
        t++;
    }

    cout << totalscore << endl;
    return 0;
}