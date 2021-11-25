//
// Created by l30014168 on 2021/11/25.
//

#include <stdlib.h>
#include "util.h"

typedef struct {
    int val;
    int idx;
} ArrayValIdx;

// int升序比较函数
static inline int arrayValIdxCmpFunc(const void *a, const void *b) {
    return ((ArrayValIdx *) a)->val - ((ArrayValIdx *) b)->val;
}

int *advantageCount(int *nums1, int nums1Size, const int *nums2, int nums2Size, int *returnSize) {
    *returnSize = nums1Size;
    int *ans = malloc(sizeof(int) * *returnSize);

    qsort(nums1, nums1Size, sizeof(int), intAscCmpFunc);
    ArrayValIdx *arrayValIdx = malloc(sizeof(ArrayValIdx) * nums2Size);
    for (int i = 0; i < nums2Size; ++i) {
        arrayValIdx[i].val = nums2[i];
        arrayValIdx[i].idx = i;
    }
    qsort(arrayValIdx, nums2Size, sizeof(ArrayValIdx), arrayValIdxCmpFunc);

    int i = 0, j = 0;  // i记录nums1的当前idx，j记录arrayValIdx(num2)的当前idx
    while (i < nums1Size) {
        if (nums1[i] <= arrayValIdx[j].val) {
            // 田忌赛马策略，下等马对上等马
            ans[arrayValIdx[nums2Size - 1 - (i - j)].idx] = nums1[i];
        } else {
            // 走到该处认为nums1[i] > nums2[j], 对上刚好能赢
            ans[arrayValIdx[j].idx] = nums1[i];
            j++;
        }
        i++;
    }
    free(arrayValIdx);
    return ans;
}