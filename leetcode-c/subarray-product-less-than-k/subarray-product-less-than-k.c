//
// Created by l30014168 on 2021/12/20.
//

#include <stdint.h>

int numSubarrayProductLessThanK(const int *nums, int numsSize, int k) {
    // 滑动窗口
    int ans = 0;
    int winLeft = 0, winRight = 0;      // left 表示窗口开始位置，right表示窗口结束的下一个位置
    int64_t winProduct = 1;             // 窗口乘积
    while (winRight < numsSize) {
        winRight++;
        winProduct *= nums[winRight - 1];
        while (winProduct >= k && winLeft < winRight) {
            winProduct /= nums[winLeft];
            winLeft++;
        }
        ans += winRight - winLeft;
    }
    return ans;
}