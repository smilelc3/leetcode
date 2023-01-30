//
// Created by smile on 2023/1/30.
//

#include "ListNode.h"

void deleteNode(struct ListNode *node) {
    // 默认保证node不为尾节点 node->next != NULL
    struct ListNode *delNote = node->next;
    node->val = delNote->val;
    node->next = delNote->next;
    free(delNote);
}
