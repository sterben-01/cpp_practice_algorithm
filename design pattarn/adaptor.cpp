#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;


class target{
    public:
        target(){}
        virtual ~target(){}
        virtual void pathPlanning() = 0;
};

class parser{
    public:
        parser(){}
        ~parser(){}
        void parsePath(){
            printf("Path Parsing...\n");
        }
};

class planner{
    public:
        planner(){}
        ~planner(){}
        void planPath(){
            printf("Path Planning...\n");
        }
};

class Adapter: public target{
    public:
        Adapter(){
            parse = new parser;
            plan = new planner;
        }
        ~Adapter(){
            delete parse;
            delete plan;
        }

        Adapter(const Adapter&) = delete;
        Adapter& operator=(const Adapter&) = delete;

        void pathPlanning(){
            parse->parsePath();
            plan->planPath();
            printf("Plan success..\n");
        }



    private:
        parser* parse;
        planner* plan;
};

int main(){
    target* usercall = new Adapter();
    usercall->pathPlanning();
}