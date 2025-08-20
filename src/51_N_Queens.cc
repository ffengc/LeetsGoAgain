
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>

/** 先自己尝试写一个版本吧 */
// 我的想法是用数字是代替字符串，字符串可以最后处理
// 比如 n=4 的时候: 0, 1, 2, 3 分别代替四个位置
// 那一个合法的path: [".Q..","...Q","Q...","..Q."] -> [1, 3, 0, 2]
// res: [[1, 3, 0, 2], []]

// 这个方法确实有一定优势，但在判断放皇后是否合法的时候时候，比较麻烦
class Solution {
private:
    std::vector<std::vector<std::pair<int, int>>> res;
    std::vector<std::pair<int, int>> path;
    void backtracking(int n, int row) {
        if(path.size() == n) {
            res.push_back(path);
            return;
        }
        for(int col = 0; col < n; ++col) {
            if(!isValid(path, {row, col})) continue;
            // std::string current_layer('.', n);
            // current_layer[col] = 'Q';
            path.push_back({row, col}); // 这里能否 push 需要判断
            backtracking(n, row + 1); // 下一行
            path.pop_back();
        }
    }
    bool isValid(const std::vector<std::pair<int, int>>& path, std::pair<int, int> location) {
        // path 有几个数字，代表已经填充了几行了，则新数字会被放在第 path.size() + 1 行的 col 上
        // 这里的思路是我自己想出来的
        // path: [2, 0,] 表示当前棋盘中: (0, 2), (1, 0) 位置已经被占用
        // 所以想到这里，还是直接维护 pair 的数组吧
        for(const auto& e : path) {
            // 遍历判断会不会和 path中任何一个冲突
            if(e.first + e.second == location.first + location.second) return false; // 正向45度冲突
            if(location.first - e.first == location.second - e.second) return false; // 反向45度冲突
            if(location.first == e.first) return false;
            if(location.second == e.second) return false;
        }
        return true;
    }
private:
    /** 把结果写成string的形式 */
    std::vector<std::vector<std::string>> pairToString(int n) {
        auto final_res = std::vector<std::vector<std::string>>();
        for(const auto& e : res) {
            // e: [(a,b), (), ...]
            auto single_final_res = std::vector<std::string>();
            for(const auto& ee : e) {
                int idx = ee.second;
                std::string s(n, '.');
                s[idx] = 'Q';
                single_final_res.push_back(s);
            }
            final_res.push_back(single_final_res);
        }
        return final_res;
    }
private:
    /** for debug */
    void printResult(const std::vector<std::vector<std::pair<int, int>>>& lst) {
        // [[(1, 2), ...], []]
        for(const auto& e : lst) {
            for(const auto& ee : e) 
                std::cout << "(" << ee.first << "," << ee.second << "), ";
            std::cout << std::endl;
        }   
    }
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        backtracking(n, 0);
        // printResult(res); // for debug
        return pairToString(n);
    }
};

int main() {
    Solution().solveNQueens(4);
    return 0;
}