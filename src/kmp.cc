

#include <iostream>
#include <string>

class Solution {
private:
    void getNext(int* next, std::string s) {
        /**
         * j指向前缀末尾位置
         * i指向后缀末尾位置
         */
        // 1. 初始化next数组
        int j = 0; // 前缀的末尾一开始就是0
        next[0] = 0; // 在0的位置就是回退到0
        // 2. 处理前后缀不相同的情况
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            // 3. 处理前后缀相同的情况
            if (s[i] == s[j])
                j++;
            // 4. 更新next数组的值
            next[i] = j;
        }
    } //
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() == 0)
            return 0;
        int* next = (int*)malloc(needle.size() * sizeof(int));
        // 先构建next数组
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            // 遇到不匹配，则回退
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++; // 继续匹配
            if (j == needle.size()) // 匹配到末尾
                return (i - needle.size() + 1);
        }
        return -1;
    }
};