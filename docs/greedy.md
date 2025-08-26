

# 贪心算法

- [贪心算法](#贪心算法)
  - [贪心算法理论基础](#贪心算法理论基础)
  - [分发饼干](#分发饼干)
    - [自己的思路](#自己的思路)
    - [Carl的思路](#carl的思路)
  - [摆动序列](#摆动序列)
    - [我的思路（有bug）](#我的思路有bug)
    - [Carl的思路](#carl的思路-1)
    - [我的思路2（通过）](#我的思路2通过)
    - [Carl的动态规划思路](#carl的动态规划思路)
  - [最大子数组和](#最大子数组和)
    - [贪心思路](#贪心思路)
    - [dp思路](#dp思路)
  - [买卖股票的最佳时机 II](#买卖股票的最佳时机-ii)
    - [贪心算法](#贪心算法-1)
    - [dp思路](#dp思路-1)
  - [跳跃游戏](#跳跃游戏)
    - [我的思路](#我的思路)
    - [Carl的思路](#carl的思路-2)
  - [跳跃游戏II (需要复习)](#跳跃游戏ii-需要复习)
  - [K 次取反后最大化的数组和](#k-次取反后最大化的数组和)
  - [加油站（需要复习）](#加油站需要复习)
    - [贪心算法一（Carl）](#贪心算法一carl)
    - [贪心算法二（Carl）](#贪心算法二carl)
  - [分发糖果](#分发糖果)
    - [我的思路（bug）](#我的思路bug)
    - [正确思路](#正确思路)
  - [柠檬水找零](#柠檬水找零)


## 贪心算法理论基础

贪心的本质就是每一阶段选择局部最优，从而达到全局最优。

**什么时候用贪心算法？**

主要是要判断好，这个问题，能否通过局部最优从而推理出整体最优。

没有固定的套路，最好用的方法就是举反例，如果想不到反例，就可以尝试用一下贪心。

**贪心算法的解题步骤：**
1. 将问题分解为若干个子问题
2. 找出适合的贪心策略
3. 求解每一个子问题的最优解
4. 将局部最优解堆叠成全局最优解


## 分发饼干

https://leetcode.cn/problems/assign-cookies/

假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 `g[i]`，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 `j`，都有一个尺寸 `s[j]` 。如果 `s[j] >= g[i]`，我们可以将这个饼干 `j` 分配给孩子 `i` ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。

输入: g = [1,2,3], s = [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。
所以你应该输出 1。

输入: g = [1,2], s = [1,2,3]
输出: 2
解释: 
你有两个孩子和三块小饼干，2 个孩子的胃口值分别是 1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出 2。

### 自己的思路

我的思路是，肯定是要排序。

然后遍历孩子的胃口，比如孩子的胃口是1，我就希望是使用最小的饼干就能满足他。

就是争取不浪费饼干。

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end()); // child
        std::sort(s.begin(), s.end()); // cookies
        int idx_s = 0; // s的下标
        int count = 0;
        for(int idx_g = 0; idx_g < g.size(); ++idx_g) { // g 的下标
            // 找到一个可以满足g的s
            while(idx_s < s.size() && s[idx_s] < g[idx_g]) idx_s++;
            if(idx_s >= s.size()) break; // 没找着
            assert(s[idx_s] >= g[idx_g]);
            idx_s++;
            count++;
        }
        return count;
    }
};
```

这道题顺利通过

### Carl的思路

然后从后向前遍历小孩数组，用大饼干优先满足胃口大的，并统计满足小孩数量。

其实本质是一样的。

## 摆动序列

https://leetcode.cn/problems/wiggle-subsequence/

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。

相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。


### 我的思路（有bug）

我感觉思路其实就是，从前向后遍历，能不删就不删。

> ‼️然后我感觉遍历一次就够了，用双指针。一个表示pre，一个表示cur。
nums[cur]-nums[pre]就是当前的差。

**我这个思路是有问题的。**

比如 [33, 53, 12, 64, 50, 41, 45, 21, 97, ...]

按照我的思路，我走到 50 这里之后，我希望后一个数是大于50的，我的cur指针就会一直跳过。直到cur找到97，其实这样是不对的，这样回删多了很多数字。

比如，如果我把50删掉，就不用删这么多数字了。

```cpp
// 错误写法
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        std::cout<< nums.size() << std::endl;
        // 先处理特殊情况
        if(nums.size() == 1) return 1;
        if(nums.size() == 2 && nums[0] != nums[1]) return 2;
        if(nums.size() == 2 && nums[0] == nums[1]) return 1;
        // flag: 当 flag == -1 的时候，表示当前差应该为负数，flag == 1 的时候，当前差为正数
        // 现在就能设置指针了
        int cur = 1;
        int pre = 0;
        int del = 0;
        int flag = 0;
        while(cur < nums.size()) {
            int diff = nums[cur] - nums[pre];
            if(flag == 0) {
                // 表示 flag 还没有被初始化，要看情况初始化
                // std::cout << "call" << std::endl;
                if(diff == 0) {
                    cur++;
                    del++; // 这里也要删除
                }
                else if(diff < 0) flag = -1;
                else flag = 1;
                continue;
            }
            if(diff * flag > 0) {
                // 表示符合规范
                pre = cur; // 这里不是 pre++, 因为要跳过删掉的数字
                cur++;
                flag = ~flag;
            } else {
                std::cout << "call" << std::endl;
                cur++;
                del++;
            }
        }
        return nums.size() - del;
    }
};

// [33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15]
```

### Carl的思路

https://programmercarl.com/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF

找序列的峰值。

但是要注意要处理三种情况：
- 情况一：上下坡中有平坡
- 情况二：数组首尾两端
- 情况三：单调坡中有平坡

其实看了下，Carl的思路也有点复杂。

### 我的思路2（通过）

我想用单调性来解决，如果单调性改变了，就++就行。我先尝试写下代码。


```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 单调性改变次数就是最终结果
        // 处理特殊情况
        if(nums.size() == 1) return 1;
        if(nums.size() == 2 && nums[0] != nums[1]) return 2;
        if(nums.size() == 2 && nums[0] == nums[1]) return 1;
        // 开始记录单调性改变次数
        int monotonicity_flag = 0; // 0表示未初始化单调性
        int monotonicity_change = 2;
        // 首先先初始化单调性，如果序列是 1-1-1-2-3，那么前面一系列1都是无用的，直接把指针放到最后一个位置再开始
        int begin_ptr = 1;
        while(begin_ptr < nums.size()) {
            if(nums[begin_ptr] == nums[begin_ptr - 1]) begin_ptr++;
            else break;
        }
        if(begin_ptr == nums.size()) return 1; // 走到尽头也不能确定单调性

        std::cout << "begin_ptr: " << begin_ptr << std::endl;

        // 1-1-1-2-3 现在 begin_ptr 指向2
        if(nums[begin_ptr] - nums[begin_ptr-1] > 0) monotonicity_flag = 1;
        else if(nums[begin_ptr] - nums[begin_ptr-1] < 0) monotonicity_flag = -1;
        else assert(false); // 前面步骤已经排除了这种情况
        // 开始遍历，统计单调性变化的次数
        int pre_ptr = begin_ptr - 1;
        int cur_ptr = begin_ptr;
        while(cur_ptr < nums.size()) {
            int diff = nums[cur_ptr] - nums[pre_ptr];
            if(diff * monotonicity_flag >= 0) {
                // 单调性不变
                cur_ptr++;
                pre_ptr++;
            } else if(diff * monotonicity_flag < 0) {
                // 发生一次单调性变化
                monotonicity_change++;
                monotonicity_flag = -monotonicity_flag;
                cur_ptr++;
                pre_ptr++;
            }
        }
        return monotonicity_change;
    }
};
```

直接通过了，我就是记录单调性的变化次数。我感觉这样能规避Carl那个分成三种情况的麻烦。


### Carl的动态规划思路

看不懂啊。得后面慢慢理解了。

## 最大子数组和

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。

### 贪心思路

这个和滑动窗口有点类似，但是是不同的。也有点类似求前缀和。

- key point: 当count为负数的时候，舍弃。注意：不是当 nums[i] 为负数的时候舍弃。

count就是前面一段子序列的和。

因此，要从第一个正数开始，count += nums[i]

当这个count变成负数的时候，count重制为0，重新计算count。

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            if(count > res) res = count;
            if(count < 0) count = 0;
        }
        return res;
    }
};
```

### dp思路

这个dp思路是我想的，不过也是因为之前做过。

dp[i] 表示以 nums[i] 结尾的连续子序列最大和是多少。

比如:
-2, 1, -3, 4, -1, 2, 1, -5, 4 这个序列
dp数组就是
-2
遇到1的时候比较 1 和 -2+1 谁大:
-2, 1, -2, 4, 3, 5, 6, 1, 5

所以最后结果就是6

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        std::vector<int>dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(nums[i], dp[i-1] + nums[i]);
            if(dp[i] > res) res = dp[i];
        }
        return res;
    }
};
```

顺利通过。

## 买卖股票的最佳时机 II

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

### 贪心算法

一开始没想到贪心怎么弄。

Carl的思路：

**如果想到其实最终利润是可以分解的，那么本题就很容易了！**

如何分解呢？

假如第 0 天买入，第 3 天卖出，那么利润为：`prices[3] - prices[0]`。

相当于`(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])`。

此时就是把利润分解为每天为单位的维度，而不是从 0 天到第 3 天整体去考虑！

那么根据 `prices` 可以得到每天的利润序列：`(prices[i] - prices[i - 1]).....(prices[1] - prices[0])`。

![](https://file1.kamacoder.com/i/algo/2020112917480858-20230310134659477.png)

贪心算法其实就是收集正利润即可。

比如收集 4 + 5，其实就是在1的时候买入，在10的时候卖出。

**所以这题的重点是：‼️要想到利润是可以被分解的！**

所以代码就是：

### dp思路

这里我没有看懂，学习dp的时候需要系统学习一下。


## 跳跃游戏

https://leetcode.cn/problems/jump-game/

给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

### 我的思路

我的思路是，从后向前遍历。

比如: [3, 2, 1, 0, 4]

倒数第一个下标位置至少需要是1，倒数第二个至少需要是2 ... 以此类推。只需要遍历一次即可。（bug）

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int loop_cnt = 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            if(nums[i] >= loop_cnt) return true;
            loop_cnt++;
        }
        return false;
    }
};
```

这个思路是有bug的。

比如 [0, 2, 3]

虽然遍历到2已经符合条件了，但是是有问题的，因为根本到不了2这个地方。

**更正后的思路：**

其实遍历到2，不能直接返回true，而是把2作为数组的末尾重新开始操作：本质就是把loop_cnt重置即可！

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int loop_cnt = 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            if(nums[i] >= loop_cnt) {
                loop_cnt = 1;
                continue; // 重置loop_cnt
            }
            loop_cnt++;
        }
        return nums[0] >= loop_cnt;
    }
};
```

需要每一个数字，都要符合条件，所以最后是返回 `return nums[0] >= loop_cnt;`。

### Carl的思路

Carl的思路也不错，通过一个cover变量来看看是不是可以走到最后。

cover: `cover = max(nums[i] + i, cover)`

Carl的方法本质上就是动态规划！

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};
```

## 跳跃游戏II (需要复习)

https://leetcode.cn/problems/jump-game-ii/description/

给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：

0 <= j <= nums[i] 且
i + j < n
返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。

这道题在做的时候我参考了Carl的方案。

我需要记录一个 `currentMaxCover` 和 `nextMaxCover` 两个变量。

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxCurrentCover = nums[0];
        int maxNextCover = 0;
        int step = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(step >= nums.size() - 1) return step;
            if(i <= maxCurrentCover) {
                maxNextCover = std::max(maxCurrentCover, std::max(maxNextCover, nums[i] + i));
            } else {
                step++;
                maxCurrentCover = maxNextCover;
                maxNextCover = std::max(maxCurrentCover, std::max(maxNextCover, nums[i] + i));
            }
        }
        return step;
    }
};
```

一次通过，good。

为什么要同时维护 `maxCurrentCover` 和 `maxNextCover` 呢？

因为我希望使用 `maxCurrentCover` 让一步走到最远，与此同时，我不断更新 `maxNextCover`。这样，如果 `maxCurrentCover` 不能 reach 到最后的位置，我就可以 `step++`。只增加一步。然后 `maxCurrentCover` 则变成上一轮的 `maxNextCover`。

这样就能保证以最少的步数走到最远的位置。

然后其实也不用遍历完数组，只要 `maxCurrentCover` 已经符合最后的要求了，就可以直接退出了。

## K 次取反后最大化的数组和

https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/

给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

 

示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。


这个题目很简单啊，以为最后是希望求和，所以其实可以直接排序就行了，把前面那些小的重复操作即可。

假设排序后: [1, 2, 3, 4, 5]，如果第一个数就是非负的，则k就一直操作第一个数。

假设排序后：[-100, -99, 0, 1, 2]，如果前面有一系列负数，则把这些负数先处理成正的，然后遇到第一个非负数，再把剩余的k重复用于第一个非负数即可。

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int idx = 0;
        while(idx < nums.size() && k > 0) {
            if(nums[idx] < 0) {
                nums[idx] = -nums[idx];
                idx++;
                k--;
            } 
            else if(nums[idx] >= 0) break;
        }
        std::sort(nums.begin(), nums.end()); // 需要重新排序，因为处理完负数可能是:[2, 1, 9, 10], 下一个应该处理1而不是9
        // 而且这里的else只会运行一次，效率没问题
        // nums[idx] = -nums[idx];
        // k--; // 这样会有bug，当第一个非负被处理后，可能会进入上面的if，我不希望这样
        if(k % 2 == 1)
            nums[0] = -nums[0];
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
```

微调了一下顺利通过。

## 加油站（需要复习）

https://leetcode.cn/problems/gas-station/description/

在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。


这道题没想出来。

这里写两个carl的方法。

### 贪心算法一（Carl）

全局进行贪心。

直接从全局进行贪心选择，情况如下：

- 情况一：如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的

- 情况二：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。

- 情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能把这个负数填平，能把这个负数填平的节点就是出发节点。

前两个情况是很好理解的，第三个情况需要理解一下。

比如: g = [1, 2, 3, 4, 5] \
     c = [3, 4, 5, 1, 2] \
     r = [-2, -2, -2, 3, 3]

**为什么要累加？**

在这个情况中，假设油是可以欠费的，那么在前三个站点，会欠费越来越多，这样是不行的。

所以情况三，是要从后面向前找，直到找到可以把欠费弥补掉之后，才能开始。

那么在绕一圈的过程中，什么时候欠费最多，一开始就要准备好足够的库存。

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int accumulate_min = INT_MAX;
        assert(gas.size() == cost.size());
        for(int i = 0; i < gas.size(); ++i) {
            int rest = gas[i] - cost[i];
            sum += rest;
            if(sum < accumulate_min) accumulate_min = sum;
        }
        // 情况1:
        if(sum < 0) return -1; // 不可能走一圈
        // 情况2:
        if(accumulate_min >= 0) return 0; // 直接从0开始即可
        // 情况3:
        sum = 0;
        int i = -1;
        for(i = gas.size() - 1; i >= 0; --i) {
            sum += (gas[i] - cost[i]);
            if(sum + accumulate_min >= 0) break;
        }
        return i;
    }
};
```

按照这个思路能顺利通过。

> **Carl:** 其实我不认为这种方式是贪心算法，因为没有找出局部最优，而是直接从全局最优的角度上思考问题。 
> 但这种解法又说不出是什么方法，这就是一个从全局角度选取最优解的模拟操作。 
> 所以对于本解法是贪心，我持保留意见！
> 但不管怎么说，解法毕竟还是巧妙的，不用过于执着于其名字称呼。

### 贪心算法二（Carl）

可以换一个思路，首先如果总油量减去总消耗大于等于零那么一定可以跑完一圈，说明 各个站点的加油站 剩油量rest[i]相加一定是大于等于零的。

每个加油站的剩余量 rest[i ]为gas[i] - cost[i]。

**i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，因为这个区间选择任何一个位置作为起点，到i这里都会断油，那么起始位置从i+1算起，再从0计算curSum。**

那么局部最优：当前累加rest[i]的和curSum一旦小于0，起始位置至少要是i+1，因为从i之前开始一定不行。全局最优：找到可以跑一圈的起始位置。

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int startIdx = 0;
        assert(gas.size() == cost.size());
        for(int i = 0; i < gas.size(); ++i) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;
            if(curSum < 0) {
                // 表示 [0, i] 都不能做起始位置
                startIdx = i + 1; // 更新 start 的位置
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return startIdx;
    }
};
```

这题还是有点难理解。要好好复习。


## 分发糖果

https://leetcode.cn/problems/candy/

### 我的思路（bug）

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        // 我的思路是，从左向右走一次，允许负数，然后最后再修正
        int sum = 1; // 第一个孩子默认一个糖果
        int pre_candy = 1; // 第一个孩子默认一个糖果
        int min_candy = 1;
        for(int i = 1; i < ratings.size(); ++i) {
            if(ratings[i] > ratings[i-1]) {
                sum += (pre_candy + 1);
                pre_candy = pre_candy + 1;
            }
            else if(ratings[i] < ratings[i-1]) {
                int tmp = pre_candy-1>1?1:pre_candy-1;
                sum += tmp;
                pre_candy = tmp;
                if(tmp < min_candy) min_candy = tmp; // 更新最小
            } else {
                sum += 1;
                pre_candy = 1;
            }
        }
        return sum + ratings.size()*(-min_candy+1);
    }
};
```

这种方式有bug，并不能很好的处理有重复 rating 的情况。

其实问题就是出在，重复的时候时候rating处理不好。

### 正确思路

所以还是从前向后，从后向前分别来处理，一开始全部处理成1就行。

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 1) return 1;
        if(ratings.size() == 2 && ratings[0] != ratings[1]) return 3;
        if(ratings.size() == 2 && ratings[0] == ratings[1]) return 2; 
        std::vector<int>res(ratings.size(), 1);
        // 从前向后
        for(int i = 1; i < ratings.size(); ++i)
            if(ratings[i] > ratings[i-1]) res[i] = std::max(res[i-1]+1, res[i]);
        // 从后向前
        for(int i = ratings.size() - 2; i >=0; --i) {
            if(ratings[i] > ratings[i+1]) res[i] = std::max(res[i+1]+1, res[i]);
        }
        return std::accumulate(res.begin(), res.end(), 0);
    }
};
```

这样就顺利通过了。

只处理大，不处理小。

## 柠檬水找零

https://leetcode.cn/problems/lemonade-change/description/

