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



bool canorcant(vector<int>& nodes, int sum, int currentpos){
    int leftnodepos = currentpos*2 + 1;
    int rightnodepos = currentpos*2 + 2;
    if(leftnodepos < nodes.size() - 1 && rightnodepos < nodes.size() -1){
        if(sum - nodes[currentpos] == 0){
            return true;
        }
        return false;
    }
    sum = sum - nodes[currentpos];
    if(currentpos*2 + 1 <= nodes.size() - 1){
        if(canorcant(nodes, sum, currentpos*2 + 1)){
            return true;
        }
    }
    if(currentpos*2 + 2 <= nodes.size() - 1){
        if(canorcant(nodes, sum, currentpos*2 + 2)){
            return true;
        }
    }
    sum = sum + nodes[currentpos];
    return false;
}


int main(){
    vector<int>my_vec = {7,5,4,1,11,9,2,19,20,4,8,3,15,14,13};
    // map<int,int> my_map;
    // for(int i = 0; i < my_vec.size(); i++){
    //     my_map[i] = my_vec[i];
    // }

    // for(auto i:my_map){
    //     cout << i.first << " "<<i.second << endl;
    // }
    if(canorcant(my_vec, 12, 0)== true){
        cout << "True" << endl;
    }
    return 0;


}