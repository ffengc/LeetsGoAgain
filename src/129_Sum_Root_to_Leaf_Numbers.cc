
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
class Solution {
   private:
    std::vector<std::vector<int>> all_paths;
    std::vector<int> layer;
    void dfs(TreeNode* root) {
        if (!root) assert(false);
        layer.push_back(root->val);
        if (!root->left && !root->right) {
            all_paths.push_back(layer);
            layer.pop_back();
            return;
        }
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        layer.pop_back();
    }
    int transferVec2Num(std::vector<int>& vec) {
        // reverse the list: O(n)
        std::reverse(vec.begin(), vec.end());
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) sum += (pow(10, i) * vec[i]);
        return sum;
    }

   public:
    int sumNumbers(TreeNode* root) {
        // 先用vec存储所有路径上的数字
        if (!root) return 0;
        dfs(root);
        // debug
        // for(int i = 0; i < all_paths.size(); ++i) {
        //     for(int j = 0; j < all_paths[i].size(); ++j) {
        //         std::cout << all_paths[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // return -1;
        int res = 0;
        for (int i = 0; i < all_paths.size(); ++i)
            res += transferVec2Num(all_paths[i]);
        return res;
    }
};