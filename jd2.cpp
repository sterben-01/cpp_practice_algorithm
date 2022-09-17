#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;


int process(int num){
    int count = 0;
    while(num > 1){
        if(num%2 == 0){
            if(num == 2){
                count++;
                num = num /2;
            }
            else{
                num = num / 2;
                count = count + 2;
            }
        }
        else if(num%2 != 0){
            num = num - 1;
            count++;
            num = num / 2;
            count = count + 2;
        }
    }
    //cout << count << endl;
    return count;
}
int main(){
    int count;
    cin >> count;
    vector<int> my_vec;
    for(int i = 0; i < count; i++){
        int temp;
        cin >> temp;
        my_vec.push_back(temp);
    }

    //vector<int> my_vec{2,6};
    int ret = 0;
    for(int i = 0; i < my_vec.size(); i++){
        ret = ret + process(my_vec[i]);
    }
    cout << ret << endl;

    return 0;
}