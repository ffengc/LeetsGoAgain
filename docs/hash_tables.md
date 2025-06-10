# 哈希表

- [哈希表](#哈希表)
  - [哈希表基础知识](#哈希表基础知识)
  - [有效的字⺟异位词](#有效的字异位词)
  - [两个数组的交集](#两个数组的交集)
    - [那所有哈希的题都用set就好了，还用什么数组？这是对的吗？](#那所有哈希的题都用set就好了还用什么数组这是对的吗)


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



### 那所有哈希的题都用set就好了，还用什么数组？这是对的吗？

不对。

直接使⽤`set`不仅占⽤空间⽐数组⼤，⽽且速度要⽐数组慢，`set`把数值映射到key上都要做hash计算的。不要⼩瞧这个耗时，在数据量⼤的情况，差距是很明显的。

如果题目是有限制数据范围的，都要想想看看要不要用数组即可。