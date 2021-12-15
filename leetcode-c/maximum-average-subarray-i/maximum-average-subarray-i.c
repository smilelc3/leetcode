//
// Created by l30014168 on 2021/12/15.
//

#include <limits.h>
#include "util.h"

double findMaxAverage(const int *nums, int numsSize, int k) {
    size_t left = 0, right = 1;      // 左边界开始位置，右边界为结束位置的下一个位置
    int maxSum = INT_MIN;
    int maxSumLength = 0;        // 分别记录和+长度，避免精度缺失

    int winSum = INT_MIN;
    int winLength = 0;

    while(left <= numsSize) {
        // 如果添加右边界，会降低平均值，一直添加直到不下降为止


        winSum += nums[right - 1];
        maxSumLength++;
        right++;

        // 如果移除左边界，会升高平均值，一直添加直到不上升为止


    }
    return maxSumLength == 0 ? 0 : maxSum * 1.0 / maxSumLength;
}