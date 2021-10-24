//
// Created by smile on 2021/10/24.
//

#include <stdlib.h>
#include <string.h>
#include <ListNode.h>

void maxQueuePushBack(DuListNode **pTail, int idx, const int *nums) {
    while (!DuCirListIsEmpty(*pTail) && nums[(*pTail)->val] <= nums[idx]) {
        // pop_back
        *pTail = (*pTail)->prev;
        DuCirListErase((*pTail)->next);
    }
    DuCirListInsert(*pTail, idx);
    *pTail = (*pTail)->next;
}

int *maxSlidingWindow(const int *nums, int numsSize, int k, int *returnSize) {
    *returnSize = numsSize - k + 1;
    int *ans = malloc(sizeof(int) * *returnSize);
    if (k == 1) {
        memcpy(ans, nums, sizeof(int) * numsSize);
        return ans;
    }
    // 使用链表实现单调队列
    DuListNode *head = DuCirListCreate();   // 保留一个空头节点
    DuListNode *tail = head;
    // 初始化队列元素
    for (int i = 0; i < k; ++i) {
        maxQueuePushBack(&tail, i, nums);
    }
    ans[0] = nums[head->next->val];

    for (int i = 1; i < *returnSize; ++i) {
        // 计算 [i, i + k) 的最大值
        // 出队
        if (i - 1 == head->next->val) {
            DuCirListErase(head->next);
        }
        // 入队
        maxQueuePushBack(&tail, i + k - 1, nums);
        ans[i] = nums[head->next->val];
    }
    DuCirListDestroy(head);
    return ans;
}