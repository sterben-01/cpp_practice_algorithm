#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <future>
#include <algorithm>
#include <stack>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;


bool is_three(string& s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum = sum + (s[i]-'0');
    }
    if((sum / 3) == 0){
        return true;
    }
    return false;
}

int my_sum(string& s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'x'){
            continue;
        }
        else{
            sum = sum + (s[i]-'0');
        }
    }
    return sum;
}


//3x2x5;
string func(string s){
    int pos = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'x'){
            pos = i;
            break;
        }
    }
    for(int i = 1; i < s.size()-1; i++){
        if(i != pos){
            if(s[i] == 'x'){
                if(s[i-1]-'0' + s[i+1]-'0' == 1){
                    s[i] = '2';
                }
                else if(s[i-1] == '0' || s[i+1] == '0'){
                    s[i] = '1';
                }
                else{
                    s[i] = '0';
                }
            }  
        }
        else{
            int need = (3 - (my_sum(s)%3)) % 3;
            if(s[i-1]-'0' != need && s[i+1]-'0' != need){
                s[i] = static_cast<char>('0' + need);
            }
            else if(s[i-1]-'0' != need + 3 && s[i+1]-'0' != need+3){
                s[i] = static_cast<char>('0' + need + 3);
            }
            else{
                s[i] = static_cast<char>('0' + need + 6);
            }
        }
    }
    cout << s << endl;
    return s;
}

int main(){
    string s = "3xxx5";
    string input = '9' + s + '9';
    func(input);


    return 0;
}