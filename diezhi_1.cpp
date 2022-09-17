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
#include <set>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param originalStr string字符串 原始字符串
     * @return string字符串
     */
    string ConvertString(string originalStr) {
        // write code here
        int ind = 0;
        string ret;
        while(ind < originalStr.size()){
            if(originalStr[ind] == '('){
                ret = ret.append(originalStr.substr(ind,1));
                ind++;
                while(originalStr[ind] != ')'){
                    ind++;
                }
                ret = ret + "*";
                ret = ret.append(originalStr.substr(ind,1));
                ind++;
            }
            else{
                ret = ret.append(originalStr.substr(ind,1));
                ind++;
            }
        }
        cout << ret << endl;
        return ret;
        
        
        
    }
};


int main(){
    Solution s;
    string ss = "Nikki (happy) new (year)";
    s.ConvertString(ss);
    return 0;
}