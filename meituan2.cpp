#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include<stack>
#include <queue>
using namespace std;





int main() {
    int original_length;
    cin >> original_length;
    int target_length;
    cin >> target_length;
    string original;
    cin >> original;
    string target;
    cin >> target;


    // int original_length = 7;
    // int target_length = 3;
    // string original = "bccccac";
    // string target = "*cc";



    int count = 0;
    for (int i = 0; i < original_length; i++) {

        int st = 0;
        int ot = i;
        bool match = false;
        while (st < target_length) {
            if (original[ot] == target[st]) {
                st++;
                ot++;
            }
            else if (original[ot] != target[st] && target[st] != '*') {
                match = false;
                break;
             
            }
            else if (original[ot] != target[st] && target[st] == '*') {
                ot++;
                st++;
            }
            match = true;
        }
        if (match == true) {
            count++;
        }
    }
    cout << count << endl;

}
