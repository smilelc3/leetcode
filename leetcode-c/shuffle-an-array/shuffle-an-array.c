//
// Created by l30014168 on 2021/9/23.
//

#include <stdio.h>
#include <string.h>
#include <time.h>

# define swap(a, b) (a)^=(b)^=(a)^=(b);

typedef struct {
    int *rawNums;
    int *shuffleNums;
    int numsLength;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
    Solution *ret = malloc(sizeof(Solution));
    if (ret == NULL) {
        fprintf(stderr, "malloc fail! size(%zu)\n", sizeof(Solution));
        return NULL;
    }
    ret->rawNums = malloc(sizeof(int) * numsSize);
    ret->shuffleNums = malloc(sizeof(int) * numsSize);
    if (ret->rawNums == NULL || ret->shuffleNums == NULL) {
        fprintf(stderr, "malloc fail! size(%zu)\n", sizeof(int) * numsSize);
        return ret;
    }

    ret->numsLength = numsSize;
    memcpy(ret->rawNums, nums, sizeof(int) * numsSize);
    memcpy(ret->shuffleNums, nums, sizeof(int) * numsSize);
    srand((unsigned int) time(NULL));
    return ret;
}

/** Resets the array to its original configuration and return it. */
int *solutionReset(Solution *obj, int *retSize) {
    *retSize = obj->numsLength;
    return obj->rawNums;
}

/** Returns a random shuffling of the array. */
int *solutionShuffle(Solution *obj, int *retSize) {
    // 打乱数组 随机选择一个位置和尾位置交换，缩小队列，直至为1
    for (int idx = obj->numsLength - 1; idx > 0; --idx) {
        int randNum = rand() % (idx + 1);
        if (randNum == idx) {
            continue;
        }
        swap(obj->shuffleNums[idx], obj->shuffleNums[randNum]);
    }
    *retSize = obj->numsLength;
    return obj->shuffleNums;
}


void solutionFree(Solution *obj) {
    free(obj->rawNums);
    free(obj->shuffleNums);
    free(obj);
}