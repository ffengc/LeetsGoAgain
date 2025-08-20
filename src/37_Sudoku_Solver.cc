
#include <set>
#include <vector>
#include <iostream>

/** 先尝试自己做 */
// 这题的思路，我个人感觉就是一个一个填，一个一个试
// 这题leetcode的答案里面还有状态压缩的方法，先不管了

// 然后为了避免一个一个填，到时候pop的时候找不到哪个是题目填好的，哪个是空。
// 所以我打算先准备一个 数组 [(), (), ...], 每个 () 里面是一个空的位置

class Solution {
private:
    std::vector<std::pair<int, int>> blanks; // 记录需要填空的地方
    std::vector<std::set<int>> small_board_sets; // 给9个小九宫格准备一个set
    std::vector<std::set<int>> row_sets; // 每一行每一列都准备一个set
    std::vector<std::set<int>> col_sets;
    int whichSmallBoard(int row, int col) {
        // 传入行和列，输入这是第几个小宫格
        if(row >= 0 && row <= 2 && col >= 0 && col <= 2) return 0;
        else if(row >= 0 && row <= 2 && col >= 3 && col <= 5) return 1;
        else if(row >= 0 && row <= 2 && col >= 6 && col <= 8) return 2;
        else if(row >= 3 && row <= 5 && col >= 0 && col <= 2) return 3;
        else if(row >= 3 && row <= 5 && col >= 3 && col <= 5) return 4;
        else if(row >= 3 && row <= 5 && col >= 6 && col <= 8) return 5;
        else if(row >= 6 && row <= 8 && col >= 0 && col <= 2) return 6;
        else if(row >= 6 && row <= 8 && col >= 3 && col <= 5) return 7;
        else if(row >= 6 && row <= 8 && col >= 6 && col <= 8) return 8;
        return -1;
    }
    void init(const std::vector<std::vector<char>>& board) {
        // 初始化需要填空的地方, 顺便初始化27个set
        for(int i = 0; i < 9; ++i) {
            // 想了好久也不知道为什么构造函数那里构造不了
            small_board_sets.push_back(std::set<int>());
            row_sets.push_back(std::set<int>());
            col_sets.push_back(std::set<int>());
        }
        for(int i = 0; i < 9; ++i) { // 可以写死，题目说了一定是九宫格
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    blanks.push_back({i,j});
                    continue;
                }
                // 此时 board[i][j]是一个数字
                int num = board[i][j] - '0';
                // std::cout << num << std::endl; // DEBUG
                // std::cout << "i: " << i << std::endl;
                row_sets[i].insert(num);
                col_sets[j].insert(num);
                small_board_sets[whichSmallBoard(i, j)].insert(num);
            }
        }
    }
private:
    bool flag = false; // 表示是否找到答案
    void backtracking(std::vector<std::vector<char>>& board, int startIndex, int fill_count) {
        if(fill_count == blanks.size()) {
            flag = true;
            return;
        }
        // 我感觉是不用设置 flag 表示结束的，因为走到这里的时候board已经被填满了
        // 然后 return 的时候也没有 pop, fill_count也不会--，所以这里是会一直往上然后结束的
        // 但是没想明白，后面还是加上了
        
        // 此时轮到填第 startIndex 个空，此时的 row, col 是可以拿到的
        int row = blanks[startIndex].first;
        int col = blanks[startIndex].second;
        for(int i = 1; i <= 9; ++i) {
            if(!isValid(board, row, col, i)) continue; // 先判断能不能填进去
            board[row][col] = '0' + i; // 填进去
            row_sets[row].insert(i);
            col_sets[col].insert(i);
            small_board_sets[whichSmallBoard(row, col)].insert(i);
            backtracking(board, startIndex+1, fill_count+1);
            if(flag == true) return; // 直接跳过后面弄步骤，而且不要erase了
            row_sets[row].erase(i);
            col_sets[col].erase(i);
            small_board_sets[whichSmallBoard(row, col)].erase(i);
            board[row][col] = '.';
        }
    }
    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, int number) {
        auto row_set = row_sets[row];
        auto col_set = col_sets[col];
        auto small_board_set = small_board_sets[whichSmallBoard(row, col)];
        if(row_set.find(number) != row_set.end()) return false;
        if(col_set.find(number) != col_set.end()) return false;
        if(small_board_set.find(number) != small_board_set.end()) return false;
        return true;
    }
private:
    /** for debug */
    void printOneSet(const std::set<int> s) {
        std::cout << '(';
        for(const auto& e : s) std::cout << e << ',';
        std::cout << ')' << std::endl;
    }
    void printAllSets() {
        for(const auto& e : small_board_sets) printOneSet(e);
        std::cout << std::endl;
        for(const auto& e : row_sets) printOneSet(e);
        std::cout << std::endl;
        for(const auto& e : col_sets) printOneSet(e);
    }
    void printBoard(const std::vector<std::vector<char>>& board) {
        for(const auto& e : board) {
            for(const auto& ee : e)
                std::cout << ee << " ";
            std::cout << std::endl;
        }
    }
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        // 回溯前的准备工作
        init(board);
        // printAllSets(); // for debug
        backtracking(board, 0, 0);
        printBoard(board);
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}};
    Solution().solveSudoku(board);
    return 0;
}