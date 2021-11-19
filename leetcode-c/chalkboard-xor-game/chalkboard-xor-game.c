//
// Created by smile on 2021/11/10.
//

#include <stdbool.h>

bool xorGame(const int *nums, int numsSize) {
    uint32_t xorVal = 0;
    for (int i = 0; i < numsSize; ++i) {
        xorVal ^= nums[i];
    }
    if (xorVal == 0) {
        return true;
    }
    for (int i = 0; i < numsSize; ++i) {
        bool isExistNot
        for (int j = i; j < numsSize; ++j) {
            if ((xorVal ^ nums[j]) != 0)
        }
        xorVal ^= nums[i];
        if (xorVal == 0) {
            if ((i & 1) == 1) {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}