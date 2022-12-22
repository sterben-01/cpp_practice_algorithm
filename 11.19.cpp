#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <unordered_map>
using namespace std;




bool func(string& pattern, string& content){
    vector<string> item;
    stringstream ss(content); //字符串放入stringstream对象
    string temp; //储存临时分割对象
    while(ss >> temp){ //直到字符耗尽
        item.emplace_back(temp); //放入结果数组。
    }
    if(pattern.size() != item.size()){
        return false;
    }
    unordered_map<string, int> mappings; //用来储存字符串对应在哪个桶
    vector<string> slots(26, ""); //26个桶，储存的是每一个如a b c d这样的字符对应的字符串
    for(int i = 0; i < pattern.size(); i++){
        if(slots[pattern[i] - 'a'] == ""){ //如果桶内没有字符，也就是一个新的字符
            if(mappings.find(item[i]) == mappings.end()){//先看当前这个字符串有没有放入过其他的桶
                slots[pattern[i] - 'a'] = item[i]; //如果没有放入过其他的桶就放入当前桶
                mappings.insert({item[i], pattern[i] - 'a'}); //在记录中登记当前字符串放入过这个桶
            }
            else{ //如果发现这个字符串放入过其他的桶
                if(mappings[item[i]] != i){ //查看这个字符串放入过的桶是不是当前这个桶
                    cout <<"false in checking" << endl; //如果不是证明冲突，比如a b 对应 dog dog
                    return false;
                }
                else{ //如果是当前桶，则下一轮。
                    continue;
                }
            }
        }
        else{ //如果桶内有字符
            if(slots[pattern[i] - 'a'] == item[i]){ //查看当前的桶内字符串和当前字符串是否匹配
                continue; //如果匹配，下一轮
            }
            else{
                cout << "false" << endl; //不匹配，退出。如 a b a b 对应dog cat cat dog
                return false;
            }
        }
    }
    cout <<"true" << endl;
    return true;
}




int main(){

    string t = "dog dog dog dog";
    string c = "abba";
    func(c,t);
    return 0;

}