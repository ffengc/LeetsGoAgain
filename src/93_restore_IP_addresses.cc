

#include <algorithm>
#include <string>
#include <vector>

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
            return false;
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