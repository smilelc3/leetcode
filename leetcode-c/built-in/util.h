//
// Created by l30014168 on 2021/7/19.
//

#ifndef LEETCODE_C_UTIL_H
#define LEETCODE_C_UTIL_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// 最大值、最小值、绝对值
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define abs(n) (((n) < 0) ? -(n) : (n))

// 数组长度
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

// 位操作
#define setBit(n, idx) ((n) |= (1 << (idx)))        // 置某一位为1
#define clrBit(n, idx) ((n) &= ~(1 << (idx)))       // 置某一位为0
#define getBit(n, idx) ((n) >> (idx) & 1)           // 获取某一位值
#define revBit(n, idx) ((n) ^= (1 << (idx)))        // 某一位取反

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
    return strcmp(*(char **) a, *(char **) b);
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

// DFS迷宫遍历 (上、右、下、左、左上、右上、左下、右下)
static const int8_t dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
static const int8_t dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

#endif //LEETCODE_C_UTIL_H
