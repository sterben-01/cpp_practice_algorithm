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
注意这里核心是位和位相加
举例子

3 2 1
5 6 7
123+765 = 888
所以是 3+5， 2+6， 1+7

&如果不一样长咋办？无所谓，不一样长当做0处理。因为sum每一轮会清0
&如果进位怎么办？增加标志位。如果进位了（sum大于等于10），则当轮sum再加1。
&如何添加节点？888应该变成888%8 = 8。按照取余方式依次添加即可。

%注意：每一轮如果sum大于等于10则标志为为真。如果sum不大于10则标志为为假。记得为假也要设置
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* virtualhead = new ListNode(-1);
        ListNode* cur = virtualhead;
        int sum = 0;
        bool carry = false;
        while(l1 != nullptr || l2 != nullptr){
            sum = 0;
            if(l1 != nullptr){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            if(carry == true){
                sum = sum + 1;
            }

            if(sum >= 10){
                carry = true;
            }
            else{
                carry = false; //记得为假也要更新标志位。
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        if(carry == true){
            cur->next = new ListNode(1);
        }
        return virtualhead->next;
    }
};