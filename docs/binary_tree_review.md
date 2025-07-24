# 二叉树知识点复习

- [二叉树知识点复习](#二叉树知识点复习)
  - [二叉树的遍历](#二叉树的遍历)
  - [翻转二叉树](#翻转二叉树)
  - [对称二叉树，相同的树，找子树，其实都是一类题](#对称二叉树相同的树找子树其实都是一类题)
  - [二叉树的最大深度](#二叉树的最大深度)
  - [二叉树最小深度（重要）](#二叉树最小深度重要)
  - [完全二叉树的节点个数](#完全二叉树的节点个数)
  - [平衡二叉树](#平衡二叉树)
  - [二叉树所有路径](#二叉树所有路径)
  - [左叶子之和](#左叶子之和)
  - [找左下角的值](#找左下角的值)
  - [路径总和两道题](#路径总和两道题)
  - [从中序与后序遍历序列构造二叉树（重要题型）](#从中序与后序遍历序列构造二叉树重要题型)
  - [验证搜索二叉树](#验证搜索二叉树)
  - [二叉搜索树中的众数](#二叉搜索树中的众数)
  - [二叉树的最近公共祖先（需要复习）](#二叉树的最近公共祖先需要复习)
  - [二叉搜索树的最近公共祖先](#二叉搜索树的最近公共祖先)
  - [删除二叉搜索树中的节点（需要复习）](#删除二叉搜索树中的节点需要复习)
  - [普通二叉树的删除](#普通二叉树的删除)
  - [修剪二叉树（需要复习）](#修剪二叉树需要复习)
  - [将有序数组转换为二叉搜索树](#将有序数组转换为二叉搜索树)
  - [把二叉搜索树转换为累加树（反中序遍历）](#把二叉搜索树转换为累加树反中序遍历)


二叉树的一些定义和名词。

二叉树的递归遍历，前中后序。

## 二叉树的遍历

二叉树的迭代遍历（dfs），前和后序，中序比较特别，需要找最左节点。要注意，带孩子的时候要反着来，因为栈是反着出去的。

二叉树的迭代遍历（dfs），也可以统一风格，用null记录，可以被加入到结果中的节点：一个节点，如果要被加入到结果中，一定要先获得一个null。当然还有boolean法，也是一样道理的。

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::stack<TreeNode*> st;
        std::vector<int>res;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top();
            if(node) {
                // 节点不为空
                st.pop(); // 先暂时弹出这个节点，避免重复操作
                // 中序需要 左中右，所以stack使用 右中左 的顺序进行操作
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left) st.push(node->left);
            } else {
                // 节点为空
                st.pop(); // 弹出null
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
```
复习了一次这个方法，问题不大，这个方法要记住，很重要。

再复习一下二叉树的层序遍历（bfs）

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> res;
        que.push(root);
        while(!que.empty()) {
            int sz = que.size();
            std::vector<int> layers;
            for(int i = 0; i < sz; ++i) {
                auto node = que.front();
                que.pop();
                layers.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(layers);
        }
        return res;
    }
};
```
问题不大。



## 翻转二叉树

翻转二叉树：把每个节点的左右都翻转下即可。所以只要是可以遍历所有节点的写法，都是可以的！

遍历到每个节点，然后swap两个节点就行了。

## 对称二叉树，相同的树，找子树，其实都是一类题

把对称二叉树改一下，把root的左右传递给函数，让他判断是不是相同的。

其实和对称是一样的，相同和对称其实是一样的，在递归里面反一下而已。

```cpp
// 对称二叉树
class Solution {
private:
    bool compare(TreeNode* left, TreeNode* right) {
        if((!left && right) || (left && !right)) return false;
        if(!left && !right) return true;
        if(left->val != right->val) return false;
        return compare(left->left, right->right) && compare(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return compare(root->left, root->right); // 判断左右是否对称
    }
};
```
这种写法是很简单的，问题不大。

也可以层序遍历，用队列的方式来弄也是可以的。

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        std::queue<TreeNode*> que;
        que.push(root->left); // 这里的顺序要和下面对上才行
        que.push(root->right);  // 先左后右，下面取的时候也要先左后右，虽然好像反了也没啥事
        while(!que.empty()) {
            auto left_node = que.front();
            que.pop();
            auto right_node = que.front();
            que.pop();
            if((!left_node && right_node) || (!right_node && left_node)) return false;
            if(!left_node && !right_node) continue;
            if(left_node->val != right_node->val) return false;
            // 把子节点带进去，这里要注意，空也要带进去，不然会出问题
            // 比如如果输入是 [1,2,2,null,3,null,3]
            // 是需要比较 null, 3 发现不同，然后返回false的，如果判空，就会出问题
            /*
            if(left_node->left) que.push(left_node->left);
            if(right_node->right) que.push(right_node->right);
            if(left_node->right) que.push(left_node->right);
            if(right_node->left) que.push(right_node->left);
            */
            que.push(left_node->left); 
            que.push(right_node->right);
            que.push(left_node->right); 
            que.push(right_node->left);
        }
        return true;
    }
};
```

## 二叉树的最大深度

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

`return 1 + std::max(maxDepth(root->left), maxDepth(root->right));` 这句话需要好好理解。如果当前传入的 `root` 不为空的时候，说明这一层是有数据，起码深度是 `1`。所以要 `+1`。


## 二叉树最小深度（重要）

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        // 此处要注意，和求最大深度是有区别的。
        // 要找叶子结点，如果 root->left == null，是不能直接返回depth=1的
        if(root->left == nullptr && root->right) return 1 + minDepth(root->right);
        if(root->right == nullptr && root->left) return 1 + minDepth(root->left);
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
};
```

## 完全二叉树的节点个数

其实就是利用完全二叉树的性质。

在完全二叉树中，如果左右两边深度一样，就一定是满二叉树。

如果发现不是满二叉树，那就 `return countNodes(root->left) + countNodes(root->right) + 1;`。return countNodes(root->left) + countNodes(root->right) + 1; // 如果不是满二叉树，就找孩子，看看孩子是不是。


```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = 0;
        int rightDepth = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while(left) {
            leftDepth++;
            left = left->left;
        }
        while(right) {
            rightDepth++;
            right = right->right;
        }
        // 此时 leftDepth 和 rightDepth 就是两边的深度，如果相同，就是满二叉树
        if(leftDepth == rightDepth) 
            return ((1 << rightDepth) - 1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

注意：这里是 `(1 << depth)` 还是 `(2 << depth)` 是取决于前面深度怎么计算的，要自己动手算下才行，不能马虎。


## 平衡二叉树

这题的 `height` 函数确实很有意思。

- height函数：如果以node为root的树是平衡树，则返回这棵树的高度。如果不是平衡树，则不返回高度，返回-1。


```cpp
class Solution {
private:
    int height(TreeNode* root) {
        if(!root) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        if(left_height == -1 || right_height == -1) return -1;
        if(std::abs(left_height-right_height) > 1) return -1;
        return 1 + std::max(left_height, right_height);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return height(root) == -1 ? false : true;
    }
};
```

复习了一下，顺利通过。这种思路还是需要好好记住才好。


## 二叉树所有路径

这个经典题了，经典回溯题目，后面回溯题型也会复习的。

```cpp
class Solution {
private:
    std::vector<std::vector<int>> all_paths;
    std::vector<int> paths;
    void dfs(TreeNode* root) {
        // 这个root是可以在外面保证不为空的，这里就不判空了
        paths.push_back(root->val);
        // 设置递归返回条件：遇到叶子结点了
        if(!root->left && !root->right) {
            all_paths.push_back(paths);
            return;
        }
        if(root->left) {
            dfs(root->left);
            paths.pop_back(); // 这里上面没有push_back, 为什么有 pop_back 呢
            // 因为在最上面进行了一次 push_back 了，画画图就知道，如果不pop是不对的
        }
        if(root->right) {
            dfs(root->right);
            paths.pop_back();
        }
    }
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        dfs(root);
        return vec2string();
    }
};
```

## 左叶子之和

这题没啥问题，我可以自己做出来的。

## 找左下角的值

层序遍历就秒了，不多说，这里直接说用递归的方法。

这题是挺有意思的，有几个需要注意的点。

- 调用dfs，第一个访问到的，就是最左边的！ 这个就是结论，所以我们只需要按照正常dfs去访问节点就行！
- **因此，** 只有 cur_depth > max_depth 才更新，不能是 cur_depth >= max_depth ！


```cpp
class Solution {
private:
    int result = 0;
    int maxDepth = INT_MIN;
    int curDepth = 0;
    void dfs(TreeNode* root) {
        if(!root) {/* ... */} 
        if(curDepth > maxDepth) {
            // 此时一定是访问到了最新的一层，而且是最左边的，因为dfs的性质和顺序
            maxDepth = curDepth;
            // 此时这个root节点就是需要记录的节点
            result = root->val;
        }
        if(root->left) {
            curDepth++; // 上面并没有++，所以这里要++
            dfs(root->left);
            curDepth--; // 回溯
        }
        if(root->right) {
            curDepth++;
            dfs(root->right);
            curDepth--;
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) assert(false); // 题目说的，二叉树至少有一个节点
        dfs(root);
        return result;
    }
};
```

复习了一次，顺利通过。


## 路径总和两道题

经典回溯题，这里不重复了。

## 从中序与后序遍历序列构造二叉树（重要题型）


这个题非常重要啊，思路我已经记住了。

所以这里复习一下怎么写就行了。


```cpp
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
```

没问题，用迭代器的做法即可。

虽然中间出现一些错误，但是最后debug也弄出来了。

注意两个点：
- 不要忘记写递归的返回条件：`if (rightInorder - leftInorder == 0) return nullptr;`
- 如果 `root` 是叶子结点，不要忘记直接返回 `if (rightInorder - leftInorder == 1) return root;`


## 验证搜索二叉树

注意一点即可：中序是有序序列，而且没有重复，就可以证明这个树是搜索树。


## 二叉搜索树中的众数

```cpp
class Solution {
private:
    TreeNode* prev = nullptr; // 记录上一个遍历上一个节点的指针
    int count = 0; // 记录当前遍历到的节点的频率
    int maxCount = 0; // 记录最大频率
    std::vector<int> res;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        /* ------------- 逻辑处理 ------------- */
        if(prev == nullptr)
            // 算法开头，刚开始遍历树的第一个节点
            count = 1;
        else if(prev && prev->val == root->val)
            count++; // 当前节点和上个节点值相同
        else if(prev && prev->val != root->val)
            count = 1; // 刷新一下

        if(count == maxCount)
            // 按照题目要求：如果树中有不止一个众数，可以按 任意顺序 返回。
            res.push_back(root->val);
        if(count > maxCount) {
            maxCount = count;
            res.clear(); // 刷新结果
            res.push_back(root->val);
        }
        prev = root; // 迭代
        /* ------------- 逻辑处理 ------------- */
        dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};
```

**这份代码需要注意两点：**
- 含有重复值的搜索二叉树，所以要中序遍历，这样重复值才能放到一起
- 用dfs中序写就行了，在中间进行逻辑的处理，其实是非常好理解的
- 题目说，如果有不止一个众数，要一起返回，所以当 count == maxCount 的时候，要在结果中push多一个合法的结果；只有当 count > maxCount 的时候，才刷新结果
- 另外，使用一个prev就可以记录前置节点了，不难的


## 二叉树的最近公共祖先（需要复习）

这个题是需要复习的。

https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

这题其实有点难，一开始老想不明白。

这次看了Carl的视频讲解是看明白了。

比如一棵树：

        8
      3   12
    1 6  11 13

遍历节点，然后写一个函数，判断p,q节点是不是在子树中

比如p,q是1和6，那么回溯到3的时候，两边都是非空的，这样就把3继续返回。

到8的时候，左边不为空，右边为空。所以此时继续返回下面的3。这就得到最后的结果了。因此我先尝试自己写写代码。

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p || root == q) return root;
        if(root->left == p && root->right == q) return root;
        if(root->right == p && root->left == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root; // 这个是公共祖先
        if(!left && right) return right; 
        if(left && !right) return left;
        return nullptr;
    }
};
```
搞清楚思路后直接通过了。

这个题需要复习。

## 二叉搜索树的最近公共祖先

这个题简单，看是不是在两边就行，比大小。

因为搜索树的性质，如果在两边，说明当前的root就是最近的公共祖先。

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root ==p || root == q) return root;
        if(root->val > p->val && root->val < q->val) return root;
        else if(root->val < p->val && root->val > q->val) return root;
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return nullptr;
    }
};
```

## 删除二叉搜索树中的节点（需要复习）

情况比较复杂，分清楚情况就可以了。

- 第一种情况：没找到删除的节点，遍历到空节点直接返回了找到删除的节点
- 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
- 第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
- 第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
- 第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。

这个题需要复习。

## 普通二叉树的删除

普通二叉树的删除方式（没有使用搜索树的特性，遍历整棵树），用交换值的操作来删除目标节点。

代码中目标节点（要删除的节点）被操作了两次：

- 第一次是和目标节点的右子树最左面节点交换。
- 第二次直接被NULL覆盖了。

思路有点绕，其实就是换走，然后被覆盖就行。画个图就能理解，这里不详细说了。

## 修剪二叉树（需要复习）

递归法和迭代法都很有意思，需要好好复习。


## 将有序数组转换为二叉搜索树

这题没问题，二分构造就行，复习顺利通过。


```cpp
class Solution {
private:
    using it = std::vector<int>::iterator;
    TreeNode* build(std::vector<int> nums, it begin, it end) {
        if(end - begin <= 0) return nullptr;
        it mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(*mid);
        root->left = build(nums, begin, mid);
        root->right = build(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, nums.begin(), nums.end());
    }
};
```

## 把二叉搜索树转换为累加树（反中序遍历）

反中序遍历即可。这题也很简单，只要理解反中序遍历即可。略过。