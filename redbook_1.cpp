#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <memory>
using namespace std;






int main(){

    int people;
    cin >> people;
    int aspects;
    cin >> aspects;
    int req;
    cin >> req;
    vector<int> scores;
    int reqscore = 0;
    int ret = 0;
    for(int i = 0; i < people; i++){
        int sum = 0;
        for(int j = 0; j < aspects; j++){
            int num;
            cin >> num;
            sum = sum + num;
            if(i == req-1){
                reqscore = reqscore + num;
            }
        }
        scores.push_back(sum);
    }
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] > reqscore){
            ret++;
        }
        if(scores[i] == reqscore){
            if(i < req-1){
                ret++;
            }
        }
    }
    cout << ret+1 << endl;

    return 0;
}