
# 动态规划

复制这里：

**确定 dp 数组以及其下标的含义：**

**递推公式：**

**初始化：**

**确认遍历顺序：**

## 动态规划理论基础

解题步骤：
- 确定 dp 数组以及其下标的含义
- 确认递推公式
- dp 数组如何初始化
- 确定遍历顺序
- 举例推导dp数组

‼️一定要先确定递推公式，再去考虑初始化。

**dp问题如何debug？**

找问题最好的方式就是把dp数组打印出来，看看究竟是不是按照自己的思路推导的。

## 斐波那契数

https://leetcode.cn/problems/fibonacci-number/description/

斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。

虽然这道题很简单，但是也要按照dp的思路一步一步做。

**确定 dp 数组以及其下标的含义：**

dp[i] 表示第i个斐波那契数

**递推公式：**

题目已经给你了：dp[i] = dp[i-1] + dp[i-2] (n>1)

**初始化：**

题目给了。

**确认遍历顺序：**

这题很简单，从前向后。

写代码：

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        std::vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```

## 爬楼梯（可以拓展成完全背包问题）

https://leetcode.cn/problems/climbing-stairs/description/

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**确定 dp 数组以及其下标的含义：**

这题很简单，dp[i] 就表示到i阶有i种方法

**递推公式：**

很简单，比如想到第i阶，那就可以从 i-2 和 i-1 分别上来

所以 dp[i] = dp[i-1] + dp[i-2]

**初始化：**

很明确

**确认遍历顺序：**

很明确，从前向后遍历

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        std::vector<int>dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```

这题很简单，不赘述了。

### 拓展

这道题目还可以继续深化，就是一步一个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种方法爬到n阶楼顶。

这又有难度了，这其实是一个完全背包问题，但力扣上没有这种题目，大家可以去卡码网去做一下 57. 爬楼梯(opens new window)

所以后续我在讲解背包问题的时候，今天这道题还会从背包问题的角度上来再讲一遍。 如果想提前看一下，可以看这篇:70.爬楼梯完全背包版本(opens new window)

这里我先给出本题的代码：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) { // 把m换成2，就可以AC爬楼梯这道题
                if (i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
```

代码中m表示最多可以爬m个台阶。

以上代码不能运行哈，我主要是为了体现只要把m换成2，粘过去，就可以AC爬楼梯这道题，不信你就粘一下试试。

**此时我就发现一个绝佳的大厂面试题，** 第一道题就是单纯的爬楼梯，然后看候选人的代码实现，如果把dp[0]的定义成1了，就可以发难了，为什么dp[0]一定要初始化为1，此时可能候选人就要强行给dp[0]应该是1找各种理由。那这就是一个考察点了，对dp[i]的定义理解的不深入。

然后可以继续发难，如果一步一个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种方法爬到n阶楼顶。这道题目leetcode上并没有原题，绝对是考察候选人算法能力的绝佳好题。

这一连套问下来，候选人算法能力如何，面试官心里就有数了。

其实大厂面试最喜欢的问题就是这种简单题，然后慢慢变化，在小细节上考察候选人。

## 使用最小花费爬楼梯

https://leetcode.cn/problems/min-cost-climbing-stairs/

给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

**确定 dp 数组以及其下标的含义：**

这道题其实也很简单，可以很容易想到。

dp[i] 可以表示到 i 级阶梯所需要的最低 cost

**递推公式：**

dp[i] 的花费：可以选择从 i-1 或 i-2 上来，谁更便宜？min一下不就行了

**初始化：**

很容易想到。

dp[0] = 0

dp[1] = 0 "因为可以选择从0/1开始，所以dp[1]"

dp[2] = min(dp[0] + cost[0], dp[1] + cost[1])

**确认遍历顺序：**

很显然是从前向后。

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost.size() >= 2
        std::vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0; // 因为我可以选择0/1开始，所以 dp[1] 也是 0
        for(int i = 2; i <= cost.size(); ++i) {
            dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[dp.size() - 1];
    }
};
```

顺利通过。

## 不同路径

https://leetcode.cn/problems/unique-paths/description/

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

这个题其实也是很简单的，每次走一步。

直接写下代码。

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 想了下这题好像前面不需要特殊处理
        std::vector<std::vector<int>>dp(m, std::vector<int>(n, 0));
        // 先初始化
        dp[0][0] = 1;
        for(int i = 1; i < n; ++i)
            dp[0][i] = 1;
        for(int j = 1; j < m; ++j)
            dp[j][0] = 1;
        // 开始遍历
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```

这题没什么问题，从左上方一直遍历到右下方就可以了。

## 不同路径 II

https://leetcode.cn/problems/unique-paths-ii/description/

跟上面那个题目是一样的，加一个判断即可。

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        // 初始化 
        // 要注意，在第一列和第一行，如果被挡住了，后面的都是0了，因为都过不去
        dp[0][0] = 1;
        bool rowObstacleFlag = false;
        for(int i = 0; i < m; ++i) {
            if(obstacleGrid[i][0] == 1) rowObstacleFlag = true;
            if(rowObstacleFlag == false)
                dp[i][0] = 1;
            else
                dp[i][0] = 0; // 其实不用这样，因为默认是0，只要遇到障碍，直接停止初始化就行了，不过问题不大
        }
        bool colObstacleFlag = false;
        for(int j = 0; j < n; ++j) {
            if(obstacleGrid[0][j] == 1) colObstacleFlag = true;
            if(colObstacleFlag == false)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }
        // 开始遍历
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else if(obstacleGrid[i][j] == 1) {
                    // 有障碍物
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```

一次通过。

## 整数拆分

https://leetcode.cn/problems/integer-break/

给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 

这题一开始没想出来，是因为我想一次遍历搞定，最后发现无论用一维还是二维，都推不出来。

其实答案的方法很简单，一个数字i, 可以分成 i-1, 1; i-2, 2; ...

所以 dp[i] = max((i-j)*j, dp[i-j]\*j)

当然这样还是有bug的
