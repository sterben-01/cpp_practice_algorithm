#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class fuck{
public:
    int val;
    fuck():val(0){}
    fuck(int x):val(x){} 
    void print3(fuck x){
        cout << x.val << endl;
    }
    static int tete; 

};
int fuck::tete = 5;


// int main(){
//     fuck* obj = new fuck();
//     fuck* sss = new fuck(4);
//     obj->print3(*sss); //sss是指针，必须要解引用才能传进去 因为传入参数是个fuck
//     fuck c = fuck(5); //可以直接等于
//     obj->print3(c);
// }
void demo() 
{ 
	// static variable 
	static int count = 0; 
	cout << count << " "; 
	
	// value is updated and 
	// will be carried to next 
	// function calls 
	count++; 
} 

int main() 
{ 
	for (int i=0; i<5; i++)	 
		demo(); 
	return 0; 
} 