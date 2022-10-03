//
// Created by smile on 2022/10/3.

#include "ListNode.h"

class Solution {
public:
    static ListNode *middleNode(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        auto slow = head, fast = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
        }
        return slow;
    }
};