
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Definition for a binary tree node.
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
    using iterator = std::vector<int>::iterator;
    TreeNode* build(const std::vector<int>& nums, iterator left, iterator right) {
        if(right - left == 0) return nullptr;
        iterator maxValueIndex = std::max_element(left, right); // 找到最大值的索引
        TreeNode* root = new TreeNode(*maxValueIndex); // 构建节点
        
        // 左子数组
        iterator leftLeft = left;
        iterator rightLeft = maxValueIndex;
        // 右子数组
        iterator leftRight = maxValueIndex + 1;
        iterator rightRight = right;

        root->left = build(nums, leftLeft, rightLeft); // 递归
        root->right = build(nums, leftRight, rightRight); // 递归
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return build(nums, nums.begin(), nums.end());
    }
};