//
// Created by l30014168 on 2022/1/29.
//

#include <stdbool.h>
#include "util.h"

bool isHappy(int n) {
    if (n < 10) {
        return n == 1 || n == 7;        // 最终小于10的数字，仅1或7不陷入循环
    }
    int next = 0;
    while (n) {
        next += square(n % 10);
        n /= 10;
    }
    return isHappy(next);
}