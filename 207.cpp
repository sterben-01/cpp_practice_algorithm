#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <future>
#include <math.h>
#include <time.h>
#include <stack>
using namespace std;


/*
text 207 拓扑排序
一共有 n 门课要上，编号为 0 ~ n-1。
先决条件[1, 0]，意思是必须先上课 0，才能上课 1。
给你 n 和一个先决条件表，请你判断能否完成所有课程。
示例：n = 6，先决条件表：[[3, 0], [3, 1], [4, 1], [4, 2], [5, 3], [5, 4]]
课 0, 1, 2 没有先修课，可以直接选。其余的课，都有两门先修课。

&也就是0，1, 2没有先决条件。那么他们的入度为0。 3有两个先决条件，则3的入度为2。以此类推。
&所以每次只能选你能上的课的意思是每次只能选入度为 0 的课，因为它不依赖别的课，是当下你能上的课。
假设选了 0，课 3 的先修课少了一门，入度由 2 变 1。
接着选 1，导致课 3 的入度变 0，课 4 的入度由 2 变 1。
接着选 2，导致课 4 的入度变 0。
现在，课 3 和课 4 的入度为 0。继续选入度为 0 的课……直到选不到入度为 0 的课。
&这很像 BFS
让入度为 0 的课入列，它们是能直接选的课。
然后逐个出列，出列代表着课被选，需要减小相关课的入度。
如果相关课的入度新变为 0，安排它入列、再出列……直到没有入度为 0 的课可入列。

&BFS 前的准备工作
1. 每门课的入度需要被记录，我们关心入度值的变化。
2. 课程之间的依赖关系也要被记录，我们关心选当前课会减小哪些课的入度。
        因此我们需要选择合适的数据结构，去存这些数据：
        1. 入度数组：课号 0 到 n - 1 作为索引，通过遍历先决条件表求出对应的初始入度。
        2. 邻接表：用哈希表记录依赖关系（也可以用二维矩阵，但有点大）
            %key：课号
            %value：依赖这门课的后续课（数组）
&怎么判断能否修完所有课？
BFS 结束时，如果仍有课的入度不为 0，无法被选，完成不了所有课。否则，能找到一种顺序把所有课上完。
或者：用一个变量 count 记录入列的顶点个数，最后判断 count 是否等于总课程数。



*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses); //入度数组。也就是储存这门课依赖几门其他课程
        unordered_map<int, vector<int>> my_map; //储存课号和依赖这门课的其他课程编号。
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++; //输入数组的第一位是课程编号。第二位是其依赖的课程。只要这个课程在数组的第1位，那么这门课一定会依赖其他课程。所以入度会增加
            my_map[prerequisites[i][1]].push_back(prerequisites[i][0]); //我们从map里找到输入数组的第二位。第二位是我们当前课程所依赖的课程。我们的map储存的是课号和依赖这门课的其他课程。
            //所以3,0 3依赖于0.那么课号0的被依赖课程就是3.所以map需要储存 0 和{3}。
        }
        queue<int> my_que;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                my_que.push(i); //把所有入度为0的课程放入队列。因为这些课程没有先决条件。可以直接上。
            }
        }
        int count = 0;
        while(!my_que.empty()){ //标准BFS模板
            int current = my_que.front();
            my_que.pop();
            count++; //上课数量++
            vector<int> current_need = my_map[current]; //这里是查看当前这个入度为0的课程的被依赖课程列表。也就是有几门课依赖这门现在正在上的课。
            if(!current_need.empty()){ //判空
                for(int i = 0; i < current_need.size(); i++){
                    inDegree[current_need[i]]--; //因为当前这门课正在上，那么所有依赖这门课程的课程的入度都减掉1。因为依赖课程已经修了一门了（当前这门）
                    //比如2和5依赖3和7。当前正在上7，则2和5的入度就从2变为1。
                    if(inDegree[current_need[i]] == 0){ //如果有课程入度为0了，证明可以上了。就入队。
                        my_que.push(current_need[i]);
                    }
                }
            }
        }
        if(count == numCourses){ //如果上的课程数量（入度最终为0的数量）和课程数量一样，证明可以修完。
            return true;
        }
        return false;
    }
};