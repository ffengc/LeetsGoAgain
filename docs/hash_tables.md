# 哈希表

- [哈希表](#哈希表)
  - [哈希表基础知识](#哈希表基础知识)
  - [有效的字⺟异位词](#有效的字异位词)
  - [两个数组的交集](#两个数组的交集)
    - [那所有哈希的题都用set就好了，还用什么数组？这是对的吗？](#那所有哈希的题都用set就好了还用什么数组这是对的吗)
  - [快乐数](#快乐数)
  - [两数之和（经典重要题目）](#两数之和经典重要题目)


## 哈希表基础知识

个人比较熟悉，但是还是补充一些内容。

⼀些C++的经典书籍上 例如STL源码剖析，说到了`hash_map`和`hash_set`，这些是C++11标准之前民间高手自发造的轮子。

当我们遇到了要快速判断⼀个元素是否出现集合⾥的时候，就要考虑哈希法。但是哈希法也是牺牲了空间换取了时间，因为我们要使⽤额外的数组，set或者是map来存放数据，才能实现快速的查找。如果在做⾯试题⽬的时候遇到需要判断⼀个元素是否出现过的场景也应该第⼀时间想到哈希法！

## 有效的字⺟异位词

https://leetcode.cn/problems/valid-anagram/description/

一眼哈希就能解决。当然因为是字母，所以也可以弄个26长度的数组。

我这种方法是用了两个哈希表，空间上会多些。如果只用一个，遍历`t`的时候就`--`, 然后最后循环看看哈希表里有没有不为0的，有不为0说明对不上，`return false`;

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::unordered_map<char, int> hash_map;
        std::unordered_map<char, int> hash_map2;
        for(const auto& e : s)
            hash_map[e]++;
        for(const auto& e : t)
            hash_map2[e]++;
        return hash_map == hash_map2;
    }
};
```

## 两个数组的交集

https://leetcode.cn/problems/intersection-of-two-arrays/

这题，除了常规的哈希法：

因为我之前是过了一两遍C++11的算法库的，里面有 `set_intersection` 这个方法是可以直接用的。**不过这个是会有重复元素的，题目要求还要去重，太折腾了。**

> [!CAUTION]
> 通过查阅文档发现，`std::set_intersection`只能处理两个**有序**列表。所以这道题如果要用，一定是要排序的！所以不要用了。\
> cplusplus.com的描述: Constructs a sorted range beginning in the location pointed by result with the set intersection of the two sorted ranges `[first1,last1)` and `[first2,last2)`.

直接用哈希就行。

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> us;
        std::unordered_set<int> nums1_set;
        for(const auto& e : nums1)
            nums1_set.insert(e);
        for(const auto& e : nums2) {
            if(nums1_set.find(e) != nums1_set.end())
                us.insert(e);
        }
        return std::vector<int>(us.begin(), us.end());
    }
};
```

直接通过，Carl也是同样的思路。

不过这里有点冗余，可以改一下。
```cpp
std::unordered_set<int> nums1_set;
for(const auto& e : nums1)
    nums1_set.insert(e);
```
直接替换成：
```cpp
std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
```
直接这样构造就行了。

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> us;
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for(const auto& e : nums2) {
            if(nums1_set.find(e) != nums1_set.end())
                us.insert(e);
        }
        return std::vector<int>(us.begin(), us.end());
    }
};
```

[350. 两个数组的交集 II](https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/)

这个题我的思路是，`nums1 = [1,2,2,1], nums2 = [2,2]`。对于 `nums1` 来说，维护一个hash_table, 然后第二个元素是一个pair，用来记录nums1和nums2中出现的次数。

遍历 `nums1` 的时候，次数++到pair的第一个元素中。遍历 `nums2` 的时候，次数++到pair的第二个元素中。

**分析下复杂度：**

遍历 `nums1` 和 `nums2` 是 O(n), 然后最后再遍历一次map取最小，这一次是 O(n)，所以最后也是 O(n)。

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, std::pair<int,int>> m;
        std::vector<int> res;
        for(const auto& e : nums1) // 遍历 nums1
            m[e].first++;
        for(const auto& e : nums2) // 遍历 nums2
            if(m.find(e)!=m.end())
                m[e].second++;
        for(const auto& e : m) {
            if(e.second.second == 0) continue;
            for(int i = 0; i < std::min(e.second.first, e.second.second); ++i)
                res.push_back(e.first);
        }
        return res;
    }
};
```
直接通过了。

看看题解：
> 由于同一个数字在两个数组中都可能出现多次，因此需要用哈希表存储每个数字出现的次数。对于一个数字，其在交集中出现的次数等于该数字在两个数组中出现次数的最小值。\
> 首先遍历第一个数组，并在哈希表中记录第一个数组中的每个数字以及对应出现的次数，然后遍历第二个数组，对于第二个数组中的每个数字，如果在哈希表中存在这个数字，则将该数字添加到答案，并减少哈希表中该数字出现的次数。\
> 为了降低空间复杂度，首先遍历较短的数组并在哈希表中记录每个数字以及对应出现的次数，然后遍历较长的数组得到交集。\
> 作者：力扣官方题解
链接：https://leetcode.cn/problems/intersection-of-two-arrays-ii/solutions/327356/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


这个动画(来自力扣题解)可以解释好。

![](https://assets.leetcode.cn/solution-static/350/350_fig1.gif)




### 那所有哈希的题都用set就好了，还用什么数组？这是对的吗？

不对。

直接使⽤`set`不仅占⽤空间⽐数组⼤，⽽且速度要⽐数组慢，`set`把数值映射到key上都要做hash计算的。不要⼩瞧这个耗时，在数据量⼤的情况，差距是很明显的。

如果题目是有限制数据范围的，都要想想看看要不要用数组即可。

## 快乐数

https://leetcode.cn/problems/happy-number/description/

这个题一眼看上去很难，其实不难的。**因为题目说了，会无限循环，所以表示，在求和过程中，sum会重复出现的。**

用哈希表来看看和会不会重复出现就行了。

没啥问题，直接通过了。


```cpp
class Solution {
private:
    // 先写一个函数，来计算每位数字上的平方和
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> s;
        while(1) {
            int sum = getSum(n);
            if(sum == 1) return true;
            if(s.find(sum) == s.end()) s.insert(sum);
            else return false; // 陷入循环
            n = sum;
        }
        assert(false);
    }
};
```

## 两数之和（经典重要题目）

https://leetcode.cn/problems/two-sum/description/

这道题的思路是很重要的，很经典的题目。两个图可以说的很清楚（来自Carl）。

![](./assets/两数之和1.png)
![](./assets/两数之和2.png)

**核心是：可以用哈希表来记录，哪些数字是被访问过的？访问过的这个元素在哪？所以用kv键值对的哈希表。**

开始写代码。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = m.find(target-nums[i]);
            if (it != m.end()) // 找到了
                return std::vector<int>{it->second, i};
            else
                m.insert({nums[i], i});
        }
        assert(false);
    }
};
```

**这份代码很重要，后面很多题目都会用到！**