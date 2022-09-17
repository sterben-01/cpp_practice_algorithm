#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class OS{
    public:
        ~OS(){printf("OS closing..\n");}
        void boot(){
            printf("OS booting..\n");
        }
};

class CPU{
    public:
        ~CPU(){printf("CPU stopping..\n");}
        void start(){
            printf("CPU starting..\n");
        }
};

class GPU{
    public:
        ~GPU(){printf("GPU unloaded..\n");}
        void load(){
            printf("GPU loaded..\n");
        }
};

class Memory{
    public:
        ~Memory(){printf("Memory deactivated..\n");}
        void activate(){
            printf("Memory activated..\n");
        }

};


class facade{
    public:
    facade(){
        printf("computer booting..\n");
        memory = new Memory();
        os = new OS();
        gpu = new GPU();
        cpu = new CPU();
    }
    ~facade(){
        delete memory;
        delete os;
        delete gpu;
        delete cpu;
        printf("computer shutdown..\n");
    }

    facade(const facade&) = delete;
    facade& operator= (const facade&) = delete;
    
    void boot(){
        os->boot();
        memory->activate();
        cpu->start();
        gpu->load();
    }


    private:
        Memory* memory;
        OS* os;
        CPU* cpu;
        GPU* gpu;


};

int main(){

    facade* controller = new facade();
    controller->boot();
    delete controller;

    return 0;
}