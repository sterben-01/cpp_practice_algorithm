#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
using namespace std;

vector<int> selection;
vector<int> pos;
int calc_area(int n){
    int total = n*n;
    int calced = (rand()%(total/4 - total/2 + 1)) + total/4;
    cout << calced << endl;
    return calced;
}
void select_area(int total){
    int max = sqrt(total);
    cout << max << endl;
    while(total != 0){
        int selected = (rand()%(max-0)) + 1;
        total = total - selected*selected;
        max = sqrt(total);
        selection.push_back(selected);
    }
    for(auto t:selection){
        cout <<t << endl;
    }
}
void pos_select(int n){
    for(int i = 0; i < selection.size(); i++){
        pos.push_back((rand()%(n-(n-selection[i]))) + (n-selection[i]));
        pos.push_back((rand()%(n-(n-selection[i]))) + (n-selection[i]));
    }
}

void generate(int n, vector<vector<int>>& ret){
    int pivot = 0;
    for(int i = 0; i < selection.size(); i++){
        int length = selection[i];
        int posx = pos[pivot];
        int posy = pos[pivot+1];
        pivot = pivot + 2;
        for(int row = posx; row < posx + length; row++){
            for(int col = posy; col < posy + length; col++){
                ret[row][col] = 1;
            }
        }
    }
}




void test(int s){
    srand((unsigned)time(NULL));
    for(int i = 0; i < s; i++){
        cout << (rand()%(10-0+1)) + 0 << endl;
    }
}

int main(){
    int s = calc_area(10);
    select_area(s);
    pos_select(10);
    vector<vector<int>> ret(10, vector<int>(10,0));
    generate(ret.size(), ret);
    for(auto i:ret){
        for(auto j:i){
            cout << j << endl;
        }
        cout << endl;
    }
}