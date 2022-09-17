#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;


class myclass{
    public:
    int vala;
    int valb;
    myclass(int x, int y):vala(x), valb(y){}
    void getval(){
        cout << vala <<" " << valb << endl;
    }
};

int main(){
    myclass obj(5,10);
    obj.getval();

    vector<myclass> my_vec{obj};
    my_vec[0].vala = 2000;
    obj.getval();

    vector<reference_wrapper<myclass>> my_vec_ref{obj};
    my_vec_ref[0].get().vala = 400;
    obj.getval();
    
    return 0;
}