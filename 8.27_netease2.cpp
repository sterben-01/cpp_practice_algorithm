#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include<stack>
#include <queue>
using namespace std;

struct rectangle {
    int x0;
    int y0;
    int x1;
    int y1;
    rectangle(int a, int b, int c, int d) : x0(a), y0(b), x1(c), y1(d) {}
};

int is_valid(rectangle& p1, rectangle& p2) {

    if ((p1.x0 >= p2.x0 && p1.x0 <= p2.x1) && (p1.y0 >= p2.y0 && p1.y0 <= p2.y1)) {
        if ((p1.x1 <= p2.x1 && p1.x1 >= p2.x0) && (p1.y1 >= p2.y0 && p1.y1 <= p2.y1)) {
            cout << "p1 in p2" << endl;
            return 1;
        }
        else {
            cout << "p1 partially in p2" << endl;
            return 2;
        }
    }
    if ((p2.x0 > p1.x0 && p2.x0 < p1.x1) && (p2.y0 > p1.y0 && p2.y0 <= p1.y1)) {
        if ((p2.x1 <= p1.x1 && p2.x1 >= p1.x0) && (p2.y1 >= p1.y0 && p2.y1 <= p1.y1)) {
            cout << "p2 in p1" << endl;
            return 1;
        }
        else {
            cout << "p2 partially in p1" << endl;
            return 2;
        }
    }
    cout << "no" << endl;
    return 5;
}


int main() {
    // int nums;
    // cin >> nums;
    // for(int k = 0; k < nums; k++){
    //     int recs;
    //     cin >> recs;
    //     vector<rectangle>points;
    //     for(int i = 0; i < recs; i++){
    //         vector<int> temp;
    //         rectangle rect;

    //         int num0;
    //         cin >> num0;
    //         rect.x0 = num0;

    //         int num1;
    //         cin >> num1;
    //         rect.y0 = num1;

    //         int num2;
    //         cin >> num2;
    //         rect.x1 = num2;

    //         int num3;
    //         cin >> num3;
    //         rect.y1 = num3;
    //         points.push_back(rect);
    //     }

    rectangle p1(1, 1, 4, 3);

    rectangle p2(1,1, 3, 3);
    cout << is_valid(p1, p2) << endl;


















    //}
    return 0;
}