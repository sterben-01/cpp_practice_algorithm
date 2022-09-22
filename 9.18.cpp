#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;



class myclass{
    public:
    int val;
    myclass(int x):val(x){};
    ~myclass(){
        val = 8964;
    }
};
void func(int a){
    cout << a << endl;
    a++;
}
int main() {
    vector<myclass> myvec{ 0,1,2,3,4,5,6 };
    // for(auto iter = myvec.begin(); iter < myvec.end(); iter++){
    //     //cout << (*iter).val << endl;
    //     myvec.erase(iter);
    // }
    // for(auto i:myvec){
    //     cout << i.val << endl;
    // }
    int a = 10;
    cout << a << endl;
    func(a);
    func(a);
    printf("fuck you\n");
    //for (int i = 0; i < myvec.size(); i++) {
    //    if (myvec[i] == 3) {
    //        myvec.erase(myvec.begin() + i);
    //    }

    //    cout << myvec[i] << endl; //注意在erase后面
    //}
    //输出0 1 2 4 5 6
    return 0;

}

