#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
	char retchar(int n){
		if(n <= 9){
            return n+'0';

        } 
		else{
            return n - 10 + 'a';
        }
	}
	
	int retint(char ch){
		if('0' <= ch && ch <= '9'){
            return ch - '0';
        }
		else{
            return ch - 'a' + 10;
        }
	}
	
	string add(string a, string b){
		int carry = 0;
		int i = a.size()-1, j = b.size()-1;
        int x,y;
		string res;
		while(i>=0 || j>=0 || carry){
            if(i >= 0){
                x = retint(a[i]);
            }
            else{
                x = 0;
            }
            if(j>=0){
                y = retint(b[j]);
            }
            else{
                y = 0;
            }
			int sum = x + y + carry;
			res += retchar(sum%36);
			carry = sum/36;
			i--,j--;
		}
		reverse(res.begin(),res.end());
		return res;  
	}
};
 
int main ()
{
	Solution s;
	string a = "b", b = "x", c;
	c = s.add(a,b);
	cout << c << endl;
}