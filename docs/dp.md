
# 动态规划

- [动态规划](#动态规划)
  - [动态规划理论基础](#动态规划理论基础)
  - [斐波那契数](#斐波那契数)
  - [爬楼梯（可以拓展成完全背包问题）](#爬楼梯可以拓展成完全背包问题)
    - [拓展](#拓展)
  - [使用最小花费爬楼梯](#使用最小花费爬楼梯)
  - [不同路径](#不同路径)
  - [不同路径 II](#不同路径-ii)
  - [整数拆分（需要复习）](#整数拆分需要复习)
  - [不同的二叉搜索树（需要复习）](#不同的二叉搜索树需要复习)
  - [01背包理论基础](#01背包理论基础)
    - [背包问题的分类](#背包问题的分类)
    - [背包问题的解法](#背包问题的解法)
      - [确定 dp 数组的含义](#确定-dp-数组的含义)
      - [确定递推公式](#确定递推公式)
      - [dp数组的初始化](#dp数组的初始化)
      - [确认遍历顺序](#确认遍历顺序)
      - [写代码](#写代码)
  - [01背包理论基础-优化成滚动数组](#01背包理论基础-优化成滚动数组)
    - [一维数组（滚动数组）](#一维数组滚动数组)
    - [递推公式](#递推公式)
    - [dp数组的初始化](#dp数组的初始化-1)
    - [dp数组的遍历](#dp数组的遍历)
    - [代码](#代码)
  - [分割等和子集（01背包可以判断：是否装满的问题）](#分割等和子集01背包可以判断是否装满的问题)
  - [最后一块石头的重量 II](#最后一块石头的重量-ii)
  - [目标和（装满背包，有几种方法）](#目标和装满背包有几种方法)
    - [先转化为背包问题](#先转化为背包问题)
    - [和之前的问题区分开来‼️ 为什么这里初始化不一样？](#和之前的问题区分开来️-为什么这里初始化不一样)
    - [二维数组](#二维数组)
    - [一维数组](#一维数组)
  - [一和零（需要复习）](#一和零需要复习)
  - [完全背包理论基础-二维数组](#完全背包理论基础-二维数组)
    - [确定dp数组以及下标的含义](#确定dp数组以及下标的含义)
    - [确定递推公式](#确定递推公式-1)
    - [dp数组如何初始化](#dp数组如何初始化)
    - [确定遍历顺序](#确定遍历顺序)
    - [写代码](#写代码-1)
  - [完全背包理论-一维数组](#完全背包理论-一维数组)
  - [零钱兑换II](#零钱兑换ii)
    - [二维dp自己思考](#二维dp自己思考)
    - [一维dp（重要！细节很多，需要复习！）](#一维dp重要细节很多需要复习)
  - [组合总和 Ⅳ](#组合总和-ⅳ)
  - [爬楼梯（进阶版）](#爬楼梯进阶版)
  - [零钱兑换](#零钱兑换)
    - [自己尝试](#自己尝试)
  - [完全平方数](#完全平方数)
  - [单词拆分（这个题目有点没有理解，需要复习）](#单词拆分这个题目有点没有理解需要复习)
  - [多重背包理论基础](#多重背包理论基础)
  - [背包问题总结篇](#背包问题总结篇)
    - [递推公式](#递推公式-1)
    - [遍历顺序](#遍历顺序)
      - [01背包](#01背包)
      - [完全背包](#完全背包)
  - [打家劫舍系列](#打家劫舍系列)
    - [打家劫舍](#打家劫舍)
    - [打家劫舍II（成环应该如何解决）](#打家劫舍ii成环应该如何解决)
    - [打家劫舍III（需要复习）](#打家劫舍iii需要复习)
      - [暴力解法](#暴力解法)
      - [记忆化暴力解法](#记忆化暴力解法)
      - [动态规划](#动态规划-1)
  - [买卖股票系列题目](#买卖股票系列题目)
    - [买卖股票的最佳时机](#买卖股票的最佳时机)
    - [买卖股票的最佳时机II](#买卖股票的最佳时机ii)
    - [买卖股票的最佳时机III](#买卖股票的最佳时机iii)
    - [买卖股票的最佳时机IV](#买卖股票的最佳时机iv)
    - [买卖股票的最佳时机含手续费](#买卖股票的最佳时机含手续费)
    - [买卖股票的最佳时机含冷冻期](#买卖股票的最佳时机含冷冻期)
  - [最长递增子序列](#最长递增子序列)
  - [最长连续递增序列](#最长连续递增序列)
  - [最长重复子数组（需要复习，经典题目）](#最长重复子数组需要复习经典题目)
    - [确定dp数组含义](#确定dp数组含义)
    - [确定递推公式](#确定递推公式-2)
    - [dp数组的初始化](#dp数组的初始化-2)
    - [确认遍历顺序](#确认遍历顺序-1)
    - [二维数组版本代码](#二维数组版本代码)
    - [滚动数组](#滚动数组)
    - [拓展](#拓展-1)
  - [最长公共子序列](#最长公共子序列)
  - [不相交的线](#不相交的线)
  - [最大子数组和](#最大子数组和)
  - [判断子序列（需要复习）](#判断子序列需要复习)
  - [不同的子序列（难）](#不同的子序列难)
    - [dp数组的含义](#dp数组的含义)
    - [确定递推公式](#确定递推公式-3)
    - [初始化](#初始化)
    - [代码](#代码-1)
  - [两个字符串的删除操作](#两个字符串的删除操作)
  - [编辑距离](#编辑距离)
  - [回文子串](#回文子串)
  - [最长回文子序列](#最长回文子序列)
  - [动态规划总结篇](#动态规划总结篇)
    - [动态规划基础问题](#动态规划基础问题)
    - [背包问题](#背包问题)
    - [打家劫舍系列](#打家劫舍系列-1)


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

## 整数拆分（需要复习）

https://leetcode.cn/problems/integer-break/

给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 

这题一开始没想出来，是因为我想一次遍历搞定，最后发现无论用一维还是二维，都推不出来。

其实答案的方法很简单，一个数字i, 可以分成 i-1, 1; i-2, 2; ...

所以 dp[i] = max((i-j)*j, dp[i-j]\*j)

当然这样还是有bug的

因为这个是在循环里面的，所以其实每次计算都要取最大的自己。毕竟每一轮计算j都能得到一个dp[i]

所以就可以写代码了！

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1; // 2 可以拆分，但1确实没有意义！
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j <= i / 2; j++) { // i/2其实相当于掠过了一些步骤，其实这些步骤是可以略过的，这个也很好理解。
                // dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
```


## 不同的二叉搜索树（需要复习）

https://leetcode.cn/problems/unique-binary-search-trees/description/

给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

这题是有点难度，不容易想到的。这部分内容来自 Carl。

首先先把 n=1, 2, 3 的情况列出来：

![](https://file1.kamacoder.com/i/algo/20210107093106367.png)

![](https://file1.kamacoder.com/i/algo/20210107093129889.png)

是可以推出来。

dp[3] 可以由 dp[2] 和 dp[1] 和 dp[0] 来推出来

![](https://file1.kamacoder.com/i/algo/20210107093226241.png)

感觉这里有点像二项式的展开。

然后我在草稿纸上画了一下，dp[4]也是同样道理的

dp[4] 这个二叉树，有可能是1，2，3，4分别做根。

dp[4] 当用1作为根的时候：左子树就是 dp[0] 很容易理解，右子树就是 dp[3] \
用2作为根的时候，同理。

所以感觉可以按这思路写代码了。

```cpp
class Solution {
public:
    int numTrees(int n) {
        if(n == 1) return 1;
        std::vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) { // 遍历每个数作为根
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
```

这个题有点意思，按照思路写是可以顺利通过的。

这个题需要复习，确实dp还是难啊，有些题还是挺难想到的。


## 01背包理论基础

此部分内容全部来自代码随想录：https://programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

https://kamacoder.com/problempage.php?pid=1046

01背包题目描述：

```
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 

小明的行李空间为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。
```

### 背包问题的分类

对于面试的话，其实掌握01背包和完全背包，就够用了，最多可以再来一个多重背包。

**所有背包问题可以这样分类，做题的时候要直接区分好。**

![](https://file1.kamacoder.com/i/algo/20210117171307407.png)

当然，01背包和完全背包掌握就可以了，其他类型的背包就是竞赛级别的了。

### 背包问题的解法

例子：

背包最大重量为4。

物品为：

重量	价值 \
物品0	1	15 \
物品1	3	20 \
物品2	4	30 

#### 确定 dp 数组的含义

因为有两个维度需要分别表示：物品 和 背包容量。

![](https://file1.kamacoder.com/i/algo/20210110103003361.png)

其实图里的背包重量，是容量的意思。感觉用重量会有一点 confuse。

这里Carl是为了解释dp数组的含义，用了一大段话的，因为比较好理解，所以这里我略过。

结论：

**即 `dp[i][j]` 表示从下标为 `[0-i]` 的物品里任意取，放进容量为j的背包，价值总和最大是多少。**

#### 确定递推公式

就拿 dp[1][4] 举例子。

首先，dp[1][4] 的意思是，在0-1的物品中任取，背包容量为4可以得到的最大价值是多少。

然后 dp[1][4] 可以分为两种情况：
- 拿物品1
- 不拿物品1

如果不拿物品1：结果不就是 dp[0][4] 吗。

如果拿物品1：那就表示已经确定有物品1的价值了，另外的再说。

怎么再说呢：如果拿了物品1，那么背包的容量就只有 4 - weight[1] 了。这个很好理解

因此，此时 dp[1][4] 中拿物品1 = dp[1-1][4-weight[1]] + value[1]。即 dp[0][1] + value[1] 了。

因此可以抽象化：

- 不放物品i：背包容量为j，里面不放物品i的最大价值是dp[i - 1][j]。

- 放物品i：背包空出物品i的容量后，背包容量为j - weight[i]，dp[i - 1][j - weight[i]] 为背包容量为j - weight[i]且不放物品i的最大价值，那么dp[i - 1][j - weight[i]] + value[i] （物品i的价值），就是背包放物品i得到的最大价值

**因此递推公式：**

`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);`

#### dp数组的初始化

首先，如果背包容量为0，则无论有几个物体，都一样，价值只能是0。

![](https://file1.kamacoder.com/i/algo/2021011010304192.png)

然后看看，递推公式。

`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);`

所以i要从1开始，i=0的情况也需要初始化。

第一行初始化也很简单，如果背包重量够，0就放进去呗，如果不够，就不放呗。

#### 确认遍历顺序

先遍历重量好呢还是遍历物品好呢？其实都可以，只是说遍历物品会好理解一些。

然后这道题，很明显可以看出，dp[i][j] 是从它的左上角来的。

**然后其实Carl说：其实背包问题里，两个for循环的先后循序是非常有讲究的，理解遍历顺序其实比理解推导公式难多了。**

#### 写代码

按照上面的思路，顺利通过了。

```cpp


#include <iostream>
#include <algorithm>
#include <vector>

/**
    6 1
    2 2 3 1 5 2
    2 3 1 5 4 3
 */

int binaryKnapsackProblem(const int &capacity, const std::vector<int> &weight, const std::vector<int> &value)
{
    int n = weight.size(); // 物品的数量
    // 创建一个dp数组再说
    std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0)); // 先全部初始化为0
    // 然后第一列都是初始化为0，就不用处理了，处理第一行
    for (int j = 0; j < capacity + 1; j++)
    {
        // j 表示当前背包的容量, 看看第一行能否放入物品0
        if (j < weight[0])
            dp[0][j] = 0;
        else
            dp[0][j] = value[0];
    }
    // 初始化完成了
    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 0; j < capacity + 1; ++j)
        {
            if (j < weight[i])
            {
                // 物品 i 一定放不了
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // 选择放物品i
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    int n = 0, capacity = 0;
    std::cin >> n >> capacity;
    std::vector<int> weight(n, 0);
    std::vector<int> value(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> weight[i];
    for (int i = 0; i < n; ++i)
        std::cin >> value[i];

    std::cout << binaryKnapsackProblem(capacity, weight, value) << std::endl;

    return 0;
}
```

## 01背包理论基础-优化成滚动数组

### 一维数组（滚动数组）

以下内容全部来自于Carl: https://programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.html#%E6%80%9D%E8%B7%AF

对于背包问题其实状态都是可以压缩的。

在使用二维数组的时候，递推公式：`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);`

其实可以发现如果把dp[i - 1]那一层拷贝到dp[i]上，表达式完全可以是：`dp[i][j] = max(dp[i][j], dp[i][j - weight[i]] + value[i]);`

与其把dp[i - 1]这一层拷贝到dp[i]上，不如只用一个一维数组了，只用dp[j]（一维数组，也可以理解是一个滚动数组）。

**这就是滚动数组的由来，需要满足的条件是上一层可以重复利用，直接拷贝到当前层。**

### 递推公式

压缩后的递推公式为：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);`

### dp数组的初始化

初始化为0.

### dp数组的遍历

```cpp
for(int i = 0; i < weight.size(); i++) { // 遍历物品
    for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    }
}
```

这里大家发现和二维dp的写法中，遍历背包的顺序是不一样的！

二维dp遍历的时候，背包容量是从小到大，而一维dp遍历的时候，背包是从大到小。

为什么呢？

倒序遍历是为了保证物品i只被放入一次！。但如果一旦正序遍历了，那么物品0就会被重复加入多次！

举一个例子：物品0的重量 `weight[0] = 1`，价值 `value[0] = 15`

如果正序遍历

`dp[1] = dp[1 - weight[0]] + value[0] = 15`

`dp[2] = dp[2 - weight[0]] + value[0] = 30`

此时dp[2]就已经是30了，意味着物品0，被放入了两次，所以不能正序遍历。

为什么倒序遍历，就可以保证物品只放入一次呢？

倒序就是先算dp[2]

`dp[2] = dp[2 - weight[0]] + value[0] = 15` （dp数组已经都初始化为0）

`dp[1] = dp[1 - weight[0]] + value[0] = 15`

所以从后往前循环，每次取得状态不会和之前取得状态重合，这样每种物品就只取一次了。

那么问题又来了，为什么二维dp数组遍历的时候不用倒序呢？

因为对于二维dp，dp[i][j]都是通过上一层即dp[i - 1][j]计算而来，本层的dp[i][j]并不会被覆盖！

（如何这里读不懂，大家就要动手试一试了，空想还是不靠谱的，实践出真知！）

再来看看两个嵌套for循环的顺序，代码中是先遍历物品嵌套遍历背包容量，那可不可以先遍历背包容量嵌套遍历物品呢？

**不可以！**

因为一维dp的写法，背包容量一定是要倒序遍历（原因上面已经讲了），如果遍历背包容量放在上一层，那么每个dp[j]就只会放入一个物品，即：背包里只放入了一个物品。

所以一维dp数组的背包在遍历顺序上和二维其实是有很大差异的！，这一点大家一定要注意。


### 代码

```cpp


#include <iostream>
#include <algorithm>
#include <vector>

/**
    6 1
    2 2 3 1 5 2
    2 3 1 5 4 3
 */

int binaryKnapsackProblem(const int &capacity, const std::vector<int> &weight, const std::vector<int> &value)
{
    int n = weight.size(); // 物品的数量
    // 创建一个dp数组再说
    // std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0)); // 先全部初始化为0
    std::vector<int> dp(capacity + 1, 0);
    // 然后第一列都是初始化为0，就不用处理了，处理第一行
    // for (int j = 0; j < capacity + 1; j++)
    // {
    //     // j 表示当前背包的容量, 看看第一行能否放入物品0
    //     if (j < weight[0])
    //         dp[0][j] = 0;
    //     else
    //         dp[0][j] = value[0];
    // }
    // 初始化完成了
    for (int i = 0; i < n; ++i)
        for (int j = capacity; j >= weight[i]; --j)
                // 选择放物品i
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
    return dp[capacity];
}

int main()
{
    int n = 0, capacity = 0;
    std::cin >> n >> capacity;
    std::vector<int> weight(n, 0);
    std::vector<int> value(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> weight[i];
    for (int i = 0; i < n; ++i)
        std::cin >> value[i];

    std::cout << binaryKnapsackProblem(capacity, weight, value) << std::endl;

    return 0;
}
```

这个确实难啊，需要好好复习

## 分割等和子集（01背包可以判断：是否装满的问题）

https://leetcode.cn/problems/partition-equal-subset-sum/description/

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

输入：nums = [1,5,11,5] \
输出：true \
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

**那么这道题就是 装满 承载重量为 `sum / 2` 的背包，价值最大是多少？**

**如果最大价值是 `sum / 2`，说明正好被商品装满了。**

先自己尝试写写代码。

```cpp
class Solution {
private:
    int binaryKnapsackProblem(int capacity, const std::vector<int>& weight, const std::vector<int>& value) {
        int n = weight.size();
        std::vector<int> dp(capacity + 1, 0);
        for(int i = 0; i < n; ++i)
            for(int j = capacity; j >= weight[i]; j--)
                dp[j] = std::max(dp[j], dp[j-weight[i]] + value[i]);
        return dp[capacity];
    }
public:
    bool canPartition(vector<int>& nums) {
        // [1,5,11,5] 假设这个是有四个物品，每个物品重量为1，背包容量为sum/2的背包问题
        // 求是否能将一个 sum / 2 的背包装满
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false; // 如果和是奇数，直接返回就行了
        // 构造 0-1 背包问题
        // nums 就是 weight
        int res = binaryKnapsackProblem(sum / 2, nums, nums);
        if (res == sum / 2) return true;
        return false;
    }
};
```

顺利通过。

**做完本题后，需要大家清晰：背包问题，不仅可以求背包能被的最大价值，还可以求这个背包是否可以装满。**

**一个数字只有一个维度，即 重量等于价值。**

## 最后一块石头的重量 II

https://leetcode.cn/problems/last-stone-weight-ii/description/

有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。



还是要灵活一点，一开始一直想，怎么转化成背包问题。

**‼️其实很简单啊：分成尽量相同重量的两堆，相减就是最后的结果啊。**

其实就是背包最多能装多少，假设 res 是背包求解结果，(sum/2-res)*2就是最后的结果。

直接写代码吧。

```cpp
class Solution {
private:
    int binaryKnapsackProblem(double capacity, const std::vector<int>& weight, const std::vector<int>& value) {
        int n = weight.size();
        auto dp = std::vector<int>(capacity + 1, 0);
        for(int i = 0; i < n; ++i)
            for(int j = capacity; j >= weight[i]; --j)
                dp[j] = std::max(dp[j], dp[j-weight[i]]+value[i]);
        return dp[capacity];
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        double sum = std::accumulate(stones.begin(), stones.end(), 0);
        double res = binaryKnapsackProblem(sum / 2, stones, stones);
        return (sum/2 - res) * 2;
    }
};
```

顺利通过。

## 目标和（装满背包，有几种方法）

https://leetcode.cn/problems/target-sum/description/

给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

感觉这题是有难度的。

### 先转化为背包问题

分成两堆，a是第一堆的和，b是第二堆的和。最后的结果 target = a - b。

同时 a + b = sum，sum是已知的

所以两式相加: 2a = sum + target

所以结果就是找，填满 (sum + target)/2 背包，有几种方法。

### 和之前的问题区分开来‼️ 为什么这里初始化不一样？

之前的问题是：能否填满背包。

现在的问题是：填满背包有多少种方法。

第一列如何初始化，是要看清楚题目的！

因为在这道题里面，weight可以为0，所以装满0的背包，可以有多种方法，所以第一列不一定完全是0。

- 如果weight都是正的，那么无论value是多少，第一列都是0。这个很好理解。
- 如果weight有可能为0，但是在题目语境中，weight和value是同一个东西
  - 如果是问装满的数量有多少种（比如这题），那么第一列有可能是需要初始化的！不一定都是0。
  - 如果问的能否装满，或者最大value的问题，拿第一列还是0。其实这个也很好理解！

在01背包理论基础中，我们的问题是：背包最大能装多少。



### 二维数组

关于递推公式：

比如：dp[2][2] = 容量为2的背包不放物品2有几种方法 + 容量为2的背包放物品2有几种方法

通过之前对01背包的了解，理解这个递推公式不困难。之前是求最大值，现在就是，符合条件的相加即可。

```cpp
if (nums[i] > j) dp[i][j] = dp[i - 1][j]; 
else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
```

然后第一行如何初始化呢，其实很简单，能刚好装满的就设置成1呗，其他就设置成0。

那第一列呢，第一列全部是0是错的。在这道题里面，因为物品重量有可能是0。

如果物品中有一个0，则只有2种，很好理解（不放和放一个），如果物品中有两个，那就是4中。如果物品中有3个0，则是4种了。它是2的指数倍。

所以初始化要这样写：

```cpp
// 初始化最上行
if (nums[0] <= bagSize) dp[0][nums[0]] = 1; 

// 初始化最左列，最左列其他数值在递推公式中就完成了赋值
dp[0][0] = 1; 

int numZero = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) numZero++;
    dp[i][0] = (int) pow(2.0, numZero);
}
```

所以可以写代码。

```cpp
class Solution {
private:
    int binaryKnapsackProblem(int capacity, std::vector<int>& weight, std::vector<int> value) {
        // weight == value
        int n = weight.size(); // 物品的个数
        auto dp = std::vector<std::vector<int>>(n, std::vector<int>(capacity + 1, 0));
        // 初始化第一行：刚好重量的可以放进去
        if(capacity >= weight[0]) dp[0][weight[0]] = 1;
        // 初始化第一列
        int zeros = 0;
        for(int i = 0; i < n; ++i) {
            if(weight[i] == 0) zeros++;
            dp[i][0] = (int)pow(2.0, zeros);
        }
        // 开始遍历
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= capacity; ++j) {
                if(j < weight[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-weight[i]];
            }
        }
        return dp[n-1][capacity];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // (target + sum) / 2
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(std::abs(target) > sum) return 0; // target太大了
        if((target + sum) % 2 == 1) return 0;
        return binaryKnapsackProblem((target + sum) / 2, nums, nums);
    }
};
```

顺利通过。

### 一维数组

```cpp
class Solution {
private:
    int binaryKnapsackProblem(int capacity, std::vector<int>& weight, std::vector<int> value) {
        int n = weight.size();
        // 用一维数组
        auto dp = std::vector<int>(capacity + 1, 0);
        dp[0] = 1; // 这里需要理解，不过之前在二维数组中 dp[0][0] 就是 1
        for(int i = 0; i < n; ++i) {
            for(int j = capacity; j >= weight[i]; --j) {
                dp[j] += dp[j-weight[i]];
            }
        }
        return dp[capacity];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(std::abs(target) > sum) return 0;
        if((target + sum ) % 2 == 1) return 0;
        return binaryKnapsackProblem((target + sum) / 2, nums, nums);
    }
};
```

顺利通过。

## 一和零（需要复习）

内容来自 Carl。

https://leetcode.cn/problems/ones-and-zeroes/

给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

**这一题其实不是多重背包。**

**本题中strs 数组里的元素就是物品，每个物品都是一个！**

**而m 和 n相当于是一个背包，两个维度的背包。**


`dp[i][j]` 可以表示，在strs数组中，最多m个0n个1的最大子集的长度。

`dp[i][j]` 可以由前一个strs里的字符串推导出来，strs里的字符串有zeroNum个0，oneNum个1。

`dp[i][j]` 就可以是 `dp[i - zeroNum][j - oneNum] + 1`。

然后我们在遍历的过程中，取dp[i][j]的最大值。

所以递推公式：`dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);`

此时大家可以回想一下01背包的递推公式：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);`

对比一下就会发现，字符串的zeroNum和oneNum相当于物品的重量（weight[i]），字符串本身的个数相当于物品的价值（value[i]）。

这就是一个典型的01背包！ 只不过物品的重量有了两个维度而已。

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0)); // 初始化为0
        // 遍历所有物品
        for(const auto& e : strs) {
            // e: std::string
            // 计算这个字符串0的个数和1的个数
            int zeros = 0, ones = 0;
            for(const auto& ee : e) {
                if(ee == '0') zeros++;
                else if(ee == '1') ones++;
            }
            // 处理背包
            for(int i = m; i >= zeros; i--) {
                for(int j = n; j >= ones; j--) {
                    dp[i][j] = std::max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```

这题挺难的，需要重新复习，背包问题的理解还不够。

## 完全背包理论基础-二维数组

内容全部来自：https://programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85.html#%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85


题目：https://kamacoder.com/problempage.php?pid=1052

有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。

**完全背包和01背包问题唯一不同的地方就是，每种物品有无限件。**

使用同样的例子：

重量	价值 \
物品0	1	15 \
物品1	3	20 \
物品2	4	30 

### 确定dp数组以及下标的含义

`dp[i][j]` 表示从下标为 `[0-i]` 的物品，每个物品可以取无限次，放进容量为j的背包，价值总和最大是多少。

这个定义和之前的定义其实就是类似的。


### 确定递推公式

思路还是一样的，就拿 dp[1][4] 来举例子。

dp[1][4]: 从下标 0-1 中的物品，放到容量为4的背包。

同样可以区分为拿物品1和不拿物品1：
- 如果不放物品1: 仍然是dp[0][4]，就是从下标0-0中的物品拿到容量为4的背包中去。
- 如果放物品1: 这里和01背包就有区别了！！！！

**如果放物品1:**

在01背包中，背包先空留出物品1的容量，此时容量为1，只考虑放物品0的最大价值是 `dp[0][1]`，因为01背包每个物品只有一个，既然空出物品1，那背包中也不会再有物品1！

而在完全背包中，物品是可以放无限个，所以 即使空出物品1空间重量，那背包中也可能还有物品1，所以此时我们依然考虑放 物品0 和 物品1 的最大价值即： `dp[1][1]`， 而不是 `dp[0][1]`。


**就这里一个区别‼️**

所以：`dp[1][4] = max(dp[0][4], dp[1][1] + 物品1 的价值)`

所以递推公式：`dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);`

### dp数组如何初始化

首先从dp[i][j]的定义出发，如果背包容量j为0的话，即dp[i][0]，无论是选取哪些物品，背包价值总和一定为0。

所以第一列一定是0。在这个问题下一定是0，有可能在变形问题中不一定。详情请见：[这个章节我解释了](#和之前的问题区分开来️-为什么这里初始化不一样)

**记住：具体需要初始化什么，是根据递推公式来决定的！**

`dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);`

很明显需要 i-1, 所以 i=0 的情况都要去处理一下。

`dp[0][j]`，即：存放编号0的物品的时候，各个容量的背包所能存放的最大价值。

那么很明显当 `j < weight[0]` 的时候，`dp[0][j]` 应该是 0，因为背包容量比编号0的物品重量还小。

当 `j >= weight[0]` 时，`dp[0][j]` 如果能放下weight[0]的话，就一直装，每一种物品有无限个。

初始化代码如下所示：

```cpp
for (int i = 1; i < weight.size(); i++) {  // 当然这一步，如果把dp数组预先初始化为0了，这一步就可以省略，但很多同学应该没有想清楚这一点。
    dp[i][0] = 0;
}

// 正序遍历，如果能放下就一直装物品0
for (int j = weight[0]; j <= bagWeight; j++)
    dp[0][j] = dp[0][j - weight[0]] + value[0];
```

下面这个第一行的代码有点巧妙的。它其实是对的，不一定weight[0]==1才能用，都能用的。挺巧妙。

### 确定遍历顺序

和01背包是一样的。

### 写代码

写一下完整的代码。

```cpp


// 完全背包问题


#include <iostream>
#include <vector>
#include <algorithm>

/**
4 5
1 2
2 4
3 4
4 5
 */

int unboundedKnapsackProblem(const int &capacity, const std::vector<int> &weight, const std::vector<int> &value)
{
    int n = weight.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0));
    // 初始化
    // 初始化第一列，默认是0
    // 初始化第一行
    for (int j = weight[0]; j <= capacity; j++)
    {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }
    // 开始dp
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= capacity; ++j)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    int n = 0;        // 物品数量
    int capacity = 0; // 背包能承受的重量
    std::vector<int> weight;
    std::vector<int> value;
    std::cin >> n >> capacity;
    for (int i = 0; i < n; ++i)
    {
        int w, v;
        std::cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    std::cout << unboundedKnapsackProblem(capacity, weight, value) << std::endl;
    return 0;
}
```

顺利通过，不错！也算复习了一次背包问题的写法。

## 完全背包理论-一维数组

内容全部来自Carl: http://programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E4%B8%80%E7%BB%B4.html

结论：和之前的都是一样的！

**唯一的区别是：**

- 一维dp数组的两个for循环先后循序一定是先遍历物品，再遍历背包容量。

- 在完全背包中，对于一维dp数组来说，其实两个for循环嵌套顺序是无所谓的！

试试写代码：

题目：https://kamacoder.com/problempage.php?pid=1052

```cpp
int unboundedKnapsackProblem(const int &capacity, const std::vector<int> &weight, const std::vector<int> &value)
{
    int n = weight.size();
    std::vector<int> dp(capacity + 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= capacity; j++) {
            if(j >= weight[i]) dp[j] = std::max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    return dp[capacity];
}
```

**注意：**

来自Carl。

细心的同学可能发现，全文我说的都是对于纯完全背包问题，其for循环的先后循环是可以颠倒的！

但如果题目稍稍有点变化，就会体现在遍历顺序上。

**如果问装满背包有几种方式的话？ 那么两个for循环的先后顺序就有很大区别了，而leetcode上的题目都是这种稍有变化的类型。**

这个区别，我将在后面讲解具体leetcode题目中给大家介绍，因为这块如果不结合具题目，单纯的介绍原理估计很多同学会越看越懵！

**最后，又可以出一道面试题了，就是纯完全背包，要求先用二维dp数组实现，然后再用一维dp数组实现，最后再问，两个for循环的先后是否可以颠倒？为什么？**

这个简单的完全背包问题，估计就可以难住不少候选人了。

## 零钱兑换II

https://leetcode.cn/problems/coin-change-ii/description/

给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

要注意了，这题就是前面说的：有几种装满的方法的问题。

我感觉可以先自己尝试用二维数组的方法思考一下。

### 二维dp自己思考

经典完全背包问题的递推公式：

```cpp
dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
```

但是这题是：求装满的方法有几种，不是经典的问题。

所以递推公式应该是：这个具体为什么，可以看[这题](#目标和装满背包有几种方法)

```cpp
dp[i][j] = dp[i - 1][j] + dp[i][j - weight[i]];
```

**初始化：**

首先先看看题目给的信息：

1 <= coins.length <= 300 \
1 <= coins[i] <= 5000 \
coins 中的所有值 互不相同 \
0 <= amount <= 5000

硬币没有0的，所以：

第一行来说，因为硬币0有无限个，所以能拿多少拿多少，当然因为他是问凑满的方法有几种，所以是可以整除的时候才能初始化为1！

对于第一列来说，因为因为硬币>=1，所以应该都是0（这是我一开始想的，这是错误的❌‼️‼️）

第一列应该是1，都有一种方法：就是不放！

尝试写代码：


```cpp
class Solution {
private:
    int unboundedKnapsackProblem(int capacity, const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<uint64_t>> dp(n, std::vector<uint64_t>(capacity + 1, 0));
        // 初始化
        // 第一行
        for(int j = 0; j <= capacity; j++) 
            if(j % nums[0] == 0) dp[0][j] = 1;
        // 第一列都是1
        for(int i = 0; i < n; ++i) 
            dp[i][0] = 1;
        // dp
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= capacity; j++) {
                if(j < nums[i]) dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-nums[i]];
            }
        }
        return dp[n-1][capacity];
    }
public:
    int change(int amount, vector<int>& coins) {
        return unboundedKnapsackProblem(amount, coins);
    }
};
```

顺利通过，其实我是可以自己写出来的。要注意的地方：
- 就是前面初始化那里要注意下，第一列是1不是0。
- 另外，递推公式那里，是不用最后加一个 `nums[i]` 的‼️‼️


### 一维dp（重要！细节很多，需要复习！）

首先dp公式不用说：`dp[j] += dp[j - coins[i]]`

然后 dp[0] 是 1。这个也不用说，装满0的背包有一种方法：就是不用装。

这里的细节在于：确认遍历顺序！

**确定遍历顺序**

本题中我们是外层for循环遍历物品（钱币），内层for遍历背包（金钱总额），还是外层for遍历背包（金钱总额），内层for循环遍历物品（钱币）呢？

我在完全背包（一维DP）中讲解了完全背包的两个for循环的先后顺序都是可以的。

但本题就不行了！

**因为纯完全背包求得装满背包的最大价值是多少，和凑成总和的元素有没有顺序没关系，即：有顺序也行，没有顺序也行！‼️**

**而本题要求凑成总和的组合数，元素之间明确要求没有顺序。**

所以纯完全背包是能凑成总和就行，不用管怎么凑的。

本题是求凑出来的方案个数，且每个方案个数是**组合数**。


- **i在外面（也就是先遍历物品）的方式：dp[j]里计算的是组合数！‼️**

- **j在外面（也就是先遍历背包容量）的方式：此时dp[j]里算出来的就是排列数！‼️**

很明显这道题是需要组合数的，因为硬币没有顺序。

所以直接写代码：

```cpp
class Solution {
private:
    int unboundedKnapsackProblem(int capacity, const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<uint64_t> dp(capacity + 1, 0);
        dp[0] = 1;
        // dp
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= capacity; ++j) {
                if(j >= nums[i]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[capacity];
    }
public:
    int change(int amount, vector<int>& coins) {
        return unboundedKnapsackProblem(amount, coins);
    }
};
```

## 组合总和 Ⅳ

https://leetcode.cn/problems/combination-sum-iv/description/

给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

示例 1：

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
**请注意，顺序不同的序列被视作不同的组合。**

这题也是经典的完全背包了，不过这里要找的是排列数，题目写的很清楚。然后这题是找装满背包的方法。

直接写代码吧。

```cpp
class Solution {
private:
    int unboundedKnapsackProblem(int capacity, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<uint32_t>(capacity + 1, 0);
        dp[0] = 1;
        for(int j = 0; j <= capacity; j++) {
            for(int i = 0; i < n; ++i) {
                if(j >= nums[i]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[capacity];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return unboundedKnapsackProblem(target,nums);
    }
};
```

顺利通过。

## 爬楼梯（进阶版）

https://kamacoder.com/problempage.php?pid=1067

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 

每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 

注意：给定 n 是一个正整数。

输入共一行，包含两个正整数，分别表示n, m

输出一个整数，表示爬到楼顶的方法数。

**首先是个完全背包。然后是求装满的方法。然后是排列数。这些都很明显，不多赘述了。**

直接写：

```cpp
#include <iostream>
#include <vector>

int unboundedKnapsackProblem(int target, int m) {
    auto dp = std::vector<int>(target + 1, 0);
    dp[0] = 1;
    for(int j = 0; j <= target; j++) {
        for(int i = 1; i <= m; ++i) {
            if(j >= i) dp[j] += dp[j - i];
        }
    }
    return dp[target];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << unboundedKnapsackProblem(n, m) << std::endl;
    return 0;
}
```

顺利通过。m我就直接用了，不过如果要弄个数组也是一样的，没区别。

## 零钱兑换

https://leetcode.cn/problems/coin-change/description/

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 **最少的硬币个数** 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

### 自己尝试

首先可以确定的是，硬币数量是无限的，所以是完全背包。

然后求的问题和之前不太一样，是求最少的硬币个数，那就重新推导一下。

那就用 dp[j] 表示在背包容量为 j 的情况下，填满背包需要最少的物品个数是多少。

那么递推公式呢：

分成两种情况：

- 不要物品i：那需要的个数就是：dp[j] = dp[j]
- 需要物品i：那就是 `dp[j] = std::min(dp[j], dp[j-weight[i]] + 1)`
  - 需要物品i的时候，就先排除物品i，然后拿多一个物品

装满0的背包需要最少的物品个数是0。

**遍历顺序呢？**

因为是求物品的个数，所以是没区别的，都可以。

尝试写下代码看看对不对：

```cpp
class Solution {
private:
    int unboundedKnapsackProblem(int target, std::vector<int>& coins) {
        int n = coins.size();
        auto dp = std::vector<long long>(target + 1, INT_MAX);
        // 初始化
        dp[0] = 0; // 装满0最少需要0个物品
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= target; ++j) {
                if(j >= coins[i]) dp[j] = std::min(dp[j], dp[j-coins[i]] + 1);
            }
        }
        return dp[target] == INT_MAX ? -1 : dp[target];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return unboundedKnapsackProblem(amount, coins);
    }
};
```

直接通过了！

这是我第一道，通过自己思考顺利一次做出来的背包问题变形题型，太爽！

- 首先求最小，肯定不能初始化为0啊。
- 然后最后如果还是INTMAX，说明根本没办法，所以按照题目要求返回-1。

## 完全平方数

https://leetcode.cn/problems/perfect-squares/description/


给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

1 <= n <= 10^4

就是一个完全背包问题，target就是整数n，然后nums就是一些完全平方数。

这个题是求最小数量，这就是和上面那道题是同一个道理啊。

很简单，直接先试下写代码。

```cpp
class Solution {
private:
    int unboundedKnapsackProblem(int target, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<int>(target + 1, INT_MAX);
        dp[0] = 0; // 装满容量为0的背包最少需要0个物品
        // 因为是求数量，所以无论是组合还是排列都是正确的
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= target; ++j) {
                if(j >= nums[i]) dp[j] = std::min(dp[j], dp[j-nums[i]] + 1);
            }
        }
        return dp[target] == INT_MAX ? -1 : dp[target];
    }
public:
    int numSquares(int n) {
        // 1 <= n <= 10^4
        // O(n)
        std::vector<int> nums;
        for(int i = 1; ;++i)
            if(i * i <= n) nums.push_back(i * i);
            else break;
        // 12
        // debug
        // for(const auto& e : nums) 
        //     std::cout << e << " ";
        // 完全背包问题
        return unboundedKnapsackProblem(n, nums);
        // return 0;
    }
};
```

思路没问题。对比Carl的方法，我多了一次 O(n) 的遍历。但是因为数量级最后就是 O(n)。我这样写会比较清晰，可以清晰看到物品的list是什么。

## 单词拆分（这个题目有点没有理解，需要复习）

https://leetcode.cn/problems/word-break/description/

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

 

示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

这个是完全背包的变形问题。

这题一下没想出来，用dp五部曲里尝试一下。

**确定dp数组的含义：**

dp[i]表示，字符串长度为i，且这个字符串可以由 `wordDict` 中的内容构成。

**确定dp的递推公式：**

如果dp[j]是true，而且 [j, i] 区间这个字符串在 `wordDict` 中是有的，这种情况下 dp[i] 是为 true

**dp数组如何初始化**

从递推公式中可以看出，dp[i] 的状态依靠 dp[j]是否为true，那么dp[0]就是递推的根基，dp[0]一定要为true，否则递推下去后面都都是false了。

**遍历顺序如何**

很明显这道题是求排列的。跟顺序是有关系的。

写一下代码：

```cpp
class Solution {
private:
    bool unboundedKnapsackProblem(const std::string& target, const std::vector<string>& wordDict) {
        std::unordered_set<std::string> sset(wordDict.begin(), wordDict.end());
        int n = wordDict.size();
        auto dp = std::vector<bool>(target.size() + 1, false);
        dp[0] = true; // 这里要注意，不然后面全是 false 了
        for(int j = 1; j <= target.size(); j++) { // 遍历背包
            for(int i = 0; i < j; i++) {
                std::string str = target.substr(i, j - i);
                if(sset.find(str) != sset.end() && dp[i]) dp[j] = true;
            }
        }
        return dp[target.size()];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return unboundedKnapsackProblem(s, wordDict);
    }
};
```

## 多重背包理论基础

内容来自Carl: https://programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85.html#%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85

题目：[56. 携带矿石资源（第八期模拟笔试）](https://kamacoder.com/problempage.php?pid=1066)

有 `N` 种物品和一个容量为 `V` 的背包。第i种物品最多有 `Mi` 件可用，每件耗费的空间是 `Ci`，价值是 `Wi`。求解将哪些物品装入背包可使这些物品的耗费的空间总和不超过背包容量，且价值总和最大。

多重背包和01背包是非常像的，为什么和01背包像呢？

每件物品最多有 `Mi` 件可用，把 `Mi` 件摊开，其实就是一个01背包问题了。

| 物品   | 重量 | 价值 | 数量 |
|--------|------|------|------|
| 物品0 | 1    | 15   | 2    |
| 物品1 | 3    | 20   | 3    |
| 物品2 | 4    | 30   | 2    |

展开成：

| 物品   | 重量 | 价值 | 数量 |
|--------|------|------|------|
| 物品0 | 1    | 15   | 1    |
| 物品0 | 1    | 15   | 1    |
| 物品1 | 3    | 20   | 1    |
| 物品1 | 3    | 20   | 1    |
| 物品1 | 3    | 20   | 1    |
| 物品2 | 4    | 30   | 1    |
| 物品2 | 4    | 30   | 1    |

就变成01背包了！

**题目：[56. 携带矿石资源（第八期模拟笔试）](https://kamacoder.com/problempage.php?pid=1066)**

你是一名宇航员，即将前往一个遥远的行星。在这个行星上，有许多不同类型的矿石资源，每种矿石都有不同的重要性和价值。你需要选择哪些矿石带回地球，但你的宇航舱有一定的容量限制。 

给定一个宇航舱，最大容量为 C。现在有 N 种不同类型的矿石，每种矿石有一个重量 w[i]，一个价值 v[i]，以及最多 k[i] 个可用。不同类型的矿石在地球上的市场价值不同。你需要计算如何在不超过宇航舱容量的情况下，最大化你所能获取的总价值。

输入：

10 3 \
1 3 4 \
15 20 30 \
2 3 2

输出：

90

```cpp
#include <iostream>
#include <vector>

int boundedKnapsackProblem(int capacity, 
                            const std::vector<int>& weight,
                            const std::vector<int>& value,
                            const std::vector<int>& quantity) {
    // 先展开成01背包问题
    int n = weight.size();
    std::vector<int> new_weight;
    std::vector<int> new_value;
    for(int i = 0; i < n; ++i) {
        int cnt = quantity[i];
        for(int j = 0; j < cnt; ++j) {
            new_weight.push_back(weight[i]);
            new_value.push_back(value[i]);
        }
    }
    // 01背包问题
    n = new_weight.size();
    auto dp = std::vector<int>(capacity + 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = capacity; j >= new_weight[i]; --j) {
            dp[j] = std::max(dp[j], dp[j-new_weight[i]] + new_value[i]);
        }
    }
    return dp[capacity];
}


int main() {
    int capacity = 0, n = 0;
    std::cin >> capacity >> n;
    std::vector<int> weight;
    std::vector<int> value;
    std::vector<int> quantity;
    // input weight
    for(int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        weight.push_back(x);
    }
    // input value
    for(int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        value.push_back(x);
    }   
    // input quantity
    for(int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        quantity.push_back(x);
    }    
    // Bounded Knapsack Problem (BKP)
    std::cout << boundedKnapsackProblem(capacity, weight, value, quantity) << std::endl; 
    return 0;
}
```

运行通过，这个没问题，就是在01背包上多加上一步而已。

当然，也可以用Carl的方法，在遍历的时候展开。

```cpp
    for(int i = 0; i < n; i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            // 以上为01背包，然后加一个遍历个数
            for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++) { // 遍历个数
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }
        }
    }
```

不过我的方法应该是更好理解一些的。

## 背包问题总结篇

### 递推公式

问能否能装满背包（或者最多装多少）：`dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);` ，对应题目如下：
- [416. 分割等和子集](#分割等和子集01背包可以判断是否装满的问题)
- [1049. 最后一块石头的重量II](#最后一块石头的重量-ii)

问装满背包有几种方法：`dp[j] += dp[j - nums[i]]` ，对应题目如下：
- [494. 目标和](#目标和装满背包有几种方法)
- [518. 零钱兑换 II](#零钱兑换ii)
- [377. 组合总和Ⅳ](#组合总和-ⅳ)
- [70. 爬楼梯进阶版（完全背包）](#爬楼梯进阶版)

问背包装满最大价值：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);` 对应题目如下：

- [474. 一和零](#一和零需要复习)

问装满背包所有物品的最小个数：`dp[j] = min(dp[j - coins[i]] + 1, dp[j]);` 对应题目如下：

- [322. 零钱兑换](#零钱兑换)
- [279. 完全平方数](#完全平方数)

### 遍历顺序

#### 01背包

- 二维dp数组解决01背包：先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

- 一维dp数组解决01背包：只能先遍历物品再遍历背包容量，且第二层for循环是从大到小遍历。

**一维dp数组的背包在遍历顺序上和二维dp数组实现的01背包其实是有很大差异的，大家需要注意！**

#### 完全背包

- 纯完全背包的一维dp数组实现，先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

**但是仅仅是纯完全背包的遍历顺序是这样的，题目稍有变化，两个for循环的先后顺序就不一样了。**

- 如果求**组合数**就是外层for循环遍历物品，内层for遍历背包。

- 如果求**排列数**就是外层for遍历背包，内层for循环遍历物品。

**相关题目如下：**

求组合数：
- [518. 零钱兑换II](#零钱兑换ii)

求排列数：
- [377. 组合总和Ⅳ](#组合总和-ⅳ)
- [70. 爬楼梯进阶版](#爬楼梯进阶版)

如果求最小数，那么两层for循环的先后顺序就无所谓了，相关题目如下：

求最小数：
- [322. 零钱兑换](#零钱兑换)
- [279. 完全平方数](#完全平方数)

对于背包问题，其实递推公式算是容易的，难是难在遍历顺序上，如果把遍历顺序搞透，才算是真正理解了。

## 打家劫舍系列

### 打家劫舍

https://leetcode.cn/problems/house-robber/

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

这个题还是很简单的，比较容易能想到。

dp[i] 表示从0-i中打劫，最多获得的金额是多少

`dp[i] = max(dp[i-2] + nums[i], dp[i-1])` 其实就是表示两种状态就行了，表示i到底是要还是不要。

这个递推公式还是很简单的。

然后初始化也是比较简单，`dp[0]`一定是 `nums[0]`, `dp[1]` 一定是 `nums[1]`。

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        auto dp = std::vector<int>(nums.size(), 0);
        dp[0] = nums[0]; dp[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i)    
            dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
        return dp[nums.size()-1];
    }
};
```
顺利通过。

### 打家劫舍II（成环应该如何解决）

https://leetcode.cn/problems/house-robber-ii/description/ 

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，今晚能够偷窃到的最高金额。

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

这里的思路参考了一下Carl。

分成两种情况。

- 如果不考虑尾元素，那么首元素无论选不选，都是无所谓的。
- 如果不考虑首元素，那么尾元素选不选，都是无所谓的。

其实我还没完完全理解这个东西的原理，只理解了个大概。先写下代码吧。

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        auto result1 = _rob(std::vector<int>(nums.begin(), nums.end()-1));
        auto result2 = _rob(std::vector<int>(nums.begin()+1, nums.end()));
        return std::max(result1, result2);
    }
    int _rob(vector<int> nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        auto dp = std::vector<int>(nums.size(), 0);
        dp[0] = nums[0]; dp[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i)    
            dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
        return dp[nums.size()-1];
    }
};
```

顺利通过。

### 打家劫舍III（需要复习）

https://leetcode.cn/problems/house-robber-iii/

小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

![](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)

输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7

首先，这个题肯定是需要获得左右递归函数的值才能进行后续操作，所以一定是后序遍历。

因为需要左右的结果，这种题一定是后序遍历！

然后，最核心的思想，就是分成两种：
1. 偷当前节点
2. 不偷当前节点

#### 暴力解法

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        // 选择偷当前节点
        int val1 = root->val;
        if(root->left)
            val1 += rob(root->left->left) + rob(root->left->right); // 不能左右孩子了
        if(root->right)
            val1 += rob(root->right->left) + rob(root->right->right);
        // 不偷当前节点
        int val2 = rob(root->left) + rob(root->right);
        return std::max(val1, val2);
    }
};
```

可以通过，但超出时间。

#### 记忆化暴力解法

因为在上面这个方法中，rob会被多次调用递归。如果这个 rob(root) 的结果已经被计算过了，就不用重复计算了。

```cpp
class Solution {
public:
    unordered_map<TreeNode*, int> mmap;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        if(mmap[root]) return mmap[root]; // 这里是可以不用find的
        // mmap[root]调用会导致在这里创建了一个 mmap[root]，但是也无所谓，因为后面这里也一定会被创建的
        // 选择偷当前节点
        int val1 = root->val;
        if(root->left)
            val1 += rob(root->left->left) + rob(root->left->right); // 不能左右孩子了
        if(root->right)
            val1 += rob(root->right->left) + rob(root->right->right);
        // 不偷当前节点
        int val2 = rob(root->left) + rob(root->right);
        mmap[root] = std::max(val1, val2);
        return std::max(val1, val2);
    }
};
```

这样是可以通过的。

#### 动态规划

其实本质是一样的。

在数组里面，遍历就是for循环遍历。在这里，遍历就是递归遍历。

核心思路：用一个 pair 来记录，pair.first 表示不偷当前节点的结果。 pair.second 表示偷当前节点的结果。

代码：

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        auto p = _rob(root);
        return std::max(p.first, p.second);
    }
    std::pair<int,int> _rob(TreeNode* root) {
        if(root == nullptr) return {0, 0}; // 如果当前节点为空，取不取都是0
        auto left = _rob(root->left);
        auto right = _rob(root->right);
        // 偷cur，那么就不能偷左右节点。
        int val1 = root->val + left.first + right.first;
        // 不偷cur，那么可以偷也可以不偷左右节点，则取较大的情况
        int val2 = max(left.first, left.second) + max(right.first, right.second);
        return {val2, val1};
    }
};
```

这个代码有点意思，要好好复习。

## 买卖股票系列题目

- 买卖股票的最佳时机
- 买卖股票的最佳时机II
- 买卖股票的最佳时机 III
- 买卖股票的最佳时机 IV
- 买卖股票的最佳时机含手续费
- 买卖股票的最佳时机含冷冻期

### 买卖股票的最佳时机

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/

这种题型是一定要学习和掌握的。

按照Carl的思路先学习。

**股票问题：创建一个两列的dp数组。**

**dp数组的含义**

`dp[i][0]` 表示第i天持有股票所得最多现金。

其实一开始现金是0，那么加入第i天买入股票现金就是 -prices[i]， 这是一个负数。

`dp[i][1]` 表示第i天不持有股票所得最多现金

注意这里说的是“持有”，“持有”不代表就是当天“买入”！也有可能是昨天就买入了，今天保持持有的状态。

**递推公式：**

如果第i天持有股票即 `dp[i][0]`， 那么可以由两个状态推出来:

- 第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金 即：`dp[i - 1][0]`
- 第i天买入股票，所得现金就是买入今天的股票后所得现金即：-prices[i]

那么dp[i][0]应该选所得现金最大的，所以` dp[i][0] = max(dp[i - 1][0], -prices[i]);`

如果第i天不持有股票即`dp[i][1]`， 也可以由两个状态推出来

第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：`dp[i - 1][1]`
第i天卖出股票，所得现金就是按照今天股票价格卖出后所得现金即：`prices[i] + dp[i - 1][0]`
同样`dp[i][1]`取最大的，`dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);`

初始化其实也挺简单。

dp[0][0] 表示第0天买股，所以就是 -prices[0]

dp[0][1] 表示第一天不买股，所以就是现金0。

从递推公式可以看出，dp[i]只是依赖于dp[i - 1]的状态。

先尝试写代码。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(2)); // n行2列
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max(-prices[i], dp[i-1][0]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[prices.size()-1][1]; // 不持有股票一定是有更多钱的
    }
};
```

### 买卖股票的最佳时机II

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。**你在任何时候 最多 只能持有 一股 股票**。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

其实这一系列问题都是同样的思路。

和上一题的区别：
- 因为上一题只能买一次，所以如果当天买，现金一定是`-prize[i]`
- 但这题可以买多次，所以如果当天买，可能身上已经有钱了。这题说手上只能有一支股票，所以如果当天买，一定是从“没有股票”的状态中推导来的：`dp[i][1]-prize[i]`

简简单单，直接写代码。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[prices.size()-1][1];
    }
};
```

顺利通过。

### 买卖股票的最佳时机III

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

这题还是比之前难了很多的。

主要是题目限制只能买两次。也就是最好的结果可能是：不买、买一次、买两次的其中之一。

解题思路是，弄5个状态（前面两个题是两个状态）。

其实感觉这种思路是有状态机的感觉。

5个状态：
1. 没有买
2. 第一次持有
3. 第一次持有后卖了
4. 第二次持有
5. 第二次持有后卖了

初始化的时候要注意一下

- dp[0][0]表示没买，那就是0
- dp[0][1]表示第一次买了，那就是 -price[0]
- dp[0][2]表示在第一天，买了又卖了，现金就是0
- dp[0][3]表示第一天，买了卖了又买了，-price[0]
- dp[0][4]同理，0

尝试写代码。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(5));
        dp[0][0] = 0; // 没买
        dp[0][1] = -prices[0]; // 第一次买
        dp[0][2] = 0; // 第一次卖
        dp[0][3] = -prices[0]; // 第二次买了
        dp[0][4] = 0; // 最后卖了
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = dp[i-1][0]; // 一开始就不买，只能一开始就不买
            dp[i][1] = std::max(dp[i-1][1], dp[i][0] - prices[i]);
            dp[i][2] = std::max(dp[i-1][2], dp[i][1] + prices[i]);
            dp[i][3] = std::max(dp[i-1][3], dp[i][2] - prices[i]);
            dp[i][4] = std::max(dp[i-1][4], dp[i][3] + prices[i]);
        }
        return std::max(dp[prices.size()-1][4], std::max(dp[prices.size()-1][2], dp[prices.size()-1][0]));
    }
};  
```

顺利通过。

### 买卖股票的最佳时机IV

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/

限制两次变成限制k次了。

可以参考上面的代码来尝试写一下，因为上面代码其实还是很规整的，可以泛化感觉。

这样确实可以通过。

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0) return 0;
        auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(2*k+1));
        // 初始化 
        for(int i = 0; i <= 2*k; ++i) {
            if(i % 2 == 0) dp[0][i] = 0;
            else dp[0][i] = -prices[0];
        }
        // dp
        for(int i = 1; i < prices.size(); ++i) {
            for(int j = 0; j <= 2*k; ++j) {
                if(j == 0) {
                    dp[i][j] = dp[i-1][j]; // 一开始就不买
                    continue;
                }
                if(j % 2 == 1) dp[i][j] = std::max(dp[i-1][j], dp[i][j-1] - prices[i]);
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1] + prices[i]);
            }
        }
        return *max_element(dp[prices.size()-1].begin(), dp[prices.size()-1].end());
    }
};
```

但是如果一开始不做前面的题做这个，那真的太难了。不可能想到。

然后确实Carl也是同样这个方法。


### 买卖股票的最佳时机含手续费

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

做到这里其实发现了，股票问题，就是把状态弄清楚就很简单了。

这里分成四个状态
1. 身上有股票
2. 身上没有股票（两天前就卖出了股票，度过一天冷冻期。或者是之前就是卖出股票状态，一直没操作）
3. 身上没有股票（今天刚卖）
4. 身上没有股票（昨天刚卖，今天冷冻期）

把递推公式弄清楚就行了。

**达到买入股票状态（状态一）即：`dp[i][0]`，有两个具体操作：**

- 操作一：前一天就是持有股票状态（状态一），dp[i][0] = dp[i - 1][0]
- 操作二：今天买入了，有两种情况
  - 前一天是冷冻期（状态四），`dp[i - 1][3] - prices[i]` （冷冻期刚过就买）
  - 前一天是保持卖出股票的状态（状态二），`dp[i - 1][1] - prices[i]`（冷冻期过了一段时间了，今天才买）

那么 `dp[i][0] = max(dp[i - 1][0], dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]);`

**达到保持卖出股票状态（状态二）即：`dp[i][1]`，有两个具体操作**：

- 操作一：前一天就是状态二
- 操作二：前一天是冷冻期（状态四）
- `dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);`

**达到今天就卖出股票状态（状态三），即：`dp[i][2]`，只有一个操作**：

昨天一定是持有股票状态（状态一），今天卖出

`即：dp[i][2] = dp[i - 1][0] + prices[i];`

**达到冷冻期状态（状态四），即：`dp[i][3]`，只有一个操作：**

昨天卖出了股票（状态三）

`dp[i][3] = dp[i - 1][2];`


写代码就可以了，搞清楚四个状态就很简单了。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0. 身上有股票
        // 1. 身上没有股票（两天前就卖出了股票，度过一天冷冻期。或者是之前就是卖出股票状态，一直没操作）
        // 2. 身上没有股票（今天刚卖）
        // 3. 身上没有股票（昨天刚卖，今天冷冻期）
        if(prices.size() == 0) return 0;
        auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(4));
        dp[0][0] = -prices[0];
        dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0; // 其实这几个都不好说，但是设置成其他，就会出问题，所以设置成0，这里还要琢磨下
        for(int i = 1; i < prices.size(); ++i) {
            // 有股票: 1. 本来就有 2. 今天刚过冷冻期就买 3. 今天买（但过了冷冻期一天以上）
            dp[i][0] = std::max(dp[i-1][0], std::max(dp[i-1][3]-prices[i], dp[i-1][1]-prices[i]));
            dp[i][1] = std::max(dp[i-1][3], dp[i-1][1]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return *max_element(dp[prices.size()-1].begin(), dp[prices.size()-1].end());
    }
};
```

顺利通过。

状态太重要了。股票问题就是搞清楚状态！

### 买卖股票的最佳时机含冷冻期

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

emm，其实这题我的思路是，因为最后股票肯定要卖掉是最好的，所以我设置在卖掉的时候交手续费。

状态:

0. 没有股票
1. 手上有股票


```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        auto dp = std::vector<std::vector<int>>(prices.size(), std::vector<int>(2));
        dp[0][0] = 0; // 手上无
        dp[0][1] = -prices[0]; // 手上有
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};
```

然后确实我的思路是对的，顺利通过了。

**股票问题总结：状态很重要！股票问题的核心就是状态！**

## 最长递增子序列

https://leetcode.cn/problems/longest-increasing-subsequence/

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。


一开始我在想，有没有一个可以遍历一次就得到结果的方法，发现最后其实还是要有内层循环。

这个题思路比较简单感觉，我直接写代码。


```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        auto dp = std::vector<int>(nums.size(), 1); // 注意，这里要初始化为1
        // dp[i]表示以nums[i]结尾的最长递增子序列
        dp[0] = 1;
        int result = -1;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    // 可以把i放到以j结尾的最长递增子序列上
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > result) result = dp[i]; // 因为最好的结果不一定在dp数组的最后
            // 因为最长递增子序列不一定是用到结尾的数字，很好理解
        }
        return result;
    }
};
```

顺利通过，细节可以见代码。

## 最长连续递增序列

https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/

给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

这个题感觉很简单，直接写。

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int result = 0;
        auto dp = std::vector<int>(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1;
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
```

顺利通过。很简单。


## 最长重复子数组（需要复习，经典题目）

https://leetcode.cn/problems/maximum-length-of-repeated-subarray/

给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

示例 1：

输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。

这个题是不简单的，要好好学习这个思路。

本题内容全部来自 Carl。

### 确定dp数组含义

`dp[i][j]`: 以下标 `i - 1` 为结尾的A，和以下标 `j - 1` 为结尾的B，最长重复子数组长度为 `dp[i][j]`。(特别注意： “以下标 `i - 1` 为结尾的A” 标明一定是 以 `A[i-1]` 为结尾的字符串)

那`dp[0][0]`好像就没有意义了。所以其实是从1开始遍历。

> [!TIP]
> 为什么`dp[i][j]`不能代表下标i和下标j呢，非要错位。\
> 其实是可以的，但是会比较麻烦，Carl后面会讲到。


### 确定递推公式

根据 `dp[i][j]` 的定义，`dp[i][j]` 的状态只能由 `dp[i - 1][j - 1]` 推导出来。

即当 A[i - 1]和B[j - 1]相等的时候，`dp[i][j] = dp[i - 1][j - 1] + 1;`

根据递推公式可以看出，遍历 i 和 j 要从1开始！

### dp数组的初始化

根据dp[i][j]的定义，dp[i][0]和dp[0][j]其实都是没有意义的！

但dp[i][0] 和dp[0][j]要初始值，因为为了方便递归公式，所以dp[i][0] 和dp[0][j]初始化为0。

举个例子A[0]如果和B[0]相同的话，`dp[1][1] = dp[0][0] + 1`，只有`dp[0][0]`初始为0，正好符合递推公式逐步累加起来。

### 确认遍历顺序

外层for循环遍历A，内层for循环遍历B。（换过来是一样的，相当于两个数组换个位置，没区别）

同时题目要求长度最长的子数组的长度。所以在遍历的时候顺便把dp[i][j]的最大值记录下来。

```cpp
for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        if (dp[i][j] > result) result = dp[i][j];
    }
}
```

### 二维数组版本代码

```cpp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        auto dp = std::vector<std::vector<int>>(nums1.size() + 1, std::vector<int>(nums2.size() + 1));
        int result = 0;
        for(int i = 1; i <= nums1.size(); ++i) {
            for(int j = 1; j <= nums2.size(); ++j) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};
```

### 滚动数组

因为很明显：dp[i][j]都是从dp[i-1][j-1]来的，所以可以压缩成滚动数组。

此时遍历B数组的时候，就要从后向前遍历，这样避免重复覆盖。（这个还要再琢磨下）

**不过最本质的办法，就是要模拟推导dp数组。**

```cpp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        auto dp = std::vector<int>(nums2.size()+1, 0);
        int result = 0;
        for(int i = 1; i <= nums1.size(); ++i) {
            for(int j = nums2.size(); j >= 1; j--) {
                if(nums1[i-1] == nums2[j-1]) dp[j] = dp[j-1] + 1;
                else dp[j] = 0; // 这里要多一步，如果不匹配要弄成0
                if(dp[j] > result) result = dp[j];
            }
        }
        return result;
    }
};
```

### 拓展

前面讲了 dp数组为什么定义：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]。

我就定义dp[i][j]为 以下标i为结尾的A，和以下标j 为结尾的B，最长重复子数组长度。不行么？

当然可以，就是实现起来麻烦一些。

如果定义 dp[i][j]为 以下标i为结尾的A，和以下标j 为结尾的B，那么 第一行和第一列毕竟要进行初始化，如果nums1[i] 与 nums2[0] 相同的话，对应的 dp[i][0]就要初始为1， 因为此时最长重复子数组为1。 nums2[j] 与 nums1[0]相同的话，同理。

```cpp
// 版本三
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;

        // 要对第一行，第一列经行初始化
        for (int i = 0; i < nums1.size(); i++) if (nums1[i] == nums2[0]) dp[i][0] = 1;
        for (int j = 0; j < nums2.size(); j++) if (nums1[0] == nums2[j]) dp[0][j] = 1;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j] && i > 0 && j > 0) { // 防止 i-1 出现负数
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};
```

## 最长公共子序列


```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto dp = std::vector<std::vector<int>>(text1.size() + 1, std::vector<int>(text2.size() + 1));
        int result = 0;
        for(int i = 1; i <= text1.size(); ++i) {
            for(int j = 1; j <= text2.size(); ++j) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result; // 其实不用记录result也行，因为这题可以继承，所以右下角一定是结果
    }
};
```

这题和上面那个题目有点类似，其实已经很接近想出来了，就差一点点。

区别就在，因为这题不要求是连续的，所以可以前面的答案。

就只有这个没想出来。

```cpp
dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
```

差一点点。

**这些题都太经典了，很重要！匹配问题。**


## 不相交的线

https://leetcode.cn/problems/uncrossed-lines/description/

在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：

 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

![](https://assets.leetcode.com/uploads/2019/04/26/142.png)

这题貌似也是和上一题是一个道理啊，找最长公共子序列。

```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        auto dp = std::vector<std::vector<int>>(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));
        for(int i = 1; i <= nums1.size(); ++i) {
            for(int j = 1; j <= nums2.size(); ++j) {
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
```

确实是如此。

## 最大子数组和

https://leetcode.cn/problems/maximum-subarray/description/

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4] \
输出: 6 \
解释: 连续子数组 [4,-1,2,1] 的和最大为6。

这题很简单啊。其实做贪心的时候做过这个题了，而且那个思想就是dp思想。

如果加上前一个比自己大，就用这个结果。如果自己大，那就更新为自己。


```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        auto dp = std::vector<int>(nums.size(), 0);
        dp[0] = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i-1]+nums[i],nums[i]);
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
```

简单。

## 判断子序列（需要复习）

https://leetcode.cn/problems/is-subsequence/description/

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

这个题和前面的 最长公共子序列 其实是比较类似的。直接尝试谢谢代码。

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 判断s是否为t的子序列
        auto dp = std::vector<std::vector<int>>(s.size() + 1, std::vector<int>(t.size() + 1));
        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 1; j <= t.size(); ++j) {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};
```

可以通过，但是这个题还是需要复习。

## 不同的子序列（难）

https://leetcode.cn/problems/distinct-subsequences/description/

给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

测试用例保证结果在 32 位有符号整数范围内。

这个题是比较难了。

一步一步来。

### dp数组的含义

`dp[i][j]`: 以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为`dp[i][j]`

### 确定递推公式

这种问题就两种情况：
- `s[i-1]` 和 `t[j-1]` 相等
- 不相等

**当相等的时候：**

dp[i][j]可以有两部分组成。

一部分是用 s[i-1] 来匹配，这时候个数就是 `dp[i-1][j-1]`，即不需要考虑当前s子串和t子串的最后一位字母，所以只需要 `dp[i-1][j-1]`

另一部分是不需要 s[i-1] 来进行匹配，个数是 `dp[i-1][j]`。

其实这个也很好理解：

> s：bagg 和 t：bag ，s[3] 和 t[2]是相同的，但是字符串s也可以不用s[3]来匹配，即用s[0]s[1]s[2]组成的bag。当然也可以用s[3]来匹配，即：s[0]s[1]s[3]组成的bag。


其实还是有点看不懂文字，看了卡哥视频后，可以这样去理解：

- 其实这个题目就是相当于删除s中部分元素，看看能不能变成t，问有几种删除方法。
- 第一种情况 `s[i-1] == j[t-1]` 的时候，s匹配上啦！s是可以用的，那我们就可以不删除它：dp[i][j] = dp[i-1][j-1]
- 或者说，就算s[i-1]下标这个地方匹配上了，我们也不使用它, dp[i][j] = dp[i-1][j] 
- 这里是最难理解的
- 然后不相等的情况，就是上面相等情况中的第二种情况。

### 初始化

要初始化什么，是要看你推导出来的递推公式的。

在这个题中，很明显，是从左上方和上方推导出来的，所以一定要初始化第一行和第一列。

按照定义：dp[i][j]表示以i-1结尾s出现以j-1结尾的t的个数。

所以第一行 dp[0][j] 就是在问，在一个空字符串中出现了几个以j-1结尾的t的个数？很明显是0个啊，因为s都是一个空字符串了。

所以第一列 dp[i][0] 在问，在一个以i-1结尾的s中，有几个空字符串？有一个，即全部删掉。

然后 dp[0][0] 是1: 因为空字符串有几种方法删除可以得到一个空字符串？不删，所以是一种。


### 代码

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        auto dp = std::vector<std::vector<uint32_t>>(s.size() + 1, std::vector<uint32_t>(t.size() + 1));
        // 初始化
        for(int j = 0; j <= t.size(); ++j) dp[0][j] = 0;
        for(int i = 0; i <= s.size(); ++i) dp[i][0] = 1; // dp[0][0]=1
        // dp
        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 1; j <= t.size(); ++j) {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};
```

## 两个字符串的删除操作

https://leetcode.cn/problems/delete-operation-for-two-strings/description/

给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

这个题其实和上面的题是类似的，然后区别就是两个串都可以删除了。

其实思路还是同样分两部分。

- 当word1[i - 1] 与 word2[j - 1]相同的时候
- 当word1[i - 1] 与 word2[j - 1]不相同的时候

第一种情况，因为两个字符相同，这个数字就不用删了！所以要删多少步跟我这个下标没关系，所以继承前面的下标！

dp[i][j] <- dp[i-1][j-1]

第二种情况就要分开了，不相同怎么样才能达到相同？
- 删除word1一个字符然后+1
- 删除word2一个字符然后+1
- 同时删除两个字符然后+2

如果是上面那题，就全部加起来就行了，但这里是求步数最小，所以取最小值就行了，取完之后

初始化怎么办？要看定义！

首先按照递推公式，肯定要初始化第一行和第一列。

dp[i][j]表示，s[i-1]为结尾，t[j-1]为结尾，删除到相同的最小步数。

- 第一行：dp[0][j]表示s空，t[j-1]要删到相同需要多少步？多长就多少步！
- 第一列：同理。

然后具体验证，还需要推导一下dp数组，才能证实我是对的，现在尝试推导！

然后我用 sea, eat 推导了一下，思路是没问题的。

也就是说，最终一定要自己推一下，因为一开始想的初始化和递推可能都不太准，必须自己推一次，修改一下微调下就能做出来。

写代码。

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        auto dp = std::vector<std::vector<int>>(word1.size()+1, std::vector<int>(word2.size()+1));
        // 初始化
        for(int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); ++j) dp[0][j] = j;
        // dp
        for(int i = 1; i <= word1.size(); ++i) {
            for(int j = 1; j <= word2.size(); ++j) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = std::min(dp[i-1][j]+1, std::min(dp[i-1][j-1]+2, dp[i][j-1]+1));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
```

**没问题，一定要手动推导！**

## 编辑距离

https://leetcode.cn/problems/edit-distance/description/

给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

思路和前面类似！

要记住这个做题的方式：

```
if (word1[i - 1] == word2[j - 1])
    不操作
if (word1[i - 1] != word2[j - 1])
    增
    删
    换
```

按照这个来，就没问题了！

> [!IMPORTANT]
> word2添加一个元素，相当于word1删除一个元素，例如 word1 = "ad" ，word2 = "a"，word1删除元素'd' 和 word2添加一个元素'd'，变成word1="a", word2="ad"， 最终的操作数是一样！ \
> **所以虽然题目问，word1可以怎么操作变word2，字面意思上word2不能动，其实可以把word1添加字符变成word2减少字符！**

**所以递推公式：**

`if (word1[i - 1] == word2[j - 1])` 那么说明不用任何编辑，dp[i][j] 就应该是 dp[i - 1][j - 1]，即dp[i][j] = dp[i - 1][j - 1];

相等的时候不用改。

重点是不相等的时候：

**操作一：** word1删除一个元素，那么就是以下标i - 2为结尾的word1 与 j-1为结尾的word2的最近编辑距离再加上一个操作。
即 dp[i][j] = dp[i - 1][j] + 1;

**操作二：** word2删除一个元素（等价于word1添加一个元素），那么就是以下标i - 1为结尾的word1 与 j-2为结尾的word2的最近编辑距离再加上一个操作。
即 dp[i][j] = dp[i][j - 1] + 1;

**操作三：**替换元素，word1替换word1[i - 1]，使其与word2[j - 1]相同，此时不用增删加元素。

可以回顾一下，if (word1[i - 1] == word2[j - 1])的时候我们的操作 是 dp[i][j] = dp[i - 1][j - 1] 对吧。

那么只需要一次替换的操作，就可以让 word1[i - 1] 和 word2[j - 1] 相同。

所以` dp[i][j] = dp[i - 1][j - 1] + 1;`

综上，当 `if (word1[i - 1] != word2[j - 1])` 时取最小的，即：`dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;`


初始化和之前一样，一个字符变成空字符，最快的方法就是全部删掉。

**代码：**

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        auto dp = std::vector<std::vector<int>>(word1.size()+1, std::vector<int>(word2.size() + 1));
        for(int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); ++j) dp[0][j] = j;
        for(int i = 1; i <= word1.size(); ++i) {
            for(int j = 1; j <= word2.size(); ++j) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = std::min(dp[i-1][j], std::min(dp[i-1][j-1], dp[i][j-1])) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
```

按照思路可以顺利通过。

**‼️这个编辑距离系列的问题不简单！要整合复习！！！**

## 回文子串

https://leetcode.cn/problems/palindromic-substrings/description/

dp[j][i]表示区间i,j能否组成回文

如果 s[j] != s[i], 一定不可以，直接给false

如果 s[j] == s[i]，就要分情况
- 如果 i==j，那不就是一个字符，true
- 如果 i-j==1，两个相同字符，回文
- 如果 i-j>1, 就要判断 s[j+1][i-1]是否是回文，

所以这样我们就得到了递推公式。

然后要看看，我们是从右上角往左下角递推。

所以遍历顺序i是正向，j是逆向。
- 这个怎么判断快一点呢：正常方向是i-1之类的，如果出现+1，那就是反过来。

**初始化**，不也定是否需要，推导来看看要不要。

然后我推导了一下，是不需要的。

代码：

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        auto dp = std::vector<std::vector<bool>>(s.size(), std::vector<bool>(s.size(), false));
        int result = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j >= 0; j--) {
                if(s[i]!=s[j]) dp[i][j] = false;
                else {
                    if(i-j==0) {dp[i][j] = true; result++;}
                    else if(i-j==1) {dp[i][j] = true; result++;}
                    else {
                        dp[i][j] = dp[i-1][j+1];
                        if(dp[i][j]) result++;
                    }
                }
            }
        }
        return result;
    }
};
```

顺利通过。

## 最长回文子序列

https://leetcode.cn/problems/longest-palindromic-subsequence/description/

给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

**这题不一样，这题是不要求连续的。**

输入：s = "bbbab" \
输出：4 \
解释：一个可能的最长回文子序列为 "bbbb" 。

这题我先自己思考。

b b b a b

dp[i]表示以i结尾最长回文是多少。

dp[0]不用说肯定是1

然后如果 dp[j] == dp[i], dp[i] = dp[j] + 1 然后dp[i]要记录并取最大

如果 dp[j] != dp[i] dp[i]<-1

试试代码。

然后这个思路是有问题的，不能判断回文。

比如 aaabaaa 就会不对了。所以还是需要一个二维数组。

**换一个思路：**

dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。

- s[i] == t[j]: 此时因为题目是不要求连续的，所以此时 dp[i][j] = dp[i-1][j+1] + 2，因为多了两个相等的
- s[i] != t[j]: 此时前后两个用不了，可以删除i也可以删除j
    。所以就是 dp[i][j] = std::max(dp[i-1][j], dp[i][j+1])

注意遍历的方向。

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        auto dp = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size()));
        // dp[0][0] = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j >= 0; j--) {
                if(s[i] == s[j]) {
                    if(i == j) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j+1] + 2;
                }
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j+1]);
            }
        }
        return dp[s.size()-1][0];
    }
};
```

这个代码是我自己推导的，和carl的还不太一样。

所以说明了，dp问题一定要自己推导！

## 动态规划总结篇

**Carl的一些留言：**

动规五部曲里，哪一部没想清楚，这道题目基本就做不出来，即使做出来了也没有想清楚，而是朦朦胧胧的就把题目过了。

- 如果想不清楚dp数组的具体含义，递归公式从何谈起，甚至初始化的时候就写错了。
- 例如动态规划：不同路径还不够，要有障碍！ (opens new window) 在这道题目中，**初始化才是重头戏**
- 如果看过背包系列，特别是完全背包，**那么两层for循环先后顺序绝对可以搞懵很多人**，反而递归公式是简单的。
- 至于推导dp数组的重要性，动规专题里几乎每篇Carl都反复强调，**当程序结果不对的时候，一定要自己推导公式，看看和程序打印的日志是否一样**。
好啦，我们再一起回顾一下，动态规划专题中我们都讲了哪些内容。

### 动态规划基础问题

- [斐波那契数](#斐波那契数)
- [爬楼梯](#爬楼梯可以拓展成完全背包问题)
- [使用最小花费爬楼梯](#使用最小花费爬楼梯)
- [不同路径](#不同路径)
- [带有障碍的不同路径](#不同路径-ii)
- [整数拆分](#整数拆分需要复习)
- [不同的搜索二叉树](#不同的二叉搜索树需要复习)

### 背包问题

- [01背包-二维数组](#01背包理论基础)
- [01背包-滚动数组](#01背包理论基础-优化成滚动数组)
- [分割等和子集（判断背包是否能被装满）](#分割等和子集01背包可以判断是否装满的问题)
- [最后一块石头的重量II](#最后一块石头的重量-ii)
- [目标和（装满背包有几种办法）](#目标和装满背包有几种方法)
- [一和零](#一和零需要复习)
- [完全背包-二维数组](#完全背包理论基础-二维数组)
- [完全背包-滚动数组](#完全背包理论-一维数组)
- [零钱兑换II](#零钱兑换ii)
- [组合总和IV](#组合总和-ⅳ)
- [爬楼梯进阶版](#爬楼梯进阶版)
- [零钱兑换](#零钱兑换)
- [完全平方数](#完全平方数)
- [单词拆分](#单词拆分这个题目有点没有理解需要复习)
- [多重背包](#多重背包理论基础)

**背包问题总结，这里列一些结论，多看看多复习：**

**递推公式**

问能否能装满背包（或者最多装多少）：`dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);` ，对应题目如下：
- [416. 分割等和子集](#分割等和子集01背包可以判断是否装满的问题)
- [1049. 最后一块石头的重量II](#最后一块石头的重量-ii)

问装满背包有几种方法：`dp[j] += dp[j - nums[i]]` ，对应题目如下：
- [494. 目标和](#目标和装满背包有几种方法)
- [518. 零钱兑换 II](#零钱兑换ii)
- [377. 组合总和Ⅳ](#组合总和-ⅳ)
- [70. 爬楼梯进阶版（完全背包）](#爬楼梯进阶版)

问背包装满最大价值：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);` 对应题目如下：

- [474. 一和零](#一和零需要复习)

问装满背包所有物品的最小个数：`dp[j] = min(dp[j - coins[i]] + 1, dp[j]);` 对应题目如下：

- [322. 零钱兑换](#零钱兑换)
- [279. 完全平方数](#完全平方数)

**遍历顺序**

**01背包：**

- 二维dp数组解决01背包：先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

- 一维dp数组解决01背包：只能先遍历物品再遍历背包容量，且第二层for循环是从大到小遍历。

**一维dp数组的背包在遍历顺序上和二维dp数组实现的01背包其实是有很大差异的，大家需要注意！**

**完全背包：**

- 纯完全背包的一维dp数组实现，先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

**但是仅仅是纯完全背包的遍历顺序是这样的，题目稍有变化，两个for循环的先后顺序就不一样了。**

- 如果求**组合数**就是外层for循环遍历物品，内层for遍历背包。

- 如果求**排列数**就是外层for遍历背包，内层for循环遍历物品。

**相关题目如下：**

求组合数：
- [518. 零钱兑换II](#零钱兑换ii)

求排列数：
- [377. 组合总和Ⅳ](#组合总和-ⅳ)
- [70. 爬楼梯进阶版](#爬楼梯进阶版)

如果求最小数，那么两层for循环的先后顺序就无所谓了，相关题目如下：

求最小数：
- [322. 零钱兑换](#零钱兑换)
- [279. 完全平方数](#完全平方数)

对于背包问题，其实递推公式算是容易的，难是难在遍历顺序上，如果把遍历顺序搞透，才算是真正理解了。

### 打家劫舍系列

