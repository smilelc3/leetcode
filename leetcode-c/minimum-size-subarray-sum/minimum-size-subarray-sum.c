//
// Created by smile on 2022/2/23.
//

#include "util.h"

int minSubArrayLen(int target, const int *nums, int numsSize) {
    // 滑动窗口
    int left = 0, right = 0; // left代表起始位置，right代表结束的下一个位置
    int curWinSum = 0;
    // 当前窗口和
    int minWinLen = numsSize + 1;      // 满足条件的最小窗口长度
    while (right < numsSize) {
        curWinSum += nums[right];       // 向右滑动一位
        right++;
        while (curWinSum >= target) {
            minWinLen = min(minWinLen, right - left);
            curWinSum -= nums[left];
            left++;
        }

    }
    return minWinLen == numsSize + 1 ? 0 : minWinLen;
}