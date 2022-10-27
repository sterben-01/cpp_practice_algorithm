#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;


void process(vector<vector<string>>& input){
    unordered_map<string, pair<string, string>> my_map;
    for(int i = 0; i < input.size(); i++){
        my_map[input[i][1]] = {input[i][2], input[i][0]};
    }



}



int main(){
    vector<vector<string>> input{{"1","left","red"}, {"2","right","red"},{"3","left","blue"},{"4","right","blue"},{"5","left","yellow"}};

    return 0;
}

