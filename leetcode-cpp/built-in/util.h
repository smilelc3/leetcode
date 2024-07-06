//
// Created by smile on 2022/1/2.
//

#ifndef LEETCODE_CPP_UTIL_H
#define LEETCODE_CPP_UTIL_H

#include <cstdint>
#include <cstdlib>
#include <array>

namespace util {
    // DFS迷宫遍历 (上、右、下、左、左上、右上、左下、右下)
    static const std::array<int8_t, 8> dx = {-1, 0, 1, 0, -1, -1, 1, 1};
    static const std::array<int8_t, 8> dy = {0, 1, 0, -1, -1, 1, -1, 1};

    // 快速幂
    constexpr int64_t fastPow(int64_t a, size_t b) {
        int64_t ret = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret *= a;
            }
            a *= a;
            b >>= 1;
        }
        return ret;
    }

    // 带取模操作的快速幂
    constexpr int64_t fastPow(int64_t a, size_t b, int64_t mod) {
        int64_t ret = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = (ret * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ret;
    }

    // 平方
    template<typename T>
    inline auto square(const T &x) -> T {
        return x * x;
    }
}


#endif //LEETCODE_CPP_UTIL_H
