# 链表

- [链表](#链表)
  - [链表基础知识](#链表基础知识)
  - [移除链表元素](#移除链表元素)
  - [设计链表](#设计链表)

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