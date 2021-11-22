//
// Created by smile on 2021/9/20.
//

#include <stdbool.h>
#include "ListNode.h"

struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *preNode = NULL, *curNode = head, *nextNode = head->next;
    while (nextNode != NULL) {
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
        nextNode = nextNode->next;
    }
    curNode->next = preNode;
    return curNode;
}

bool isPalindrome(struct ListNode *head) {
    if (head == NULL) {
        return true;
    }
    size_t length = 0;
    struct ListNode *pNode = head;
    while (pNode != NULL) {
        length++;
        pNode = pNode->next;
    }
    pNode = head;
    length /= 2;
    for (size_t idx = 0; idx < length; idx++) {
        pNode = pNode->next;
    }
    struct ListNode *left = head;
    // 以 pNode 开始反转链表
    struct ListNode *right = reverseList(pNode);
    struct ListNode *rightCopy = right; // 用作恢复

    // 双指针比较
    while (length > 0) {
        if (left->val != right->val) {
            (void) reverseList(rightCopy);      // 恢复链表(以便回收内存)
            return false;
        }
        left = left->next;
        right = right->next;
        length--;
    }
    (void) reverseList(rightCopy);
    return true;
}
