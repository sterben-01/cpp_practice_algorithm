#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
#include <map>
#include <unordered_map>
#include <future>
#include <list>
#include <atomic>
using namespace std;

class person{
    public:
    string name;
    int age;
    person() = default;
    person(const string& a, int b): name(move(a)), age(b){
        cout <<"person" << endl;
    };

};

class student: public person{
    public:
    int student_id;
    string school_name;
    student(const string& a, int b, const string& c, int d): person(move(a), b), school_name(move(c)), student_id(d){
        cout <<"student" << endl;
    };

};

class containS{
    public:
    person p;
    int st_id;
    string sc_name;
    containS() = default;
    containS(const string& a, int b, const string& c, int d): p(move(a), b), sc_name(move(c)), st_id(d){
        cout <<"containS" << endl;
    };
};

int a;
int b;
int c;
void func(){
    int d;
    int e;
    int f;
    e++;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
}

void func1() 
{ 
    printf("The process is done...\n"); 
} 
void func2() 
{ 
    printf("Clean up the processing\n"); 
} 
void func3() 
{ 
    printf("Exit sucessful..\n"); 
} 

int main(){
    // student a("miku", 17, "highschool", 39);
    // containS a("miku", 17, "highschool", 39);
    // cout << a.st_id << endl;
    // cout << a.sc_name << endl;
    // cout << a.p.age <<endl;
    // cout << a.p.name << endl;
    // int x;
    // int y;
    // int z;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // func();
    // cout << x << endl;
    // cout << y << endl;
    // cout << z << endl;
    atexit(func1);
    atexit(func2);
    atexit(func3);
    exit(0);
}