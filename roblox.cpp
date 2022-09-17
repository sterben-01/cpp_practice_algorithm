#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
using namespace std;


int solution(vector<string> pricelist, vector<string> logs) {
    unordered_map<string, int>my_price;
    unordered_map<string, int> dis_price;
    unordered_map<string, int> dis_count;
    for(int i = 0; i < pricelist.size(); i++){
        int pos = pricelist[i].find(":");
        if(pos != pricelist[i].npos){
            string s = pricelist[i].substr(0, pos);
            int t = stoi(pricelist[i].substr(pos+2, pricelist[i].size() - pos+1));
            my_price.insert(make_pair(s,t));
            dis_count.insert(make_pair(s,0));
            dis_price.insert(make_pair(s,0));
        }
    }
    int accumu = 0;
    for(int i = 0; i < logs.size(); i++){
        int pos = logs[i].find(" ");
        
        string action;
        string other;
        string name;
        int amount;
        int disamount;
        string other2;
        if(pos != logs[i].npos){
            action = logs[i].substr(0, pos);
            other = logs[i].substr(pos+2,  logs[i].size() - pos+1);
        }
        int pos = other.find(",");
        if(pos != other.npos){
            name = other.substr(0, pos); //name
            other2 = other.substr(pos+2,  other.size() - pos+1);
        } 
        if(action == "sell"){
            amount = stoi(other2); //数量
            int temp = amount * my_price[name];
            if(amount > dis_count[name]){
                temp = temp - dis_count[name] * dis_price[name];
                accumu += temp;
                dis_count[name] = 0;
            }
            else{
                temp = temp - amount * dis_price[name];
                accumu += temp;
                dis_count[name] = dis_count[name] - amount;
            }

        }
        else if(action == "discount_start"){
            int pos = other2.find(",");
            if(pos != other.npos){
                amount = stoi(other2.substr(0, pos)); //卖出数量
                disamount = stoi(other2.substr(pos+2,  other2.size() - pos+1)); //打折数量
            }
            dis_count[name] = disamount;
            dis_price[name] = amount;
            
        }   
        else if(action == "discount_end"){
            dis_count[name] = 0;
            dis_price[name] = 0;
        }
    }
    return accumu;
}

int main(){
    string s = "item1wwewewe2: 20000001";
    int pos = s.find(":");
    string ss = s.substr(0, pos);
    string tt = s.substr(pos+2, s.size()-pos+1);
    cout << ss << endl;
    cout << tt << endl;
    return 0;
}