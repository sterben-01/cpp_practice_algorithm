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
using namespace std;


// template <int size, bool judge>
// class myobj{
//     public:
//     myobj(){
//         my_vec.reserve(size);
//         testfunc();
//     };
//     void testfunc(){
//         cout << my_vec.capacity() << endl;
//         if(judge == true){
//             cout << "true" << endl;
//         }
//         else{
//             cout << "false" << endl;
//         }    
//     }
//     vector<int> my_vec;
// };

template <typename T, typename T1>
T func(){
    // cout << size << endl;
    // if(judge == true){
    //     cout << "true" << endl;
    // }
    // else{
    //     cout << "false" << endl;
    // }
    T a;
    cout <<"void" << endl;
}
T1 func(){
    cout <<"int" << endl;
    return 0;
}
// int funcaa(int a){
//     cout << "funcaa" << endl; 
//     return 0;
// }
// int *p(int){
//     cout << "func" << endl;
// }

// class myobj{
//     public:
//         // void func(int a, int b){
//         //     cout << "normal func" << endl;
//         // }
//         void func(int a, int b) &{
//             cout << "non const lref func" << endl;
//         }
//         void func(int a, int b) const &{
//             cout << "const lref func" << endl;
//         }
//         void func(int a, int b) &&{
//             cout << "non const rref func" << endl;
//         }
//         void func(int a, int b) const &&{
//             cout << "const rref func" << endl;
//         }
// };

int main(){
    // myobj<int,8> instance(10);
    // cout << instance.my_vec.capacity() << endl;
    // func<10, sizeof(int) == 4>();
    // func<10, (sizeof(int) > 4 )>();
    // myobj<10, sizeof(int) == 4> instance;
    // myobj<10, (sizeof(int) > 4 )> instance1;
    // vector<int> as;
    // int s = 10;
    // as.push_back(s);
    // s = 200;
    // cout << as[0] << endl;
    // int a[20];
    // int p = 200;
    // a[0] = p;
    // cout << a[0] << endl;
    // p = 400;
    // cout << a[0] << endl;
    // int *p(int);
    // int (*p)(int)
    //p(10);
    func<int, double>();
    func<int, double>();
    return 0;
}