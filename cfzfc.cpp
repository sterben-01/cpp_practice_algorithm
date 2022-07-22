#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <cstring>
#include <typeinfo>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end){
        int left = start;
        int right = end;
        while(left <= right){
            swap(s[left],s[right]);
            left = left + 1;
            right = right - 1;
        }
    }
    void removeExtraSpaces(string& s) {
        int slow = 0;
        int fast = 0;
        if(s.empty()){
            return;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                fast = fast + 1;
            }
            else{
                break;
            }
        }
        if(fast == s.size()-1){
            return;
     }
        // for (; fast < s.size(); fast++) {
        //     // 去掉字符串中间部分的冗余空格
        //     if ( s[fast - 1] == s[fast] && s[fast] == ' ') {
        //         continue;
        //     } 
        //     else {
        //         s[slow] = s[fast];
        //         slow = slow + 1;
        //     }
        // }
        while(fast < s.size()){
            cout << "the first fast" << fast << endl;
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' '){
                fast = fast + 1;
                continue;
            }
            else{
                cout << "the last slow" << slow << endl;
                s[slow] = s[fast];
                slow = slow + 1;
                cout << "the last slow" << slow << endl;
            }
            fast = fast + 1;
        }
        if(s[slow-1] == ' '){
            cout << "slow" <<slow << endl;
            cout << "sadkjashdksjdhs" << endl;
            s.resize(slow-1);
        }
        else{
            cout << "slow" <<slow << endl;
            cout << "bbbbbbbbb" << endl;
            s.resize(slow);
        }
    }
    string reverseWords(string s){
        removeExtraSpaces(s);
        cout << s << endl;
        reverse(s,0,s.length()-1);
        cout << s << endl;
        
        int start = 0;
        int end = 0;
        bool entry = false;
        for(int i = 0; i < s.size(); i++){
            cout << entry << endl;
            if(entry == false){
                start = i;
                entry = true;
                cout<<"start: " << start << endl;
            }
            if(entry == true && s[i] == ' '){
                end = i;
                entry = false;
                reverse(s,start,end-1);
                cout<<"start: " << start << endl;
                cout <<"end" << end << endl;
            }
            if (entry && (i == (s.size() - 1)) && s[i] != ' ' ) {
                end = i;// 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
                cout<<"endif" << endl;
            }
        }
        
        return s;
        
    }

};

int main(){
    // Solution * obj = new Solution();
    // string a = "hello world";
    // string b = obj->reverseWords(a);
    // int a = 5;
    // int* t = new int;
    // t = &a;
    // cout << *t << endl;
    // string test = "might";
    // test[0] = 'n';
    // char* name = "apple";
    // name[0] = 'b';
    // cout << test << endl;
    // cout << name << endl;
    char s[] = "abcedf";
    const char* f = "sasda";
    cout << f << endl;
    s[2] = 'v';
    char* str;
    str = new char[7];
    strcpy(str,s);
    cout << *str << endl;
    str[2] = 'a';
    char rr[6];
    vector<string>aaa(10, string(10,'.'));
    cout << aaa[1] << endl;
    string an = "abcdei";
    // if(an[3] == "d"){
    //     cout << 0 << endl;
    // }
    an.compare("avf");
    string q = "Q";
    int res = an.compare(5,1,q);
    cout << res << endl;
    char dd = 'a';
    char ddd = 'b';
    dd.compare(ddd);

}