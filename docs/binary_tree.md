# 二叉树

- [二叉树](#二叉树)
  - [二叉树理论基础](#二叉树理论基础)
  - [二叉树的递归遍历](#二叉树的递归遍历)
  - [二叉树的迭代遍历](#二叉树的迭代遍历)
    - [前序遍历](#前序遍历)
    - [中序遍历](#中序遍历)
    - [后序遍历](#后序遍历)
  - [二叉树的统一迭代法](#二叉树的统一迭代法)

## 二叉树理论基础

**二叉树的一些用语：**

此部分内容我是熟悉的，不过在这里再次复习。

- **满二叉树：** 如果一棵二叉树只有度为0的结点和度为2的结点，并且度为0的结点在同一层上，则这棵二叉树为满二叉树。
  - 深度为k，有`2^k-1`个节点的二叉树。
- **完全二叉树：** 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
  - 若最底层为第 h 层（h从1开始），则该层包含 `1~2^(h-1)` 个节点。
- **二叉搜索树：** 二叉搜索树是一个有序树。
- **平衡二叉搜索树：** 又被称为AVL（Adelson-Velsky and Landis）树，且具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

**二叉树的存储：**

注意：二叉树可以链式存储，也可以顺序存储。

![](https://file1.kamacoder.com/i/algo/20200920200429452.png)

**如果父节点的数组下标是 `i`，那么它的左孩子就是 `i * 2 + 1`，右孩子就是 `i * 2 + 2`。**

这个结论非常的重要，需要记住。

**二叉树的遍历：**

- 深度优先遍历
  - 前序遍历（递归法，迭代法）
  - 中序遍历（递归法，迭代法）
  - 后序遍历（递归法，迭代法）
- 广度优先遍历
  - 层次遍历（迭代法）

**二叉树的链式存储定义：**

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

## 二叉树的递归遍历

其实就是前中后序。

**递归一定要注意：**

- **确定递归函数的参数和返回值：**确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数，并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
- **确定终止条件：**写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
- **确定单层递归的逻辑：**确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。

[144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)\
[45. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)\
[94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

前序：
```cpp
class Solution {
private:
    std::vector<int> res;
    void dfs(TreeNode* node) {
        if(!node) return;
        res.push_back(node->val);
        if(node->left) dfs(node->left);
        if(node->right) dfs(node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
```

后序：
```cpp
class Solution {
private:
    std::vector<int> res;
    void dfs(TreeNode* node) {
        if(!node) return;
        if(node->left) dfs(node->left);
        if(node->right) dfs(node->right);
        res.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
```

中序：
```cpp
class Solution {
private:
    std::vector<int> res;
    void dfs(TreeNode* node) {
        if(!node) return;
        if(node->left) dfs(node->left);
        res.push_back(node->val);
        if(node->right) dfs(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
```

## 二叉树的迭代遍历

### 前序遍历

一句话说清楚：先把root放到stack里，root出栈的时候，把孩子带进（先带右孩子啊，再带左孩子）

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        std::stack<TreeNode*> st;
        std::vector<int> res;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top(); // 当前要访问的节点
            res.push_back(node->val);
            st.pop(); // 弹出并访问root
            if(node->right) st.push(node->right); // 把右孩子带进去
            if(node->left) st.push(node->left); // 把左孩子带进去
        }
        return res;
    }
};
```

但接下来，再用迭代法写中序遍历的时候，会发现套路又不一样了，目前的前序遍历的逻辑无法直接应用到中序遍历上。

### 中序遍历

**中序遍历会有点难，一定要学会！这个是很重要的！因为后续面搜索树写迭代器，也是这个中序顺序！！！**

分析一下为什么刚刚写的前序遍历的代码，不能和中序遍历通用呢，因为前序遍历的顺序是中左右，先访问的元素是中间节点，要处理的元素也是中间节点，所以刚刚才能写出相对简洁的代码，因为要访问的元素和要处理的元素顺序是一致的，都是中间节点。

那么再看看中序遍历，中序遍历是左中右，先访问的是二叉树顶部的节点，然后一层一层向下访问，直到到达树左面的最底部，再开始处理节点（也就是在把节点的数值放进result数组中），这就造成了**处理顺序和访问顺序是不一致的。**

那么在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        std::stack<TreeNode*> st;
        std::vector<int> res;
        TreeNode* cur = root;
        while(cur || !st.empty()) {
            // 先找以cur为开始，最左边的后代节点
            if(cur) {
                st.push(cur); // 把访问到的节点放进栈
                cur = cur->left;
            }
            else {
                // 此时cur为nullptr
                cur = st.top(); // 则访问到这个cur之前的上一个非空（同时也在栈里），我们就可以去访问这个节点了
                st.pop();
                res.push_back(cur->val);
                cur = cur->right; // 如果有右，则会以 cur->right 开始的最左子孙节点；如果没有右，则继续访问栈里的
            }
        }
        return res;
    }
};
```

### 后序遍历

再来看后序遍历，先序遍历是中左右，后序遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了。

![](https://file1.kamacoder.com/i/algo/20200808200338924.png)

代码如下：

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        std::stack<TreeNode*> st;
        std::vector<int> res;
        st.push(root);
        while(!st.empty()) {
            auto cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
```

## 二叉树的统一迭代法
