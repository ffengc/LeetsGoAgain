# 补充题目

- [补充题目](#补充题目)
  - [1365.有多少小于当前数字的数字](#1365有多少小于当前数字的数字)
  - [941. 有效的山脉数组](#941-有效的山脉数组)
  - [1207. 独一无二的出现次数](#1207-独一无二的出现次数)
  - [283. 移动零](#283-移动零)
  - [189. 轮转数组](#189-轮转数组)
  - [724. 寻找数组的中心下标](#724-寻找数组的中心下标)
  - [34. 在排序数组中查找元素的第一个和最后一个位置](#34-在排序数组中查找元素的第一个和最后一个位置)
  - [922. 按奇偶排序数组 II](#922-按奇偶排序数组-ii)
  - [35. 搜索插入位置](#35-搜索插入位置)
  - [24. 两两交换链表中的节点](#24-两两交换链表中的节点)
  - [234. 回文链表](#234-回文链表)
  - [143. 重排链表](#143-重排链表)
  - [141. 环形链表](#141-环形链表)
  - [205. 同构字符串](#205-同构字符串)
  - [1002. 查找共用字符](#1002-查找共用字符)


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

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

我先试试直接分成两个函数来找，然后再看看怎么合并。

```cpp
class Solution {
private:
    int find_lower_bound(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[left] == target) return left;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid;
            else if(nums[mid] >= target) right = mid;
            if(left + 1 == right) {
                left++; break;
            }
        }
        assert(left == right);
        return nums[right] == target ? right : -1;
    }
    int find_upper_bound(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[right] == target) return right;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] <= target) left = mid;
            else if(nums[mid] > target) right = mid;
            if(left + 1 == right) {
                right--; break;
            }
        }
        assert(left == right);
        return nums[left] == target ? left : -1;       
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int left = find_lower_bound(nums, target);
        int right = find_upper_bound(nums, target);
        return {left, right};
    }
};
```

虽然做出来了，但是感觉写的有点捞。感觉做了很多判断。不过这题也没啥好说的。

## 922. 按奇偶排序数组 II

https://leetcode.cn/problems/sort-array-by-parity-ii/description/

给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。

对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。

你可以返回 任何满足上述条件的数组作为答案 。

我感觉可以控制两个指针，一个来指向奇数位置，一个指向偶数位置。

然后遇到不合法的就停下来。进行swap。

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // 控制两个指针
        int odd_ptr = 1;
        int even_ptr = 0;
        while(odd_ptr < nums.size() && even_ptr < nums.size()) {
            // 寻找奇数指针的非法位置
            while(odd_ptr < nums.size() && nums[odd_ptr] % 2 == 1) odd_ptr += 2;
            // 寻找偶数指针的非法位置
            while(even_ptr < nums.size() && nums[even_ptr] % 2 == 0) even_ptr += 2;
            // 因为题目说明了一半一半，所以这里放心
            if(odd_ptr < nums.size() && even_ptr < nums.size())
                std::swap(nums[odd_ptr], nums[even_ptr]);
            else break;
        }
        return nums;
    }
};
```

顺利通过，简单。

## 35. 搜索插入位置

https://leetcode.cn/problems/search-insert-position/description/

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

搜索树的插入，不多说。

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else if(nums[mid] == target) return mid;
        }
        return left;
    }
};
```

## 24. 两两交换链表中的节点

https://leetcode.cn/problems/swap-nodes-in-pairs/description/

这个没问题，我擅长的领域来了。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(head->next == nullptr) return head; // 只有一个节点
        // 弄个dummy节点
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* prev = dummy_head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while(ptr2) {
            ListNode* nnext = ptr2->next;
            // 交换ptr1, ptr2
            prev->next = ptr2;
            ptr2->next = ptr1;
            ptr1->next = nnext;
            // 迭代
            prev = ptr1;
            ptr1 = nnext;
            if(!ptr1) break;
            ptr2 = ptr1->next;
        }
        return dummy_head->next;
    }
};
```

## 234. 回文链表

https://leetcode.cn/problems/palindrome-linked-list/description/

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 题目说了不能为空
        if(head->next == nullptr) return true;
        // 先计算链表长度
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        // len可能是奇数也可能是偶数
        ListNode* dummy_head = new ListNode();
        // 头插
        cur = head;
        ListNode* new_list_next = dummy_head->next;
        for(int i = 0; i < len / 2; ++i) {
            auto next = cur->next;
            dummy_head->next = cur;
            cur->next = new_list_next;
            new_list_next = cur;
            cur = next;
        }
        // 匹配
        ListNode* match_head1 = nullptr;
        if(len % 2 == 0)
            match_head1 = cur;
        else if(len % 2 == 1)
            match_head1 = cur->next;
        ListNode* match_head2 = dummy_head->next;
        while(match_head1 && match_head2) {
            if(match_head1->val != match_head2->val) return false;
            match_head1 = match_head1->next;
            match_head2 = match_head2->next;
        }
        if(match_head1 && !match_head2) return false;
        if(!match_head1 && match_head2) return false;
        return true;
    }
};
```

虽然有些复杂，但一次过。链表果然是我的主场。

1. 计算长度
2. 把前一半头插到另一个哨兵头中，完成前半部分翻转
3. 长度是奇数和偶数是有区别的，如果是奇数，match的时候要略过最中间那个
4. 最后一个一个match就行了
5. 计算长度遍历一次，然后match的时候遍历第二次，O(n)

## 143. 重排链表

https://leetcode.cn/problems/reorder-list/description/

给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

我的思路，先拿出来然后插进去，这样遍历两次，也是 O(n)

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next == nullptr) return; // 1个节点的情况
        // 计算链表长度
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        int subLen = (len % 2 == 1) ? len/2+1 : len/2;
        // 跳过前sublen个
        cur = head;
        ListNode* prev = nullptr;
        while(subLen--) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr; // 断开链表
        // 
        ListNode* dummy_head = new ListNode();
        ListNode* nnext = dummy_head->next; // null
        while(cur) {
            ListNode* next = cur->next;
            dummy_head->next = cur;
            cur->next = nnext;
            nnext = cur;
            cur = next;
        }
        // debug new linkedlist:
        // ListNode* debug_cur = dummy_head;
        // while(debug_cur) {
        //     std::cout << debug_cur->val << " ";
        //     debug_cur = debug_cur->next;
        // }
        // debug_cur = head;
        // std::cout << std::endl;
        // while(debug_cur) {
        //     std::cout << debug_cur->val << " ";
        //     debug_cur = debug_cur->next;
        // }   
        // exit(1);     
        ListNode* insert_prev = head;
        ListNode* insert_cur = head->next;
        ListNode* new_list_cur = dummy_head->next;
        // exit(1);
        while(new_list_cur) {
            ListNode* new_list_next = new_list_cur->next;
            insert_prev->next = new_list_cur;
            new_list_cur->next = insert_cur;
            new_list_cur = new_list_next;
            // 迭代
            if(!insert_cur) {
                std::cout << "hello" << std::endl;
                break;
            }
            insert_prev = insert_cur;
            insert_cur = insert_prev->next;
        }
        // debug
        // ListNode* debug_cur = head;
        // while(debug_cur) {
        //     std::cout << debug_cur->val << " ";
        //     debug_cur = debug_cur->next;
        // }   
        // std::cout << "here" << std::endl;
    }
};
```

debug了一会儿，最终还是没问题，做出来了。

## 141. 环形链表

https://leetcode.cn/problems/linked-list-cycle/description/

经典题目，快慢指针。

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
```

## 205. 同构字符串

https://leetcode.cn/problems/isomorphic-strings/description/

给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

输入：s = "egg", t = "add" \
输出：true

感觉可以用哈希表进行一个编码，只要新出现一个字符，就赋予一个数字。

```cpp
class Solution {
private:
    std::vector<int> encoder(const std::string& s) {
        // 做一个编码，看编码是否相同就行了
        std::unordered_map<char, int> umap;
        std::vector<int> encode_result;
        int noteNumber = 0;
        for(const auto& e : s) {
            if(umap.find(e) == umap.end()) {
                // 这个字符第一次出现
                umap[e] = noteNumber++;
                encode_result.push_back(noteNumber);
            }
            else {
                encode_result.push_back(umap[e]);
            }
        }
        return encode_result;
    }
public:
    bool isIsomorphic(string s, string t) {
        return encoder(s) == encoder(t);
    }
};
```

## 1002. 查找共用字符

https://leetcode.cn/problems/find-common-characters/description/

给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 

示例 1：\
输入：words = ["bella","label","roller"] \
输出：["e","l","l"] \

示例 2：\
输入：words = ["cool","lock","cook"] \
输出：["c","o"]


这题的思路有点抽象，一下子没有想到特别好的方法。看了Carl的思路才想到。

Carl的思路：
![](https://file1.kamacoder.com/i/algo/1002.查找常用字符.png)

按照这个思路，可以顺利通过。

```cpp
class Solution {
private:
    std::vector<int> encoder(const std::string& str) {
        auto hash = std::vector<int>(26);
        for(const auto& e : str)
            hash[e - 'a'] += 1;
        return hash;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        std::vector<std::vector<int>>hash_res;
        for(const auto& e: words)
            hash_res.push_back(encoder(e));
        // 处理最后结果
        std::vector<std::string> res;
        for(int j = 0; j < 26; ++j) {
            int _min = INT_MAX;
            for(int i = 0; i < hash_res.size(); ++i)
                _min = std::min(hash_res[i][j], _min);
            if(_min > 0)
                for(int k = 0; k < _min; ++k)
                    res.push_back(std::string(1, j+'a'));
        }
        return res;
    }
};
```