#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;






int main(){
    vector<int> myvec{0,1,2,3,4,5,6};
    for(int i = 0; i < myvec.size(); i++){
        if(myvec[i] == 3){
            myvec.erase(myvec.begin()+i);
        }
        cout << myvec[i] << endl;
    }
    cout << *myvec.begin() + 6 << endl;

}