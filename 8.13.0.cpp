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
#include <limits.h>
using namespace std;


int main(){

    int num;
    cin >> num;
    vector<int> items;
    for(int i = 0; i < num; i++){
        int temp;
        cin >> temp;
        items.push_back(temp);
    }
    int magicnum = 0;
    int magiccount = 0;
    for(int i = 1; i <=300; i++){
        vector<int> getencode(items);
        sort(getencode.begin(), getencode.end(), greater<int>());
        if(getencode[0] - i <= 90 && getencode[0] - i >= 65){
            if(getencode[getencode.size()-1] - i == 32){
                while(getencode[getencode.size()-1] - i == 32){
                    getencode.pop_back();
                }
                if(!getencode.empty() && getencode[getencode.size()-1] - i <= 90 && getencode[getencode.size()-1] - i >= 65){
                    magiccount++;
                    magicnum = i;
                }
            }
            else{
                if(getencode[getencode.size()-1] - i <= 90 && getencode[getencode.size()-1] - i >= 65){
                    magiccount++;
                    magicnum = i;
                }
            }

        }      
    }
    if(magiccount == 1){
        string s;
        for(int i = 0; i < items.size(); i++){
            s = s+(char)(items[i] - magicnum);
        }
        cout << s << endl;
    }
    else if(magiccount > 1){
        cout << magiccount << endl;
    }
    return 0;
}
