#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;




int main(){
    int nums;
    cin >> nums;
    while(nums > 0){
        nums--;
        string mes_count;
        cin >> mes_count;
        int count = stoi(mes_count);
        vector<string> mes_list;
        mes_list.reserve(stoi(mes_count));
        stack<string> mystack;
        while(count > 0){
            string temp;
            cin >> temp;
            mystack.push(temp);
            count --;
        }
        while(!mystack.empty()){
            if(find(mes_list.begin(), mes_list.end(), mystack.top()) != mes_list.end()){
                mystack.pop();
                continue;
            }
            mes_list.push_back(mystack.top());
            mystack.pop();
        }
        string ret;
        for(auto i : mes_list){
            ret = ret + i + " ";
        }
        ret = ret.substr(0, ret.size() - 1);
        cout << ret << endl;
    }
}