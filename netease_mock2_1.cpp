#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <map>
using namespace std;
class mycomp{
    public:
    bool operator()(const vector<double>& vec1, const vector<double>& vec2) const{
        if(vec1[0] * vec1[1] < vec2[0] * vec2[1]){
            return true;
        }
        else if(vec1[0] * vec1[1] > vec2[0] * vec2[1]){
            return false;
        }
        else{
            double wh1 = min(vec1[1]/vec1[0],vec1[0]/vec1[1]);
            double wh2 = min(vec2[1]/vec2[0],vec2[0]/vec2[1]);
            if(wh1 < wh2){
                return false;
            }
            else if(wh1 > wh2){
                return true;
            }
            else{       
                if(vec1[0] < vec2[0]){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
};



int main(){
    int nums;
    cin >> nums;
    vector<vector<double>> myvec;
    for(int i = 0; i < nums; i++){
        double num1;
        cin >> num1;
        double num2;
        cin >> num2;
        myvec.push_back({num1,num2});

    }
    sort(myvec.begin(), myvec.end(), mycomp());
    for(int i = 0; i < myvec.size()-1; i++){
        cout <<myvec[i][0] << " " << myvec[i][1] <<" ";
    }
    cout <<myvec[myvec.size()-1][0] << " " << myvec[myvec.size()-1][1];
}
