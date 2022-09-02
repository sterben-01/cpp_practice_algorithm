#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>
#include<stack>
#include <queue>
using namespace std;




int main() {
    int nums;
    cin >> nums;
    for(int o = 0; o < nums; o++){
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<string> content;
        vector<string>ori;
        vector<string> res;
        vector<string> final;
        for(int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            content.push_back(temp);
        }
        ori = content;
        string s;
        getline(cin, s);
        int k = (m-n)/2;
        if(k>=n){
            int k1 = k-n;
            for(int i = 0; i < content.size(); i++){
                string& tmp = ori[i];
                int size = k1;
                while(size-- > 0){
                    content[i] += tmp;
                }
            }
            for(int i = 0; i < content.size(); i++){
                string& tmp = ori[i];
                int size = k1;
                while(size-- > 0){
                    content[i] += tmp;
                }
            }
        }
        k = k % n;
        if(k > 0){
            for(int i = 0; i < content.size(); i++){
                string& tmp = ori[i];
                int idx = n - 1;
                int k2 = k;
                while(k2-- > 0){
                    content[i].insert(content[i].begin(), tmp[idx--]);
                }
            }
            for(int i = 0; i < content.size(); i++){
                string& tmp = ori[i];
                int idx = 0;
                int k2 = k;
                while(k2-- > 0){
                    content[i].push_back(tmp[idx++]);
                }
            }
        }
        int outsize = (m-n)/2;
        int os1 = outsize%n;
        if(os1 > 0){
            os1 = n-os1;
            for(os1; os1<n; os1++){
                cout << content[os1] << endl;
            }
        }
        os1 = outsize/n+1;
        if(os1 > 0){
            while(os1-->0){
                for(int i = 0; i < content.size(); i++){
                    cout << content[i] << endl;
                }
            }
        }
        int os2 = outsize/n;
        if(os2 > 0){
            while(os2-->0){
                for(int i = 0; i < content.size(); i++){
                    cout <<content[i]<<endl;
                }
            }
        }
        os2 = outsize%n;
        if(os2 > 0){
            for(int i = 0; i < os2; i++){
                cout<< content[i] << endl;
            }
        }

    }

    return 0;
}