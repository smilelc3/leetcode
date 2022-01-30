//
// Created by l30014168 on 2022/1/30.
//

#include "ListNode.h"

struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode temp = {0, head};
    struct ListNode *prev = &temp, *pNode = head;
    while (pNode != NULL) {
        if (pNode->val == val) {
            prev->next = pNode->next;
            free(pNode);
            pNode = prev->next;
        } else {
            prev = pNode;
            pNode = pNode->next;
        }
    }
    return temp.next;
}