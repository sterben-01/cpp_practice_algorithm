#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
using namespace std;

class test{
    public:
    class testinner{
        public:
        int _val;
        testinner(){
            cout << "inner constructor" << endl;
        }
        testinner(int x):_val(x){}
    };
    testinner b;
    test(){
        cout <<"outer constructor" << endl;
    }
    typedef int testdef;


    int s;
};

int main()
{
    // test::testinner tt1 = test::testinner(5); //OK
    // test::testinner tt2; //OK
    // test::testdef tt3 = 5; //OK
    // test::s;
    // test t;
    // t.test::s = 5; //non static member ERROR

    test a;

    return 0;
}