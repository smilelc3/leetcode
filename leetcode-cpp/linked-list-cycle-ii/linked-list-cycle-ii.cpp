//
// Created by smile on 2021/4/28.
//

#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(const ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        auto slowNode = head, fastNode = head;
        do {
            if (fastNode == nullptr or fastNode->next == nullptr) {
                return nullptr;
            }
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        } while (fastNode != slowNode);

        // 存在环
        auto first = head, second = fastNode;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return const_cast<ListNode *>(first);
    }
};