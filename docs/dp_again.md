

# DP是很难的，刷完一次立刻再复习一次

- [DP是很难的，刷完一次立刻再复习一次](#dp是很难的刷完一次立刻再复习一次)
  - [如何复习？](#如何复习)
  - [dp基础](#dp基础)
    - [509. 斐波那契数](#509-斐波那契数)
    - [70. 爬楼梯](#70-爬楼梯)
    - [746. 使用最小花费爬楼梯](#746-使用最小花费爬楼梯)
    - [62. 不同路径](#62-不同路径)
    - [63. 不同路径II](#63-不同路径ii)
    - [96. 不同的二叉搜索树](#96-不同的二叉搜索树)
  - [背包问题](#背包问题)
    - [46. 携带研究材料（第六期模拟笔试）](#46-携带研究材料第六期模拟笔试)
    - [416. 分割等和子集](#416-分割等和子集)
    - [1049. 最后一块石头的重量 II](#1049-最后一块石头的重量-ii)
    - [494. 目标和](#494-目标和)
    - [474. 一和零](#474-一和零)
    - [52. 携带研究材料（第七期模拟笔试）](#52-携带研究材料第七期模拟笔试)
    - [518. 零钱兑换 II](#518-零钱兑换-ii)
    - [377. 组合总和 Ⅳ](#377-组合总和-ⅳ)
    - [57. 爬楼梯（第八期模拟笔试）](#57-爬楼梯第八期模拟笔试)
    - [322. 零钱兑换](#322-零钱兑换)
    - [279. 完全平方数](#279-完全平方数)
    - [139. 单词拆分](#139-单词拆分)
    - [56. 携带矿石资源（第八期模拟笔试）](#56-携带矿石资源第八期模拟笔试)
  - [打家劫舍系列](#打家劫舍系列)
    - [198. 打家劫舍](#198-打家劫舍)
    - [213. 打家劫舍 II](#213-打家劫舍-ii)
    - [337. 打家劫舍 III](#337-打家劫舍-iii)
  - [股票系列](#股票系列)
    - [121. 买卖股票的最佳时机](#121-买卖股票的最佳时机)
    - [122. 买卖股票的最佳时机 II](#122-买卖股票的最佳时机-ii)
    - [123. 买卖股票的最佳时机 III](#123-买卖股票的最佳时机-iii)
    - [188. 买卖股票的最佳时机 IV](#188-买卖股票的最佳时机-iv)
    - [309. 买卖股票的最佳时机含冷冻期](#309-买卖股票的最佳时机含冷冻期)
    - [714. 买卖股票的最佳时机含手续费](#714-买卖股票的最佳时机含手续费)

## 如何复习？

分成四个部分：
- dp基础
- 背包
- 打家劫舍系列
- 股票系列
- 子序列问题

## dp基础

### 509. 斐波那契数

https://leetcode.cn/problems/fibonacci-number/

easy.

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        auto dp = std::vector<int>(n + 1);
        dp[0] = 0; dp[1] = 1;
        for(int i = 2; i <= n; ++i) 
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```

### 70. 爬楼梯

https://leetcode.cn/problems/climbing-stairs/description/

easy.

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        auto dp = std::vector<int>(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) 
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```

### 746. 使用最小花费爬楼梯

https://leetcode.cn/problems/min-cost-climbing-stairs/description/

easy

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto dp = std::vector<int>(cost.size() + 1, 0);
        // cost.size() >= 2
        dp[0] = 0; dp[1] = 0;
        for(int i = 2; i <= cost.size(); ++i)
            dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        return dp[cost.size()];
    }
};
```

### 62. 不同路径

https://leetcode.cn/problems/unique-paths/description/

easy

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        auto dp = std::vector<std::vector<int>>(m, std::vector<int>(n));
        // init
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for(int j = 0; j < n; ++j)
            dp[0][j] = 1;
        // dp
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```

### 63. 不同路径II

https://leetcode.cn/problems/unique-paths-ii/description/

easy

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        auto dp = std::vector<std::vector<int>>(m, std::vector<int>(n));
        // init
        for(int i = 0; i < m && !obstacleGrid[i][0]; ++i) dp[i][0] = 1;
        for(int j = 0; j < n && !obstacleGrid[0][j]; ++j) dp[0][j] = 1;
        // dp
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```

### 96. 不同的二叉搜索树

https://leetcode.cn/problems/unique-binary-search-trees/description/

![](./dp_again_assets/dp1.png)

```cpp
class Solution {
public:
    int numTrees(int n) {
        if(n == 1) return 1;
        auto dp = std::vector<int>(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j <= i-1; ++j) {
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};
```

基础复习完毕，接下来就是背包问题。

## 背包问题

### 46. 携带研究材料（第六期模拟笔试）

https://kamacoder.com/problempage.php?pid=1046

最基本的一套代码

```cpp


#include <iostream>
#include <vector>

int binaryKnapsackProblem(int bagweight, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size(); // 有n个物品
    auto dp = std::vector<std::vector<int>>(n, std::vector<int>(bagweight + 1, 0));
    // 初始化
    // 第一列: 当背包容量为0的时候，可以携带多少价值的东西
    // 第一行: 当只有第0个物品的时候
    for(int j = 0; j <= bagweight; ++j)
        if(j >= weights[0]) dp[0][j] = values[0];
    // dp
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= bagweight; ++j) {
            if(j < weights[i]) dp[i][j] = dp[i-1][j]; //放不了物品i
            else dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
        }
    }
    return dp[n-1][bagweight];
}

int main() {
    int n, bagweight;
    std::cin >> n >> bagweight;
    std::vector<int> weights(n);
    std::vector<int> values(n);
    for(int i = 0; i < n; ++i)
        std::cin >> weights[i];
    for(int i = 0; i < n; ++i)
        std::cin >> values[i];
    int res = binaryKnapsackProblem(bagweight, weights, values);
    std::cout << res << std::endl;
    return 0;
}
```

一位数组的版本，也是一份非常基础的代码。

```cpp
int binaryKnapsackProblem(int bagweight, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size(); // 有n个物品
    auto dp = std::vector<int>(bagweight + 1);
    for(int i = 0; i < n; ++i) 
        for(int j = bagweight; j >= weights[i]; j--)
            dp[j] = std::max(dp[j], dp[j-weights[i]] + values[i]);
    return dp[bagweight];
}
```

### 416. 分割等和子集

https://leetcode.cn/problems/partition-equal-subset-sum/description/

> [!TIP]
> **是否能填满背包的问题**

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

顺利通过。

```cpp
class Solution {
private:
    bool solution(int target, const std::vector<int>& nums) {
        // 判断是否能填满 target 这么大的背包
        int n = nums.size();
        auto dp = std::vector<int>(target + 1);
        for(int i = 0; i < n; ++i)
            for(int j = target; j >= nums[i]; j--) 
                dp[j] = std::max(dp[j], dp[j-nums[i]] + nums[i]);
        return dp[target] == target;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        return solution(target, nums);
    }
};
```



### 1049. 最后一块石头的重量 II

https://leetcode.cn/problems/last-stone-weight-ii/description/

> [!TIP]
> **是否能填满背包的问题** \
> 其实就是看能不能把石头分成相等的两堆

```cpp
class Solution {
private:
    double solution(double target, const std::vector<int>& stones) {
        int n = stones.size();
        auto dp = std::vector<double>(target + 1);
        for(int i = 0; i < n; ++i) 
            for(int j = target; j >= stones[i]; j--)
                dp[j] = std::max(dp[j], dp[j-stones[i]] + stones[i]);
        return dp[target];
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 其实就是看能不能把石头分成相等的两堆
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        double target = sum / 2.0;
        double values = solution(target, stones);
        return std::abs(target - values) * 2;
    }
};
```

### 494. 目标和

给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

**一位数组的版本。**
```cpp
class Solution {
private:
    int solution(int bagweight, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<int>(bagweight + 1);
        // tips: 0 <= nums[i] <= 1000, 如果用二维dp，要注意第一列的初始化，不都是0哦
        // 第一行: 如果物品0，填满背包有几种方法
        dp[0] = 1; // 装满背包容量为0的方法有一种：就是不装
        // dp
        for(int i = 0; i < n; ++i) 
            for(int j = bagweight; j >= nums[i]; --j)
                dp[j] += dp[j - nums[i]];
        return dp[bagweight];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 本质是：问填满背包有几种方法
        // 把 (sum + target) / 2 就是背包问题的 target
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(std::abs(target) > sum) return 0;
        if((sum + target) % 2 == 1) return 0;
        int bagweight = (sum + target) / 2;
        return solution(bagweight, nums);
    }
};
```

> [!WARNING]
> 这一句很重要：`if(std::abs(target) > sum) return 0;` \
> 不加上会通过不了，因为我们要创建一个vector，这个vector长度和target是直接相关的，要排除一些极端情况。

**二维数组的版本：**

> [!IMPORTANT]
> 其实行和列的初始化，一般只有在二维数组的方法中才需要。\
> 如果我们用的是一位数组的版本，其实一般只需要初始化第一个数字。

```cpp
class Solution {
private:
    int solution(int bagweight, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<std::vector<int>>(n, std::vector<int>(bagweight + 1));
        // tips: 0 <= nums[i] <= 1000, 如果用二维dp，要注意第一列的初始化，不都是0哦
        // 第一行
        if(bagweight >= nums[0]) dp[0][nums[0]] = 1;
        // 第一列
        int zeros = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0) zeros++;
            dp[i][0] = (int)pow(2.0, zeros);
        }
        // dp
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= bagweight; ++j) {
                if(j < nums[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j]  = dp[i-1][j] + dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][bagweight];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 本质是：问填满背包有几种方法
        // 把 (sum + target) / 2 就是背包问题的 target
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(std::abs(target) > sum) return 0;
        if((sum + target) % 2 == 1) return 0;
        int bagweight = (sum + target) / 2;
        return solution(bagweight, nums);
    }
};
```

### 474. 一和零

https://leetcode.cn/problems/ones-and-zeroes/description/

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // m 和 n 相当于 target
        // strs 数组相当于物品
        // tips: 这题里面的二维数组，其实是滚动数组来的！因为有两维的背包需要填满
        auto dp = std::vector<std::vector<int>>(m+1, std::vector<int>(n+1, 0));
        dp[0][0] = 0; // 没有空字符串
        for(const auto& e : strs) { // 背包第一层
            // 遍历所有物品
            int zeros = 0;
            int ones = 0;
            for(const auto& ee : e) {
                if(ee == '0') zeros++;
                if(ee == '1') ones++; 
            }
            for(int i = m; i >= zeros; i--) { // 背包第二层, 这两层for其实对应之前背包的同一层，其实都是第二层  
                for(int j = n; j >= ones; j--) {
                    dp[i][j] = std::max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            } 
        }
        return dp[m][n];
    }
};
```

> [!IMPORTANT]
> 这题是很有意思的。
> - 首先，这题也是01背包，因为也只能选和不选。
> - 这里看似有三层循环，其实本质和前面题目的两层循环是一样的
>   - 这里面第一层，遍历所有元素，不就是之前01背包的遍历所有物品吗
>   - 这里面第二层和第三层，本质就是之前01背包的第二层而已

### 52. 携带研究材料（第七期模拟笔试）

https://kamacoder.com/problempage.php?pid=1052


```cpp
int unboundedKnapsackProblem(int bagweight, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    // 二维数组
    auto dp = std::vector<std::vector<int>>(n, std::vector<int>(bagweight + 1));
    // 初始化第一行
    // tips: 这个初始化挺巧秒的，可以学一下
    // 如果这个不好理解，可以用无脑一点的方法
    for (int j = weights[0]; j <= bagweight; j++)
        dp[0][j] = dp[0][j - weights[0]] + values[0];
    // 第一列：背包容量0的时候最大价值，因为这里weights都是正的，所以都是0
    // dp
    for(int i = 1; i < n; ++i) {
        // 遍历所有物品
        for(int j = 0; j <= bagweight; j++) {
            if(j < weights[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-weights[i]] + values[i]);
        }
    }
    return dp[n-1][bagweight];
}
```

一位数组:

```cpp
int unboundedKnapsackProblem(int bagweight, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    auto dp = std::vector<int>(bagweight+1);
    dp[0] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= bagweight; ++j) // 要注意，这里是从0开始
            if(j >= weights[i]) dp[j] = std::max(dp[j], dp[j-weights[i]] + values[i]);
    return dp[bagweight];
}
```

> [!IMPORTANT]
> **注意，j的循环是从0开始的，不是从1开始的，要看清楚**


### 518. 零钱兑换 II

https://leetcode.cn/problems/coin-change-ii/description/

给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

> [!TIP]
> 无脑完全背包啊 \
> 然后这里是组合数，所以是经典的背包 \
> 然后这里是求装满背包的方法有几种

```cpp
class Solution {
private:
    int solution(int target, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<uint32_t>(target + 1);
        dp[0] = 1; // 填满容量为0的背包有一种方法
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= target; ++j)
                if(j >= nums[i]) dp[j] += dp[j-nums[i]];
        return dp[target];
    }
public:
    int change(int amount, vector<int>& coins) {
        return solution(amount, coins);
    }
};
```

简简单单，很熟练。

### 377. 组合总和 Ⅳ

https://leetcode.cn/problems/combination-sum-iv/description/

给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

> [!TIP]
> 无脑完全背包啊 \
> 然后这里题目说了，不同顺序是不同的，所以是排列数，先遍历背包 \
> 然后这里是求装满背包的方法有几种

```cpp
class Solution {
private:
    int solution(int target, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<uint32_t>(target + 1);
        dp[0] = 1; // 填满容量为0的背包有一种方法
        for(int j = 0; j <= target; ++j)
            for(int i = 0; i < n; ++i)
                if(j >= nums[i]) dp[j] += dp[j-nums[i]];
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solution(target, nums);
    }
};
```

### 57. 爬楼梯（第八期模拟笔试）

https://kamacoder.com/problempage.php?pid=1067

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
注意：给定 n 是一个正整数。

> [!TIP]
> 完全背包 \
> 明显是排列数，先遍历背包 \
> 然后这里是求装满背包的方法有几种

```cpp
int solution(int target, int numbers) {
    auto dp = std::vector<uint32_t>(target + 1);
    dp[0] = 1; // 填满容量为0的背包有一种方法
    for(int j = 0; j <= target; ++j)
        for(int i = 1; i <= numbers; ++i)
            if(j >= i) dp[j] += dp[j-i];
    return dp[target];
}
int main() {
    int target, numbers;
    std::cin >> target >> numbers;
    std::cout << solution(target, numbers) << std::endl;
    return 0;
}
```

简简单单，很熟练！

### 322. 零钱兑换

https://leetcode.cn/problems/coin-change/description/

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

> [!TIP]
> 完全背包 \
> 一般求个数的，就和排列组合没关系了，谁先谁后应该都是可以的 \
> 然后这里是求最少硬币数量，做一些小改变就行

```cpp
class Solution {
private:
    int solution(int target, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<uint32_t>(target + 1, INT_MAX);
        dp[0] = 0; // 装满容量为0的背包，最少硬币个数为0
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= target; ++j)
                if(j >= nums[i])
                    dp[j] = std::min(dp[j], dp[j-nums[i]] + 1);
        return dp[target] == INT_MAX ? -1 : dp[target];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return solution(amount, coins);
    }
};
```

简简单单，直接通过。

### 279. 完全平方数

https://leetcode.cn/problems/perfect-squares/description/

```cpp
class Solution {
private:
    int solution(int target, const std::vector<int>& nums) {
        int n = nums.size();
        auto dp = std::vector<uint32_t>(target + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= target; ++j)
                if(j >= nums[i]) dp[j] = std::min(dp[j], dp[j-nums[i]] + 1);
        return dp[target];
    }
public:
    int numSquares(int n) {
        std::vector<int> objs;
        for(int i = 1; i <= std::sqrt(n); ++i)
            objs.push_back(i*i);
        return solution(n, objs);
    }
};
```

直接通过。其实就是上一题稍微改一下而已。

### 139. 单词拆分

https://leetcode.cn/problems/word-break/description/

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

这题还是有点没有理解的，需要再复习才行。

### 56. 携带矿石资源（第八期模拟笔试）

多重背包。把多重背包展开，变成01背包就行了。

```cpp


#include <iostream>
#include <vector>

int solution(int bagweight, const std::vector<int>& w, const std::vector<int>& v, const std::vector<int>& q) {
    std::vector<int> weight, value;
    for(int i = 0; i < q.size(); ++i) {
        for(int j = 0; j < q[i]; ++j) {
            weight.push_back(w[i]);
            value.push_back(v[i]);
        }
    }
    // 01 knapsack problem
    int n = weight.size();
    auto dp = std::vector<int>(bagweight + 1);
    for(int i = 0; i < n; ++i)
        for(int j = bagweight; j >= weight[i]; j--)
            dp[j] = std::max(dp[j], dp[j-weight[i]] + value[i]);
    return dp[bagweight];
}

int main() {
    int bagweight, n;
    std::cin >> bagweight >> n;
    std::vector<int> weight(n);
    std::vector<int> value(n);
    std::vector<int> quantity(n);
    for(int i = 0; i < n; ++i)
        std::cin >> weight[i];
    for(int i = 0; i < n; ++i)
        std::cin >> value[i];
    for(int i = 0; i < n; ++i)
        std::cin >> quantity[i];
    std::cout << solution(bagweight, weight, value, quantity) << std::endl;
    return 0;
}
```

简简单单。背包问题复习到这里就圆满结束了。

> [!CAUTION]
> 单词拆分那个题目，还需要复习才行。

## 打家劫舍系列

### 198. 打家劫舍

https://leetcode.cn/problems/house-robber/description/

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        // 这题其实很简单
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        auto dp = std::vector<int>(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i)
            dp[i] = std::max(dp[i-1], nums[i] + dp[i-2]);
        return dp[nums.size() - 1];
    }
};
```

这题很简单。

### 213. 打家劫舍 II

https://leetcode.cn/problems/house-robber-ii/description/

对比上面，就是所有房子围成一圈了。

```cpp
class Solution {
private:
    int _rob(vector<int> nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        auto dp = std::vector<int>(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i)
            dp[i] = std::max(dp[i-1], nums[i] + dp[i-2]);
        return dp[nums.size() - 1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res1 = _rob(std::vector<int>(nums.begin() + 1, nums.end()));
        int res2 = _rob(std::vector<int>(nums.begin(), nums.end() - 1));
        return std::max(res1, res2);
    }
};
```

> [!NOTE]
> 这个其实和570考试那个题有点像，考虑第一个不考虑最后一个。考虑最后一个不考虑第一个。这个思想，很重要。要记住！

### 337. 打家劫舍 III

https://leetcode.cn/problems/house-robber-iii/description/

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。


![](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)

```cpp
class Solution {
/**
    核心思路：用一个 pair 来记录，pair.first 表示不偷当前节点的结果。 
    pair.second 表示偷当前节点的结果。
*/
private:
    std::pair<int,int> dfs(TreeNode* root) {
        if(root == nullptr) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right); // 无脑后序遍历再说
        int val1 = root->val + left.first + right.first; // 偷当前节点
        int val2 = std::max(left.first, left.second) + std::max(right.first, right.second);
        return {val2, val1};
    }
public:
    int rob(TreeNode* root) {
        return std::max(dfs(root).first, dfs(root).second);
    }
};
```

这题还是蛮有意思的。

> [!IMPORTANT]
> 核心思路：用一个 pair 来记录，`pair.first` 表示不偷当前节点的结果。`pair.second` 表示偷当前节点的结果。


## 股票系列

> [!IMPORTANT]
> 股票问题的核心在于：控制好状态，每一种状态用一行dp来表示即可！

### 121. 买卖股票的最佳时机

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        // 第一行表示不持有股票，第二行表示持有股票
        auto dp = std::vector<std::vector<int>>(2, std::vector<int>(prices.size()));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for(int j = 1; j < prices.size(); ++j) {
            dp[0][j] = std::max(dp[0][j-1], dp[1][j-1] + prices[j]);
            dp[1][j] = std::max(dp[1][j-1], -prices[j]);
        }
        return dp[0][prices.size() - 1];
    }
};
```

当然这题写成了，2行n列的形式。在Carl的结果中，都是n行两列的形式的。后面还是继续用我这种方式是不错的。

### 122. 买卖股票的最佳时机 II

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        auto dp = std::vector<std::vector<int>>(2, std::vector<int>(prices.size()));
        dp[0][0] = 0; // 第一行不持有
        dp[1][0] = -prices[0]; // 第二行持有
        for(int j = 1; j < prices.size(); ++j) {
            dp[0][j] = std::max(dp[1][j-1] + prices[j], dp[0][j-1]);
            dp[1][j] = std::max(dp[1][j-1], dp[0][j-1] - prices[j]);
        }
        return dp[0][prices.size()-1];
    }
};
```

没问题，也是控制好状态即可。

### 123. 买卖股票的最佳时机 III

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

你最多可以完成两笔交易。

所以控制五个状态:
1. 还没买过，不持有股票
2. 买入第一次，持有股票
3. 第一次卖出，不持有股票
4. 第二次买入，持有股票
5. 第二次卖出，不持有股票

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        auto dp = std::vector<std::vector<int>>(5, std::vector<int>(prices.size()));
        dp[0][0] = 0; // 还没买过，不持有股票
        dp[1][0] = -prices[0]; // 买入第一次，持有股票
        dp[2][0] = 0; // 第一次卖出，不持有股票
        dp[3][0] = -prices[0]; // 第二次买入，持有股票
        dp[4][0] = 0; // 第二次卖出，不持有股票
        for(int j = 1; j < prices.size(); ++j) {
            dp[0][j] = dp[0][j-1];
            dp[1][j] = std::max(dp[1][j-1], dp[0][j-1] - prices[j]);
            dp[2][j] = std::max(dp[2][j-1], dp[1][j-1] + prices[j]);
            dp[3][j] = std::max(dp[3][j-1], dp[2][j-1] - prices[j]);
            dp[4][j] = std::max(dp[4][j-1], dp[3][j-1] + prices[j]);
        }
        return std::max(dp[0][prices.size()-1], std::max(dp[2][prices.size()-1], dp[4][prices.size()-1]));
    }
};
```

顺利通过。


### 188. 买卖股票的最佳时机 IV

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/

你最多可以完成 k 笔交易。

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 1) return 0;
        auto dp = std::vector<std::vector<int>>(k*2+1, std::vector<int>(prices.size()));
        // 初始化
        for(int i = 0; i <= 2*k; ++i) {
            if(i % 2 == 0) dp[i][0] = 0; // 不持有股票
            else dp[i][0] = -prices[0]; // 持有股票
        }
        for(int j = 1; j < prices.size(); ++j) {
            dp[0][j] = dp[0][j-1];
            for(int i = 1; i <= 2*k; ++i)
                if(i % 2 == 1) 
                    dp[i][j] = std::max(dp[i][j-1], dp[i-1][j-1] - prices[j]);
                else 
                    dp[i][j] = std::max(dp[i][j-1], dp[i-1][j-1] + prices[j]);
        }
        int res = 0;
        for(int i = 0; i <= 2*k; i+=2) 
            res = std::max(res, dp[i][prices.size()-1]);
        return res;
    }
};
```

顺利通过。

### 309. 买卖股票的最佳时机含冷冻期

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        // 0: 手上有股票: 刚买+之前买的
        // 1: 手上没有股票: 今天卖的
        // 2: 手上没有股票: 昨天刚卖（冷冻期）
        // 3: 手上没有股票: 前天或之前卖的（不在冷冻期）
        auto dp = std::vector<std::vector<int>>(4, std::vector<int>(prices.size()));
        dp[0][0] = -prices[0];
        dp[1][0] = 0; dp[2][0] = 0; dp[3][0] = 0;
        for(int j = 1; j < prices.size(); ++j) {
            dp[0][j] = std::max(dp[0][j-1], std::max(dp[3][j-1] - prices[j], dp[2][j-1]-prices[j]));
            dp[1][j] = dp[0][j-1] + prices[j]; // 昨天有股票，今天卖掉
            dp[2][j] = dp[1][j-1]; // 昨天刚卖，今天冷冻期
            dp[3][j] = std::max(dp[3][j-1], dp[2][j-1]);
        }
        return std::max(dp[1][prices.size()-1], std::max(dp[2][prices.size()-1], dp[3][prices.size()-1]));
    }
};
```

> [!NOTE]
> 这题里面，有个状态要注意一下，一开始写错了：
> `dp[0][j] = std::max(dp[0][j-1], std::max(dp[3][j-1] - prices[j], dp[2][j-1]-prices[j]));` \
> 一开始我写成了: `dp[0][j] = std::max(dp[0][j-1], std::max(dp[3][j-1] - prices[j]);` 漏了2号状态。\
> 这里是要加上的，表示冷冻期刚过，就买入。`dp[2][j-1]`表示昨天处于冷冻期，那今天就可以买了嘛，所以2这个状态是要加上的。

### 714. 买卖股票的最佳时机含手续费

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

比较简单。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 1) return 0;
        auto dp = std::vector<std::vector<int>>(2, std::vector<int>(prices.size()));
        dp[0][0] = 0; // 第一行不持有
        dp[1][0] = -prices[0]; // 第二行持有
        for(int j = 1; j < prices.size(); ++j) {
            dp[0][j] = std::max(dp[1][j-1] + prices[j] - fee, dp[0][j-1]);
            dp[1][j] = std::max(dp[1][j-1], dp[0][j-1] - prices[j]);
        }
        return dp[0][prices.size()-1];
    }
};
```