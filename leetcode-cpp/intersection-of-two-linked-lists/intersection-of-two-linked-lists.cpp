//
// Created by smile on 2021/6/9.
//
#include "ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lengthA = getListLength(headA), lengthB;
        ListNode *rsvB;
        std::tie(rsvB, lengthB) = reverseList(headB);     // 反转其中一条链
        auto lenAAddLenBSub2TAdd1 = getListLength(headA);
        auto T = (lengthA + lengthB + 1 - lenAAddLenBSub2TAdd1) / 2;
        reverseList(rsvB);     // 将反转的链恢复
        if (lengthA >= T and lengthB >= T) {
            auto targetA = getNumNList(headA, lengthA - T), targetB = getNumNList(headB, lengthB - T);
            return targetA == targetB ? targetA : nullptr;
        }
        return nullptr;
    }

private:
    // 反转链表并获取长度
    std::pair<ListNode *, size_t> reverseList(ListNode *head) {
        size_t length = 0;
        if (head == nullptr) {
            return std::make_pair(nullptr, length);
        }
        length++;
        ListNode *preNode = nullptr, *curNode = head, *nextNode = head->next;
        while (nextNode != nullptr) {
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
            nextNode = nextNode->next;
            length++;
        }
        curNode->next = preNode;
        return std::make_pair(curNode, length);
    }

    // 获取链表长度
    inline size_t getListLength(ListNode *head) {
        size_t length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

    // 获取链表第N个值
    inline ListNode *getNumNList(ListNode *head, size_t N) noexcept {
        while (N != 0) {
            head = head->next;
            N--;
        }
        return head;
    }
};