//
// Created by l30014168 on 2021/9/13.
//

#include <stdio.h>

size_t findMinBinaryMethod(const int *nums, size_t start, size_t end) {
    if (start == end) {
        return nums[start];
    }
    size_t mid = (start + end) / 2;
    if (nums[mid] < nums[end]) {
        return findMinBinaryMethod(nums, start, mid);
    } else {
        return findMinBinaryMethod(nums, mid + 1, end);
    }
}

int findMin(const int *nums, int numsSize) {
    if (numsSize <= 0) {
        fprintf(stderr, "numSize(%d) must > 0\n", numsSize);
        return -1;
    }
    return (int) findMinBinaryMethod(nums, 0, numsSize - 1);
}