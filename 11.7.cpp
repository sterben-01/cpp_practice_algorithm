#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include<memory>
using namespace std;




class obj{
    public:
    int val;
    obj(int x):val(x){};

    void objfunc(){
        cout <<"obj" << endl;
    }
    void getval(){
        cout << val << endl;
    }
};
class objhelper{
    public:
    objhelper(){
        objptr = new obj(10);
    }
    obj* operator->(){
        return objptr;
    }

    obj operator*(){
        return *objptr;
    }

    const obj operator*() const{
        return *objptr;
    }

    ~objhelper(){
        delete objptr;
    }
    obj* objptr;

    
};
int main(){

    objhelper helper;
    helper->objfunc();
    helper->getval();
    helper->val;
    cout << (*helper).val << endl;
    auto s = (*helper).val;
    s = 2000;
    cout << (*helper).val << endl;
    return 0;
}
