
# 回溯算法

- [回溯算法](#回溯算法)
  - [回溯算法理论基础](#回溯算法理论基础)
  - [组合](#组合)
  - [组合总和 III](#组合总和-iii)
  - [电话号码的字母组合](#电话号码的字母组合)
  - [组合总和](#组合总和)
  - [组合总和II (重要, used数组的运用)](#组合总和ii-重要-used数组的运用)
  - [分割回文串（需要复习）](#分割回文串需要复习)
    - [利用dp数组进行优化](#利用dp数组进行优化)
  - [复原 IP 地址（需要复习）](#复原-ip-地址需要复习)
  - [子集（经典题目，要和组合问题区分开来）](#子集经典题目要和组合问题区分开来)


## 回溯算法理论基础

**此部分内容来自：[https://programmercarl.com/...](https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80)**

回溯算法本质就是一种暴力搜索，效率是不高的。

在回溯的基础上我们可以剪枝来获得更好的性能。

回溯法，一般可以解决如下几种问题：

- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

排列和组合的区别：这个也不用多说了，排列是要强调顺序的，组合是set，不强调顺序。

比如用回溯遍历下面这张图：
![](https://file1.kamacoder.com/i/algo/20210130173631174.png)

回溯算法的模版是：

```cpp
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```

## 组合

https://leetcode.cn/problems/combinations/description/

自己写的版本。

```cpp
class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        // 先写递归结束条件
        if(path.size() == k) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; ++i) { // startIndex最小是1
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};
```

这个是没问题的，但是是可以剪枝的。

剪枝是这样处理的：`for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)`

举个例子，当 n=4, k=4 的时候，从1，2，3，4的2，3，4这一轮开始已经没有意义了。

**`for(int i = startIndex; i <= n; ++i)` 这句的意义就是，在这个数组范围里面再选 k-path.size() 个数字，如果 n-startIndex已经没有 k-path.size() 个数字了，就没必要循环了。**


## 组合总和 III

https://leetcode.cn/problems/combination-sum-iii/description/

找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

自己尝试写，顺利通过。

```cpp
class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int>path;
    void backtracking(int n, int k, int sum, int startIndex) {
        if(sum > n) return; // 剪支也很容易想到，不赘述
        if(sum == n && path.size() == k) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <=9; ++i) {
            sum += i;
            path.push_back(i);
            backtracking(n, k, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // sum为n的k个数
        backtracking(n, k, 0, 1);
        return result;
    }
};
```


## 电话号码的字母组合

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

```cpp
class Solution {
private:
    std::vector<std::string> res;
    std::string path;
    std::unordered_map<char, std::string> mmap = { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
    void backtracking(const std::string& digits, size_t digitsStartIndex) {
        if (digits.size() == path.size()) {
            res.push_back(path);
            return;
        }
        for (int i = digitsStartIndex; i < digits.size(); ++i) {
            auto str_mmap = mmap[digits[i]];
            for(const auto& e : str_mmap) {
                path.push_back(e);
                backtracking(digits, i + 1);
                path.pop_back();
            }
        }
    } //
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.size() == 0) return {};
        backtracking(digits, 0);
        return res;
    }
};
```
自己写的，顺利通过。


这个是Carl的做法，他只需要一层遍历。

```cpp
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // 处理
            backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
            s.pop_back();                       // 回溯
        }
    }
```

效率其实和我是一样的。


其实我的代码冗余了，其实根本不需要循环 `for (int i = digitsStartIndex; i < digits.size(); ++i)`

因为backtracking递归调用的时候传了 i + 1 的，直接换成 digitsStartIndex + 1 也是一样的。

## 组合总和

https://leetcode.cn/problems/combination-sum/description/

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

这个没有疑问也是经典题目。

自己写下就行。

```cpp
class Solution {
private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    void backtracking(const std::vector<int>& candidates, int target, int sum, int startIndex) {
        if(sum > target) return;
        if(sum == target) {
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i); // 这里不是 i+1，可以重复
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        // candidates 无重复，candidates数字全部大于0，所以可以用 target 剪枝
        // 结果中的数字可以重复
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
```

顺利通过。

剪枝的话，先排序，然后每层for里面可以剪一下。

```cpp
class Solution {
private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    void backtracking(const std::vector<int>& candidates, int target, int sum, int startIndex) {
        if(sum > target) return;
        if(sum == target) {
            res.push_back(path);
            return;
        }
        for(int i = startIndex; (i < candidates.size() && (sum + candidates[i] <= target)); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i); // 这里不是 i+1，可以重复
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        // candidates 无重复，candidates数字全部大于0，所以可以用 target 剪枝
        // 结果中的数字可以重复
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
```

反正就是两个地方，目前做到的题目两个地方可以剪枝：
- 每次backtracking可以剪枝，比如上面的 `if(sum > target) return;`
- for那里也可以剪枝


## 组合总和II (重要, used数组的运用)

https://leetcode.cn/problems/combination-sum-ii/description/

这题很重要，我自己做的时候遇到了这个问题（其实就是不记得大一时候做的了）。

比如sort之后: [1, 1, 2, 5, 6, 7, 10], target = 8

用第一个1，组成了[1, 2, 5]
那么第二个1，也能组成[1, 2, 5]
所以这个是要去重的，这一层我能想到。

所以我在for里面写了：`if (i > 0 && candidates[i] == candidates[i - 1])`

但这个是有问题的。[1, 1, 6]也是合法答案！

如果我直接用上面去重，就会去掉这种情况。

区别就是：
- [1, 2, 5]：1是没有被用过的
- [1, 1, 6]：遍历到第二个1的时候不能continue，因为 used[i-1]=true，用过了，所以此时不能continue

所以只有当：`if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)`的时候才能continue。

```cpp
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};

```

这题需要用used数组来去重，非常重要。


## 分割回文串（需要复习）

https://leetcode.cn/problems/palindrome-partitioning/description/

给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

这题有点难，其实暴力遍历的是切割字符串的位置。

要好好看看代码。

```cpp
class Solution {
private:
    bool isPalindrome(const std::string& str, int left, int right) {
        while(left < right)
            if(str[left++] != str[right--]) return false;
        return true;
    }
private:
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> path;
    void backtracking(const std::string& s, int cutIndex) {
        // cutIndex表示第一次切割的位置
        if(cutIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for(int i = cutIndex; i < s.size(); ++i) {
            // 先检查[cutIndex, i]这部分是不是合法的，如果不是可以直接跳过
            if(isPalindrome(s, cutIndex, i))
                // 说明 s中 [cutIndex, i] 这部分是合法的子串
                path.push_back(std::string(s.begin() + cutIndex, s.begin() + i + 1));
            else continue;
            backtracking(s, i+1); // 开始找 i+1 开始切割的子串
            path.pop_back(); // 因为上面一定会运行到if里面，如果没有运行到if里面，就不会调用 backtracking
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        backtracking(s, 0);
        return res;
    }
};
```

### 利用dp数组进行优化

上面的代码有一个性能瓶颈就是：每一次都要判断回文。

其实可以记录一个 `dp[][]` 数组，`dp[left][right]` 就可以告诉你是否是回文。然后dp数组在第一次调用 `backtracking` 之前就处理好，这样效率会更高。

具体代码在联系了dp思想后再写吧。


## 复原 IP 地址（需要复习）

https://leetcode.cn/problems/restore-ip-addresses/description/

这题是有点意思的，值得复习，自己也写出来了，不错。

```cpp
class Solution {
private:
    std::vector<std::string> result;
    std::string valid_answers;
    void backtracking(std::string& s, size_t startIndex, size_t dotNumber) {
        // 其实就是插入三个.
        // 插入的位置是有说法的
        if (dotNumber == 3) {
            // 点了第三个点后，第四段需要判断是否合法
            if (isValid(s, startIndex, s.size() - 1))
                result.push_back(s);
            return; // 如果第四段不合法，就不用加到结果中了
        }
        for (int i = startIndex; i < s.size(); ++i) {
            // 找一个位置插入点
            // 在 i 的身后插入一个点，因为i从0开始，不能在前面插入
            // 但是，要先判断在此为止插入是否合法
            // 判断 [startIndex, i] 的位置是否合法，如果合法，则在i后插入一个 .
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                backtracking(s, i + 2, dotNumber + 1); // 注意！这里是 i+2, 因为已经插入了一个 .
                s.erase(s.begin() + i + 1);
            } else break; // 不合法，直接结束循环
            /**
             * 这里为什么不是continue呢？
             * 我思考了一下，如果 [startIndex, i] 不合法，那么 [startIndex, i + n] 也一定不合法
            */
        }
    }
    bool isValid(const std::string& s, int begin, int end) {
        // 判断 s中，[begin, end] 区间是否是合法ip地址
        if (end - begin > 2)
            return false; // 大于3位数肯定不合法
        if (s[begin] == '0' && end - begin != 0) // 可以单独为0
            return false; // 有前导0不合法
        
        int num = -1;
        try {
            num = std::stoi(std::string(s.begin() + begin, s.begin() + end + 1));
        }
        catch(const std::exception& e) {
            return false; // 如果不能解析成数字，表示不合法
        }
        if (num < 0 || num > 255)
            return false; // 判断数字范围
        return true;
    } //
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        backtracking(s, 0, 0);
        return result;
    }
};
```


## 子集（经典题目，要和组合问题区分开来）

https://leetcode.cn/problems/subsets/description/

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

```cpp
class Solution {
private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    void backtracking(const std::vector<int>& nums, int startIndex) {
        res.push_back(path);
        if (startIndex >= nums.size()) // 这个终止条件可以不加，因为for循环也会结束，startIndex不会超
            return;
        for(int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
```

**注意两个点：**
- 终止条件是可以不加的，不会无限递归。因为每次 `backtracking` 是从 `i+1` 开始的。
- 如果要写终止条件，`res.push_back(path);` 要写在前面，不然会漏掉最后一种情况的。然后其实发现，`res.push_back(path);`写在前面之后，终止条件就是多余的，和for循环的终止条件重复了。