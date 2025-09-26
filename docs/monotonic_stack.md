

# 单调栈

- [单调栈](#单调栈)
  - [单调栈简介](#单调栈简介)
  - [每日温度](#每日温度)
    - [Carl的模拟过程](#carl的模拟过程)
    - [看完思路自己尝试写代码](#看完思路自己尝试写代码)
  - [下一个更大元素I](#下一个更大元素i)
  - [下一个更大元素II](#下一个更大元素ii)
  - [接雨水](#接雨水)

## 单调栈简介

Carl里面没有解释单调栈是什么。这里简单写一些ai生成的介绍。

“单调栈”在英文里一般叫 Monotonic Stack。有时候根据具体用法，也会说成 monotone increasing stack 或 monotone decreasing stack。

简单解释：
单调栈是一种特殊的栈，它在入栈/出栈的过程中保持某种单调性。
- 如果是单调递增栈（monotone increasing stack），栈里元素从栈底到栈顶是递增的。当有新元素要入栈时，如果它比栈顶元素小或相等，就要不断弹出栈顶直到满足单调性，再把新元素压入。
- 如果是单调递减栈（monotone decreasing stack），规则刚好相反。

**直观理解：
它就是一个“有序的栈”，用来快速找到某个元素左边/右边最近的比它大或比它小的元素。**

常见用途：
- 求数组中每个元素 下一个更大/更小元素（Next Greater/Smaller Element）。
- 解决像 接雨水、柱状图最大矩形 这样的经典问题。

遇到什么情况要想到要使用单调栈呢？

通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，此时我们就要想到可以用单调栈了。时间复杂度为 `O(n)`。

## 每日温度

https://leetcode.cn/problems/daily-temperatures/description/

给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 `answer[i]` 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

### Carl的模拟过程

此部分内容来自Carl: https://programmercarl.com/0739.每日温度.html#思路

使用单调栈主要有三个判断条件：
- 当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况
- 当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况
- 当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况

| ![](https://file1.kamacoder.com/i/algo/20210219124434172.jpg) | ![](https://file1.kamacoder.com/i/algo/20210219124504299.jpg) | ![](https://file1.kamacoder.com/i/algo/20210219124527361.jpg) |
|------|------|------|
| ![](https://file1.kamacoder.com/i/algo/20210219124610761.jpg)   | ![](https://file1.kamacoder.com/i/algo/20210219124633444.jpg)   | ![](https://file1.kamacoder.com/i/algo/20210219124700567.jpg)   |
| ![](https://file1.kamacoder.com/i/algo/20210219124726613.jpg)   | ![](https://file1.kamacoder.com/i/algo/20210219124807715.jpg)   | ![](https://file1.kamacoder.com/i/algo/2021021912483374.jpg)   |
| ![](https://file1.kamacoder.com/i/algo/2021021912490098.jpg)   | ![](https://file1.kamacoder.com/i/algo/20210219124930156.jpg)   | ![](https://file1.kamacoder.com/i/algo/20210219124957216.jpg)   |


### 看完思路自己尝试写代码

```cpp
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        // temperatures = [73,74,75,71,69,72,76,73]
        std::stack<int> st;
        std::vector<int> res(temperatures.size());
        st.push(0);
        // 单调栈逻辑
        for(int i = 1; i < temperatures.size(); ++i) {
            if(temperatures[i] > temperatures[st.top()]) {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) { 
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            else if(temperatures[i] <= temperatures[st.top()])
                st.push(i);
        }
        return res;
    }
};
```

确实对于我来说是一种新的思路，需要好好消化。

## 下一个更大元素I

https://leetcode.cn/problems/next-greater-element-i/description/

nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

先自己尝试写代码。

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack<int> st;
        std::vector<int> res(nums1.size(), -1);
        // 先存映射
        std::unordered_map<int, int> mmap;
        for(int i = 0; i < nums1.size(); ++i)
            mmap[nums1[i]] = i;
        // 单调栈
        st.push(nums2[0]);
        for(int j = 1; j < nums2.size(); ++j) {
            // if(mmap.find(nums2[j]) == mmap.end()) continue; // 没有这个数
            if(nums2[j] > st.top()) {
                while(!st.empty() && nums2[j] > st.top()) {
                    if(mmap.find(st.top()) != mmap.end())
                        res[mmap[st.top()]] = nums2[j]; // 这题是存数，不是下标差
                    st.pop();
                }
                st.push(nums2[j]);
            } else st.push(nums2[j]);
        }
        return res;
    }
};
```

调试了好一会儿，画了好几次图终于调试出来了。

**所以单调栈的题目，不一定存下标，直接存数字也可以的，看题目要求！**


## 下一个更大元素II

https://leetcode.cn/problems/next-greater-element-ii/description/

给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

这个题我的思路可能有点抽象，但是我想尝试一下。

收到之前字符串旋转的启发。

如果我把最大的数字rotate到最后一个位置，就可以当普通情况求了，求完之后再rotate回去。问题就是，如何记录自己一开始是如何rotate的。

然后我发现这个rotate也不用真的rotate，模拟这个过程也是可以的。比如一开始遍历的位置，就是最大数字的下一个位置，然后开始遍历，遇到结尾就回到0的位置，终止条件就是 != maxElementIdx。

先试试。

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<int> st;
        std::vector<int>res(nums.size(), -1);
        // 找到最大元素的下标
        int maxIdx = -1;
        int max_ = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > max_) {
                max_ = nums[i];
                maxIdx = i;
            }
        }
        // 开始下标
        int beginIdx = maxIdx + 1;
        if(beginIdx == nums.size()) beginIdx = 0;
        st.push(beginIdx);
        int curIdx = beginIdx;
        curIdx++;
        if(curIdx == nums.size()) curIdx = 0;
        while(true) {
            if(nums[curIdx] > nums[st.top()]) {
                while(!st.empty() && nums[curIdx] > nums[st.top()]) {
                    res[st.top()] = nums[curIdx];
                    st.pop();
                }
                st.push(curIdx);
            } else st.push(curIdx);
            // 判断是否要退出循环
            if(curIdx == maxIdx) break;
            // 迭代
            curIdx++;
            if(curIdx == nums.size()) curIdx = 0;
        }
        return res;
    }
};
```

我的方法虽然有点猎奇，但是也做出来了，good！

看了Carl的方法之后，其实我的方法效率是非常好的。

**Carl其中一个比较清晰的方法，就是，把数组复制一份拼接到后面去，这个方法确实清晰，而且好。**

后面遇到循环的情况，都要想到可以把数组copy一份拼接到后面去。

## 接雨水

https://leetcode.cn/problems/trapping-rain-water/description/

