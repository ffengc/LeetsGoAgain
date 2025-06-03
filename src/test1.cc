
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<char, int> m;

private:
    bool is_valid(const std::string& t) {
        for (const auto& e : t)
            if (m[e] < 1)
                return false;
        return true;
    }
    bool print_m() {
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
        // init_map(t);
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

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string res = Solution().minWindow(s, t);
    std::cout << res << std::endl;
    return 0;
}