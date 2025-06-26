# 二叉树

- [二叉树](#二叉树)
  - [二叉树理论基础](#二叉树理论基础)
  - [二叉树的递归遍历](#二叉树的递归遍历)
  - [二叉树的迭代遍历（重要）](#二叉树的迭代遍历重要)
    - [前序遍历](#前序遍历)
    - [中序遍历](#中序遍历)
    - [后序遍历](#后序遍历)
  - [二叉树的统一迭代法（较难理解）](#二叉树的统一迭代法较难理解)
  - [二叉树的层序遍历（重要）](#二叉树的层序遍历重要)
    - [二叉树的层序遍历](#二叉树的层序遍历)
    - [二叉树的层次遍历 II](#二叉树的层次遍历-ii)
    - [二叉树的右视图](#二叉树的右视图)
    - [二叉树的层平均值](#二叉树的层平均值)
    - [N叉树的层序遍历](#n叉树的层序遍历)
    - [在每个树行中找最大值](#在每个树行中找最大值)
    - [填充每个节点的下一个右侧节点指针](#填充每个节点的下一个右侧节点指针)
    - [填充每个节点的下一个右侧节点指针II](#填充每个节点的下一个右侧节点指针ii)
    - [二叉树的最大深度](#二叉树的最大深度)
    - [二叉树的最小深度](#二叉树的最小深度)
  - [翻转二叉树](#翻转二叉树)

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

- **确定递归函数的参数和返回值：** 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数，并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
- **确定终止条件：** 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
- **确定单层递归的逻辑：** 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。

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

## 二叉树的迭代遍历（重要）

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

## 二叉树的统一迭代法（较难理解）

上面提到说使用栈的话，无法同时解决访问节点（遍历节点）和处理节点（将元素放进结果集）不一致的情况。

那我们就将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。

如何标记呢？

- 方法一：就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。 这种方法可以叫做空指针标记法。

- 方法二：加一个 boolean 值跟随每个节点，false (默认值) 表示需要为该节点和它的左右儿子安排在栈中的位次，true 表示该节点的位次之前已经安排过了，可以收割节点了。 这种方法可以叫做 boolean 标记法，样例代码见下文C++ 和 Python 的 boolean 标记法。 这种方法更容易理解，在面试中更容易写出来。

![](https://file1.kamacoder.com/i/algo/%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E8%BF%AD%E4%BB%A3%EF%BC%88%E7%BB%9F%E4%B8%80%E5%86%99%E6%B3%95%EF%BC%89.gif)

其实思路和之前是一样的。

**Note by Yufc:** 因为从上往下访问，必须要访问到root才能访问到children，但是，访问root的时候，不能加到res里面去，所以要先记录：这个root已经被处理，但是还没有加入到结果中。

**总之，一个节点要被加入到res中，那么他前面一定要有一个null；那么这个节点如何才能拥有这个null呢？把右左孩子带进来，你就可以拥有这个null了！**

这样，就不用按照上面那种找最左边的子孙节点了。

迭代法中序遍历尝试谢谢：

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::stack<TreeNode*> st;
        std::vector<int> res;
        st.push(root); // 先不要放到结果里
        while(!st.empty()) {
            auto node = st.top();
            if(node) {
                // 不是空指针 要将这个节点弹出来 避免重复操作
                st.pop();
                if(node->right) st.push(node->right); // 右
                st.push(node); // 重新插入这个节点
                st.push(nullptr); // 表示这个中间节点已经被访问了
                if(node->left) st.push(node->left); // 左
            } else {
                // 遇到空指针，说明null前面的那个node的左和右已经处理好了
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
```

反正：中左右分别就是这几行，因为是栈，所以反过来就行。中序遍历需要左中右，插入就是右左中。后序和前序是同一个道理。

```cpp
if(node->right) st.push(node->right); // 右
st.push(node); // 中
st.push(nullptr); 
if(node->left) st.push(node->left); // 左
```


前序：

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::stack<TreeNode*> st;
        std::vector<int> res;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top();
            if(node) {
                // 这个节点前没有null，因此需要把孩子弄进去，才能给他发放一个null
                st.pop(); // 先暂时弹出这个节点
                // 前序需要 中 左 右
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr); // 发放 null
            } else {
                // node为null
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
```

后序：

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::stack<TreeNode*> st;
        std::vector<int> res;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top();
            if(node) {
                // 这个节点前没有null，因此需要把孩子弄进去，才能给他发放一个null
                st.pop(); // 先暂时弹出这个节点
                // 后需要 左 右 中
                st.push(node);
                st.push(nullptr); // 发放 null
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            } else {
                // node为null
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
```

boolean 标记法其实是一样的，前面这种是：一个节点想要放入res，必须前面有个null。这里换成，一个节点想要放入res，必须是true，而不是false。

stack里面放个pair就行。

顺利通过。

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::stack<std::pair<TreeNode*, bool>> st;
        std::vector<int> res;
        st.push({root, false});
        while(!st.empty()) {
            auto node_pair = st.top();
            TreeNode* node = node_pair.first;
            bool is_valid = node_pair.second;
            if(!is_valid) {
                st.pop(); // 先弹出此节点
                // 中序需要 左 中 右
                if(node->right) st.push({node->right,false});
                st.push({node, true}); // 标记为true
                if(node->left) st.push({node->left,false});
            } else {
                node_pair = st.top();
                st.pop();
                res.push_back(node_pair.first->val);
            }
        }
        return res;
    }
};
```

## 二叉树的层序遍历（重要）

**层序相关题目：**

- [102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)
- [107. 二叉树的层次遍历II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/)
- [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)
- [637. 二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)
- [429. N叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)
- [515. 在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)
- [117. 填充每个节点的下一个右侧节点指针II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)
- [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)
- [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

### 二叉树的层序遍历

https://leetcode.cn/problems/binary-tree-level-order-traversal/

用队列先进先出就行，和stack用来深度遍历一样，出队列的时候把两个孩子带进来就行了。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            std::vector<int> vec;
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left); // 把孩子带进去
                if(node->right) q.push(node->right); // 把孩子带进去
            }
            res.push_back(vec);
        }
        return res;
    }
};
```
**这一份就是层序遍历的核心代码，很重要！**



### 二叉树的层次遍历 II

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/

上面那题的基础上反转一下结果的数组就行了。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            std::vector<int> vec;
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(vec);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
```

### 二叉树的右视图

https://leetcode.cn/problems/binary-tree-right-side-view/description/

给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

![](https://assets.leetcode.com/uploads/2024/11/24/tmpd5jn43fs-1.png)

输入：`root = [1,2,3,null,5,null,4]`

输出：`[1,3,4]`

其实很好理解，层序遍历的时候，遍历到本层最后一个节点，才加入到结果中。

直接写代码：

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> q;
        std::vector<int> res;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();
                // 如果是本层最后一个，才加入到结果中
                if(i == sz - 1) 
                    res.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
```
直接通过，很顺利。

### 二叉树的层平均值

https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/

计算每一层的平均值，很简单，求和除一下就行了。

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> q;
        std::vector<double> res;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            double sum = 0;
            for(int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sum / sz);
        }
        return res;
    }
};
```


### N叉树的层序遍历

https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/

同理，把每一个孩子都带进去就行了，都是一样的。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        std::queue<Node*> q;
        std::vector<std::vector<int>> res;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            std::vector<int> layer;
            for(int i = 0; i < sz; ++i) {
                Node* node = q.front();
                q.pop();
                layer.push_back(node->val);
                for(const auto& e : node->children) // 把每一个孩子都带进去
                    if(e)
                        q.push(e);
            }
            res.push_back(layer);
        }
        return res;
    }
};
```
顺利通过。

### 在每个树行中找最大值

https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/

给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

简单，直接写代码。

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> q;
        std::vector<int> res;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int max = INT_MIN;
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node->val > max) // 计算最大值
                    max = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
```

### 填充每个节点的下一个右侧节点指针

给一个完美二叉树

![](https://file1.kamacoder.com/i/algo/20210203152044855.jpg)

填充这些指针。很简单，获取到每一层就行了。

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            Node* cur = nullptr; // 用双指针记录前面的节点就行了
            Node* pre = nullptr; // 这里是链表题目打下的基础
            for(int i = 0; i < sz; ++i) {
                cur = q.front();
                auto node = q.front();
                q.pop();
                if(i == 0) {
                    cur->next = nullptr;
                } else {
                    pre->next = cur;
                    cur->next = nullptr;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                pre = cur;
            }
        }
        return root;
    }
};
```

### 填充每个节点的下一个右侧节点指针II

https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/

和上一题代码没有任何区别。

### 二叉树的最大深度

https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

这题是可以递归的，但是这里先用层序遍历做下先。

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        size_t layer = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            layer++; // 记录层数即可
        }
        return layer;
    }
};
```

### 二叉树的最小深度

https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/

一层一层搞，如果左右孩子都为空，就返回记录的深度就行了。

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {
            int sz = q.size();
            depth++; // 在这里就要++了，不能放到for结束，不然return的时候就没++到了
            for(int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(!node->left && !node->right) return depth;
            }
        }
        assert(false);
        return -1;
    }
};
```

## 翻转二叉树