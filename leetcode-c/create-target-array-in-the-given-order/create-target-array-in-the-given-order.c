//
// Created by smile on 2021/8/22.
//

#include <string.h>
#include "Vector.h"


int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize) {
    if (numsSize != indexSize || numsSize < 0) {
        return 0;
    }

    Vector *vector = VectorCreate(sizeof(int));
    for (int idx = 0; idx < numsSize; ++idx) {
        VectorInsert(vector, index[idx], &nums[idx]);
    }
    *returnSize = (int) vector->size;

    int *ret = malloc(numsSize * sizeof(int));
    memcpy(ret, vector->items, numsSize * sizeof(int));
    VectorDestroy(vector);
    return ret;
}