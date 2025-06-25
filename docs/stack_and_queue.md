# 栈和队列

- [栈和队列](#栈和队列)
  - [栈和队列理论基础](#栈和队列理论基础)
  - [用栈实现队列](#用栈实现队列)
  - [用队列实现栈](#用队列实现栈)
  - [有效的括号](#有效的括号)
  - [删除字符串中的所有相邻重复项](#删除字符串中的所有相邻重复项)
  - [逆波兰表达式求值（重要题型：后缀表达式）](#逆波兰表达式求值重要题型后缀表达式)
  - [滑动窗口最大值](#滑动窗口最大值)
  - [前 K 个高频元素](#前-k-个高频元素)

## 栈和队列理论基础

这部分我个人比较熟悉，这里略过。


## 用栈实现队列

https://leetcode.cn/problems/implement-queue-using-stacks/description/

用两个栈，一个用于进数据，一个用于出数据。

`push`的时候，把数据放入输入栈，在`pop`的时候，如果输出栈为空，则把输入栈的内容先导入输出栈，再进行`pop`操作。

`peek`和`pop`是类似的。

直接写代码。

```cpp
class MyQueue {
private:
    std::stack<int>__inStack;
    std::stack<int>__outStack;
private:
    void transferData() {
        while(__inStack.size() > 0) {
            __outStack.push(__inStack.top());
            __inStack.pop();
        }
        assert(__inStack.size() == 0);
    }
public:
    MyQueue() {}
    void push(int x) {__inStack.push(x);}
    int pop() {
        if(__outStack.size() == 0)
            transferData();
        int res = __outStack.top();
        __outStack.pop();
        return res;
    }
    int peek() {
        if(__outStack.size() == 0)
            transferData();
        return __outStack.top();    
    }
    bool empty() {
        return __inStack.size() == 0 && __outStack.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

顺利通过。

## 用队列实现栈

https://leetcode.cn/problems/implement-stack-using-queues/description/

思路是：push的时候正常push，pop的时候，把最后一个前面的先出，然后pop最后一个，然后后面的再次push到队列中去。用一个队列即可。

```cpp
class MyStack {
private:
    std::queue<int> __que;
private:
    void transferData() {
        for(int i = 0; i < __que.size() - 1; ++i) {
            int data = __que.front();
            __que.push(data);
            __que.pop();
        }
    }
public:
    MyStack() {}
    void push(int x) {__que.push(x);}
    int pop() {
        transferData();
        int res = __que.front();
        __que.pop();
        return res;
    }
    int top() {
        transferData();
        int res = __que.front();
        __que.pop();
        __que.push(res);
        return res;
    }
    bool empty() {
        return __que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

没啥问题，直接通过。

## 有效的括号

https://leetcode.cn/problems/valid-parentheses/description/

这题很简单，遇到左括号入，遇到右括号出，如果出的时候top不是匹配的，则false，如果s能遍历完，则为true。

```cpp
class Solution {
public:
    bool isValid(string s) {
        std::stack<int> st;
        for(const auto& e : s) {
            if(e == '(' || e == '{' || e == '[') st.push(e);
            else if(e == ')' && !st.empty() && st.top() == '(') st.pop();
            else if(e == ']' && !st.empty() && st.top() == '[') st.pop();
            else if(e == '}' && !st.empty() && st.top() == '{') st.pop();
            else return false;
        }
        return st.empty();
    }
};
```
直接通过了。

## 删除字符串中的所有相邻重复项

https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/

这题好像之前没有做过，思路如动图所示。

![](https://file1.kamacoder.com/i/algo/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.gif)

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> st;
        std::list<char> lst;
        for(const auto& e : s) {
            if(st.size() == 0 || st.top() != e) st.push(e);
            else if(st.top() == e) st.pop();
        }
        while(st.size() > 0) {
            lst.push_front(st.top());
            st.pop();
        }
        return std::string(lst.begin(), lst.end());
    }
}; 
```

最后是需要逆序一下字符串的。

当然也可以直接调用reverse，效率都是O(n)。

## 逆波兰表达式求值（重要题型：后缀表达式）

**逆波兰表达式：后缀表达式，所谓后缀就是指运算符是写在后面的。**

**这里涉及到后缀表达式。后面学习树的时候还会遇到的。**


https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/

思路如动图所示。

![](https://file1.kamacoder.com/i/algo/150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.gif)

```cpp
class Solution {
    using ll = long long;

private:
    int count(ll a, ll b, char op) {
        // note: b是第一个操作数
        switch (op)
        {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        default:
            assert(false);
        }
    } //
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<ll> st;
        for (const auto& e : tokens) {
            if (e == "+" || e == "-" || e == "*" || e == "/") {
                auto a = st.top();
                st.pop();
                auto b = st.top();
                st.pop();
                st.push(count(a, b, e[0]));
            } else
                st.push(std::stoi(e));
        }
        assert(st.size() == 1);
        return st.top();
    }
};
```

顺利通过。

## 滑动窗口最大值

https://leetcode.cn/problems/sliding-window-maximum/

这是使用单调队列的经典题目。

**摘自：代码随想录(https://programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html#%E6%80%9D%E8%B7%AF)**

版权所属：代码随想录(https://programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html#%E6%80%9D%E8%B7%AF)

难点是如何求一个区间里的最大值呢？（这好像是废话），暴力一下不就得了。

暴力方法，遍历一遍的过程中每次从窗口中再找到最大的数值，这样很明显是O(n × k)的算法。

有的同学可能会想用一个大顶堆（优先级队列）来存放这个窗口里的k个数字，这样就可以知道最大的最大值是多少了， 但是问题是这个窗口是移动的，而大顶堆每次只能弹出最大值，我们无法移除其他数值，这样就造成大顶堆维护的不是滑动窗口里面的数值了。所以不能用大顶堆。

此时我们需要一个队列，这个队列呢，放进去窗口里的元素，然后随着窗口的移动，队列也一进一出，每次移动之后，队列告诉我们里面的最大值是什么。


显然：队列里的元素一定是要排序的，而且要最大值放在出队口，要不然怎么知道最大值呢。

但如果把窗口里的元素都放进队列里，窗口移动的时候，队列需要弹出元素。

那么问题来了，已经排序之后的队列 怎么能把窗口要移除的元素（这个元素可不一定是最大值）弹出呢。

大家此时应该陷入深思.....

**其实队列没有必要维护窗口里的所有元素，只需要维护有可能成为窗口里最大值的元素就可以了，同时保证队列里的元素数值是由大到小的。**

那么这个维护元素单调递减的队列就叫做单调队列，即单调递减或单调递增的队列。C++中没有直接支持单调队列，需要我们自己来实现一个单调队列

**不要以为实现的单调队列就是对窗口里面的数进行排序，如果排序的话，那和优先级队列又有什么区别了呢。**

来看一下单调队列如何维护队列里的元素。

![](https://file1.kamacoder.com/i/algo/239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.gif)

设计单调队列的时候，pop，和push操作要保持如下规则：

- `pop(value)`：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作。（这个一定要自己画图理解一下）
- `push(value)`：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止。

保持如上规则，每次窗口移动的时候，只要问`que.front()`就可以返回当前窗口的最大值。

为了更直观的感受到单调队列的工作过程，以题目示例为例，输入: `nums = [1,3,-1,-3,5,3,6,7]`, 和 `k = 3`，动画如下：

![](https://file1.kamacoder.com/i/algo/239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC-2.gif)

一定要自己重新画图，模拟这个过程，才能懂。

```cpp
class Solution {
private:
    class MonotonicQueue {
    private:
        std::deque<int> __que; //
    public:
        void push(int val) {
            while (!__que.empty() && val > __que.back())
                __que.pop_back();
            __que.push_back(val);
        }
        void pop(int val) {
            if (!__que.empty() && __que.front() == val)
                __que.pop_front();
        }
        int front() { return __que.front(); }
    }; //
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        MonotonicQueue que;
        std::vector<int> res;
        // 先把头k个插入到que里面
        for (int i = 0; i < k; ++i)
            que.push(nums[i]);
        res.push_back(que.front()); // 记录结果
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front()); // 记录结果
        }
        return res;
    }
};
```

**NOTE: 摘自代码随想录**

题解中单调队列里的 `pop` `和push` 接口，仅适用于本题哈。单调队列不是一成不变的，而是不同场景不同写法，总之要保证队列里单调递减或递增的原则，所以叫做单调队列。 不要以为本题中的单调队列实现就是固定的写法。

## 前 K 个高频元素

https://leetcode.cn/problems/top-k-frequent-elements/description/

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 任意顺序 返回答案。

首先，这题是记录频率，所以先记录一下出现的次数，用map就行，然后用个堆。

```cpp
class Solution {
private:
    struct CompareFunction {
        bool operator()(const std::pair<int, int>& e1, const std::pair<int, int>& e2) {
            return e1.second < e2.second;
        }
    }; //
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 先记录频率
        std::unordered_map<int, int> hash_table;
        for (const auto& e : nums)
            hash_table[e]++;
        // 构建堆
        /**
         * note: std::priority_queue这里传入的是类，std::sort那里传的是函数
         * 要注意好！
         */
        std::priority_queue<std::pair<int, int>, std::deque<std::pair<int, int>>, CompareFunction> pq;
        for (auto it = hash_table.begin(); it != hash_table.end(); ++it)
            pq.push(*it);
        // 记录结果
        std::vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```

顺利通过。

**需要注意的地方：**
- `std::priority_queue`是第三个模版参数传入对比逻辑，第二个参数是容器。这个看看文档就知道了，不过也是需要记住比较好。
- `std::priority_queue`对比逻辑需要的是一个类，类里面重载一个`()`。这个要记住。和`std::sort`要区分开来，`std::sort`需要的是一个函数。
  - 调用`std::sort`的时候，如果写了一个struct，就`compare()`这样调用。如果写了一个函数就，直接传函数名。
  - 这个道理我是懂的，不过现在是需要复习一下加深印象。
- `std::priority_queue`的对比逻辑中，如果左>右，则是小堆；如果是左<右，则是大堆。


栈和队列到这里就结束了。