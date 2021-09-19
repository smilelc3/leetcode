//
// Created by l30014168 on 2021/7/19.
//

#ifndef LEETCODE_C_UTIL_H
#define LEETCODE_C_UTIL_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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

// 字符串字典序比较函数
static inline int strAscCmpFunc(const void *a, const void *b) {
    return strcmp((char *) a, (char *) b);
}

// 字符串逆字典序比较函数
static inline int strDescCmpFunc(const void *a, const void *b) {
    return -strAscCmpFunc(a, b);
}

// 快速幂
int64_t fastPow(int64_t a, size_t b);

// TODO gcd/lcm函数，需要从C++17标准中移植

#endif //LEETCODE_C_UTIL_H
