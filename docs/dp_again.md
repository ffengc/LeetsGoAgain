

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
