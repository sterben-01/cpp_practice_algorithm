#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <array>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// map记录已走过的节点, 避免重复探索, 或者不用map, 探索过后更改节点值也可以
map<pair<int, int>, int> m;

void dfs(vector<vector<int>>& data, int y, int x, queue<pair<int, int>>& q)
{
    // 若坐标越界
    if (y < 0 || x < 0)
        return;
    if (y >= data.size() || x >= data[0].size())
        return;
    // 若已探索过
    if (m.find({ y,x }) != m.end())
        return;
    // 未探索则将当前节点添加进map
    m[{y, x}] = 1;

    // 1. up
    if (y - 1 >= 0)
    {
        // 1.1 若 up 为1, 则继续探索
        if (data[y - 1][x] == 1)
            dfs(data, y - 1, x, q);
        // 1.2 若 up 为0, 则up为其边缘, 将其添加进队列
        if (data[y - 1][x] == 0)
        {
            q.push({ y - 1, x });
            m[{y - 1, x}] = 1;
        }
    }

    // 2. bottom
    if (y + 1 < data.size())
    {
        // 2.1 若 up 为1, 则继续探索
        if (data[y + 1][x] == 1)
            dfs(data, y + 1, x, q);
        // 2.2 若 up 为0, 则up为其边缘, 将其添加进队列, 并标记为已探索
        if (data[y + 1][x] == 0)
        {
            q.push({ y + 1, x });
            m[{y + 1, x}] = 1;
        }
    }

    // 3. left
    if (x - 1 >= 0)
    {
        // 3.1 若 up 为1, 则继续探索
        if (data[y][x - 1] == 1)
            dfs(data, y, x - 1, q);
        // 3.2 若 up 为0, 则up为其边缘, 将其添加进队列
        if (data[y][x - 1] == 0)
        {
            q.push({ y, x - 1 });
            m[{y, x - 1}] = 1;
        }
    }

    // 4. right
    if (x + 1 < data[0].size())
    {
        // 4.1 若 up 为1, 则继续探索
        if (data[y][x + 1] == 1)
            dfs(data, y, x + 1, q);
        // 4.2 若 up 为0, 则up为其边缘, 将其添加进队列
        if (data[y][x + 1] == 0)
        {
            q.push({ y, x + 1 });
            m[{y, x + 1}] = 1;
        }
    }
}

int landMinDistance(vector<vector<int>>& data)
{
    int xsize = data[0].size();
    int ysize = data.size();

    pair<int, int> start = { -1, -1 };
    // 找到第一个岛屿的起点
    for (int y = 0; y < ysize; y++)
    {
        for (int x = 0; x < xsize; x++)
        {
            // 找到第一个岛屿起点直接跳出
            if (data[y][x] == 1)
            {
                start.first = y;
                start.second = x;
                break;
            }
        }
        // break只会跳出一个for loop, 所以这里还需要一个break
        if (start.first != -1)
            break;
    }

    // dfs遍历岛屿, 并将岛屿边缘记录下来
    // 什么样的节点是岛屿边缘? 上下左右任意一处为0, 则其是岛屿边缘
    // 用于bfs的队列, 存放节点下标
    queue<pair<int, int>> q;
    dfs(data, start.first, start.second, q);


    // 现在队列里存的就是第一个岛屿外圈的一圈0, 此时距离为1
    // bfs去探索, 每探索一圈距离增加1, 直到探索到未知节点, 且其值为1
    int distance = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size > 0)
        {
            auto idx = q.front();
            int y = idx.first;
            int x = idx.second;
            q.pop();

            
            // 向上下左右看, 把那些未探索过的节点添加到队列
            // 若有节点满足其未探索过且值为1, 那么该节点就是要找的新岛屿

            // 1. up
            if (y - 1 > 0 && m.find({ y - 1, x }) == m.end())
            {
                // 1.1 若为0则添加进队列
                if (data[y - 1][x] == 0)
                {
                    q.push({ y - 1, x });
                    m[{y - 1, x}] = 1;
                }
                else
                {
                    // 1.2 遇到新的岛屿就输出返回
                    cout << distance;
                    return 0;
                }
            }
            // 2. bottom
            if (y + 1 < ysize && m.find({ y + 1, x }) == m.end())
            {
                // 2.1 若为0则添加进队列
                if (data[y + 1][x] == 0)
                {
                    q.push({ y + 1, x });
                    m[{y + 1, x}] = 1;
                }
                else
                {
                    // 2.2 遇到新的岛屿就输出返回
                    cout << distance;
                    return 0;
                }
            }
            // 3. left
            if (x - 1 >= 0 && m.find({ y, x - 1 }) == m.end())
            {
                // 3.1 若为0则添加进队列
                if (data[y][x - 1] == 0)
                {
                    q.push({ y, x - 1 });
                    m[{y, x - 1}] = 1;
                }
                else
                {
                    // 3.2 遇到新的岛屿就输出返回
                    cout << distance;
                    return 0;
                }
            }
            // 4. right
            if (x + 1 < xsize && m.find({ y, x + 1 }) == m.end())
            {
                // 3.1 若为0则添加进队列
                if (data[y][x + 1] == 0)
                {
                    q.push({ y, x + 1 });
                    m[{y, x + 1}] = 1;
                }
                else
                {
                    // 4.2 遇到新的岛屿就输出返回
                    cout << distance;
                    return 0;
                }
            }

            size--;
        }
        // 本轮探索完仍未发现新岛屿, 则增加距离
        distance++;
    }

    return 0;
}


int main()
{
    vector<vector<int>> data =
    {
        {1,1,0},
        {0,0,0},
        {0,0,1}
    };

    landMinDistance(data);

    return 0;
}
