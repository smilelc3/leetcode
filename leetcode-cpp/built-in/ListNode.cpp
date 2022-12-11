//
// Created by smile on 2021/3/17.
//
#include <stdexcept>
#include "ListNode.h"

namespace LinkedList {
    ListNode *createByNums(const std::vector<int> &nums) {
        ListNode *head = nullptr, *preNode;
        for (auto idx = 0; idx < nums.size(); idx++) {
            auto curNode = new ListNode{nums[idx]};
            if (idx == 0 or preNode == nullptr) {
                head = curNode;
                preNode = curNode;
            } else {
                preNode->next = curNode;
                preNode = preNode->next;
            }
        }
        return head;
    }

    void destroy(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        destroy(head->next);
        delete head;
    }

    bool isEqual(const ListNode *head1, const ListNode *head2) {
        // 判定是否存在环
        if (isHasCycle(head1) or isHasCycle(head2)) {
            throw std::length_error("Link exist Cycle");
        }

        if ((head1 == nullptr) ^ (head2 == nullptr)) {
            return false;
        } else {
            if (head1 == nullptr) {
                return true;
            } else {
                if (head1->val != head2->val) {
                    return false;
                } else {
                    return isEqual(head1->next, head2->next);
                }
            }
        }
        return false;
    }

// TEST 判链表是否存在环
    bool isHasCycle(const ListNode *head) {
        if (head == nullptr or head->next == nullptr or head->next->next == nullptr) {
            return false;
        }
        ListNode *Fast, *Slow;
        Slow = head->next;
        Fast = head->next->next;
        while (Fast != Slow && Fast->next != nullptr and Slow->next != nullptr) {
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

}