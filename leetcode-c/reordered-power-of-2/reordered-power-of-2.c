//
// Created by smile on 2021/10/29.
//

#include <stdbool.h>
#include <string.h>

bool reorderedPowerOf2(int n) {
    uint8_t nLength = 0;
    uint8_t nums[10] = {0};
    int64_t power10 = 10;
    int64_t tmp = n;
    while (tmp > 0) {
        nums[tmp % 10]++;
        nLength++;
        tmp /= 10;
    }
    int64_t power2 = 1;
    int power2Length = 1;
    while (power2Length <= nLength) {
        if (power2Length == nLength) {
            uint8_t numsCopy[10];
            memcpy(numsCopy, nums, sizeof(numsCopy));
            tmp = power2;
            while (tmp > 0) {
                if (numsCopy[tmp % 10] == 0) {
                    break;
                }
                numsCopy[tmp % 10]--;
                tmp /= 10;
            }
            if (tmp == 0) {     // 全匹配
                return true;
            }
        }
        power2 <<= 1;
        if (power2 > power10) {
            power10 *= 10;
            power2Length++;
        }
    }
    return false;
}