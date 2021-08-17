//
// Created by l30014168 on 2021/7/29.
//
#include <math.h>
#include <stdlib.h>

int *pathInZigZagTree(int label, int *returnSize) {
    if (label < 1) {
        return NULL;
    }
    int level = (int) log2(label);  // level从0开始
    *returnSize = level + 1;
    int *ans = malloc(sizeof(int) * (*returnSize));
    if (ans == NULL) {
        return NULL;
    }
    int *pow2 = malloc(sizeof(int) * (*returnSize));
    if (pow2 == NULL) {
        free(ans);
        return NULL;
    }
    pow2[0] = ans[0] = 1;
    for (int idx = 1; idx <= level; idx++) {
        pow2[idx] = pow2[idx - 1] << 1;
    }
    while (level > 0) {
        ans[level] = label;
        if ((level & 1) == 1) { // 奇数层
            label = 3 * pow2[level] - 1 - label;
            label = label >> 1;
            level--;
        } else {    // 偶数层
            label = label >> 1;
            level--;
            label = 3 * pow2[level] - 1 - label;
        }
    }
    free(pow2);
    return ans;
}

