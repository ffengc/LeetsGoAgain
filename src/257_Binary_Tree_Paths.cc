

#include <iostream>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr) { }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right) { }
};

class Solution {
private:
    std::vector<std::vector<int>> all_paths;
    std::vector<int> paths;
    void dfs(TreeNode* node) {
        paths.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            // 遇到叶子节点了
            all_paths.push_back(paths);
            return;
        }
        if (node->left) {
            dfs(node->left);
            // note: 一个递归配一个回溯
            paths.pop_back();
        }
        if (node->right) {
            dfs(node->right);
            paths.pop_back();
        }
    } //
    std::vector<std::string> vec2string() {
        std::vector<std::string> res;
        for(int i = 0; i < all_paths.size(); ++i) {
            auto path = all_paths[i];
            std::string str;
            for(int j = 0; j < path.size(); ++j) {
                str += std::to_string(path[j]);
                if(j != path.size() - 1)
                    str += "->";
            }
            res.push_back(str);
        }
        return res;
    }
private:
    void debug_print() {
        for(const auto& e : all_paths) {
            for(const auto& ee : e) {
                std::cout << ee << " ";
            }
            std::cout << std::endl;
        }
    }
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        // 最后再处理成字符串吧，处理成字符串不是重点
        // 先用一个 std::vector<std::vector<int>> 存
        if (!root)
            return {};
        std::vector<std::vector<int>> all_paths;
        dfs(root);
        return vec2string();
    }
};