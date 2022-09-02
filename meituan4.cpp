#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include<stack>
#include <queue>
using namespace std;





int main(){
    int cloth;
    cin >> cloth;
    int battery;
    cin >> battery;
    vector<int> breq;
    vector<int> time;
    for(int i = 0; i < cloth; i++){
        int temp;
        cin >> temp;
        breq.push_back(temp);
    }
    for(int i = 0; i < cloth; i++){
        int temp;
        cin >> temp;
        time.push_back(temp);
    }

}
