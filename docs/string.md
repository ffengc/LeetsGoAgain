# 字符串

- [字符串](#字符串)
  - [反转字符串](#反转字符串)
  - [反转字符串II](#反转字符串ii)
  - [剑指Offer 05.替换空格](#剑指offer-05替换空格)
  - [翻转字符串⾥的单词](#翻转字符串的单词)


## 反转字符串

https://leetcode.cn/problems/reverse-string/

直接双指针即可。但是我也记得，在上比特就业课的时候，鹏哥教过一种递归的方法，也挺有趣的，我也会用这个方法写一次。

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0 || s.size() == 1) return;
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
            std::swap(s[left++], s[right--]);
    }
};
```

鹏哥之前教的递归版。是C语言的，我试试。

```c
void reverseString(char* s, int sSize) {
    if(sSize <= 0) return;
    char* ptr_left = s;
    char* ptr_right = ptr_left + sSize - 1;
    char tmp = *ptr_right;
    *ptr_right = *ptr_left;
    *ptr_left = tmp;
    reverseString(ptr_left+1, sSize-2);
}
```

但是之前的递归版本不是这样的。网上找到一个，鹏哥版本的。

```c
void reverse(char* str)//这里传的其实是第一个元素的地址
{
    char temp = *str;//用一个临时变量记录第一个元素
    int len = strlen(str);
    *str = *(str + len - 1);//将数组第一个元素改为最后一个元素
    *(str + len - 1) = '\0';//将数组最后一个元素改为终止字符
    if (strlen(str + 1) >= 2)
        reverse(str + 1);
    *(str + len - 1) = temp;
}
int main()
{
    char arr[] = "abcdefghijklmn";
    reverse(arr);
    printf("%s\n", arr);
    return 0;
}
```

现在看了下，这种方法效率其实很低的，因为用了 `strlen` 求字符串长度，效率不高。

不过四年前的我，感觉这个 `*(str + len - 1) = '\0'` 很精髓，所以多少记住了这个方法。

## 反转字符串II

https://leetcode.cn/problems/reverse-string-ii/description/

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

`"abcdefghijklmn", k=2` -> `"bacdfeghjiklnm"`

这题我马上想到的思路，就是快慢指针就行了，O(n)能做。

一共定义三个指针，`wait`指针原地等待，`slow`指针一次走一步，`fast`指针一次走两步即可。反转 `wait+1` 和 `slow` 之间的字符串。

```
abcdef, k=3
  a b c d e f
|     |     | 三个分别是 wait, slow, fast
```

我的方法没问题！直接通过。

```cpp
class Solution {
public:
    void reverseByPtr(std::string& str, int ptr1, int ptr2) {
        if (ptr1 < 0 || ptr1 >= str.size())
            return;
        if (ptr2 < 0)
            return;
        if (ptr2 >= str.size()) // ptr2超出范围，则反转ptr1至结尾
            ptr2 = str.size() - 1;
        while (ptr1 < ptr2)
            std::swap(str[ptr1++], str[ptr2--]);
    } //
public:
    std::string reverseStr(std::string s, int k) {
        if (s.size() == 1 || k == 1)
            return s;
        int wait = -1;
        int slow = -1;
        int fast = -1;
        while (fast < (int)s.size()) { // 这里一定要用int，因为 size() 返回的是 size_t，这个道理我是懂的
            for (int i = 0; i < k; ++i) {
                slow++;
                fast += 2;
            }
            // std::cout << slow << ":" << fast << std::endl;
            // 无论是否越界，slow和fast都要走完
            if (slow >= s.size()) {
                // 反转剩余字符串
                reverseByPtr(s, wait + 1, slow);
            } else if (fast >= s.size() && slow < s.size()) {
                // 最后一轮反转
                reverseByPtr(s, wait + 1, slow);
                break;
            } else if (fast < s.size() && slow < s.size()) {
                reverseByPtr(s, wait + 1, slow);
                // 迭代
                wait = fast;
                slow = fast;
            }
        }
        return s;
    }
};
```

## 剑指Offer 05.替换空格

https://leetcode.cn/problems/ti-huan-kong-ge-lcof/description/
         
这题链接不太对，过去是一道很简单的题目。

我直接用vscode做就行。

请实现⼀个函数，把字符串 s 中的每个空格替换成"%20"。
输⼊：s = "We are happy."
输出："We%20are%20happy."

**其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的⼤⼩，然后在从后向前进⾏操作。**

这么做有两个好处：
1. 不⽤申请新数组。
2. 从后向前填充元素，避免了从前向后填充元素时，每次添加元素都要将添加元素之后的所有元素向后移动的问题。

```cpp
std::string replaceString(std::string s) {
    // 1. 先统计空格的个数
    int space_count = 0;
    int old_sz = s.size();
    for (char ch : s)
        if (ch == ' ')
            space_count++;
    // 2. 给字符串扩容
    s.resize(s.size() + space_count * 2);
    int new_sz = s.size();
    // 3. 从后向前替换
    // abcdefg***
    int left = old_sz - 1;
    int right = new_sz - 1;
    while (left < right) { // 如果right向左追上了left，表示前面已经没有空格需要处理了
        if (s[left] != ' ')
            s[right--] = s[left--];
        else if (s[left] == ' ') {
            s[right] = '0';
            s[right - 1] = '2';
            s[right - 2] = '%';
            right -= 3;
            left--;
        }
    }
    return s;
}
```

## 翻转字符串⾥的单词

https://leetcode.cn/problems/reverse-words-in-a-string/description/

输入：s = "the sky is blue" \
输出："blue is sky the"

这题不要使用额外的空间，才是难度所在。就在原字符串上做操作。

这题的思路没有这么好想的：
1. 移除多余空格
2. 将整个字符串反转
3. 将每个单词反转

就能完成此题。

第一步“移除多余空格”已经不简单了其实。已经算一道题了。

>[!NOTE]
> 以后这种“移除元素”的题型，一定要记住！\
> 解题关键在于：“合法元素”和“非法元素”，fast指针一定要指向合法元素，slow指针来慢慢填充元素。\
> 无论这个非法元素是空格还是其他符号，还是第二个空格，都是一样的。
> 关键在于如何判断这个字符是否是“合法元素”。\
> 比如这题，相比于单纯的移除空格题目，区别就仅仅只是如何判断是否“合法元素”复杂了一些而已。

```cpp
void removeDummySpaces(std::string& s) {
    // 1. 先去除字符串前面的空格
    int slow = 0;
    int fast = 0;
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ')
        fast++;
    // 此时fast指向第一个不为空格的字符，这个空格为“合法字符”
    // 要注意，不是所有的空格都是不合法字符，单词中间第一个空格也是合法字符！！！
    // 合法字符，fast就不能跳过，如果是不合法字符，fast++的时候才continue‘
    for (; fast < s.size(); ++fast) {
        // 2. 去掉字符串中间部分冗余空格
        if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
            continue;
        else
            s[slow++] = s[fast];
    }
    // 3. 去除末尾的空格
    if (slow - 1 > 0 && s[slow - 1] == ' ')
        s.resize(slow - 1);
    else
        s.resize(slow);
} //
```

后面就按照思路写，问题不大了。
```cpp
class Solution {
public:
    void removeDummySpaces(std::string& s) {
        // 1. 先去除字符串前面的空格
        int slow = 0;
        int fast = 0;
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ')
            fast++;
        // 此时fast指向第一个不为空格的字符，这个空格为“合法字符”
        // 要注意，不是所有的空格都是不合法字符，单词中间第一个空格也是合法字符！！！
        // 合法字符，fast就不能跳过，如果是不合法字符，fast++的时候才continue‘
        for (; fast < s.size(); ++fast) {
            // 2. 去掉字符串中间部分冗余空格
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
                continue;
            else
                s[slow++] = s[fast];
        }
        // 3. 去除末尾的空格
        if (slow - 1 > 0 && s[slow - 1] == ' ')
            s.resize(slow - 1);
        else
            s.resize(slow);
    } //
    void reverseByPtr(std::string& s, int left, int right) {
        while (left < right)
            std::swap(s[left++], s[right--]);
    } //
public:
    std::string reverseWords(std::string s) {
        removeDummySpaces(s); // 1. 移除多余空格
        // 2. 将整个字符串反转
        reverseByPtr(s, 0, s.size() - 1);
        // 3. 将每个单词反转
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            while (right < s.size() && s[right] != ' ')
                right++;
            assert(right > 0);
            if (right - left == 1) {
                // 不需要反转
                right++;
                left = right;
                continue;
            } else {
                reverseByPtr(s, left, right - 1);
                right++;
                left = right;
                continue;
            }
        }
        return s;
    }
};
```