#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){


    int x = 3;
    switch(x){
        case 1:
            cout << "case1" << endl;
        case 3:
            x = 3+2;
            cout << "case3" << endl;
        case 4:
            cout << "case4" << endl;
        case 5:
            cout << "case 5" << endl;
        case 0:
            cout << "case 0" << endl;
        default:
            x = x + 5;

    }
    cout << x <<endl;
    return 0;
}