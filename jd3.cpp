#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;



long long check(string& s, long long left, long long  right){
    long long count = 0;
    long long ind = 0;
    for(long long i = left; i<=right; i++){
        if(s[i] == '('){
            ind++;
        }
        else if(ind > 0){
            ind--;
            count++;
        }
    }
    return count*2;
}

int main(){
    string s;
    cin >> s;
    long long count = 0;
    for(long long i = 0; i < s.size(); i++){
        for(long long k = i+1; k < s.size(); k++){
            count = count + check(s, i, k);
        }
    }
    cout << count << endl;
    return 0;

}