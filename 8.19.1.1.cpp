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

    vector<float> precentage;
    vector<int> scores;
    vector<float> calc;
    float totalscore = 0;
    for(int i = 0; i < total_test; i++){
        float temp;
        cin >> temp;
        precentage.push_back(temp/100);
    }
    for(int i = 0; i < total_test; i++){
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }


    for(int i = 0; i < total_test; i++){
        calc.push_back((1-precentage[i]) * scores[i]);
    }

    sort(calc.begin(), calc.end(), greater<float>());
    // for(auto i:calc){
    //     cout << i << endl;
    // }
    for(int i = 0; i < total_test; i++){
        totalscore = totalscore + precentage[i] * scores[i];
    }
    for(int i = 0; i < review; i++){
        totalscore = totalscore + calc[i];
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << totalscore << endl;
    return 0;
}