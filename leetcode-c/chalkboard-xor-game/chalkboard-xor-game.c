//
// Created by smile on 2021/11/10.
//

#include <stdbool.h>

bool xorGame(const int *nums, int numsSize) {
    uint32_t xorVal = 0;
    for (int i = 0; i < numsSize; ++i) {
        xorVal ^= (uint32_t) nums[i];
    }
    return xorVal == 0 || (numsSize & 1) == 0;      // 刚开始结果就异或为0，赢；否则偶数才必赢
}