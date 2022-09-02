#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;





int main() {
    int windows_num, click_num;
    cin >> windows_num >> click_num;
    vector<vector<int>> window_pos;
    for (int i = 0; i < windows_num; i++) {
        int start_x = 0, start_y = 0, width = 0, height = 0;
        cin >> start_x >> start_y >> width >> height;
        int pos_x = start_x + width;
        int pos_y = start_y + height;
        window_pos.push_back({ start_x, start_y, pos_x, pos_y, i});

    }
    for (int i = 0; i < click_num; i++) {

        int click_x = 0, click_y = 0;
        bool target = false;
        cin >> click_x >> click_y;
        for (int j = window_pos.size() - 1; j >= 0; j--) {
            if (window_pos[j][0] <= click_x && click_x <= window_pos[j][2] && window_pos[j][1] <= click_y && click_y <= window_pos[j][3]) {

                cout << window_pos[j][4]+1 << endl;
                auto tempvec = window_pos[j];
                window_pos.erase(window_pos.begin() + j);
                window_pos.push_back(tempvec);
                target = true;
                break;
            }
        }
        if (target == false) {
            cout << -1 << endl;
        }
    }

    return 0;
}