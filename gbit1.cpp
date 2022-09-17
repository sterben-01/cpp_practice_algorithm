#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

void process1(vector<int>& nums, int size){
    int count = 0;
    sort(nums.begin(), nums.end());
    if(nums[1] % 2 == 0){
        count = count + nums[1]/2;
    }
    else{
        count = count + nums[1]/2 + 1;
    }
    nums[0] = nums[0] - count;
    if(nums[0] <= 0){
        res.push_back(count);
    }
    else{
        if(nums[0] % 2 == 0){
            count = count + nums[0]/2;
        }
        else{
            count = count + nums[0]/2 + 1;
        }
        res.push_back(count);
    }
}

bool is_even(int s){
    if(s%2 == 0){
        return true;
    }
    return false;
}

void triple(int m, int l, int r, int l1, int r1){
    int count = 0;
    while(m > 0 && l > 0 && r > 0){
        count++;
        l = l - 1;
        r = r - 1;
        m = m - 2;
    }
    if(m <= 0){
        if(l < r){
            while(l > 0 && l1 > 0){
                count++;
                l = l - 2;
                l1 = l1 - 1;
            }
        }
        else{
            while(r > 0 && r1 > 0){
                count++;
                r = r - 2;
                r1 = r1 - 1;
            }
        }
    }
    else if(l <= 0){
        if(m < r){
            while(m > 0 && r > 0){
                count++;
                m = m - 2;
                r = r - 1;
            }
        }
        else{
            while(r > 0 && r1 > 0){
                count++;
                r = r - 2;
                r1 = r1 - 1;
            }
        }      
    }
    else if(r <= 0){
        if(l < m){
            while(l > 0 && l1 > 0){
                count++;
                l = l - 2;
                l1 = l1 - 1;
            }
        }
        else{
            while(m > 0 && l > 0){
                count++;
                m = m - 2;
                l = l - 1;
            }
        }        
    }
    res.push_back(count);
}


int main(){
    int num;
    cin >> num;
    vector<int>grape;
    for(int i = 0; i < num; i++){
        int temp;
        cin >>temp;
        grape.push_back(temp);
    }
    if(num == 2){
        process1(grape,2);
    }
    else{
        for(int i = 0; i < num; i++){
            if(i == 0){
                triple(grape[i], grape[num-1], grape[i+1], grape[num-2], grape[i+2]);
            }
            else if(i == num-1){
                triple(grape[num-1], grape[num-2], grape[0], grape[num-3], grape[1]);
            }
            else{
                int lpos = 0;
                int rpos = 0;
                if(i-2 < 0){
                    lpos = num-1-abs(i-2);
                }
                if(i+2 > num-1){
                    rpos = (i+2)-1-num;
                }
                else{
                    lpos = i-2; //之前忘写了
                    rpos = i+2; //之前忘写了
                }
                triple(grape[i], grape[i-1], grape[i+1], grape[lpos], grape[rpos]);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res[0] << endl;
    return 0;
}