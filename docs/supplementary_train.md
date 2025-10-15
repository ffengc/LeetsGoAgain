# 补充题目

- [补充题目](#补充题目)
  - [1365.有多少小于当前数字的数字](#1365有多少小于当前数字的数字)
  - [941. 有效的山脉数组](#941-有效的山脉数组)
  - [1207. 独一无二的出现次数](#1207-独一无二的出现次数)
  - [283. 移动零](#283-移动零)
  - [189. 轮转数组](#189-轮转数组)
  - [724. 寻找数组的中心下标](#724-寻找数组的中心下标)
  - [34. 在排序数组中查找元素的第一个和最后一个位置](#34-在排序数组中查找元素的第一个和最后一个位置)


## 1365.有多少小于当前数字的数字

https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

**我的思路：**

首先暴力肯定是 $O(n^2)$。所以我这里优化一下，用一个 `multimap` 试一下。key是这个数字，value是它的下标。然后最后遍历一次 multimap, 就可以直接把结果填到 result 数组中。

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::multimap<int, int> mmap;
        // build index
        for(int i = 0; i < nums.size(); ++i)
            mmap.insert({nums[i], i});
        // search
        auto result = std::vector<int>(nums.size());
        // 这里要特别处理数字相同的情况
        int fill_in_num = 0;
        int cur_idx = 0;
        int prev = 0;
        for(const auto& e : mmap) {
            if(cur_idx != 0 && e.first == prev) {
                // 遇到数字相同的情况
                result[e.second] = fill_in_num;
                prev = e.first;
                cur_idx++;
            } else {
                fill_in_num = cur_idx;
                result[e.second] = fill_in_num;
                prev = e.first;
                cur_idx++;
            }
        }
        return result;
    }
};
```

可以通过。

Carl的思路和我的大致是一样的，他是用hashmap，然后也是记住下标在哪。所以是一样的。

## 941. 有效的山脉数组

https://leetcode.cn/problems/valid-mountain-array/description/

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // 先计算前缀和数组
        std::vector<int> prefix;
        for(int i = 1; i < arr.size(); ++i) 
            prefix.push_back(arr[i] - arr[i-1]);
        // check if valid
        bool prefixFlag = false; // 记录是否达到山峰
        for(int i = 0; i < prefix.size(); ++i) {
            if(i == 0 && prefix[i] < 0) return false;
            if(!prefixFlag && prefix[i] > 0) continue;
            else if(prefix[i] == 0) return false;
            else if(!prefixFlag && prefix[i] < 0) prefixFlag = true;
            else if(prefixFlag && prefix[i] < 0) continue;
            else if(prefixFlag && prefix[i] > 0) return false;
        }
        return prefixFlag == true;
    }
};
```

这题很简单，没啥好说的，按照题目定义去弄就行了。

## 1207. 独一无二的出现次数

https://leetcode.cn/problems/unique-number-of-occurrences/

给你一个整数数组 arr，如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

简单题。

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> umap;
        for(const auto& e : arr)
            umap[e]++;
        std::unordered_set<int> uset;
        for(const auto& e : umap){
            if(uset.find(e.second) != uset.end()) return false;
            uset.insert(e.second);
        }
        return true;
    }
};
```

## 283. 移动零

https://leetcode.cn/problems/move-zeroes/

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意 ，必须在不复制数组的情况下原地对数组进行操作。**

双指针就行了，这题也可以看成是双指针题目的一个复习了。

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // fast指针，如果遇到不是0的，就copy到slow指针上
        int fast = 0; int slow = 0;
        while(fast < nums.size() && slow < nums.size()) {
            while(fast < nums.size() && nums[fast] == 0) fast++;
            // 此时fast指向一个非0的合法数字
            // while(slow < nums.size() && nums[slow] != 0) slow++;
            if(fast >= nums.size()) break;
            // 此时 slow 指向 0
            nums[slow++] = nums[fast++];
        }
        while(slow < nums.size()) nums[slow++] = 0;
    }
};
```

顺利通过。

## 189. 轮转数组

https://leetcode.cn/problems/rotate-array/description/

给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

这题我是记得的，把前k个和后n-k个分别逆序，然后整体逆序即可。

```cpp
class Solution {
private:
    using it = std::vector<int>::iterator;
    void reverse(it begin, it end) {
        while(begin < end) std::swap(*begin++, *end--);
    }
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()) k %= nums.size(); // 这一步很重要，不然会越界访问
        reverse(nums.begin(), nums.begin() + (nums.size() - k) - 1);
        reverse(nums.begin() + (nums.size() - k), nums.end() - 1);
        reverse(nums.begin(), nums.end() - 1);
    }
};
```

轻松简单。

## 724. 寻找数组的中心下标

https://leetcode.cn/problems/find-pivot-index/description/

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        std::cout << sum << std::endl; // -6
        int leftSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            std::cout << sum - nums[i] << std::endl;
            if(abs(sum - nums[i]) % 2 == 1) { // 因为这里有负数，这里要处理一下
                leftSum += nums[i];
                continue;
            }
            int target = (sum - nums[i]) / 2;
            if(leftSum == target) return i;
            else{
                leftSum += nums[i];
                continue;      
            }
        }
        return -1;
    }
};
```

Carl的思路也是一样的。

## 34. 在排序数组中查找元素的第一个和最后一个位置

