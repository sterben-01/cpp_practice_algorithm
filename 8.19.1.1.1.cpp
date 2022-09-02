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




int main(){

    vector<int> a{2,8,7,6,5,1,2,3,4};
    sort(a.begin(), a.end(), greater<int>());
    for(auto i:a){
        cout << i << endl;
    }

}