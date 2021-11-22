//
// Created by smile on 2021/11/19.
//

#include <stdlib.h>
#include <string.h>
#include "util.h"

// 排序优先级：身高高的在前，身高相同则第二个数（大于等于该身高的人数）小的在前
static inline int peopleCmpFunc(const void *pPeopleA, const void *pPeopleB) {
    int *peopleA = *(int **) pPeopleA, *peopleB = *(int **) pPeopleB;
    int aHeight = peopleA[0], aGreaterNum = peopleA[1];
    int bHeight = peopleB[0], bGreaterNum = peopleB[1];
    if (aHeight != bHeight) {
        return intDescCmpFunc(&aHeight, &bHeight);
    }
    return intAscCmpFunc(&aGreaterNum, &bGreaterNum);
}

int **reconstructQueue(int **people, int peopleSize, int *peopleColSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = peopleSize;
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    int **ret = malloc(sizeof(int *) * *returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        ret[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
    }

    qsort(people, peopleSize, sizeof(int *), peopleCmpFunc);
    for (int i = 0; i < peopleSize; ++i) {
        int curHeight = people[i][0];
        int curGreaterNum = people[i][1];
        if (curGreaterNum != i) {    // 需要移动数组
            int *tmp = ret[i];
            // 将 ret[curGreaterNum, i-1] 内容后移一位
            // memmove(ret + curGreaterNum + 1, ret + curGreaterNum, sizeof(int *) * (i - curGreaterNum));
            for (int j = i; j > curGreaterNum; --j) {
                ret[j] = ret[j - 1];
            }
            ret[curGreaterNum] = tmp;
        }
        ret[curGreaterNum][0] = curHeight;
        ret[curGreaterNum][1] = curGreaterNum;
    }
    return ret;
}


// TODO 线段树版本