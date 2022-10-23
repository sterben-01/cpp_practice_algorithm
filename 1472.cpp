#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
text 核心是通过控制栈顶指针和当前位置来进行模拟删除。并不真正的删除。
*/
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.resize(5001);
        visit(homepage);
        
    }
    
    void visit(string url) {
        curpos++;
        toppos = curpos; //&此处的目的是配合下面的模拟删除。假设现在top是7，退回到了2，top还是7，cur是2。如果这时候visit了，那么curpos变为3，top也变为3！！然后在3处赋值。
        history[toppos] = url; //&注意这里不是在vector尾部加入。而是在栈顶处替换。我们此处只是模拟被删掉。其实只是替换掉而已。
        toppos++; //此时栈顶应该是前进一位，
    }
    
    string back(int steps) {
        if(steps > curpos){
            steps = curpos;
        }
        if(curpos < 0){
            return"notvalid";
        }
        curpos = curpos - steps;
        return history[curpos];
    }
    
    string forward(int steps) {
        steps = min(steps, toppos - 1 -  curpos); //这里需要-1的原因是top顶部指针永远是指向下一个空位。
        //比如 ["a.com","b.com","c.com","","","",...] 栈顶指针会指向[3]而不是[2]。因为我们visit的时候后移了一个位置。这个比较符合逻辑。如果此处不-1的话会移动过头。
        curpos = curpos + steps;
        return history[curpos];
    }
    private:
        vector<string> history;
        int curpos = -1;
        int toppos = -1;
};