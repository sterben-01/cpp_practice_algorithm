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
#include <stdarg.h>
using namespace std;

//&反射

typedef void* (*create_fun)();
typedef void* (*fuck_fun)(int);

class ClassFactory{
    public:
        ~ClassFactory() {}; 

        
        void registClass(std::string name, void*(*fun)()){
            my_map[name] = fun;
        }
        void registFuckClass(std::string name, void*(*fuck_fun)(int)){
            myFuck_map[name] = fuck_fun;
        }   

        //根据类注册时的名字, 创建类实例, 并返回
        void* getClassByName(std::string name){
            std::map<std::string, create_fun>::iterator it = my_map.find(name);
            if (it == my_map.end()) { 
                //没找到
                return NULL; 
            }
            //找到了返回类实例
            create_fun fun = it->second;
            if (!fun) { 
                return NULL; 
            }
            return fun(); 
        }   
        //根据类注册时的名字, 创建类实例, 并返回
        void* getClassByFuckName(std::string name, int a){
            std::map<std::string, fuck_fun>::iterator it = myFuck_map.find(name);
            if (it == myFuck_map.end()) { 
                //没找到
                return NULL; 
            }
            //找到了返回类实例
            //!这个返回的是类的实例。其实就是函数调用了。
            fuck_fun fun = it->second;
            if (!fun) { 
                return NULL; 
            }
            void* s = fun(a);
            return s;
        }   


        //单例模式
        static ClassFactory& getInstance(){
            static ClassFactory fac;
            return fac;
        }   

    private:
        ClassFactory() {};  //私有
        std::map<std::string, create_fun> my_map;
        std::map<std::string, fuck_fun> myFuck_map;
}; 


class Test{
public:
    Test(){ std::cout << "call Test Constructor fun" << std::endl; }
    ~Test(){ std::cout << "call Test Destructor fun" << std::endl; }     
    void print(){ std::cout << "call Test print fun" << std::endl; }
};

void* create_Test(){
    Test *t = new Test;
    return (t == NULL)? NULL:t;
}

class Fuck{
    public:
        int val;
        Fuck(){
            cout <<" fuck created" << endl;
        }
        Fuck(int x):val(x){
            cout << "fuck with num" << x << " created" << endl;
        }
        void getval(){
            cout <<"FFFval " << val << endl;
        }
        
    
};


void* create_fuck(int a){
    Fuck* f = new Fuck(a);
    return (f == NULL)? NULL:f;
}



int main(){

    ClassFactory::getInstance().registClass("Test", create_Test);
    Test *t = (Test*)ClassFactory::getInstance().getClassByName("Test");
    if (!t){
        std::cout << "get instnce Test err;" << std::endl;
        return 1;
    }   
    t->print();
    delete t;



    ClassFactory::getInstance().registFuckClass("Fuck", create_fuck);
    Fuck* f = (Fuck*)ClassFactory::getInstance().getClassByFuckName("Fuck", 6);
    if(!f){
        cout << "get fuck err" << endl;
        return 0;
    }
    f->getval();
    delete f;

    function<void*(int)> fc  = create_fuck;

    Fuck* ff =(Fuck*) fc(3);
    ff->getval();
    delete ff;


    return 0;
}