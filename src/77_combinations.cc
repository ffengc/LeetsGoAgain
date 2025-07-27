

#include <vector>
#include <iostream>

class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        // 先写递归结束条件
        if(path.size() == k) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; ++i) { // startIndex最小是1
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};