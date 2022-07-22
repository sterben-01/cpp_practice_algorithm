#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
/*
	重量	价值
物品0	1	15
物品1	3	20
物品2	4	30
dp[i][j]表示在背包重量为j的时候，任意装入编号为0至i的物品后，背包的最大价值。注意这里是任意装，意思是不一定要按照顺序每一个都装入。

背包重量j→      0   1   2   3   4
物品编号i↓  0   0   15  15  15  15

            1   0   15  15  20  ...

            2   0   15  15  ...

            3   0   15  15

            4   0   15  15
首先，每种物品都有两个状态，装或者不装。如果要装的话，无论如何也要装，哪怕把之前的物品拿出来（总价值-之前物品的价值）
这里，第一列都初始化为0.意思是，当背包重量最大为0的时候，装物品i的时候背包的总价值。最大为0那么不能装那价值也是0
这里，第一行都初始化。初始化的意思是当背包重量最大为j的时候，装物品0的时候背包的总价值。所以除了[0][0]以外，别的都可以装得下物品0，所以价值就是物品0的价值
这里，[1][1]为15的意思是，当背包重量最大为1的时候，装入物品0之后，装入物品1的话背包最大价值是多少。我们发现我们无法装下物品1，所以背包最大价值一定是15
[1][i]都是15 同理。

关键来了。在[3][1]的时候。意思是当背包重量最大为3的时候，装入物品1的时候背包总价值。
我们发现可以装入物品1，因为1的重量小于背包的重量。但是我们此时无法装入，因为有物品0占用，我们可以用bagweight - weight[i]来算出如果装物品i的话背包剩余空间是多少。也就是我们需要拿出多少物品才能放得下当前物品。
我们要依次来看。这里的剩余空间指的是能够存放除当前物品之外，剩余的物品(依次来看的话是前一个物品)的空间。
在这里，bagweight是j 所以我们有j-weight[i]。

我们发现3-3是0。意思是我们如果要装物品1，那么没办法装入之前的物品。之前的物品是i-1所以我们有dp[i-1][j-weight[i]]。这个是装入之后。
装入之后我们需要把当前物品价值加上。那么就是dp[i-1][j-weight[i]]+value。
然后我们要比较一下，我们是装了这个物品，背包价值能最大还是不装背包价值最大呢？不装物品的话是dp[i-1][j]也就是前一个位置背包的价值
所以我们有max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]).
所以这就是我们的装入物品时的递推公式：max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]).
我们不装入物品的递推公式：dp[i-1][j]
*/



/*
    dp[i][j]的意思是
*/

void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1)); //加1是因为bagweight是从0开始算的

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0]; //初始化第一行
    }
    //剩下的数默认是0所以第一列不用初始化

    // weight数组的大小 就是物品个数 这里是横向遍历，意思是每个物品先都塞进背包
    for(int i = 1; i < weight.size(); i++) { // 遍历物品 
        for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]){
                dp[i][j] = dp[i - 1][j]; //如果物品容量大于背包容量，那就不放。按照不放的递推公式来
            }
            else{ //只要当前物品容量可以塞进背包，哪怕把之前所有的东西都抽出来（东西都抽出来就是背包最大价值归0）也要放进去
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]); //放东西的递推公式
            } 

        }
    }
    //也可以纵向遍历。一样的

    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
    string a = "125";
    string b = "124";
    if(a>b){
        cout << a << endl;
    }
    else{
        cout << b << endl;
    }
}