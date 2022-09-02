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

vector<int> solution(vector<int>& locations, vector<int>& movedfrom, vector<int>& movedto){
    set<int> my_set;
    vector<int> ret;
    for(int i = 0; i < locations.size(); i++){
        my_set.insert(locations[i]);
    }
    for(int i = 0; i < movedfrom.size(); i++){
        my_set.erase(movedfrom[i]);
        my_set.insert(movedto[i]);
    }
    for(auto i:my_set){
        ret.push_back(i);
    }

    for(auto i:ret){
        cout << i << endl;
    }
    return ret;
}


int main(){
    vector<int> locations{1,7,6,8};
    vector<int> movedfrom{1,7,2};
    vector<int> movedto{2,9,5};
    solution(locations, movedfrom, movedto);
    return 0;
}