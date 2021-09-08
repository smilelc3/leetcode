//
// Created by l30014168 on 2021/7/19.
//

#ifndef LEETCODE_C_UTIL_H
#define LEETCODE_C_UTIL_H

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

#endif //LEETCODE_C_UTIL_H
