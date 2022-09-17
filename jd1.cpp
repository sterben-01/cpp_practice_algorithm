#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

class mymax{
    public:
        bool operator()(const pair<int, int>& a, const pair<int,int>& b) const{
            return a.first < b.first;
        }
};

int main(){
    int count;
    cin >> count;
    vector<int> item;

    for(int i = 0; i < count; i++){
        int temp;
        cin >> temp;
        item.push_back(temp);
    }
    unordered_map<int,int> my_map;

    for(int i = 0; i < count; i++){
        my_map[item[i]]++;
    }
    auto t = max_element(my_map.begin(), my_map.end(), mymax());
    int ret = count - t->second;
    cout << ret << endl;

    return 0;
}