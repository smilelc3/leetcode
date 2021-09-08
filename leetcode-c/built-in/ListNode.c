//
// Created by l30014168 on 2021/9/8.
//

#include "ListNode.h"
#include <stdio.h>


struct ListNode *ListCreateByNums(const int *nums, size_t numsSize) {
    if (numsSize == 0) {
        return NULL;
    }
    struct ListNode *head = calloc(1, sizeof(struct ListNode));
    if (head == NULL) {
        fprintf(stderr, "calloc ListNode head fail! function(%s)\n", __func__);
        return NULL;
    }
    head->val = nums[0];
    struct ListNode *preNode = head;
    for (size_t idx = 1; idx < numsSize; ++idx) {
        struct ListNode *node = calloc(1, sizeof(struct ListNode));
        if (node == NULL) {
            fprintf(stderr, "calloc ListNode node fail! function(%s), index(%zu), size(%zu)\n", __func__, idx, sizeof(struct ListNode));
            return head;
        }
        preNode->next = node;
        node->val = nums[idx];
        preNode = node;
    }
    return head;
}

void ListDestroy(struct ListNode *head) {
    if (head == NULL) {
        return;
    }
    ListDestroy(head->next);
    free(head);
    head = NULL;
}
