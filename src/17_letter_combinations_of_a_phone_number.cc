
#include <string>
#include <unordered_map>
#include <vector>

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