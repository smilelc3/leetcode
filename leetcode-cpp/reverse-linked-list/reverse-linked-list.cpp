//
// Created by smile on 2021/4/29.
//

#include "ListNode.h"

class Solution {
public:
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
