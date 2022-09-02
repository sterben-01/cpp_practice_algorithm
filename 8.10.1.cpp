#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main(){
    string num;
    cin >> num;
    int temp = 0;
    
    string mysec = "8";
    if(num.find(mysec) != num.npos){
        cout <<"YES" << endl;
        return 0;
    }
    
    for(int i = num.size() - 1; i >= 0; i--){
        if(num[i] == '2' || num[i] == '6'){
            for(int j = i-1; j >=0; j--){
                if(num[i] == '2' && (num[j] - '0') % 4 == 3){
                    cout << "YES" << endl;
                    return 0;
                }
                if(num[i] == '6' && (num[j] - '0') % 4 == 1){
                    cout << "YES" << endl;
                    return 0;
                }
                if((num[j] -'0') % 2 == 1){
                    for(int k = j - 1; k >=0; k--){
                        if((num[k] - '0') % 2 == 0 && num[k] != '0'){
                            if(num[i] == '2' && (num[j] -'0') % 4 == 3){
                                cout << "YES" << endl;
                                return 0;
                            }
                            if(num[i] == '6' && (num[j] -'0') % 4 == 1){
                                cout << "YES" << endl;
                                return 0;
                            }

                        }
                        else{
                            if(num[i] == '6' && (num[j] -'0') % 4 == 3){
                                cout << "YES" << endl;
                                return 0;
                            }  
                            if(num[i] == '2' && (num[j] -'0') % 4 == 1){
                                cout << "YES" << endl;
                                return 0;
                            } 
                        }
                    }
                }
            }
        }
        else if(num[i] == '0' || num[i] == '4' || num[i] == '8'){
            for(int j = i - 1; j >=0; j--){
                if(num[i] == '0' && num[j] != '0' && (num[j] - '0') % 4 == 0){
                    cout << "YES" << endl;
                    return 0;
                }
                if(num[i] == '8' && num[j] != '0' && (num[j] - '0') % 4 == 0){
                    cout << "YES" << endl;
                    return 0;
                }
                if(num[i] == '4' && (num[j] - '0') % 4 == 2){
                    cout << "YES" << endl;
                    return 0;
                }
                if((num[j] - '0') % 2 == 0){
                    for(int k = j - 1; k >=0; k--){
                        if((num[k] - '0') % 2 == 0 && num[k] != '0'){
                            if(num[i] == '0' && (num[j] -'0') % 4 == 0){
                                cout << "YES" << endl;
                                return 0;
                            }
                            if(num[i] == '8' && (num[j] -'0') % 4 == 0){
                                cout << "YES" << endl;
                                return 0;
                            }   
                            if(num[i] == '4' && (num[j] -'0') % 4 == 2){
                                cout << "YES" << endl;
                                return 0;
                            }                          
                        }
                        else{
                            if(num[i] == '4' && (num[j] -'0') % 4 == 0){
                                cout << "YES" << endl;
                                return 0;
                            }  
                            if(num[i] == '0' && (num[j] -'0') % 4 == 2){
                                cout << "YES" << endl;
                                return 0;
                            } 
                            if(num[i] == '8' && (num[j] -'0') % 4 == 2){
                                cout << "YES" << endl;
                                return 0;
                            }                          
                        }
                    }
                }
            }
        }
        else{
            continue;
        }
    }
    cout << "NO" <<endl;


    return 0;
}
