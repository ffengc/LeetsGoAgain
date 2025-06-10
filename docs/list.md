# 链表

- [链表](#链表)
  - [链表基础知识](#链表基础知识)
  - [移除链表元素](#移除链表元素)
  - [设计链表](#设计链表)
  - [反转链表](#反转链表)
  - [两两交换链表中的节点](#两两交换链表中的节点)
  - [删除链表的倒数第N个节点](#删除链表的倒数第n个节点)
  - [链表相交](#链表相交)
  - [环形链表II (重要: 如何判环)](#环形链表ii-重要-如何判环)

## 链表基础知识

因为个人比较熟悉了，这里略过。

## 移除链表元素

[203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/description/)

这种题目设置一个哨兵位的头节点是最好的。

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        auto cur = dummy_head;
        // dummy->head->1->2->3->null
        // 7->7->7->7
        while(cur->next) {
            if(cur->next->val == val) {
                auto tmp = cur->next; // 待删除节点
                cur->next = cur->next->next;
                delete tmp;                
            } else {
                cur = cur->next;
            }
        }
        return dummy_head->next; // 不能返回 head, 因为 head 有可能已经被删除了
    }
};
```

要记住了，确实是不熟练，但是从现在开始要开始捡起来了。


## 设计链表

https://leetcode.cn/problems/design-linked-list/description/

这其实就是让你手搓一个单链表或双链表。两者都可以。这对于2022年的我来说应该是很简单的，但是现在需要回忆了。

为了练习，我单链表和双链表都实现一下。

这个仓库里面 https://github.com/ffengc/rookie-cplusplus
是我之前手撕stl数据结构的代码库，我复习过程中会参考这个库。

双链表版本，直接通过，没有怎么调试。
```cpp
// 双链表
struct __list_node {
    int __data;
    __list_node* __next;
    __list_node* __prev;
    __list_node(const int& val = 0)
        : __next(nullptr)
        , __prev(nullptr)
        , __data(val) { }
};

class MyLinkedList {
private:
    typedef __list_node Node;
    Node* __head;
    size_t __size; // 为了这道题，添加一个size，因为这道题有get接口，因此这个也不能完全作为链表
private:
    void __empty_initialize() {
        __head = new Node;
        __head->__next = __head;
        __head->__prev = __head;
        __size = 0;
    }

public:
    // 用于测试
    void print_list() {
        Node* cur = __head->__next;
        std::cout << "head->";
        while (1) {
            if (cur == __head) {
                std::cout << "head" << std::endl;
                return;
            }
            std::cout << cur->__data << "->";
            cur = cur->__next;
        }
    }
    size_t size() { return __size; }

public:
    MyLinkedList() {
        __empty_initialize();
    }
    int get(int index) {
        if (index >= __size)
            return -1;
        Node* ret_node = __head->__next; // 第一个节点
        for (int i = 0; i < index; ++i) {
            if (ret_node == __head)
                assert(false);
            ret_node = ret_node->__next;
        }
        // head->1->2->3->head
        if (ret_node == __head)
            assert(false);
        return ret_node->__data;
    }

    void addAtHead(int val) {
        // head->2
        // head->1->2
        Node* new_node = new Node(val);
        Node* next_node = __head->__next;
        __head->__next = new_node;
        new_node->__next = next_node;
        next_node->__prev = new_node;
        new_node->__prev = __head;
        __size++;
    }

    void addAtTail(int val) {
        Node* new_node = new Node(val);
        Node* tail = __head->__prev;
        __head->__prev = new_node;
        new_node->__next = __head;
        tail->__next = new_node;
        new_node->__prev = tail;
        __size++;
    }

    void addAtIndex(int index, int val) {
        // head->1->2->3->4->head
        if (index > __size)
            return;
        if (index == __size) {
            addAtTail(val);
            return;
        }
        // 先找到 index 位置的节点
        Node* idx_node = __head->__next;
        Node* new_node = new Node(val);
        for (int i = 0; i < index; ++i) {
            if (idx_node == __head)
                return;
            idx_node = idx_node->__next;
        }
        Node* prev_node = idx_node->__prev;
        prev_node->__next = new_node;
        new_node->__next = idx_node;
        idx_node->__prev = new_node;
        new_node->__prev = prev_node;
        __size++;
    }

    void deleteAtIndex(int index) {
        // head->1->2->3->4->head
        if (index >= __size)
            return;
        // 先找到 index 位置的节点
        Node* idx_node = __head->__next;
        for (int i = 0; i < index; ++i) {
            if (idx_node == __head)
                assert(false);
            idx_node = idx_node->__next;
        }
        Node* prev_node = idx_node->__prev;
        Node* next_node = idx_node->__next;
        prev_node->__next = next_node;
        next_node->__prev = prev_node;
        delete idx_node;
        __size--;
    }
};
```


单链表版本。

```cpp

// 单链表版本
struct __list_node {
    int __data;
    __list_node* __next;
    __list_node(const int& val = 0)
        : __next(nullptr)
        , __data(val) { }
};
class MyLinkedList {
private:
    typedef __list_node Node;
    Node* __head;
    size_t __size; // 为了这道题，添加一个size，因为这道题有get接口，因此这个也不能完全作为链表
private:
    void __empty_initialize() {
        __head = new Node;
        __head->__next = nullptr;
        __size = 0;
    }

public:
    // 用于测试
    void print_list() {
        Node* cur = __head->__next;
        std::cout << "head->";
        while (1) {
            if (cur == nullptr) {
                std::cout << "null" << std::endl;
                return;
            }
            std::cout << cur->__data << "->";
            cur = cur->__next;
        }
    }
    size_t size() { return __size; }
public:
    MyLinkedList() {
        __empty_initialize();
    }
    int get(int index) {
        if (index >= __size)
            return -1;
        Node* ret_node = __head->__next; // 第一个节点
        for (int i = 0; i < index; ++i) {
            if (ret_node == nullptr)
                assert(false);
            ret_node = ret_node->__next;
        }
        // head->1->2->3->head
        if (ret_node == nullptr)
            assert(false);
        return ret_node->__data;
    }

    void addAtHead(int val) {
        // head->2->null
        // head->1->2->null
        Node* new_node = new Node(val);
        Node* next_node = __head->__next;
        __head->__next = new_node;
        new_node->__next = next_node;
        __size++;
    }

    void addAtTail(int val) {
        Node* new_node = new Node(val);
        Node* cur = __head;
        while(1) {
            if(cur->__next == nullptr) break;
            cur = cur->__next;
        }
        // 此时 cur->next == nullptr
        cur->__next = new_node;
        new_node->__next = nullptr;
        __size++;
    }

    void addAtIndex(int index, int val) {
        // head->1->3->null
        // (1, 2)
        if (index > __size)
            return;
        if (index == __size) {
            addAtTail(val);
            return;
        }
        // 先找到 index-1 位置的节点
        Node* idx_node = __head;
        Node* new_node = new Node(val);
        for (int i = 0; i < index; ++i) {
            if (idx_node == nullptr)
                assert(false);
            idx_node = idx_node->__next;
        }
        Node* prev_node = idx_node;
        Node* next_node = idx_node->__next;
        prev_node->__next = new_node;
        new_node->__next = next_node;
        __size++;
    }

    void deleteAtIndex(int index) {
        // head->1->2->3->null
        // head->1->2->null
        // (1)
        if (index >= __size)
            return;
        // 先找到 index-1 位置的节点
        Node* idx_node = __head;
        for (int i = 0; i < index; ++i) {
            if (idx_node == nullptr)
                assert(false);
            idx_node = idx_node->__next;
        }
        Node* prev_node = idx_node;
        assert(idx_node->__next);
        Node* delete_node = idx_node->__next;
        Node* next_node = idx_node->__next->__next;
        prev_node->__next = next_node;
        delete delete_node;
        __size--;
    }
};
```
`deleteIndex`编写过程中出现了问题，不过问题不大，最后也解决了。一定要注意指针的状态！

## 反转链表

https://leetcode.cn/problems/reverse-linked-list/description/

这题有很多思路，每一种都要好好弄下学习下。

**方法1:**

用两个指针就行，cur和pre，pre初始化为null。然后直接原地改变指针的方向。

这个我直接通过了。
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            // 迭代
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
```

**方法2:**

递归法，其实和上面双指针的方法是一样的。

双指针方法中，迭代是: pre = cur; cur = temp;

```cpp
class Solution {
private:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if(cur == nullptr) return pre; // 和双指针法一样，返回pre
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
```

**使用虚拟头节点**

创建一个虚拟头节点，然后头插。

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* new_head = new ListNode(-1); // 虚拟头节点
        ListNode* cur = head;
        while(cur) {
            ListNode* tmp = cur->next; // 先记录后一个
            ListNode* new_tmp = new_head->next;
            new_head->next = cur;
            cur->next = new_tmp;
            cur = tmp;
        }
        return new_head->next;
    }
};
```
没问题，直接秒了。

用栈也可以，很简单，就不尝试了。

## 两两交换链表中的节点

https://leetcode.cn/problems/swap-nodes-in-pairs/description/

这个用指针迭代就行。我直接通过了。

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        // 链表长度>=2
        ListNode* pre = nullptr;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode* new_head = head->next;
        while(1) {
            if(!ptr1 || !ptr2) break;
            ListNode* tmp = ptr2->next;
            ptr2->next = ptr1;
            ptr1->next = tmp;
            if(pre)
                pre->next = ptr2;
            // 迭代
            pre = ptr1;
            ptr1 = ptr1->next;
            if(ptr1) 
                ptr2 = ptr1->next;
        }
        return new_head;
    }
};
```

## 删除链表的倒数第N个节点

https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/

这题也是直接通过了。要注意最后`slow_prev`是可能为空的，此时是把`head`的位置进行更改，要注意！
如果使用`dummy_head`的方法，就可以规避这个问题。

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        if(head && !head->next && n == 1) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_prev = nullptr;
        for(int i = 0; i < n; ++i) {
            if(!fast) assert(false);
            fast = fast->next;
        }
        // 同时前进
        while(fast) {
            fast = fast->next;
            slow_prev = slow;
            slow = slow->next;
        }
        if(slow_prev)
            slow_prev->next = slow->next;
        else 
            head = slow->next;
        delete slow;
        return head;
    }
};
```

## 链表相交

https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/

他这里题目要求时间是 O(n), 空间是 O(1)。

我直接通过了，没有问题。
我们求出两个链表的长度，并求出两个链表长度的差值，然后让 `beginA` 移动到，和 `beginB` 对⻬的位置，一起向前走，相同的时候就是要找的节点，问题不大。

```cpp
class Solution {
private:
    size_t get_length(ListNode* head) {
        size_t sz = 0;
        auto cur = head;
        while(cur) {
            cur = cur->next;
            sz++;
        }
        return sz;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 先求出两个链表的长度
        size_t szA = get_length(headA);
        size_t szB = get_length(headB);
        ListNode* beginA = headA;
        ListNode* beginB = headB;
        if(szA == szB) {
            beginA = headA; beginB = headB;
        } else if(szA < szB) {
            size_t diff = szB - szA;
            for(int i = 0; i < diff; ++i) beginB = beginB->next;
        } else if(szA > szB) {
            size_t diff = szA - szB;
            for(int i = 0; i < diff; ++i) beginA = beginA->next; 
        }
        while(beginA && beginB) {
            if(beginA == beginB) return beginA;
            beginA = beginA->next;
            beginB = beginB->next;
        }
        return nullptr;
    }
};
```

## 环形链表II (重要: 如何判环)

https://leetcode.cn/problems/linked-list-cycle-ii/

给定⼀个链表，返回链表开始⼊环的第⼀个节点。 如果链表⽆环，则返回null。

我第一个想到的思路是，用一个 set 记录已经走过的节点，如果遇到第一个重复的节点，set就会告诉我。

但是现在需要的是 O(1) 的空间。

> [!IMPORTANT]
> **重要！如何判断是否有环？**
> 结论：fast指针一次走两步，slow指针一次走一步。
> 如果fast和slow相遇，则表示一定有环，而且相遇的位置一定是在环里的。\
> 为什么？如果没有环，肯定不会相遇，这是显然的。
> 有环的话，进入环后，相当于fast在追slow，这也是显然的。

找到环之后，如何确定环的入口？

> [!IMPORTANT]
> 找到环之后，如何确定环的入口？
> 当`fast==slow`的时候，切开链表，就能把环切开，然后用上一题的链表相交找交点即可。
> 1. 当`fast==slow`的位置不在环入口的时候：画图就可以得出，找`(head, fast)`两个链表的交点即可
> 2. 当`fast==slow`的位置在环入口的时候：也是同理，画图即可。

所以如何解这道题：
1. 判断是否有环（如果出现 `fast==slow` 则有环，然后利用此位置找入口）
2. 在此位置切开环
3. 调用链表相交的函数，传入 `(head, fast)` 来找到入口。

```cpp
class Solution {
private:
    size_t get_length(ListNode* head) {
        size_t sz = 0;
        auto cur = head;
        while(cur) {
            cur = cur->next;
            sz++;
        }
        return sz;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 先求出两个链表的长度
        size_t szA = get_length(headA);
        size_t szB = get_length(headB);
        ListNode* beginA = headA;
        ListNode* beginB = headB;
        if(szA == szB) {
            beginA = headA; beginB = headB;
        } else if(szA < szB) {
            size_t diff = szB - szA;
            for(int i = 0; i < diff; ++i) beginB = beginB->next;
        } else if(szA > szB) {
            size_t diff = szA - szB;
            for(int i = 0; i < diff; ++i) beginA = beginA->next; 
        }
        while(beginA && beginB) {
            if(beginA == beginB) return beginA;
            beginA = beginA->next;
            beginB = beginB->next;
        }
        return nullptr;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                // 有环
                fast = fast->next;
                slow->next = nullptr; // 切开
                return getIntersectionNode(head, fast);
            }
        }
        return nullptr;
    }
};
```
通过了。

用set的方式肯定是没问题的，也做下吧，联系一下stl的用法。

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode*> s;
        auto cur = head;
        while(cur) {
            if(s.find(cur) != s.end()) return cur;
            s.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};
```
没问题，直接通过了。

**链表到此就完结了。下一part见。**