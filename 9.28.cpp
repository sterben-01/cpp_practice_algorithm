#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <bitset>
#include <stack>
using namespace std;
int solution(vector<int> numbers) {
    int count = 0;
    unordered_set<int> nums;
    for(int i = 0; i <= 201; i++){
        nums.insert(i*i);
    }
    unordered_map<int, int> my_map;
    for(int i = 0; i < numbers.size(); i++){
        for(auto t = nums.begin(); t != nums.end(); t++){
            int diff = *t - numbers[i];
            if(my_map.find(diff) != my_map.end()){
                count++;
            }
            else{
                my_map[numbers[i]] = i;
            }
        }
    }
    cout << count << endl;
    return count;
}

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> a(num1);
        bitset<32> b(num2);
        int aone = a.count();
        int bone = b.count();
        int ans = 0;
        int ret = 0;
        if (aone == bone){
            return num1;
        }
        if(aone > bone){
            ret = aone - bone;
            for(int i = 0; i < 30; i++){
                if(num1 & (1<<i)){
                    ans |= (1<<i);
                    ret = ret - 1;
                    if(ret == 0){
                        ans ^= num1;
                        return ans;
                    }
                }
            }
        }
        else{
            ret = bone - aone;
            while(ret){
                for(int i = 0; i < 30; i++){
                    if(num1 & (1<<i) == 0){
                        ans |= (1<<i);
                        ret = ret - 1;
                        if (ret == 0){
                            ans |=num1;
                            return ans;
                        }
                    }
                }
            }
        }
    }
};
int main(){
    vector<int> v{4,4,4,4,4,12};
    if(1+2+3 == 6){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;

}