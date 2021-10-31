//
// Created by smile on 2021/10/24.
//

#include <stdlib.h>
#include <string.h>
#include "ListNode.h"
#include "util.h"

// DuLinkList模拟的单调队列入队函数
void maxDuLinkListQueuePushBack(DuListNode **pTail, int idx, const int *nums) {
    while (!DuCirListIsEmpty(*pTail) && nums[(*pTail)->val] <= nums[idx]) {
        // pop_back
        *pTail = (*pTail)->prev;
        DuCirListErase((*pTail)->next);
    }
    DuCirListInsert(*pTail, idx);
    *pTail = (*pTail)->next;
}

// 顺序表模拟的单调队列入队函数
void maxVectorQueuePushBack(int *queue, const int *pStart, int *pEnd, int idx, const int *nums) {
    while (*pStart != *pEnd && nums[queue[*pEnd - 1]] <= nums[idx]) {
        (*pEnd)--;  // pop_back
    }
    queue[*pEnd] = idx;
    (*pEnd)++;
}

int *maxSlidingWindowDuLinkListMethod(const int *nums, int numsSize, int k, int *returnSize) {
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
        maxDuLinkListQueuePushBack(&tail, i, nums);
    }
    ans[0] = nums[head->next->val];

    for (int i = 1; i < *returnSize; ++i) {
        // 计算 [i, i + k) 的最大值
        // 出队
        if (i - 1 == head->next->val) {
            DuCirListErase(head->next);
        }
        // 入队
        maxDuLinkListQueuePushBack(&tail, i + k - 1, nums);
        ans[i] = nums[head->next->val];
    }
    DuCirListDestroy(head);
    return ans;
}

int *maxSlidingWindowDuLoopMethod(const int *nums, int numsSize, int k, int *returnSize) {
    *returnSize = numsSize - k + 1;
    int *ans = malloc(sizeof(int) * *returnSize);

    for (int i = 0; i < *returnSize; ++i) {
        int maxInWin = nums[i];
        for (int j = 1; j < k; ++j) {
            maxInWin = max(maxInWin, nums[i + j]);
        }
        ans[i] = maxInWin;
    }
    return ans;
}

int *maxSlidingWindowVectorMethod(const int *nums, int numsSize, int k, int *returnSize) {
    *returnSize = numsSize - k + 1;
    int *ans = malloc(sizeof(int) * *returnSize);
    // 使用顺序表实现单调队列
    int *queue = malloc(sizeof(int) * numsSize);
    int queueBegin = 0;     // 队列开始位置
    int queueEnd = 0;       // 指向结束位置的下一个
    // 初始化队列元素
    for (int i = 0; i < k; ++i) {
        maxVectorQueuePushBack(queue, &queueBegin, &queueEnd, i, nums);
    }
    ans[0] = nums[queue[queueBegin]];
    for (int i = 1; i < *returnSize; ++i) {
        // 计算 [i, i + k) 的最大值
        // 出队
        if (i - 1 == queue[queueBegin]) {
            queueBegin++;
        }
        // 入队
        maxVectorQueuePushBack(queue, &queueBegin, &queueEnd, i + k - 1, nums);
        ans[i] = nums[queue[queueBegin]];
    }
    free(queue);
    return ans;
}

int *maxSlidingWindow(const int *nums, int numsSize, int k, int *returnSize) {
    // double loop method
    // return maxSlidingWindowDuLoopMethod(nums, numsSize, k, returnSize);

    // duLinkList 单调队列
    // return maxSlidingWindowDuLinkListMethod(nums, numsSize, k, returnSize);

    // 顺序表实现单调队列
    return maxSlidingWindowVectorMethod(nums, numsSize, k, returnSize);
}
