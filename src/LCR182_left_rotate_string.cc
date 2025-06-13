

#include <assert.h>
#include <iostream>
#include <string>

class Solution {
private:
    void reverseByPtr(std::string& s, int left, int right) {
        while (left < right)
            std::swap(s[left++], s[right--]);
    } //
public:
    std::string dynamicPassword(std::string password, int target) {
        // 1 <= target < password.length <= 10000
        // 1. 反转前target个字符
        int ptr1 = 0;
        int ptr2 = target - 1;
        assert(ptr2 < password.size());
        reverseByPtr(password, ptr1, ptr2);
        reverseByPtr(password, ptr2 + 1, password.size() - 1);
        reverseByPtr(password, 0, password.size() - 1);
        return password;
    }
};

int main() {
    std::string str = "abcdefg";
    std::cout << Solution().dynamicPassword(str, 3) << std::endl;
    return 0;
}