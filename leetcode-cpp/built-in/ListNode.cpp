//
// Created by smile on 2021/3/17.
//
#include <stdexcept>
#include "ListNode.h"

ListNode *GenLinksByNums(const std::vector<int> &nums) {
    ListNode *head = nullptr, *preNode;
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

bool isSameList(const ListNode *head1, const ListNode *head2) {
    // 判定是否存在环
    if (isLinkHasCycle(head1) or isLinkHasCycle(head2)) {
        throw std::length_error("Link exist Cycle");
    }

    if (head1 == nullptr ^ head2 == nullptr) {
        return false;
    } else {
        if (head1 == nullptr) {
            return true;
        } else {
            if (head1->val != head2->val) {
                return false;
            } else {
                return isSameList(head1->next, head2->next);
            }
        }
    }
    return false;
}

// TEST 判链表是否存在环
bool isLinkHasCycle(const ListNode *head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return false;
    }
    ListNode *Fast, *Slow;
    Slow = head->next;
    Fast = head->next->next;
    while (Fast != Slow && Fast->next != nullptr && Slow->next != nullptr) {
        Slow = Slow->next;
        Fast = Fast->next;
        if (Fast->next != nullptr) {
            Fast = Fast->next;
        } else {
            return false;
        }
    }
    return Fast == Slow;
}