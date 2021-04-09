//
// Created by smile on 2021/4/9.
//
#include "ListNode.h"

class Solution {
public:
    static ListNode *sortList(ListNode *head) {
        if (head == nullptr or head->next == nullptr) {
            return head;
        }
        auto head1 = head;
        auto head2 = getMidNode(head);
        head1 = sortList(head1);
        head2 = sortList(head2);
        return mergeTwoLists(head1, head2);
    }

private:

    // 合并两个有序链表
    static ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
        if (head1 != nullptr and head2 != nullptr) {
            if (head1->val < head2->val) {
                head1->next = mergeTwoLists(head1->next, head2);
                return head1;
            } else {
                head2->next = mergeTwoLists(head1, head2->next);
                return head2;
            }
        } else if (head1 != nullptr) {
            return head1;
        }else {
            // head2 != nullptr
            return head2;
        }
    }

    // 获取链表中间节点
    static ListNode *getMidNode(ListNode *head) {
        auto fast = head;
        auto slow = head;
        ListNode *pre;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast == nullptr) {
                break;
            }
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        if (pre != nullptr) {
            pre->next = nullptr;
        }
        return slow;
    }

};
