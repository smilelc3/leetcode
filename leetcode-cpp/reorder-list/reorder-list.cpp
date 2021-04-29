//
// Created by smile on 2021/4/29.
//

#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr or head->next == nullptr) {
            return;
        }
        ListNode *mid = head, *tail = head, *preMid = nullptr;
        while (tail->next != nullptr) {
            preMid = mid;
            mid = mid->next;
            tail = tail->next;
            if (tail->next != nullptr) {
                tail = tail->next;
            }
        }
        // 从 mid -> tail reverse
        preMid->next = nullptr;
        reverseList(mid);
        // 从 [head, mid) + [tail, mid] 构建新链表
        ListNode *pNode = head;
        head = head->next;
        while (tail != nullptr) {
            // len([tail, mid]) >= len([head, mid))  不用判断 tail != nullptr
            pNode->next = tail;
            pNode = pNode->next;
            tail = tail->next;
            if (head != nullptr) {
                pNode->next = head;
                pNode = pNode->next;
                head = head->next;
            }
        }
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