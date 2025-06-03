# 数组

## 数组理论知识

因为个人非常熟悉了，这里略过。

### 题目

### 二分查找

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
