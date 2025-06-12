

#include <assert.h>
#include <iostream>
#include <string>

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

int main() {
    std::string str = "  abc   cdf dfb   ";
    std::cout << Solution().reverseWords(str) << std::endl;
    return 0;
}