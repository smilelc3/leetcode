//
// Created by smile on 2021/10/24.
//

#include <stdbool.h>

static inline bool isIntEven(int val) {
    return (val & 1) == 0;
}

int *sumEvenAfterQueries(int *nums, int numsSize,
                         int **queries, int queriesSize, const int *queriesColSize,
                         int *returnSize) {
    int *ret = malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    int sumEven = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (isIntEven(nums[i])) {
            sumEven += nums[i];
        }
    }

    for (int i = 0; i < queriesSize; ++i) {
        int addIdx = queries[i][1];
        int addVal = queries[i][0];
        bool isValEven = isIntEven(nums[addIdx]);
        bool isAddValEven = isIntEven(addVal);
        if (isValEven && isAddValEven) {
            sumEven += addVal;
        } else if (!isValEven && !isAddValEven) {
            sumEven += nums[addIdx] + addVal;
        } else if (isValEven) {
            sumEven -= nums[addIdx];
        }
        nums[addIdx] += addVal;
        ret[i] = sumEven;
    }
    return ret;
}