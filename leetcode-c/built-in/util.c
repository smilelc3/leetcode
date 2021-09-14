//
// Created by l30014168 on 2021/7/19.
//

#include "util.h"

int64_t fastPow(int64_t a, size_t b) {
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
