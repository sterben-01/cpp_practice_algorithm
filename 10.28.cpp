#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
using namespace std;
void func(int* a){
    cout << &a << endl;
    cout << a << endl;
}

int main(){
    int* ptr = new int(5);
    cout << &ptr <<endl;
    cout << ptr << endl;
    func(ptr);
}
