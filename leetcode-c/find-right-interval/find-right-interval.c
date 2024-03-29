//
// Created by l30014168 on 2021/11/22.
//

#include <stdlib.h>
#include "util.h"

typedef struct {
    int leftVal;
    int idx;
} LeftAndIdx;

static inline int leftAndIdxCmpFunc(const void *a, const void *b) {
    return intAscCmpFunc(&(*(LeftAndIdx *) a).leftVal, &(*(LeftAndIdx *) b).leftVal);
}

// 在找到第一个大于等于rightVal的idx
int findClosestIdx(LeftAndIdx *leftAndIdxArraySort, int right, int rightVal) {
    if (leftAndIdxArraySort[right - 1].leftVal < rightVal) {
        return -1;
    }
    int left = 0;      // left 左边界， right 右边界的下一个
    while (left < right) {
        int mid = (left + right) / 2;
        if (leftAndIdxArraySort[mid].leftVal == rightVal) {
            return leftAndIdxArraySort[mid].idx;
        } else if (leftAndIdxArraySort[mid].leftVal < rightVal) {
            left = mid + 1;
        } else {        // leftAndIdxArraySort[mid].leftVal > rightVal
            right = mid;
        }
    }
    return leftAndIdxArraySort[left].idx;
}

int *findRightInterval(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize) {
    LeftAndIdx *leftAndIdxArray = malloc(sizeof(LeftAndIdx) * intervalsSize);
    for (int i = 0; i < intervalsSize; ++i) {
        leftAndIdxArray[i].leftVal = intervals[i][0];
        leftAndIdxArray[i].idx = i;
    }
    qsort(leftAndIdxArray, intervalsSize, sizeof(LeftAndIdx), leftAndIdxCmpFunc);

    *returnSize = intervalsSize;
    int *ans = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < intervalsSize; ++i) {
        ans[i] = findClosestIdx(leftAndIdxArray, intervalsSize, intervals[i][1]);
    }

    free(leftAndIdxArray);
    return ans;
}