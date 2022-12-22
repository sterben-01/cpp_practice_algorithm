#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

class student{
    public:
        student(int x, const string& y):id(x), name(y){};
        int id;
        string name;

        void change_name(const string& s){
            name = s;
        }
};

class mycomp{
    public:
        bool operator()(const student a, const student b) const{
            if(a.id < b.id){
                return true;
            }
            return false;
        }   
};


int main(){

    set<student, mycomp> my_set;
    my_set.insert(student(1,"miku"));
    my_set.insert(student(2,"luka"));
    my_set.insert(student(3,"nozomi"));

    // auto t = my_set.begin();
    // cout << t->name << endl;
    // //const_cast<student&>(*t).change_name("changedmiku");
    // static_cast<student>(*t).change_name("changedmiku");
    // cout << t->name << endl;
    student target(2,"luka"); 
    auto t = my_set.find(target); 
    if(t != my_set.end()){ 
        student temp(*t); 
        temp.change_name("changed_luka"); 
        t = my_set.erase(t); //注意这里
        my_set.insert(t, temp); 
    }
    
    for(auto t:my_set){
        cout << t.name << endl;
    }

    return 0;


}