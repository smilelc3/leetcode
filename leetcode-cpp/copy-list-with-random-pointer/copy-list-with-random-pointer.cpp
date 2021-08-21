//
// Created by smile on 2021/5/8.
//

#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }

};


class Solution {
public:
    Node *copyRandomList(Node *head) {
        // time: O(2n) space: O(n)
        //return copyRandomListUsingTwoTraverWithMap(head);

        // time: O(3n) space: O(1)
        return copyRandomListUsingThreeTraver(head);
    }

    Node *copyRandomListUsingTwoTraverWithMap(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node *, Node *> raw2CopyMap;

        // 复制Node，并为next创建索引，建立raw2CopyMap
        auto headCopy = new Node(head->val);
        raw2CopyMap[head] = headCopy;
        for (auto pNode = head->next, preNodeCopy = headCopy;
             pNode != nullptr;
             pNode = pNode->next, preNodeCopy = preNodeCopy->next) {
            auto pNodeCopy = new Node(pNode->val);
            preNodeCopy->next = pNodeCopy;
            raw2CopyMap[pNode] = pNodeCopy;
        }

        // 为random指针复制
        for (auto pNode = head, pNodeCopy = headCopy;
             pNode != nullptr;
             pNode = pNode->next, pNodeCopy = pNodeCopy->next) {
            if (pNode->random != nullptr) {
                pNodeCopy->random = raw2CopyMap[pNode->random];
            }
        }

        return headCopy;
    }

    Node *copyRandomListUsingThreeTraver(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        // 1. 在原链表的每个节点后面拷贝出一个新的节点
        // 例如：1(2) -> 2(3) -> 3(1)，括号中是其 random 指针指向的结点，
        // 每个结点后拷贝一个同样的结点，但是拷贝结点的 random 指针仍为空，
        // 则原链表变为 1(2) -> 1'(null) -> 2(3) -> 2'(null) -> 3(1) -> 3'(null)
        auto pNode = head;
        while (pNode != nullptr) {
            auto pNodeCopy = new Node(pNode->val);
            pNodeCopy->next = pNode->next;
            pNode->next = pNodeCopy;
            pNode = pNodeCopy->next;
        }

        // 2. 将拷贝结点的 random 指针赋上正确的值
        // 则原链表变为 1(2) -> 1'(2') -> 2(3) -> 2'(3') -> 3(1) -> 3'(1')
        pNode = head;
        while (pNode != nullptr) {
            if (pNode->random != nullptr) {
                pNode->next->random = pNode->random->next;  // 将copy节点的random指向正确的copy节点
            }
            pNode = pNode->next->next;
        }

        // 3. 断开链表可得到深度拷贝后的新链表
        // 原链表：1(2) -> 2(3) -> 3(1)
        // 新链表：1'(2') -> 2'(3') -> 3'(1')
        pNode = head;
        auto headCopy = head->next;
        while (pNode != nullptr) {
            auto temp = pNode->next;
            pNode->next = temp->next;
            if (temp->next != nullptr) { // 下一个 Node 还有值
                temp->next = pNode->next->next;
            }
            pNode = pNode->next;
        }

        return headCopy;
    }

    void destroyList(Node *head) {
        if (head == nullptr) {
            return;
        }
        destroyList(head->next);
        delete head;
    }
};
