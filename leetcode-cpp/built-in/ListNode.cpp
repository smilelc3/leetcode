//
// Created by smile on 2021/3/17.
//
#include "ListNode.h"

ListNode *GenLinksByNums(std::vector<int> &nums) {
    ListNode *head, *preNode;
    for (int idx = 0; idx < nums.size(); idx++) {
        auto curNode = new ListNode{nums[idx]};
        if (idx == 0 || preNode == nullptr) {
            head = curNode;
            preNode = curNode;
        } else {
            preNode->next = curNode;
            preNode = preNode->next;
        }
    }
    return head;
}
