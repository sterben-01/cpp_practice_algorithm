#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include<functional>
#include <type_traits>
#include <memory>
using namespace std;

/*
2
eyaobjcbcbioay
2
bob boy
mkijnebhuygv
1
make
*/
int backtracking(unordered_map<char, int> my_map, string& S, string& word){
    //unordered_map<char, int> my_map;
    int my_count = 0;
    bool target = true;
    // for(int i = 0; i < S.size(); i++){
    //     my_map[S[i]] = my_map[S[i]] + 1;
    // }
    // for(auto p:my_map){
    //     cout << p.first << p.second << endl;
    // }

    unordered_map<char, int> word_map;
    for(int i = 0; i < word.size(); i++){
        word_map[word[i]] = word_map[word[i]] + 1;
    }
    
    // for(auto i: word_map){
    //     cout << i.first << "," <<i.second << endl;
    // }

    for(auto iter = word_map.begin(); iter!= word_map.end(); iter++){
        if(my_map.find(iter->first) != my_map.end()){
            if(my_count == 0){
                my_count = my_map[iter->first] / iter->second;
            }
            else{   
                my_count = min(my_count, my_map[iter->first] / iter->second);
            }
            
        }
    }

    // while(target){
    //     for(int i = 0; i < word.size(); i++){
    //         if(my_map.find(word[i])!= my_map.end()){
    //             if(my_map[word[i]] > 0){
    //                 my_map[word[i]]--;
    //             }
    //             else{
    //                 target = false;
    //                 break;
    //             }
    //         }
    //         else{
    //             target = false;
    //             break;
    //         }
    //     }
    //     if(target == true){
    //         my_count++;
    //     }
        
    // }
    return my_count;
}




int main(){
    int group;
    cin >> group;
    for(int i = 0; i < group; i++){
        int res = 0;
        int maxnum = 0;
        string input_card;
        cin >> input_card;
        int word_num;
        cin >> word_num;
//         vector<string> word_list;
//         for(int j = 0; j < word_num; j++){
//             string temp;
//             cin >> temp;
//             word_list.push_back(temp);
//         }
//         unordered_map<char, int> my_map;
//         for(int i = 0; i < input_card.size(); i++){
//             my_map[input_card[i]] = my_map[input_card[i]] + 1;
//         }
//         for(int j = 0; j < word_list.size(); j++){
//             res = max(res, backtracking(my_map, input_card, word_list[j]));
//         }
//         cout << res << endl;
        unordered_map<char, int> my_map;
        for(int i = 0; i < input_card.size(); i++){
            my_map[input_card[i]] = my_map[input_card[i]] + 1;
        }
        for(int j = 0; j < word_num; j++){
            string temp;
            cin >> temp;
            res = backtracking(my_map, input_card, temp);
            maxnum = max(res, maxnum);
        }
        cout << maxnum << endl;
    }
    return 0;
}
/*
3
eyaobjcbcbioay
2
bob boy
mkijnebhuygv
1
make
jklaskdjalsjkdhjaslkjdfhsakjfhakfjhbvfgjkjhsdbfjsnfbkfjsdnfkjfhkfjhgskjgjpoiaidcksjbghbfad
2
ajj ccc
*/