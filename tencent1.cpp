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
#include <stdarg.h>
#include <future>
#include <thread>
#include <numeric>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a ListNode类
     * @param b ListNode类
     * @return ListNode类
     */
    ListNode* xorList(ListNode* a, ListNode* b) {
        vector<int>numa;
        vector<int>numb;
        int alen = 0;
        int blen = 0;
        ListNode* ahead = a;
        ListNode* bhead = b;
        while (ahead != nullptr) {
            alen++;
            numa.push_back(ahead->val);
            ahead = ahead->next;
        }
        while (bhead != nullptr) {
            blen++;
            numb.push_back(bhead->val);
            bhead = bhead->next;
        }
        vector<int> ret;

        int larger = max(alen, blen);
        int smaller = min(alen, blen);
        int apos = 0;
        for (; apos < larger- smaller; apos++) {
            ret.push_back(numa[apos] ^ 0);
        }
        int bpos = numb.size() - 1;

        while (apos < numa.size()) {
            ret.push_back(numa[apos] ^ numb[bpos]);
            apos++;
            bpos--;
        }
        ListNode* dummyhead = new ListNode(-1);
        ListNode* cur = dummyhead;

        bool passed = false;
        for (int i = 0; i < ret.size(); i++) {
            if (ret[i] == 0 && passed == false) {
                continue;
            }
            passed = true;
            ListNode* node = new ListNode(ret[i]);
            cur->next = node;
            cur = cur->next;
        }
        return dummyhead->next;

    }
};
int main() {
    vector<int>a = { 1,1,1 };
    vector<int>b = { 1,0,1 };
    ListNode* dummyhead = new ListNode(-1);
    ListNode* cur = dummyhead;
    for (int i = 0; i < a.size(); i++) {
        ListNode* node = new ListNode(a[i]);
        cur->next = node;
        cur = cur->next;
    }

    ListNode* dummyhead2 = new ListNode(-1);
    ListNode* cur2 = dummyhead2;
    for (int i = 0; i < b.size(); i++) {
        ListNode* node = new ListNode(b[i]);
        cur2->next = node;
        cur2 = cur2->next;
    }
    Solution s;
    s.xorList(dummyhead->next, dummyhead2->next);
    return 0;
   
}