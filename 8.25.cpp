
#include<iostream>
using namespace std;



class A {
    int a;
};

class B: public A {
    
};

class C: public  B {

};
class D: public  B,  C {

};
int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    return 0;
}
