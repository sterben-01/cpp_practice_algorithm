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
#include <type_traits>
#include <memory>
using namespace std;

class B;

class A{
    public:
        shared_ptr<B> bptr;
        ~A(){
            cout << "A destory" << endl;
            cout << bptr.use_count() << endl;
        }
};

class B{
    public:
        weak_ptr<A> aptr;
        ~B(){
            cout << "B destory" << endl;
            cout << aptr.use_count() << endl;
        }
};

class emptyd{

};

class emptyc : public emptyd{
    int a;
};

int main(){
    {
        // shared_ptr<A> classA(new A());
        // shared_ptr<B> classB(new B());
        // cout << classA.use_count() << endl;         //1
        // cout << classB.use_count() << endl;         //1
        // classA->bptr = classB;
        // cout << classA.use_count() << endl;         //1
        // cout << classB.use_count() << endl;         //2
        // classB->aptr = classA;
        // cout << classA.use_count() << endl;         //1
        // cout << classB.use_count() << endl;         //2
        shared_ptr<emptyc> test(new emptyc());
        weak_ptr<emptyc>(test1);
        emptyc obj;
        cout << sizeof(obj) << endl;

    }
    return 0;
}
