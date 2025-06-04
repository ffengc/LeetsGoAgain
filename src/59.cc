/**
 * 螺旋矩阵II
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 * 螺旋矩阵
 * https://leetcode.cn/problems/spiral-matrix/
 */
#include <assert.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
private:
    struct self_reference_pair {
        std::string first;
        self_reference_pair* second;
        bool operator==(const self_reference_pair& self) { return first == self.first; }
    }; //
private:
    bool is_location_valid(const std::vector<std::vector<bool>>& check_vec, const std::pair<int, int>& loc) {
        int limit = check_vec.size();
        if (loc.first >= 0 && loc.second >= 0 && loc.first < limit && loc.second < limit && check_vec[loc.first][loc.second] == false)
            return true;
        return false;
    } //
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        auto check_vec = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
        auto res_vec = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        // 构建一个mode的简易链表
        self_reference_pair down_mode, left_mode, up_mode; // 提前声明
        self_reference_pair right_mode = { "right_mode", &down_mode };
        down_mode = { "down_mode", &left_mode };
        left_mode = { "left_mode", &up_mode };
        up_mode = { "up_mode", &right_mode };
        // 开始循环
        int current_n = 1;
        self_reference_pair current_mode = right_mode; // 一开始向右
        std::pair<int, int> location = { 0, 0 };
        while (current_n <= n * n) {
            if (current_mode == right_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    // std::cout << "is_valid: " << is_valid << std::endl;
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        // std::cout << location.first << ":" << location.second << std::endl;
                        location.first += 1;
                        location.second -= 1;
                        // std::cout << location.first << ":" << location.second << std::endl;
                        if (current_n == n * n) {
                            // std::cout << "call1" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first;
                    location.second++;
                }
            } else if (current_mode == down_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first -= 1;
                        location.second -= 1;
                        if (current_n == n * n) {
                            // std::cout << "call2" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first++;
                    location.second;
                }
            } else if (current_mode == left_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                // std::cout << location.first << ":" << location.second << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    // std::cout << "here" << std::endl;
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first -= 1;
                        location.second += 1;
                        if (current_n == n * n) {
                            // std::cout << "call3" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first;
                    location.second--;
                }
            } else if (current_mode == up_mode) {
                // std::cout << "mode: " << current_mode.first << std::endl;
                while (current_n <= n * n) {
                    // if (current_n == n * n) {
                    //     res_vec[location.first][location.second] = current_n;
                    //     return res_vec;
                    // }
                    bool is_valid = is_location_valid(check_vec, location);
                    if (is_valid == false) {
                        // 需要转变mode
                        current_mode = *(current_mode.second); // 没有填写数字，所以 current_n 不需要 ++
                        location.first++;
                        location.second++;
                        if (current_n == n * n) {
                            // std::cout << "call4" << std::endl;
                            res_vec[location.first][location.second] = current_n;
                            return res_vec;
                        }
                        break;
                    }
                    res_vec[location.first][location.second] = current_n;
                    check_vec[location.first][location.second] = true;
                    // if (current_n == n * n)
                    //     return res_vec;
                    current_n += 1;
                    location.first--;
                    location.second;
                }
            } else {
                assert(false);
            }
        }
        return res_vec;
    }
};

void print_vector(const std::vector<std::vector<int>>& res) {
    assert(res.size() == res[0].size()); // 确定是一个正方形
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int n = 4;
    auto res = Solution().generateMatrix(n);
    // auto test_vec = std::vector<std::vector<int>> { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    print_vector(res);
}