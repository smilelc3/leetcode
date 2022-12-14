//
// Created by smile on 2021/8/23.
//

#include <stdlib.h>
#include <string.h>
#include <util.h>

int strCmpFun(const char *a, const char *b) {
    size_t lenA = strlen(a), lenB = strlen(b);
    for (size_t i = 0; i < min(lenA, lenB); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    if (lenA < lenB) {
        return strCmpFun(a, b + lenA);
    }
    if (lenA > lenB) {
        return strCmpFun(a + lenB, b);
    }
    return 0;
}

int strPtrCmpFun(const void *a, const void *b) {
    char *strA = *(char **) a;
    char *strB = *(char **) b;
    return strCmpFun(strA, strB);
}


char *largestNumber(const int *nums, int numsSize) {
    char **numsStr = malloc(sizeof(char *) * numsSize);
    if (numsStr == NULL) {
        perror("malloc fail.\n");
        return NULL;
    }
    for (int idx = 0; idx < numsSize; ++idx) {
        const uint8_t numStrLen = 10;  // 最多有10位
        char *numStr = malloc(numStrLen + 1);
        if (numStr == NULL) {
            fprintf(stderr, "malloc fail. idx(%d)\n", idx);
            continue;
        }
        snprintf(numStr, numStrLen, "%d", nums[idx]);
        numsStr[idx] = numStr;
    }

    qsort(numsStr, numsSize, sizeof(char *), strPtrCmpFun);

    char *ret = malloc(sizeof(char) * 100 * 10 + 1);
    size_t length = 0;
    for (int idx = 0; idx < numsSize; ++idx) {
        strcpy(ret + length, numsStr[idx]);
        length += strlen(numsStr[idx]);
        free(numsStr[idx]);
    }
    // 考虑全零情况
    if (ret[0] == '0') {
        ret[1] = '\0';
    }
    free(numsStr);
    return ret;
}