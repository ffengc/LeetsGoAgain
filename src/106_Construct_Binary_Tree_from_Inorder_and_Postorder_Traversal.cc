
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

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
    TreeNode* traveral(std::vector<int>& inorder, std::vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr;
        int rootValue = postorder[postorder.size()-1]; // 当前节点就是后序最后一个节点
        TreeNode* root = new TreeNode(rootValue); // 构建新节点
        // 叶子结点
        if(postorder.size() == 1) return root; // 此时的root已经是叶子结点了
        // 找到中序的切割点
        int delimiterIndex = -1;
        for(delimiterIndex = 0; delimiterIndex < inorder.size(); ++delimiterIndex) {
            if(inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        std::vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        std::vector<int> rightInorder(inorder.begin()+delimiterIndex+1, inorder.end());
        assert(leftInorder.size() + rightInorder.size() == postorder.size()-1);
        // 切割后序数组
        postorder.pop_back(); // 去掉最后一个元素（rootValu）
        std::vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        std::vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());

        root->left = traveral(leftInorder, leftPostorder);
        root->right = traveral(rightInorder, rightPostorder);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traveral(inorder, postorder);
    }
};