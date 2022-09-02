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

using namespace std;






void solution(string& str1, string& target){
    int strindex = 0;
    int targetindex = 0;
    while(strindex < str1.length() && targetindex < target.length()){
        if(str1[strindex] != target[targetindex]){
            strindex++;
        }
        else if(str1[strindex] == target[targetindex]){
            strindex++;
            targetindex++;
        }
    }
    int res = target.size() - targetindex;
    cout << res << endl;
}

int main(){
    string s1 = "aarmaze";
    string s2 = "amazon";
    solution(s1, s2);
    return 0;
}