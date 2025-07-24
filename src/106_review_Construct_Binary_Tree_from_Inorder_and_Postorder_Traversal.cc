
#include <algorithm>
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
    using it = std::vector<int>::iterator;
    TreeNode* build(it leftInorder, it rightInorder, it leftPostorder, it rightPostorder) {
        // 0. 做一些判断
        if (rightInorder - leftInorder == 0)
            return nullptr; // 没有节点，不要忘记递归的返回条件！！！
        // 1. 获取postorder最后一个元素
        int rootValue = *(rightPostorder - 1); // 这是最后一个元素，也就是当前的根
        TreeNode* root = new TreeNode(rootValue);
        if (rightInorder - leftInorder == 1)
            return root; // 此时的root是叶子结点，这里不要忘记返回了！
        // 2. 利用 rootValue 获取切割位置（这里使用迭代器）
        auto itt = std::find(leftInorder, rightInorder, rootValue); // 题目保证了二叉树中每个元素是不同的
        // 3. 切割数组
        // 3.1 切割 inorder 数组
        it leftleftInorder = leftInorder;
        it rightleftInorder = itt;
        it leftrightInorder = itt + 1;
        it rightrightInorder = rightInorder;
        // 3.2 切割 postorder 数组
        it leftleftPostorder = leftPostorder;
        it rightleftPostorder = leftPostorder + (rightleftInorder - leftleftInorder);
        it leftrightPostorder = rightleftPostorder; // 这里不用+1的
        it rightrightPostorder = rightPostorder - 1; // 这里要把最后一个去掉
        // 4. 递归
        root->left = build(leftleftInorder, rightleftInorder, leftleftPostorder, rightleftPostorder);
        root->right = build(leftrightInorder, rightrightInorder, leftrightPostorder, rightrightPostorder);
        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        // 0. 做一些判断
        if (inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        assert(inorder.size() == postorder.size());
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};