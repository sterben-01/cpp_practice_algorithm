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


class mysort{
    public:
    bool operator()(const pair<char, int>& a, const pair<char,int>& b) const{
        if(a.second > b.second){
            return false;
        }
        return true;
    }
};

void solution(string& text){
    unordered_map<char , int> my_map;
    vector<char> my_vec;
    for(int i = 0; i < text.length(); i++){
        my_map[text[i]]++;
    }
    while(!my_map.empty()){
        auto T = max_element(my_map.begin(), my_map.end(),mysort());
        my_vec.push_back(T->first);
        my_map.erase(T->first);
    }
    int sum = 0;
    int curpos = 0;
    for(int i = 0; i < text.length(); i++){
        for(int j = 0; j < my_vec.size(); j++){
            if(text[i] == my_vec[j]){
                curpos = j;
                break;
            }
        }
        if(curpos >= 0 && curpos <= 8){
            sum = sum + 1;
        }
        else if(curpos >= 9 && curpos <= 17){
            sum = sum + 2;
        }
        else if(curpos >= 18 && curpos <= 25){
            sum = sum + 3;
        }
    }
    cout << sum << endl;

}
int main(){
    string s = "aaaaaaaaa";
    solution(s);
    return 0;
}