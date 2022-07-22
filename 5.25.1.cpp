#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


void test(int* b){
    *b = *b + 5;
}

int main(){
    int a = 5;
    int* b = &a;
    cout << *b << endl;
    cout << &b << endl;
    test(&a);
    cout << a << endl;
}