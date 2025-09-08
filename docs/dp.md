
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


## 一维dp（重要！细节很多，需要复习！）

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