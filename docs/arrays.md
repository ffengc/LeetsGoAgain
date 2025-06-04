# 数组


- [数组](#数组)
  - [数组理论知识](#数组理论知识)
  - [二分查找](#二分查找)
  - [移除元素](#移除元素)
  - [⻓度最⼩的⼦数组](#度最的数组)
  - [螺旋矩阵II](#螺旋矩阵ii)


## 数组理论知识

因为个人非常熟悉了，这里略过。

## 二分查找

https://leetcode.cn/problems/binary-search/description/

我写的
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;
            int mid = (left + right) / 2;
            if (nums[mid] < target){
                left = mid + 1;
                continue;
            } else if (nums[mid] > target) {
                right = mid - 1;
                continue;
            } else if(nums[mid] == target) return mid;
        }
        return -1;
    }
};
```

这道题问题不大，一定要注意边界条件的处理，防止死循环。这题其实很简单，但是已经可以看出，刷题其实已经没有大一的时候熟练了。

**二分查找相关题目推荐：**

- [35.搜索插⼊位置](https://leetcode.cn/problems/search-insert-position/description/)

```cpp
// 一次过，问题不大
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;
            int mid = (left + right) / 2;
            if(nums[mid] < target){ 
                left = mid + 1;
                continue;
            } else if(nums[mid] > target) {
                right = mid - 1;
                continue;
            } else return mid;
        }
        return left;
    }
};
```

- [34.在排序数组中查找元素的第⼀个和最后⼀个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

这题有点意思，我想到的思路是，比如 [5, 7, 7, 8, 8, 10]。找8。
找到8是非常简单的，但是如何找到区间比较有意思。

比如，left = 7, right = 10, 此时 mid = 第一个8
那么可以在 left, mid 的区间找第一个8，mid, 10的区间找最后一个8。

但是这样我不确定是否是 logn。先用这个思路写，看看能不能过。（个人感觉不是logn）。

这个是我写的，全部通过。

```cpp
class Solution {
public:
    std::vector<int> find_forward_and_backward(const vector<int>& nums, int target, int current_idx) {
        assert(nums[current_idx] == target);
        std::vector<int> res;
        int left_ret = current_idx;
        int right_ret = current_idx;
        while(1) {
            if(left_ret <= 0) break;
            if(nums[left_ret] == target && nums[left_ret - 1] != target) break;
            left_ret--;
        }
        while(1) {
            if(right_ret >= nums.size()-1) break;
            if(nums[right_ret] == target && nums[right_ret + 1] != target) break;
            right_ret++;
        }
        return {left_ret, right_ret};
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return {0, 0};
            return {-1, -1};
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if(nums[left] == target) {
                return find_forward_and_backward(nums, target, left);
            } if (nums[right] == target) {
                return find_forward_and_backward(nums, target, right);
            }
            int mid = (left + right) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
                continue;
            } else if(nums[mid] > target) {
                right = mid - 1; 
                continue;
            } else if(nums[mid] == target) {
                return find_forward_and_backward(nums, target, mid);
            }
        }
        return {-1, -1};
    }
};
```


学习了一下 Carl 的做法，他通过两个函数，寻找左边界和寻找右边界去做的。她这个是完全是 logn

**这里值得注意，Carl 的做法，是可以得到边界的。注意 if else 的设置。**

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        // 情况二
        return {-1, -1};
    }
private:
     int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else { // 寻找右边界，nums[middle] == target的时候更新left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
                right = middle - 1;
                leftBorder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};
```

- [69.x的平⽅根](https://leetcode.cn/problems/sqrtx/description/)

这题我的思路是二分查找。不知道是不是准确的，先试试。
比如10，一开始就是1，10这个区间，然后二分是5，5的平方大于10，所以是1，5的区间，然后是2，5的区间 ...

自己写的，也通过了。

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        if (x == 0) return 0;
        long long left = 1;
        long long right = x;
        while (left <= right) {
            if(left * left == x) return left;
            if(right * right == x) return right;
            long long mid = (left + right) / 2;
            if (mid * mid == x || (mid * mid < x && (mid+1)*(mid+1)>x)) return mid;
            else if(mid * mid < x) {
                left = mid;
                continue;
            } else if (mid * mid > x) {
                right = mid;
                continue;
            }
        }
        assert(false);
    }
};
```

这题carl没有给结果，看了下题解和我这个基本是一样的，问题不大。

- [367.有效的完全平⽅数](https://leetcode.cn/problems/valid-perfect-square/description/)

这题和上面基本一致。一次通过。

```cpp
class Solution {
public:
    bool isPerfectSquare(int x) {
        if (x == 1) return true;
        long long left = 1;
        long long right = x;
        while (left <= right) {
            if(left * left == x) return true;
            if(right * right == x) return true;
            long long mid = (left + right) / 2;
            if (mid * mid == x) return true;
            if (mid * mid < x && (mid+1)*(mid+1) > x) return false;
            else if(mid * mid < x) {
                left = mid;
                continue;
            } else if (mid * mid > x) {
                right = mid;
                continue;
            }
        }
        assert(false);     
    }
};
```

## 移除元素

https://leetcode.cn/problems/remove-element/description/

好的方法肯定是双指针，这个方法后续肯定是很常用的。
慢指针，指向后续东西填补过来的位置。快指针寻找填补过来的数字。
我自己先写一个版本。

我自己写的这个版本，用双指针，但是用了-1去记录数组的数字是否被移动过。感觉不是最优写法。不过也通过了，总体来说比较顺利，效率也是ok的。

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int slow = 0;
        while(slow < nums.size() && nums[slow] != val) slow++;
        int fast = slow;
        while(fast < nums.size()) {
            while(slow < nums.size() && nums[slow] != val && nums[slow] != -1) slow++;
            if(fast < slow) fast = slow;
            // 此时 slow 指向第一个需要删除的数字
            while(fast < nums.size() && nums[fast] == val) fast++;
            // 此时 fast 指向一个需要移动的数字
            if(fast >= nums.size() || slow >= nums.size()) break;
            nums[slow++] = nums[fast];
            nums[fast++] = -1; // 用 -1 记录这个位置可以被覆盖。
        }
        return slow;
    }
};
```

看看carl的写法。

```cpp
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
```

用 [0, 1, 2, 2, 3, 0, 4, 2], val=2 去理解了一下这个写法，他可以重复赋值的，就不用做这么多判断了，确实更简洁。

[26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int slow = 0;
        int fast = 1;
        while(fast < nums.size()) {
            while(1) {
                if(fast < nums.size() && nums[slow] == nums[fast]) fast++;
                else break;
            }
            if(fast >= nums.size()) break;
            // 此时 slow 和 fast 指向的数字不一样
            slow++;
            assert(slow < nums.size());
            nums[slow] = nums[fast++];
        }
        return ++slow;
    }
};
```
直接通过，没啥问题，在草稿纸上做过一般都没问题。

[283. 移动零](https://leetcode.cn/problems/move-zeroes/description/)

这题个人感觉很简单，slow指针指向0，fast指向非0，交换即可。

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1) return;
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()) {
            while(slow < nums.size() && nums[slow] != 0) slow++;
            while(fast < nums.size() && nums[fast] == 0) fast++;
            if(slow > fast) {
                fast = slow;
                continue;
            }
            if(fast >= nums.size()) break;
            std::swap(nums[fast], nums[slow]);
            slow++;
        }
    }
};
```
问题不大，顺利通过

[844. 比较含退格的字符串](https://leetcode.cn/problems/backspace-string-compare/description/)

这个题怎么感觉用栈做是最好的，先试试用栈。不过这样空间就不是O(1)了。

```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::stack<int> st1;
        std::stack<int> st2;
        for (const auto& e : s) {
            if (e == '#' && st1.size() > 0) st1.pop();
            else if (e == '#' && st1.size() == 0) continue;
            else st1.push(e);
        }
        for(const auto& e : t) {
            if (e == '#' && st2.size() > 0) st2.pop();
            else if (e == '#' && st2.size() == 0) continue;
            else st2.push(e);
        }
        return st1 == st2;
    }
};
```
用栈没问题，速通。

试一下用双指针，空间用 O(1)


这题做的有点慢，不过最后也是做出来了。

```cpp
class Solution {
private:
    int simplify(std::string& str) {
        // int current_size = str.size();
        int fast = 0;
        int slow = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '#') {
                fast++;
                if(slow > 0) slow--;
            } else if(str[i] != '#') {
                slow++;
                fast++;
            }
            if(fast >= str.size()) break;
            str[slow] = str[fast];
        }
        return slow; // slow的大小表示字符串长短
    }
public:
    bool backspaceCompare(string s, string t) {
        // 使用双指针
        // fast指针为探索指针
        // slow指针为有效位置指针
        // fast指针负责探索前面路况，如果遇到#，则有效位置--，同时str的长度--
        // fast指针如果遇到有效字符，则str长度不变，如果此时fast和slow不在同一位置，则覆盖
        int ssize = simplify(s);
        std::cout << ssize << ":" << std::string(s.begin(), s.begin()+ssize) << std::endl;
        int tsize = simplify(t);
        std::cout << tsize << ":" << std::string(t.begin(), t.begin()+tsize) << std::endl;
        return (std::string(s.begin(), s.begin()+ssize) == std::string(t.begin(), t.begin()+tsize)) || (ssize == 0 && tsize == 0);
        // 最后这里重新构造string，表示切割后的字符串
    }
};
```

[977. 有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)

这一题最好是用归并的思想。

之前的一类题：两个升序的序列，合成一个升序序列，双指针归并思想。题目没说空间要 O(1)。


```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> ans;
        int right = 0;
        while(right < nums.size() && nums[right] < 0) right++;
        int left = right - 1;
        while(right < nums.size() && left >= 0) {
            size_t left_ans = nums[left] * nums[left];
            size_t right_ans = nums[right] * nums[right];
            if(left_ans < right_ans) {left--; ans.push_back(left_ans);}
            else {right++; ans.push_back(right_ans);}
        }
        while(left >= 0) ans.push_back(nums[left]*nums[left--]);
        while(right < nums.size()) ans.push_back(nums[right]*nums[right++]);
        return ans;
    }
};
```

其实思路就是归并的思路。但是过程不算太顺利，这也说明了，不熟练了。问题不大大。这个是 O(n) 的。


## ⻓度最⼩的⼦数组

https://leetcode.cn/problems/minimum-size-subarray-sum/

我能直接想到滑动窗口的双指针解法。区间和大了，就slow++，区间和小了就fast++。


```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 处理下特殊情况
        if (nums.size() == 1) {
            if(nums[0] >= target) return 1;
            else return 0;
        }
        int len = INT32_MAX; // 滑动窗口大小
        int slow = 0;
        int fast = 0;
        int current_sum = nums[0];
        while(fast < nums.size()) {
            if (current_sum >= target) {
                int cur_len = fast-slow+1;
                if(cur_len < len) len = cur_len;
                if(slow == fast) {slow++; fast++; current_sum = nums[fast];}
                else {current_sum-=nums[slow++];}
            } else if(current_sum < target) {
                fast++;
                if(fast >= nums.size()) break;
                current_sum += nums[fast];
            }
        }
        return len == INT32_MAX ? 0 : len;
    }
};
```

我的思路没问题，和carl的一样，顺利通过。


[904. 水果成篮](https://leetcode.cn/problems/fruit-into-baskets/description/)

这题题目有点难理解，我理解了很久。还是打算用滑动窗口去做即可。

这题真的有点难，先按照自己的思路写一下，写了很久，主要是指针有点难管理清楚。

```cpp
class Solution {
private:
    bool in_pair(std::pair<int,int>& p, int x) {
        // if (x == p.first) return true;
        // if (x == p.second) {
        //     std::swap(p.first, p.second);
        //     return true;
        // }
        // return false;
        return p.second == x || p.first == x;
    }
public:
    int totalFruit(vector<int>& fruits) {
        // 这个题目太难理解了
        // 我理解了之后，翻译成人话：找一个最长的，只包含两种元素的子序列（即这个子序列set之后的size为2）
        // 我用一个 pair 来记录哪些类型是记录过的
        if(fruits.size() == 1) return 1;
        // 初始化
        int len = 2;
        int slow = 0;
        int fast = 0;
        // 初始化
        while(fast < fruits.size()) {
            std::pair<int, int> p;
            p.first = fruits[slow];
            p.second = -1;
            while(fast < fruits.size()) {
                if(in_pair(p, fruits[fast])) {
                    fast++;
                    continue;
                }
                else if(p.second == -1) {
                    p.second = fruits[fast];
                    fast++;
                    continue;
                }
                else if(in_pair(p, fruits[fast]) == false && p.first != -1 && p.second != -1) break;
            }
            // if(fast >= fruits.size()) break;
            int cur_len = fast - slow;
            // std::cout << cur_len << std::endl;
            if(cur_len > len) len = cur_len;
            // 下一轮迭代
            if(fast >= fruits.size()) break;
            assert(fruits[fast]!=fruits[fast-1]);
            int temp = fruits[fast-1];
            slow = fast-1;
            while(fruits[slow]==temp) slow--;
            slow++;
        }
        return len;
    }
};
```

不过最后也是艰难通过。


[76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/description/)

```cpp
class Solution {
private:
    std::unordered_map<char, int> m;
    std::unordered_map<char, int> m_for_check;
private:
    void init_check_map(const std::string& t) {
        for(const auto& e : t) {
            m_for_check[e] += 1;
        }
    }
    bool is_valid(const std::string& t) {
        for (const auto& e : t)
            if (m[e] < m_for_check[e])
                return false;
        return true;
    }
    void print_m() {
        for (const auto& e : m)
            std::cout << e.first << ":" << e.second << std::endl;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        // 处理边界条件
        if (s.size() == 1) {
            return s == t ? s : "";
        }
        // 开始处理
        init_check_map(t);
        int slow = 0;
        int fast = 0;
        int len = INT32_MAX;
        std::string ret_string;
        m[s[fast]] += 1;
        while (fast < s.size()) {
            bool res = is_valid(t);
            // std::cout << slow << ":" << fast << std::endl; print_m();
            // std::cout << res << std::endl; exit(1);
            if (res) {
                int cur_len = fast - slow + 1;
                if (cur_len < len) {
                    len = cur_len;
                    ret_string = std::string(s.begin() + slow, s.begin() + fast + 1);
                    // std::cout << "更新 ret: " << ret_string << std::endl; 
                }
                m[s[slow]] -= 1;
                slow++;
            } else {
                fast++;
                m[s[fast]] += 1;
            }
        }
        return ret_string;
    }
};
```
写了一个版本，但是没有通过，超出时间限制了，明天再看看吧。

题解：
```cpp
class Solution {
public:
    unordered_map <char, int> ori, cnt;
    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }
    /* 我大概看明白了
        ori这个map是用来作对照的
        cnt这个map是用来记录t中字符出现的次数的
        这里和我的区别就是，我的cnt（m）记录所有s中的字符，其实不需要记录这么多，记录和t相关的即可了
        check()函数用来表示当前子串是否合法
     */
    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c]; // 这里先初始化ori
        }
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]]; // 存在所需要的字符，则cnt
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1; // 更新最新的len
                    ansL = l; // 记录下标而已，其实我用res_string也是一样的，都是可以的
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]]; // 因为l指针准备向右了，先看看这个指针指向的字符是不是t所需的，如果是，才需要控制cnt，否则直接++l即可了
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
```

我的思路是完全没问题的，个人感觉超时问题就是出在 cnt (m) 这个map里面，答案里cnt只管理有用字符，而我管理了全部字符。 

## 螺旋矩阵II

https://leetcode.cn/problems/spiral-matrix-ii/description/


**这道题⽬可以说在⾯试中出现频率较⾼的题⽬，本题并不涉及到什么算法，就是模拟过程，但却⼗分考察对代码的掌控能⼒。**


这题我先按自己的思路试一下吧。

```cpp
class Solution {
private:
    struct self_reference_pair {
        std::string first;
        self_reference_pair* second;
        bool operator==(const self_reference_pair& self) { return first == self.first; }
    }; //
private:
    bool is_location_valid(const std::vector<std::vector<bool>>& check_vec, const std::pair<int, int>& loc) {
        int limit = check_vec.size();
        if (loc.first >= 0 && loc.second >= 0 && loc.first < limit && loc.second < limit && check_vec[loc.first][loc.second] == false)
            return true;
        return false;
        // return check_vec[loc.first][loc.second] == false;
    } //
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        auto check_vec = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
        auto res_vec = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        // 构建一个mode的简易链表
        self_reference_pair down_mode, left_mode, up_mode; // 提前声明
        self_reference_pair right_mode = { "right_mode", &down_mode };
        down_mode = { "down_mode", &left_mode };
        left_mode = { "left_mode", &up_mode };
        up_mode = { "up_mode", &right_mode };
        // 开始循环
        int current_n = 1;
        self_reference_pair current_mode = right_mode; // 一开始向右
        std::pair<int, int> location = { 0, 0 };
        while (current_n <= n * n) {
            if (current_mode == right_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    // std::cout << "is_valid: " << is_valid << std::endl;
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        // std::cout << location.first << ":" << location.second << std::endl;
                        location.first += 1;
                        location.second -= 1;
                        // std::cout << location.first << ":" << location.second << std::endl;
                        if (current_n == n * n) {
                            // std::cout << "call1" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first;
                    location.second++;
                }
            } else if (current_mode == down_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first -= 1;
                        location.second -= 1;
                        if (current_n == n * n) {
                            // std::cout << "call2" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first++;
                    location.second;
                }
            } else if (current_mode == left_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                // std::cout << location.first << ":" << location.second << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    // std::cout << "here" << std::endl;
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first -= 1;
                        location.second += 1;
                        if (current_n == n * n) {
                            // std::cout << "call3" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first;
                    location.second--;
                }
            } else if (current_mode == up_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first++;
                        location.second++;
                        if (current_n == n * n) {
                            // std::cout << "call4" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first--;
                    location.second;
                }
            } else {
                assert(false);
            }
        }
        return res_vec;
    }
};
```
调试了一个下午终于通过了。


[54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/description/)
[LCR 146. 螺旋遍历二维数组](https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/)
这两个题是一样的，顺利通过了，和上面的题类似，大部分代码可以重复使用。

```cpp
class Solution {
private:
    struct self_reference_pair {
        std::string first;
        self_reference_pair* second;
        bool operator==(const self_reference_pair& self) { return first == self.first; }
    }; //
private:
    bool is_location_valid(const std::vector<std::vector<bool>>& check_vec, const std::pair<int, int>& loc) {
        int limit = check_vec.size();
        int m = check_vec.size();
        int n = check_vec[0].size();
        if (loc.first >= 0 && loc.second >= 0 && loc.first < m && loc.second < n && check_vec[loc.first][loc.second] == false)
            return true;
        return false;
    } //
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        auto check_vec = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));
        auto res_vec = std::vector<int>(); // 初始化
        // 构建一个mode的简易链表
        self_reference_pair down_mode, left_mode, up_mode; // 提前声明
        self_reference_pair right_mode = { "right_mode", &down_mode };
        down_mode = { "down_mode", &left_mode };
        left_mode = { "left_mode", &up_mode };
        up_mode = { "up_mode", &right_mode };
        // 开始循环
        int current_n = 1;
        self_reference_pair current_mode = right_mode; // 一开始向右
        std::pair<int, int> location = { 0, 0 };
        while (current_n <= m * n) {
            if (current_mode == right_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= m * n) {
                    // if (current_n == m * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    // std::cout << "is_valid: " << is_valid << std::endl;
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        // std::cout << location.first << ":" << location.second << std::endl;
                        location.first += 1;
                        location.second -= 1;
                        // std::cout << location.first << ":" << location.second << std::endl;
                        if (current_n == m * n) {
                            // std::cout << "call1" << std::endl;
                            res_vec.push_back(matrix[location.first][location.second]);
                            return res_vec;
                        }
                        break;
                    }
                    // res_vec[location.first][location.second] = current_n;
                    res_vec.push_back(matrix[location.first][location.second]);
                    check_vec[location.first][location.second] = true;
                    // if (current_n == m * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first;
                    location.second++;
                }
            } else if (current_mode == down_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= m * n) {
                    // if (current_n == m * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first -= 1;
                        location.second -= 1;
                        if (current_n == m * n) {
                            // std::cout << "call2" << std::endl;
                            res_vec.push_back(matrix[location.first][location.second]);
                            return res_vec;
                        }
                        break;
                    }
                    res_vec.push_back(matrix[location.first][location.second]);
                    check_vec[location.first][location.second] = true;
                    // if (current_n == m * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first++;
                    location.second;
                }
            } else if (current_mode == left_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                // std::cout << location.first << ":" << location.second << std::endl;
                while (current_n <= m * n) {
                    // if (current_n == m * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    // std::cout << "here" << std::endl;
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first -= 1;
                        location.second += 1;
                        if (current_n == m * n) {
                            // std::cout << "call3" << std::endl;
                            res_vec.push_back(matrix[location.first][location.second]);
                            return res_vec;
                        }
                        break;
                    }
                    res_vec.push_back(matrix[location.first][location.second]);
                    check_vec[location.first][location.second] = true;
                    // if (current_n == m * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first;
                    location.second--;
                }
            } else if (current_mode == up_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= m * n) {
                    // if (current_n == m * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first++;
                        location.second++;
                        if (current_n == m * n) {
                            // std::cout << "call4" << std::endl;
                            res_vec.push_back(matrix[location.first][location.second]);
                            return res_vec;
                        }
                        break;
                    }
                    res_vec.push_back(matrix[location.first][location.second]);
                    check_vec[location.first][location.second] = true;
                    // if (current_n == m * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first--;
                    location.second;
                }
            } else {
                assert(false);
            }
        }
        return res_vec;
    }
};
```