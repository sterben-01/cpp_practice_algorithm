#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int GetFarthestRoad(vector<uint8_t>& vecRoad)
{
    vector<bitset<8>> vec1;
    vec1.reserve(vecRoad.size());
    for (long long i = 0; i < vecRoad.size(); i++) {
        vec1.push_back(bitset<8>(vecRoad[i]));
    }
    int count = 0;
    auto t = vec1.begin();
    bool has = false;
    for (int j = 0; j < vec1.size()-1; j++) {
  
        if (vec1[j].flip().none()) { //没有0
            if (j != 0) {
                count++;
            }
            has = true;
            break;
        }
        else {
            if (vec1[j+1].flip().none()){ //没有0
                if (j+1 != 0) {
                    count++;
                }
                has = true;
                break;
            }
            else{
                bool check = false;
                for(int i = 7; j >=0; j++){
                    if(vec1[j][i] == 0 && vec1[j+1][i] == 0){
                        count++;
                        check = true;
                        break;
                    }
                }
                if(check == false){
                    has = true;
                    break;
                }
            }
        }
    }
    if(has == false){
        if(!vec1[vec1.size()-1].flip().none()){
            count++;
        }
    }

    cout << count << endl;


    return count;
}


int main() {
    vector<uint8_t> vec{82,243,235,235,254,255 };
    vector<uint8_t> vec1{ 8,4,2,1,254 };
    vector<uint8_t> vec2{ 255 };
    GetFarthestRoad(vec);
    return 0;
}