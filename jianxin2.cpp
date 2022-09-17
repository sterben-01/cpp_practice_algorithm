#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


int main(){
    vector<int> vec{ 239,191,239,254,127,128 };
    auto t = vec.begin();
    for(; t!= vec.end()-1; t++){
        cout << *t << endl;
    }
    return 0;
}