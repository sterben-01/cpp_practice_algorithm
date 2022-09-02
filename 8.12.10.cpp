#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <map>
using namespace std;




vector<int> yuefen(int x, int y) {

	int originalx = x, originaly = y;
	while (x != y) {

		if (x > y) {
			x = x - y;
		}
		else if (y > x) {

			y = y - x;
		}

	}
	return { originalx / x, originaly / y };;
}



int solution(vector<int>& X, vector<int>& Y) {
	// write your code in C++ (C++14 (g++ 6.2.0))
	for (int i = 0; i < X.size(); i++) {
		vector<int> temp = yuefen(X[i], Y[i]);

		X[i] = temp[0];
		Y[i] = temp[1];
	}

	unordered_map<int, unordered_map<int, int>> my_map;
	for (int i = 0; i < X.size(); i++) {
		if (my_map.count(Y[i]) == 0) {
			unordered_map<int, int> temp{ {X[i], 1} };
			my_map.insert(make_pair(Y[i], temp));
		}
		else {
			my_map[Y[i]][X[i]]++;
		}
	}
	for (auto i : my_map) {
		cout << i.first << endl;
		for (auto j : i.second) {
			cout << j.first << j.second << endl;
		}
	}
	int summmm = 0;
	for(auto i = my_map.begin(); i != my_map.end(); i++){
		int tt = i->first;
		cout <<"big map key" << tt << endl;
		auto secnd_map = i->second;
		for(auto j = secnd_map.begin(); j !=secnd_map.end(); j++){

			int another_num = j->first;
			cout <<"small map key" << another_num << endl;
			cout <<"small map key" << j->second << endl;
			if(another_num > tt/2){
				continue;
			}
			auto iter = secnd_map.find(tt - another_num);
			if(iter != secnd_map.end()){
				if((iter->first) == another_num){
					cout << iter->first << ' ' << j->second << endl;
					summmm = (summmm + (j->second)*((j->second)-1)/2) % 1000000007;
				}
				else {
					summmm = (summmm + (j->second)*(iter->second)) % 1000000007;
				}
				
			}
		}
	}
	cout <<"sum" <<summmm << endl;
	return summmm;


}

int main()
{
	vector<int> test{ 1,2,3,1,2,12,8,4 };
	vector<int> test2{ 5,10,15,2,4,15,10,5 };

	solution(test, test2);


}