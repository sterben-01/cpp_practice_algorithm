#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;


/*
text amazon OA medium
& Maximum sustainable cluster size
&这道题首先要注意的是，这个集群必须是下标连续的，也就是子串。然后我们用到了滑动窗口最大值
&我们的my_boostingPower这里的队头一定是当前区间内 启动耗电量最大的cpu的下标
!注意是下标
&然后具体怎么做就是和那个滑动窗口最大值一样。如果新来的下标对应的启动耗电量比当前队尾的大就把队尾的拿走。所以整个deque应该是降序排列的
然后我们按照公式看一下累加的处理功率如果超过了最大值，那么就把开始的位置往后移动。
&一个要点是，我们如果当前启动功率最大值的下标如果和当前判定为导致功率过大的元素的下标一致，则需要把这个启动功率也移除我们的my_boostingPower。因为已经“过期”了。
*/

void solution(vector<int>& processingPower, vector<int>& boostingPower, int maxPower){
    deque<int> my_boostingPower;
    int ans = 0;
    int sum = 0;
    int startPos = 0;
    int currentPos = 0;
    while(currentPos < processingPower.size()){
        sum = sum + processingPower[currentPos];
        while(!my_boostingPower.empty() && boostingPower[my_boostingPower.back()] <= boostingPower[currentPos]){
            my_boostingPower.pop_back();
        }
        my_boostingPower.push_back(currentPos);

        while(startPos <= currentPos && boostingPower[my_boostingPower.front()] + sum*(currentPos - startPos + 1) > maxPower){

            if(my_boostingPower.front() == startPos){
                my_boostingPower.pop_front();
            }

            sum = sum - processingPower[startPos];
            startPos++;
        }
        ans = max(ans, currentPos-startPos+1);
        currentPos++;
    }
    cout << ans << endl;
}






int main(){
    vector<int>s1{4,1,4,5,3};
    vector<int>s2{8,8,10,9,12};
    solution(s1, s2, 33);

    return 0;
}