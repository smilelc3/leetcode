//
// Created by smile on 2022/1/2.
//

#ifndef LEETCODE_CPP_UTIL_H
#define LEETCODE_CPP_UTIL_H

#include <cstdint>
#include <cstdlib>

// DFS迷宫遍历 (上、右、下、左、左上、右上、左下、右下)
static const char dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
static const char dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

// 快速幂
int64_t fastPow(int64_t a, size_t b);
int64_t fastPow(int64_t a, size_t b, int64_t mod);

#endif //LEETCODE_CPP_UTIL_H
