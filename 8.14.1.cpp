//#include <iostream>
//#include <string>
//#include <memory>
//#include <queue>
//#include <vector>
//#include <functional>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <map>
//#include <stack>
//#include <limits.h>
//using namespace std;
//
//
//void color_converter(string& S, string& convert) {
//    string s;
//    s.push_back(S[1]);
//    if (s == "R") {
//        convert = "FF0000";
//    }
//    else if (s == "G") {
//        convert = "00C932";
//    }
//    else if (s == "B") {
//        convert = "0000FF";
//    }
//    else if (s == "K") {
//        convert = "000000";
//    }
//    else if (s == "Y") {
//        convert = "FFFF00";
//    }
//    else if (s == "W") {
//        convert = "FFFFFF";
//    }
//    else if (s == "P") {
//        convert = "FF88FF";
//    }
//    else if (s == "C") {
//        convert = S.substr(2, 6);
//    }
//}
//
//
//bool is_valid(int pos, int length) {
//    return pos < length;
//}
//bool is_inrange(const string& s) {
//    for (int i = 2; i < s.size(); i++) {
//        if (s[i] >= '0' && s[i] <= '9') {
//            return true;
//        }
//        else {
//            if (s[i] >= 'A' && s[i] <= 'F') {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//bool is_color(string& s) {
//    bool temp = is_inrange(s);
//    if (temp == true) {
//        return true;
//    }
//    if (temp == false) {
//        if (s == "#R" || s == "#G" || s == "#B" || s == "#K" || s == "#Y" || s == "#W" || s == "#P") {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//}
//
//bool check_res(stack<string>& my_stack, vector<string>& tempvec) {
//    if (!my_stack.empty()) {
//        if (my_stack.top() == "#n") {
//            my_stack.pop();
//            while (!my_stack.empty() && !is_color(my_stack.top())) {
//                tempvec.push_back(my_stack.top());
//                my_stack.pop();
//            }
//            if (!my_stack.empty()) {
//                if (is_color(my_stack.top())) {
//                    tempvec.push_back(my_stack.top());
//                    my_stack.pop();
//                }
//            }
//        }
//    }
//    if (!tempvec.empty()) {
//        return true;
//    }
//    return false;
//}
//
//
//
//
//int main() {
//    //string group;
//    //getline(cin, group);
//    //int g = stoi(group);
//    int g  = 1;
//    for (int i = 0; i < g; i++) {
//        string text = "#Ppan gu#n you fu, kai tian pi di, li jie er wang.#C52BE80#CE74C3Cqing qi#n sheng, wei tian; #C2E86C1zhuo qi#n jiang, wei di#n; yuan qi yan sheng chu wan wu, cui fa sheng ji; mo qi yan sheng chu si wang duo luo, mi luan hui mie.yu zhou wan wu, you zheng, ze bi you fan.";
//        //string text;
//        //getline(cin, text);
//        stack<string> my_stack;
//        vector<vector<string>> ret;
//        int text_length = text.length();
//        for (int j = 0; j < text.length();) {
//            vector<string> each_round;
//            if (text[j] == '#') {
//                if (is_valid(j + 1, text_length)) {
//                    if (text[j + 1] == 'R' || text[j + 1] == 'G' || text[j + 1] == 'B' || text[j + 1] == 'K' || text[j + 1] == 'Y' || text[j + 1] == 'W' || text[j + 1] == 'P') {
//                        string myfuck = "#";
//                        myfuck.push_back(text[j + 1]);
//                        my_stack.push(myfuck);
//                        j = j + 2;
//                    }
//                    else if (text[j + 1] == 'C') {
//                        if (is_valid(j + 7, text_length)) {
//                            if (is_inrange(text.substr(j, 8))) { //带#
//                                my_stack.push(text.substr(j, 8));
//                                j = j + 8;
//                            }
//                            else {
//                                int endindex = 1;
//                                while (text[endindex] != '#') {
//                                    endindex++;
//                                }
//                                my_stack.push(text.substr(j, endindex - j));
//                                j = j + endindex;
//                            }
//                        }
//                        else {
//                            j = j + 7;
//                        }
//
//                    }
//                    else if (text[j + 1] == 'n') {
//                        my_stack.push("#n");
//                        if (check_res(my_stack, each_round)) {
//                            ret.push_back(each_round);
//                        }
//                        j = j + 2;
//                    }
//                }
//                else {
//                    j = j + 1;
//                }
//            }
//            else {
//                int endindex = j;
//                while ( endindex < text.length() && text[endindex] != '#') {
//                    endindex++;
//                }
//                my_stack.push(text.substr(j, endindex - j));
//                j = endindex;
//            }
//        }
//        if (ret.empty()) {
//            cout << "empty" << endl;
//        }
//        for (int i = 0; i < ret.size(); i++) {
//            vector<string> ec = ret[i];
//            if (ec.size() > 2) {
//                for (int i = ec.size() - 2; i >= 0; i--) {
//                    string p;
//                    color_converter(ec[ec.size() - 1], p);
//                    cout << ec[i] <<" " << p << endl;
//                }
//            }
//            else {
//                for (int i = ec.size() - 2; i >= 0; i--) {
//                    string p;
//                    color_converter(ec[ec.size() - 1], p);
//                    cout << ec[i] << " " << p;
//                }
//                //for (int i = 0; i < ec.size(); i++) {
//                //    cout << ec[i] <<" ";
//                //}
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <map>
#include <stack>
#include <limits.h>
using namespace std;


void color_converter(string& S, string& convert) {
    string s;
    s.push_back(S[1]);
    if (s == "R") {
        convert = "FF0000";
    }
    else if (s == "G") {
        convert = "00C932";
    }
    else if (s == "B") {
        convert = "0000FF";
    }
    else if (s == "K") {
        convert = "000000";
    }
    else if (s == "Y") {
        convert = "FFFF00";
    }
    else if (s == "W") {
        convert = "FFFFFF";
    }
    else if (s == "P") {
        convert = "FF88FF";
    }
    else if (s == "C") {
        convert = S.substr(2, 6);
    }
}


bool is_valid(int pos, int length) {
    return pos < length;
}
bool is_inrange(const string& s) {
    for (int i = 2; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            return true;
        }
        else {
            if (s[i] >= 'A' && s[i] <= 'F') {
                return true;
            }
        }
    }
    return false;
}
bool is_color(string& s) {
    bool temp = is_inrange(s);
    if (temp == true) {
        return true;
    }
    if (temp == false) {
        if (s == "#R" || s == "#G" || s == "#B" || s == "#K" || s == "#Y" || s == "#W" || s == "#P") {
            return true;
        }
        else {
            return false;
        }
    }
}

bool check_res(stack<string>& my_stack, vector<string>& tempvec) {
    if (!my_stack.empty()) {
        if (my_stack.top() == "#n") {
            my_stack.pop();
            while (!my_stack.empty() && !is_color(my_stack.top())) {
                tempvec.push_back(my_stack.top());
                my_stack.pop();
            }
            if (!my_stack.empty()) {
                if (is_color(my_stack.top())) {
                    tempvec.push_back(my_stack.top());
                    my_stack.pop();
                }
            }
        }
    }
    if (!tempvec.empty()) {
        return true;
    }
    return false;
}




int main() {
    //string group;
    //getline(cin, group);
    //int g = stoi(group);
    int g = 1;
    for (int i = 0; i < g; i++) {
        string text = "#Ppan gu#n you fu, kai tian pi di, li jie er wang.#C52BE80#CE74C3Cqing qi#n sheng, wei tian; #C2E86C1zhuo qi#n jiang, wei di#n; yuan qi yan sheng chu wan wu, cui fa sheng ji; mo qi yan sheng chu si wang duo luo, mi luan hui mie.yu zhou wan wu, you zheng, ze bi you fan.";
        //string text;
        //getline(cin, text);
        stack<string> my_stack;
        vector<vector<string>> ret;
        int text_length = text.length();
        for (int j = 0; j < text.length();) {
            vector<string> each_round;
            if (text[j] == '#') {
                if (is_valid(j + 1, text_length)) {
                    if (text[j + 1] == 'R' || text[j + 1] == 'G' || text[j + 1] == 'B' || text[j + 1] == 'K' || text[j + 1] == 'Y' || text[j + 1] == 'W' || text[j + 1] == 'P') {
                        string myfuck = "#";
                        myfuck.push_back(text[j + 1]);
                        my_stack.push(myfuck);
                        j = j + 2;
                    }
                    else if (text[j + 1] == 'C') {
                        if (is_valid(j + 7, text_length)) {
                            if (is_inrange(text.substr(j, 8))) { //带#
                                if (!is_color(my_stack.top())) {
                                    each_round.push_back(my_stack.top());
                                    my_stack.pop();
                                    if (!my_stack.empty() && is_color(my_stack.top())) {
                                        each_round.push_back(my_stack.top());
                                        ret.push_back(each_round);
                                    }
                                }
                                my_stack.push(text.substr(j, 8));
                                j = j + 8;
                            }
                            else {
                                int endindex = 1;
                                while (text[endindex] != '#') {
                                    endindex++;
                                }
                                my_stack.push(text.substr(j, endindex - j));
                                j = j + endindex;
                            }
                        }
                        else {
                            j = j + 7;
                        }

                    }
                    else if (text[j + 1] == 'n') {
                        my_stack.push("#n");
                        if (check_res(my_stack, each_round)) {
                            ret.push_back(each_round);
                        }
                        j = j + 2;
                    }
                }
                else {
                    j = j + 1;
                }
            }
            else {
                int endindex = j;
                while (endindex < text.length() && text[endindex] != '#') {
                    endindex++;
                }
                my_stack.push(text.substr(j, endindex - j));
                j = endindex;
            }
        }
        if (ret.empty()) {
            cout << "empty" << endl;
        }
        for (int i = 0; i < ret.size(); i++) {
            vector<string> ec = ret[i];
            if (ec.size() > 2) {
                for (int i = ec.size() - 2; i >= 0; i--) {
                    string p;
                    color_converter(ec[ec.size() - 1], p);
                    cout << ec[i] << " " << p << endl;
                }
            }
            else {
                for (int i = ec.size() - 2; i >= 0; i--) {
                    string p;
                    color_converter(ec[ec.size() - 1], p);
                    cout << ec[i] << " " << p;
                }
                //for (int i = 0; i < ec.size(); i++) {
                //    cout << ec[i] <<" ";
                //}
            }
            cout << endl;
        }
    }
    return 0;
}