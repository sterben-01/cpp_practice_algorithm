#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class mycomp{
    public:
        bool operator()(const string& str1, const string& str2) const{
            int index1 = str1.find(' ');
            int index2 = str2.find(' ');
            if(str1.substr(index1) != str2.substr(index2)){
                return str1.substr(index1) < str2.substr(index2);
            }
            return str1 < str2;
            
        }
};



class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        if(logs.size() <= 1){
            return logs;
        }
        vector<string> wordlog;
        vector<string> numlog;
        for(int i = 0; i < logs.size(); i++) {
            int index = logs[i].find(' ');
            /* 现将字母日志和数字日志分开排好序 */
            if(logs[i][index+ 1] >= '0' && logs[i][index + 1] <= '9') 
                numlog.push_back(logs[i]);
            else 
                wordlog.push_back(logs[i]);
        }
        /* 利用自定义排序规则排序 */
        sort(wordlog.begin(), wordlog.end(), mycomp());
        /* 最后将数字日志在不改变原有顺序的情况下直接插入到后面即可 */
        numlog.insert(numlog.end(), wordlog.begin(), wordlog.end());
        return numlog;
    }
};
