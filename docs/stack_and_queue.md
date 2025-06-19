# 栈和队列

- [栈和队列](#栈和队列)
  - [栈和队列理论基础](#栈和队列理论基础)
  - [用栈实现队列](#用栈实现队列)
  - [用队列实现栈](#用队列实现栈)
  - [有效的括号](#有效的括号)
  - [删除字符串中的所有相邻重复项](#删除字符串中的所有相邻重复项)
  - [逆波兰表达式求值（重要题型：后缀表达式）](#逆波兰表达式求值重要题型后缀表达式)

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





