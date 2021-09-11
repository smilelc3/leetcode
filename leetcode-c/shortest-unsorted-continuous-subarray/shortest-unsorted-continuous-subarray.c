//
// Created by l30014168 on 2021/8/13.
//

#include <stdlib.h>
#include <string.h>
#include "util.h"

static int findUnsortedSubarrayBoundMethod(const int *nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int left = numsSize - 1, right = 0;

    // 从左往右，找右边界
    int maxNum = nums[0];
    for (int idx = 1; idx < numsSize; ++idx) {
        if (maxNum > nums[idx]) {        // 当前idx位置不在正确位置
            right = idx;
        } else {
            maxNum = nums[idx];
        }
    }
    // 从右往左，找左边界
    int minNum = nums[numsSize - 1];
    for (int idx = numsSize - 2; idx >= 0; --idx) {
        if (minNum < nums[idx]) {        // 当前idx位置不在正确位置
            left = idx;
        } else {
            minNum = nums[idx];
        }
    }
    if (left == numsSize - 1 && right == 0) {       // 位置未变动
        return 0;
    }
    return right - left + 1;
}


static int findUnsortedSubarraySortMethod(const int *nums, int numsSize) {

    int *numsSort;
    numsSort = malloc(sizeof(int) * numsSize);
    if (numsSort == NULL) {
        return 0;
    }
    memcpy(numsSort, nums, sizeof(int) * numsSize);

    qsort(numsSort, numsSize, sizeof(int), intAscCmpFunc);
    int left = 0, right = numsSize - 1;
    while (nums[left] == numsSort[left]) {
        left++;
        if (left == numsSize) {
            return 0;
        }
    }
    while (nums[right] == numsSort[right]) {
        right--;
    }
    free(numsSort);
    return right - left + 1;
}

static int findUnsortedSubarray(const int *nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    // sort method. time: O(nlog(n)) space: O(n)
    // return findUnsortedSubarraySortMethod(nums, numsSize);


    // bound method. time: O(n) space: O(1)
    return findUnsortedSubarrayBoundMethod(nums, numsSize);
}