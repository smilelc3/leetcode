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
#define abs(n) (((n) < 0) ? -(n) : (n))

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

// 最大公约数（移植于C++17 std::gcd）
static int64_t gcd(int64_t m, int64_t n) {
    return m == 0 ? abs(n)
                  : n == 0 ? abs(m)
                           : gcd(n, m % n);
}

// 最小公倍数（移植于C++17 std::lcm）
static int64_t lcm(int64_t m, int64_t n) {
    return (m != 0 && n != 0)
           ? (abs(m) / gcd(m, n)) * abs(n)
           : 0;
}

// 交换元素
void swap(void *_a, void *_b, size_t _sizeOfElement) {
    uint8_t *buf = malloc(_sizeOfElement);
    memmove(buf, _a, _sizeOfElement);
    memmove(_a, _b, _sizeOfElement);
    memmove(_b, buf, _sizeOfElement);
}

#endif //LEETCODE_C_UTIL_H
