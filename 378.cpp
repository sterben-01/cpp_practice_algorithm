
#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
text 此题也是利用了 74 240 的思维。但是有一些区别。我们不用二分法，使用优先队列。
&具体方法是，我们知道每一行的第一个元素一定是这一行的最小值。但是每行的第一个并不一定比上一行的最后一个大。
&所以我们可以利用一个技巧。我们既然要找到第K小的，那么假设矩阵是5X5。那么目前来看，最小的数字一定是第一行第一个。但是第二小的数字具体是第二行第一个还是第一行第二个就不一定了。但是这个数字下面的和右面的数字一定比当前数字要大。
所以我们维护一个最小候选人的队列。然后每次弹出最小的元素。
&在一开始，我们能看到的范围，每一行的第一个都是最小的。那么我们把每一行的第一个元素，也就是第一列放入优先队列。
&然后我们每次从优先队列中取最小值。当第一行第一个去掉之后，我们把第一行的第二个元素放入队列。
todo也就是每一行的首元素是在队列里的。
&然后我们就看这些元素哪个最小。直到放到了某一行的最后一个元素，他后面没有数字了，那么就不管他了。继续进行。直到弹出第k-1小的数字。最后队头就是我们要的第K个
*/

class element{ //设定一个结构体。储存x和y坐标还有这个元素的值。
    public:
    int x;
    int y;
    int val;
    element(int a, int b, int c):x(a), y(b),val(c){}
};
class mycomp{ //自定义比较器
    public:
    bool operator()(const element& a, const element& b) const{
        if(a.val > b.val){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<element, vector<element>, mycomp> my_que;
        for(int i = 0; i < matrix.size(); i++){
            my_que.push({i,0,matrix[i][0]}); //初始化，第一列放入队列
        }
        for(int i = 0; i < k-1; i++){
            element temp = my_que.top(); //每次弹出最小元素
            my_que.pop();
            if(temp.y < matrix[0].size()-1){
                my_que.push({temp.x, temp.y+1, matrix[temp.x][temp.y+1]}); //如果当前元素右边还有元素，就把右侧元素入队。
            }
        }
        return my_que.top().val;

    }
};

int main(){
    Solution s;
    vector<vector<int>> vec {{1,5,9}, {10,11,13}, {12,13,15}};
    s.kthSmallest(vec, 8);
}
