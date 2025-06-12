
#include <iostream>
#include <string>

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

int main() {
    std::string s = "abcdefg";
    std::cout << Solution().reverseStr(s, 2) << std::endl;
    return 0;
}