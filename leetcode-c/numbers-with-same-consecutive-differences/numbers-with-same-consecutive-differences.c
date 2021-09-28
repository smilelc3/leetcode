//
// Created by l30014168 on 2021/9/28.
//

#include <string.h>
#include "Vector.h"

void dfsSolver(int n, int k, int idx, int cur, Vector *ans) {
    if (idx == n) {
        VectorAppend(ans, &cur);
        return;
    }
    int last = cur % 10;
    if (last + k < 10) {
        dfsSolver(n, k, idx + 1, cur * 10 + last + k, ans);

    }
    if (k != 0 && last - k >= 0) {
        dfsSolver(n, k, idx + 1, cur * 10 - k + last, ans);
    }
}


int *numsSameConsecDiff(int n, int k, int *returnSize) {
    Vector *ans = VectorCreate(sizeof(int));
    for (int i = 1; i < 10; ++i) {
        dfsSolver(n, k, 1, i, ans);
    }

    *returnSize = (int) ans->size;
    int *ret = malloc(sizeof(int) * *returnSize);
    memcpy(ret, ans->items, sizeof(int) * *returnSize);
    VectorDestroy(ans);
    return ret;
}