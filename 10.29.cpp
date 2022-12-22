#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> vec;

void func(int& a){
    vec.push_back(a);
}

int main(){
    int num = 100;
    func(num);
    cout << vec[0] << endl;
    num = 20;
    cout << vec[0] << endl;

}