
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

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
    using itType = std::vector<int>::iterator;
    TreeNode* traveral(const std::vector<int>& preorder, const std::vector<int>& inorder,
        itType leftPreorderIndex, itType rightPreorderIndex, itType leftInorderIndex, itType rightInorderIndex) {
        if(rightPreorderIndex - leftPreorderIndex == 0) return nullptr; // 没有节点
        int rootValue = *leftPreorderIndex; // 第一个数组就是要找的
        TreeNode* root = new TreeNode(rootValue); // 此时的根
        
        if(rightPreorderIndex - leftPreorderIndex == 1) return root; // 此时的root是叶子节点
        itType delimiterIndex;
        for(delimiterIndex = leftInorderIndex; delimiterIndex != rightInorderIndex; delimiterIndex++)
            if(*delimiterIndex == rootValue) break;
        // 此时 delimiterIndex 指向中序的切割点

        // 切割中序数组
        itType left_leftInorderIndex = leftInorderIndex;
        itType right_leftInorderIndex = delimiterIndex;
        itType left_rightInorderIndex = delimiterIndex + 1;
        itType right_rightInorderIndex = rightInorderIndex;
        // 切割前序数组
        leftPreorderIndex++; // pop_front 一下
        itType left_leftPreorderIndex = leftPreorderIndex;
        itType right_leftPreorderIndex = leftPreorderIndex + (right_leftInorderIndex - left_leftInorderIndex);
        itType left_rightPreorderIndex = leftPreorderIndex + (right_leftInorderIndex - left_leftInorderIndex);
        itType right_rightPreorderIndex = rightPreorderIndex;
        // 递归
        root->left = traveral(preorder, inorder, left_leftPreorderIndex, right_leftPreorderIndex, left_leftInorderIndex, right_leftInorderIndex);
        root->right = traveral(preorder, inorder, left_rightPreorderIndex, right_rightPreorderIndex, left_rightInorderIndex, right_rightInorderIndex);
        return root;
    } //
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        return traveral(preorder, inorder, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};