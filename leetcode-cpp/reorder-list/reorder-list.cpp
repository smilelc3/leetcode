//
// Created by smile on 2021/4/29.
//

#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        auto mid = head, tail = head;
        while (tail->next != nullptr) {
            mid = mid->next;
            tail = tail->next;
            if (tail->next != nullptr) {
                tail = tail->next;
            }
        }
        // 从 mid -> tail reverse
        reverseList(head);
        // 从 [head, mid) + [tail,mid] 构建新链表
        bool isReverseOrder = false;

    }

private:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *preNode = nullptr, *curNode = head, *nextNode = head->next;
        while (nextNode != nullptr) {
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
            nextNode = nextNode->next;
        }
        curNode->next = preNode;
        return curNode;
    }

};