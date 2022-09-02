#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <memory>
#include <algorithm>
using namespace std;






int main(){

    int magic_num;
    cin >> magic_num;
    long long total;
    cin >> total;
    vector<long long> magic;
    // int magic_num = 3;
    // long long total = 3;
    // vector<long long> magic{3,2,1};
    int ret = 0;
    for(int i = 0; i < magic_num; i++){
        int temp;
        cin >> temp;
        magic.push_back(temp);
    }

    sort(magic.begin(), magic.end(), greater<long long>());
    for(int i = 0; i < magic_num; i++){
        for(int j = i+1; j < magic_num; j++){
            if(magic[i] * magic[j] < total){
                break;
            }
            else{
                ret+=2;
            }
        }
    }
    cout << ret << endl;



    return 0;
}