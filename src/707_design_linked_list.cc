
#include <assert.h>
#include <iostream>

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

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->print_list();
    // head->1->3->null
    obj->addAtIndex(1, 2);
    obj->print_list();
    std::cout << obj->get(1) << std::endl;
    obj->deleteAtIndex(1);
    obj->print_list();
    return 0;
}

#if false
// 双链表版本
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

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtHead(4);
    obj->addAtHead(5);
    obj->addAtHead(6);
    obj->print_list();
    // std::cout << obj->size() <<std::endl;
    // std::cout << obj->get(0) << std::endl;
    // std::cout << obj->get(1) << std::endl;
    // std::cout << obj->get(5) << std::endl;
    // std::cout << obj->get(10) << std::endl;
    obj->addAtIndex(obj->size(), 100);
    obj->print_list();
    return 0;
}
#endif