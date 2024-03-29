//
// Created by smile on 2022/1/5.
//

#include "util.h"

int64_t util::fastPow(int64_t a, size_t b) {
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

int64_t util::fastPow(int64_t a, size_t b, int64_t mod) {
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
