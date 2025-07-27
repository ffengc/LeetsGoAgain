
# 回溯算法

- [回溯算法](#回溯算法)
  - [回溯算法理论基础](#回溯算法理论基础)
  - [组合](#组合)
  - [组合总和 III](#组合总和-iii)
  - [电话号码的字母组合](#电话号码的字母组合)
  - [组合总和](#组合总和)
  - [组合总和II (重要, used数组的运用)](#组合总和ii-重要-used数组的运用)
  - [分割回文串](#分割回文串)


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


## 分割回文串

https://leetcode.cn/problems/palindrome-partitioning/description/

给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

