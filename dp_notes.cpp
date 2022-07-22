#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

/*
如果我们是比较类，也就是看放和不放哪个大/小... 的时候，我们会在后面加nums[i]
dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i])


动态规划的核心就是每个物品可以拿也可以不拿。
这里 dp[i-1][j] 的意思是 不拿当前i物品的情况。


这里 dp[i-1][j-nums[i]] + nums[i]的意思是 我要是拿了物品i我就一定得拿。
所以我先把i放进去，把价值加上去这是+nums[i]
i已经拿了 所以得从i-1看 所以是dp[i-1]
然后算放了i之后我背包还剩下多大，我就找到重量为j-nums[i]时候最大的价值是多少 
然后二者取最大值


如果是累加类 也就是求组合类 求有多少种组合或者方法 比如 518 和 494 那就不加nums[i]
二维不要用+= 还是按照+的老方法

例子： dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
这里 dp[i-1][j] 是我如果不拿的情况
dp[i-1][j-nums[i]] 的意思是 i已经拿了 所以得从i-1看 所以是dp[i-1]
然后我因为是求方法数量 不需要具体nums[i]的数值。所以没有+nums[i]
但是我依旧还是看当我一定要装i的时候，装了i之后背包还剩多大。我要去看重量为j-nums[i]的时候的最大值是多少。然后相加就可以




*/