//
// Created by l30014168 on 2021/7/19.
//

#ifndef LEETCODE_C_UTIL_H
#define LEETCODE_C_UTIL_H

#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// int升序比较函数
static inline int intAscCmpFunc(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

// int降序比较函数
static inline int intDescCmpFunc(const void *a, const void *b) {
    return -intAscCmpFunc(a, b);
}

// 快速幂
int64_t fastPow(int64_t a, size_t b);

#endif //LEETCODE_C_UTIL_H
